%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

void yyerror(char *);
int row = 1;
%}
INUM [1-9]+[0-9]*|0
VAR 	[a-zA-Z_$]+[a-zA-Z_$0-9]*
%%
"="							return ASS;
"+"							return ADD;
"-"							return SUB;
"*"							return MUL;
"/"							return DIV;
">"							return GT;
"<"							return LT;
"=="							return EQ;				
">="							return GQ;
"<="							return LQ;
";"							return FIN;
"("							return LB;
")"							return RB;
"if"							return IF;
"then"							return THEN;
"end"							return END;
"else"							return ELSE;
"repeat"						return REPEAT;
"until"							return UNTIL;
"read"							return READ;
"write"							return WRITE;
{INUM}		       sscanf(yytext,"%d",&yylval.inum);return NUM;
{VAR}	{yylval.id = (char*)malloc(sizeof(char) * (strlen(yytext) + 1));
			sscanf(yytext,"%s",yylval.id);return IDENTIFIER;}
\n                          				{row++;}
[ \t]+                     /* ignore whitespace */;
.
%%
