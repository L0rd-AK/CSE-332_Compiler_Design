%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* msg);
int yylex(void);

// External file pointer from flex
extern FILE* yyin;
extern int yylineno;

// Token list structure
typedef struct TokenNode {
    char* token;
    char* type;
    struct TokenNode* next;
} TokenNode;

extern TokenNode* token_list;

typedef struct Symbol {
    char* name;
    int value;
    struct Symbol* next;
} Symbol;

Symbol* symbol_table = NULL;

Symbol* find_symbol(char* name) {
    Symbol* s = symbol_table;
    while (s) {
        if (strcmp(s->name, name) == 0) return s;
        s = s->next;
    }
    return NULL;
}

void add_symbol(char* name) {
    if (find_symbol(name)) {
        yyerror("Variable redeclared");
        return;
    }
    Symbol* s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->value = 0;
    s->next = symbol_table;
    symbol_table = s;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, msg);
}

%}

%union {
    int num;
    char* str;
}

%token MYTYPE SHOW
%token INT CHAR FLOAT DOUBLE VOID MAIN
%token IF ELSE WHILE FOR RETURN
%token PRINTF SCANF INCLUDE
%token <str> ID STRING HEADER_FILE
%token <num> NUMBER
%token '=' '+' '-' '*' '/' '(' ')' ';' '{' '}' ',' '<' '>' '[' ']' '%'
%token EQ NEQ LT GT LTE GTE
%token INC DEC  /* for ++ and -- */

%type <num> expression
%type <str> type

%left EQ NEQ
%left '<' '>' LTE GTE
%left '+' '-'
%left '*' '/' '%'

%%

program:
    /* empty */
    | program external_declaration
;

external_declaration:
    include_directive
    | function_definition
    | declaration ';'
;

include_directive:
    INCLUDE HEADER_FILE {
        printf("Processed include directive: %s\n", $2);
        free($2);
    }
;

function_definition:
    type ID '(' parameter_list ')' compound_statement {
        printf("Defined function: %s\n", $2);
        free($1);
        free($2);
    }
    | INT MAIN '(' parameter_list ')' compound_statement {
        printf("Defined main function\n");
    }
;

parameter_list:
    /* empty */
    | parameters
;

parameters:
    parameter
    | parameters ',' parameter
;

parameter:
    type ID {
        add_symbol($2);
        printf("Parameter: %s\n", $2);
        free($1);
        free($2);
    }
;

type:
    INT { $$ = strdup("int"); }
    | CHAR { $$ = strdup("char"); }
    | FLOAT { $$ = strdup("float"); }
    | DOUBLE { $$ = strdup("double"); }
    | VOID { $$ = strdup("void"); }
    | MYTYPE { $$ = strdup("mytype"); }
;

compound_statement:
    '{' statement_list '}'
;

statement_list:
    /* empty */
    | statement_list statement
;
statement:
    declaration ';'
    | assignment ';'
    | function_call ';'
    | return_statement ';'
    | expression ';' { printf("Expression result: %d\n", $1); }
    | compound_statement
    | show_stmt ';'
    | if_statement
    | for_statement
    | while_statement
;

/* Add these new rules for if statements */
if_statement:
    IF '(' expression ')' statement {
        printf("Processed if statement\n");
    }
    | IF '(' expression ')' statement ELSE statement {
        printf("Processed if-else statement\n");
    }
;

/* Add these new rules for for statements */
for_statement:
    FOR '(' declaration expression ';' expression ')' statement {
        printf("Processed for loop\n");
    }
    | FOR '(' assignment expression ';' expression ')' statement {
        printf("Processed for loop\n");
    }
    | FOR '(' declaration ';' expression ';' expression ')' statement {
        printf("Processed for loop with three parts\n");
    }
    | FOR '(' assignment ';' expression ';' expression ')' statement {
        printf("Processed for loop with three parts\n");
    }
;

/* Add new rules for while statements */
while_statement:
    WHILE '(' expression ')' statement {
        printf("Processed while loop\n");
    }
;

declaration:
    type declaration_list {
        free($1);
    }
;

declaration_list:
    declarator
    | declaration_list ',' declarator
;

declarator:
    ID {
        add_symbol($1);
        printf("Declared variable: %s\n", $1);
        free($1);
    }
    | ID '=' expression {
        add_symbol($1);
        Symbol* s = find_symbol($1);
        if (s) {
            s->value = $3;
            printf("Declared and initialized variable: %s with value %d\n", $1, $3);
        }
        free($1);
    }
;

assignment:
    ID '=' expression {
        Symbol* s = find_symbol($1);
        if (s) {
            s->value = $3;
            printf("Assigned %d to variable %s\n", $3, $1);
        } else {
            yyerror("Undeclared variable");
        }
        free($1);
    }
;

function_call:
    ID '(' argument_list ')' {
        printf("Function call: %s\n", $1);
        free($1);
    }
    | PRINTF '(' STRING ')' {
        printf("Printf statement with format: %s\n", $3);
        free($3);
    }
    | PRINTF '(' STRING ',' argument_list ')' {
        printf("Printf statement with format: %s\n", $3);
        free($3);
    }
    | SCANF '(' STRING ',' argument_list ')' {
        printf("Scanf statement with format: %s\n", $3);
        free($3);
    }
;

argument_list:
    /* empty */
    | arguments
;

arguments:
    expression
    | STRING {
        printf("String argument: %s\n", $1);
        free($1);
    }
    | arguments ',' expression
    | arguments ',' STRING {
        printf("String argument: %s\n", $3);
        free($3);
    }
;

return_statement:
    RETURN expression {
        printf("Return statement with value: %d\n", $2);
    }
    | RETURN {
        printf("Return statement with no value\n");
    }
;

show_stmt:
    SHOW '(' ID ')' {
        Symbol* s = find_symbol($3);
        if (s) printf("Displaying value of %s: %d\n", $3, s->value);
        else yyerror("Undeclared variable");
        free($3);
    }
;

expression:
    NUMBER { $$ = $1; }
    | ID {
        Symbol* s = find_symbol($1);
        if (s) $$ = s->value;
        else { yyerror("Undeclared variable"); $$ = 0; }
        free($1);
      }
    | '(' expression ')' { $$ = $2; }
    | expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
    | expression '%' expression {
        if ($3 == 0) {
            yyerror("Modulo by zero");
            $$ = 0;
        } else {
            $$ = $1 % $3;
        }
    }
    | expression EQ expression { $$ = ($1 == $3); }
    | expression NEQ expression { $$ = ($1 != $3); }
    | expression '<' expression { $$ = ($1 < $3); }
    | expression '>' expression { $$ = ($1 > $3); }
    | expression LTE expression { $$ = ($1 <= $3); }
    | expression GTE expression { $$ = ($1 >= $3); }
    | ID INC { 
        Symbol* s = find_symbol($1);
        if (s) {
            $$ = s->value++;
            printf("Incrementing variable %s\n", $1);
        } else {
            yyerror("Undeclared variable");
            $$ = 0;
        }
        free($1);
    }
    | ID DEC { 
        Symbol* s = find_symbol($1);
        if (s) {
            $$ = s->value--;
            printf("Decrementing variable %s\n", $1);
        } else {
            yyerror("Undeclared variable");
            $$ = 0;
        }
        free($1);
    }
    | INC ID { 
        Symbol* s = find_symbol($2);
        if (s) {
            s->value++;
            $$ = s->value;
            printf("Pre-incrementing variable %s\n", $2);
        } else {
            yyerror("Undeclared variable");
            $$ = 0;
        }
        free($2);
    }
    | DEC ID { 
        Symbol* s = find_symbol($2);
        if (s) {
            s->value--;
            $$ = s->value;
            printf("Pre-decrementing variable %s\n", $2);
        } else {
            yyerror("Undeclared variable");
            $$ = 0;
        }
        free($2);
    }
;

%%