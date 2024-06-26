@echo off
set str=%1
bison --yacc -dv %str%.y
flex %str%.l
gcc -o %str% y.tab.c lex.yy.c