#recompile:
bison -d parser.y
flex lexer.l
gcc -o compiler parser.tab.c lex.yy.c main.c

#execute:
compiler.exe input.txt