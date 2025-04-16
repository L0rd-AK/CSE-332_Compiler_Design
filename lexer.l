%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap
%option yylineno

/* Define exclusive start conditions for comments */
%x SINGLE_COMMENT
%x MULTI_COMMENT

%%

"mytype"    { return MYTYPE; }
"show"      { return SHOW; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }

"=="        { return EQ; }
"!="        { return NEQ; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LTE; }
">="        { return GTE; }

"//"        { BEGIN(SINGLE_COMMENT); } /* Single line comment start */
<SINGLE_COMMENT>\n { BEGIN(INITIAL); } /* Return to normal mode at end of line */
<SINGLE_COMMENT>.  { /* Ignore everything in single-line comment */ }

"/*"        { BEGIN(MULTI_COMMENT); } /* Multi-line comment start */
<MULTI_COMMENT>"*/" { BEGIN(INITIAL); } /* Multi-line comment end */
<MULTI_COMMENT>\n   { /* Ignore newlines in multi-line comments */ }
<MULTI_COMMENT>.    { /* Ignore everything in multi-line comments */ }

[a-zA-Z]+   { yylval.str = strdup(yytext); return ID; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
";"         { return ';'; }
"="         { return '='; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
[ \t\n]     ; /* Ignore whitespace */
.           { fprintf(stderr, "Lex error: Invalid token '%s' at line %d\n", yytext, yylineno); }

%%