%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hashmap.c"
#include "stack.c"
#include "strstack.c"
#include "quater.c"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;
extern row;
HashMap* map;
Stack* if_flag;
Stack* if_exp;
Stack* repeat_flag;
StringStack* op_num;
Queue* que;
int read();
%}

%union{
  int inum;
  char* id;
}
%token FIN
%token ASS 
%token GT LT EQ GQ LQ
%token ADD SUB 
%token MUL DIV 
%token LB RB 
%token READ WRITE 
%token IF THEN END ELSE REPEAT UNTIL
%token <inum> NUM
%token <id> IDENTIFIER
%type  <inum> factor term simple_exp exp
%type <id> var_name 

%%
program: stmt_sequence
		;
stmt_sequence: stmt_sequence statement FIN  
		| statement FIN {
			if(!isEmpty(if_flag)) {
				pop(if_exp);
			}
		}         
		;
statement: if_stmt
		| repeat_stmt  
		| assign_stmt  
		| read_stmt 	
		| write_stmt
		;
if_stmt: if_flag exp THEN stmt_sequence END
	| if_flag exp THEN stmt_sequence ELSE stmt_sequence END {if(!isEmpty(if_flag)){pop(if_flag);}}
	;
repeat_stmt: re_flag stmt_sequence UNTIL exp {
	int size = getSizeQueue(que);
	while(1){
		for(int i = 0; i < size - 1; i++) {
			Quater* quater = dequeue(que);
			char* op = quater->operation;
			if(strcmp(op, "ADD") == 0) { 
				char* num1 = (char*)quater->num1;
				char* num2 = (char*)quater->num2;
				char* num3 = (char*)quater->num3;
				int value1 = (int)(int* )get(map, num1);
				int value2 = (int)(int* )get(map, num2);
				insert(map, num3, (void *)(value1 + value2));
			}
			else if(strcmp(op, "SUB") == 0) { 
				char* num1 = (char*)quater->num1;
				char* num2 = (char*)quater->num2;
				char* num3 = (char*)quater->num3;
				int value1 = (int)(int* )get(map, num1);
				int value2 = (int)(int* )get(map, num2);
				insert(map, num3, (void *)(value1 - value2));
			}
			else if(strcmp(op, "MUL") == 0) { 
				char* num1 = (char*)quater->num1;
				char* num2 = (char*)quater->num2;
				char* num3 = (char*)quater->num3;
				int value1 = (int)(int* )get(map, num1);
				int value2 = (int)(int* )get(map, num2);
				insert(map, num3, (void *)(value1 * value2));
			}
			else if(strcmp(op, "DIV") == 0) { 
				char* num1 = (char*)quater->num1;
				char* num2 = (char*)quater->num2;
				char* num3 = (char*)quater->num3;
				int value1 = (int)(int* )get(map, num1);
				int value2 = (int)(int* )get(map, num2);
				insert(map, num3, (void *)(value1 / value2));
			}
			enqueue(que, quater);
		}
		Quater* quater = dequeue(que);
		char* op = quater->operation;
		if(strcmp(op, "LT") == 0) {
			char* num1 = (char*)quater->num1;
			char* num2 = (char*)quater->num2;
			int value1 = (int)(int*)get(map, num1);
			int value2 = (int)(int*)get(map, num2);
			if(value1 < value2) {
				break;
			}
		}
		else if(strcmp(op, "GT") == 0) {
			char* num1 = (char*)quater->num1;
			char* num2 = (char*)quater->num2;
			int value1 = (int)(int*)get(map, num1);
			int value2 = (int)(int*)get(map, num2);
			if(value1 > value2) {
				break;
			}
		}
		else if(strcmp(op, "LQ") == 0) {
			char* num1 = (char*)quater->num1;
			char* num2 = (char*)quater->num2;
			int value1 = (int)(int*)get(map, num1);
			int value2 = (int)(int*)get(map, num2);
			if(value1 <= value2) {
				break;
			}
		}
		else if(strcmp(op, "GQ") == 0) {
			char* num1 = (char*)quater->num1;
			char* num2 = (char*)quater->num2;
			int value1 = (int)(int*)get(map, num1);
			int value2 = (int)(int*)get(map, num2);
			if(value1 >= value2) {
				break;
			}
		}
		else if(strcmp(op, "EQ") == 0) {
			char* num1 = (char*)quater->num1;
			char* num2 = (char*)quater->num2;
			int value1 = (int)(int*)get(map, num1);
			int value2 = (int)(int*)get(map, num2);
			if(value1 == value2) {
				break;
			}
		}
		enqueue(que, quater);
	}
		pop(repeat_flag);
		clearQueue(que);
	}
	;

assign_stmt: var_name ASS exp  {
			if(isEmpty(if_flag)|| peek(if_exp)){
				insert(map, $1, (void*)$3);
			}
			if(!isEmpty(repeat_flag)) {
				char* op = popStringStack(op_num);
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				char* num3 = popStringStack(op_num);
				Quater* quater = createQuater(op, (void*)num1, (void*)num2, (void*)num3);
				enqueue(que, quater);
			} 
		}
		;
read_stmt: READ var_name {
			int v = read();
			insert(map, $2, (void*)v);
		}
		;
write_stmt: WRITE var_name {
			int* value = (int*)get(map, $2);
			if(isEmpty(if_flag) || peek(if_exp)){
				printf("%s = %d\n", $2, value);
			}
		}
		;
exp: simple_exp LT simple_exp  {
			$$=$1<$3;
			if(!isEmpty(if_flag)){ 
				if($1<$3){
					push(if_exp, 0);
					push(if_exp, 1);
				}
				else{
					push(if_exp, 1);
					push(if_exp, 0);
				}
			}
			if(!isEmpty(repeat_flag)) {
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				Quater* quater = createQuater("LT", (void*)num1, (void*)num2, NULL);
				enqueue(que, quater);
			}		
		}
	|simple_exp GT simple_exp {
			$$=$1>$3;
			if(!isEmpty(if_flag)){ 
				if($1>$3){
					push(if_exp, 0);
					push(if_exp, 1);
				}
				else{
					push(if_exp, 1);
					push(if_exp, 0);
				}
			}
			if(!isEmpty(repeat_flag)) {
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				Quater* quater = createQuater("GT", (void*)num1, (void*)num2, NULL);
				enqueue(que, quater);
			}  
									
	}
	|simple_exp EQ simple_exp {
			$$=$1==$3;
			if(!isEmpty(if_flag)){ 
				if($1==$3){
					push(if_exp, 0);
					push(if_exp, 1);
				}
				else{
					push(if_exp, 1);
					push(if_exp, 0);
				}
			}
			if(!isEmpty(repeat_flag)) {
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				Quater* quater = createQuater("EQ", (void*)num1, (void*)num2, NULL);
				enqueue(que, quater);
			}
		}
	|simple_exp GQ simple_exp {
			$$=$1>=$3;
			if(!isEmpty(if_flag)){ 
				if($1>=$3){
					push(if_exp, 0);
					push(if_exp, 1);
				}
				else{
					push(if_exp, 1);
					push(if_exp, 0);
				}
			}
			if(!isEmpty(repeat_flag)) {
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				Quater* quater = createQuater("GQ", (void*)num1, (void*)num2, NULL);
				enqueue(que, quater);
			}


			}
	|simple_exp LQ simple_exp {
			$$=$1<=$3;
			if(!isEmpty(if_flag)){ 
				if($1<=$3){
					push(if_exp, 0);
					push(if_exp, 1);
				}
				else{
					push(if_exp, 1);
					push(if_exp, 0);
				}
			}
			if(!isEmpty(repeat_flag)) {
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				Quater* quater = createQuater("LQ", (void*)num1, (void*)num2, NULL);
				enqueue(que, quater);
			}
		}
	|simple_exp {$$=$1}
	;
simple_exp:  simple_exp ADD term {
				$$=$1+$3;
				if(!isEmpty(repeat_flag)) {
					pushStringStack(op_num, "ADD");
				}
			}
		| simple_exp SUB term {
				$$=$1-$3;
				if(!isEmpty(repeat_flag)) {
					pushStringStack(op_num, "SUB");
				}
			}
		| term  {$$=$1}
		;
term: term MUL factor  {
			$$=$1*$3;
			if(!isEmpty(repeat_flag)) {
				pushStringStack(op_num, "MUL");
			}
		}
	| term DIV factor {
			$$=$1/$3;
			if(!isEmpty(repeat_flag)) {
				pushStringStack(op_num, "DIV");
			}
		}
	| factor  {$$=$1}
	| var_name {int* value = (int*)get(map, $1); $$ = (int)value;}
	;
factor: LB exp RB {$$=$2}
	| NUM {$$=$1}
	;
var_name: IDENTIFIER {
		$$=$1;
		if(!isEmpty(repeat_flag)) {
			pushStringStack(op_num, $1);
		}	
	}
	;
if_flag: IF {push(if_flag, 1);}
	;
re_flag: REPEAT {push(repeat_flag, 1);}
	;

%%
void yyerror(char *str){
    fprintf(stderr,"error:%s in %d line\n",str, row);
}
int read() {
    int a;
    printf("<< ");
    scanf("%d", &a);
    return a;
}
int yywrap(){
    return 1;
}
int main(int argc, char **argv)
{
  if (argc>1)
  {
    FILE *file;
    file=fopen(argv[1],"r");
    if(file) yyin=file;
  }
  else {
   time_t rawtime;
   struct tm *timeinfo;
   char buffer[80];
   time(&rawtime);
   timeinfo = localtime(&rawtime);
   strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
   printf("Operation 0.0.1  %s\n", buffer);
  }
  map = createHashMap(100);
  if_flag = createStack();
  if_exp = createStack();
  op_num = createStringStack();
  repeat_flag = createStack();
  que = createQueue();
  yyparse();
}
