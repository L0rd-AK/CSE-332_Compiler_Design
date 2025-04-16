%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* msg);
int yylex(void);

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
    fprintf(stderr, "Syntax Error: %s\n", msg);
}

// For tracking line numbers in error reporting
extern int yylineno;

%}

%union {
    int num;
    char* str;
}

%token MYTYPE SHOW IF ELSE WHILE
%token <num> NUMBER
%token <str> ID
%token '=' '+' '-' '*' '/' '(' ')' ';' '{' '}'
%token EQ NEQ LT GT LTE GTE

%type <num> expression condition

%left EQ NEQ LT GT LTE GTE
%left '+' '-'
%left '*' '/'

%%

program:
    | program statement
;

statement:
    declaration ';'
    | assignment ';'
    | show_stmt ';'
    | expression ';' { printf("Expression result: %d\n", $1); }
    | if_stmt
    | while_stmt
    | block
;

block:
    '{' statements '}'
;

statements:
    /* empty */
    | statements statement
;

declaration:
    MYTYPE ID { add_symbol($2); printf("Declared %s\n", $2); free($2); }
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

show_stmt:
    SHOW '(' ID ')' {
        Symbol* s = find_symbol($3);
        if (s) printf("Displaying value of %s: %d\n", $3, s->value);
        else yyerror("Undeclared variable");
        free($3);
    }
;

if_stmt:
    IF '(' condition ')' statement { 
        printf("If statement executed\n"); 
    }
    | IF '(' condition ')' statement ELSE statement { 
        printf("If-else statement executed\n"); 
    }
;

while_stmt:
    WHILE '(' condition ')' statement { 
        printf("While loop executed\n"); 
    }
;

condition:
    expression EQ expression { $$ = ($1 == $3); }
    | expression NEQ expression { $$ = ($1 != $3); }
    | expression LT expression { $$ = ($1 < $3); }
    | expression GT expression { $$ = ($1 > $3); }
    | expression LTE expression { $$ = ($1 <= $3); }
    | expression GTE expression { $$ = ($1 >= $3); }
    | expression { $$ = ($1 != 0); }
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
;

%%