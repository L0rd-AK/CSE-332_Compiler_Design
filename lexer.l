%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

// Token collection for display
typedef struct TokenNode {
    char* token;
    char* type;
    struct TokenNode* next;
} TokenNode;

TokenNode* token_list = NULL;

void add_token(char* token, char* type) {
    TokenNode* new_node = (TokenNode*)malloc(sizeof(TokenNode));
    new_node->token = strdup(token);
    new_node->type = strdup(type);
    new_node->next = token_list;
    token_list = new_node;
}

%}

%option noyywrap

/* Define exclusive start conditions for comments */
%x SINGLE_COMMENT
%x MULTI_COMMENT
%x INCLUDE_STATE

%%

"#include"      { add_token(yytext, "Preprocessor Directive"); BEGIN(INCLUDE_STATE); return INCLUDE; }
<INCLUDE_STATE>[<][^>]*[>] { 
    add_token(yytext, "Header File");
    yylval.str = strdup(yytext); 
    BEGIN(INITIAL); 
    return HEADER_FILE; 
}
<INCLUDE_STATE>[ \t]      { /* Skip whitespace */ }
<INCLUDE_STATE>\"[^\"]*\" { 
    add_token(yytext, "Header File");
    yylval.str = strdup(yytext); 
    BEGIN(INITIAL); 
    return HEADER_FILE; 
}

"int"           { add_token(yytext, "Keyword"); return INT; }
"main"          { add_token(yytext, "Keyword"); return MAIN; }
"char"          { add_token(yytext, "Keyword"); return CHAR; }
"float"         { add_token(yytext, "Keyword"); return FLOAT; }
"double"        { add_token(yytext, "Keyword"); return DOUBLE; }
"void"          { add_token(yytext, "Keyword"); return VOID; }
"return"        { add_token(yytext, "Keyword"); return RETURN; }
"if"            { add_token(yytext, "Keyword"); return IF; }
"else"          { add_token(yytext, "Keyword"); return ELSE; }
"while"         { add_token(yytext, "Keyword"); return WHILE; }
"for"           { add_token(yytext, "Keyword"); return FOR; }
"printf"        { add_token(yytext, "Identifier"); return PRINTF; }
"scanf"         { add_token(yytext, "Identifier"); return SCANF; }

"mytype"        { add_token(yytext, "Keyword"); return MYTYPE; }
"show"          { add_token(yytext, "Keyword"); return SHOW; }

"//"            { BEGIN(SINGLE_COMMENT); }
<SINGLE_COMMENT>\n { BEGIN(INITIAL); }
<SINGLE_COMMENT>.  { /* Ignore everything in single-line comment */ }

"/*"            { BEGIN(MULTI_COMMENT); }
<MULTI_COMMENT>"*/" { BEGIN(INITIAL); }
<MULTI_COMMENT>\n   { /* Ignore newlines in multi-line comments */ }
<MULTI_COMMENT>.    { /* Ignore everything in multi-line comments */ }

[a-zA-Z_][a-zA-Z0-9_]* { 
    add_token(yytext, "Identifier"); 
    yylval.str = strdup(yytext); 
    return ID; 
}

[0-9]+          { 
    add_token(yytext, "Integer Literal"); 
    yylval.num = atoi(yytext); 
    return NUMBER; 
}

\"[^\"]*\"      { 
    add_token(yytext, "String Literal"); 
    yylval.str = strdup(yytext); 
    return STRING; 
}

";"             { add_token(yytext, "Punctuation"); return ';'; }
","             { add_token(yytext, "Punctuation"); return ','; }
"="             { add_token(yytext, "Assignment Operator"); return '='; }
"+"             { add_token(yytext, "Arithmetic Operator"); return '+'; }
"-"             { add_token(yytext, "Arithmetic Operator"); return '-'; }
"*"             { add_token(yytext, "Arithmetic Operator"); return '*'; }
"/"             { add_token(yytext, "Arithmetic Operator"); return '/'; }
"("             { add_token(yytext, "Punctuation"); return '('; }
")"             { add_token(yytext, "Punctuation"); return ')'; }
"{"             { add_token(yytext, "Punctuation"); return '{'; }
"}"             { add_token(yytext, "Punctuation"); return '}'; }
"<"             { add_token(yytext, "Relational Operator"); return '<'; }
">"             { add_token(yytext, "Relational Operator"); return '>'; }
"["             { add_token(yytext, "Punctuation"); return '['; }
"]"             { add_token(yytext, "Punctuation"); return ']'; }
"%"             { add_token(yytext, "Arithmetic Operator"); return '%'; }

[ \t\n]         ; /* Ignore whitespace */
.               { fprintf(stderr, "Lex error: Invalid token '%s'\n", yytext); }

%%