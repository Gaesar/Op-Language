typedef union{
  int inum;
  char* id;
} YYSTYPE;
#define	FIN	257
#define	ASS	258
#define	GT	259
#define	LT	260
#define	EQ	261
#define	GQ	262
#define	LQ	263
#define	ADD	264
#define	SUB	265
#define	MUL	266
#define	DIV	267
#define	LB	268
#define	RB	269
#define	READ	270
#define	WRITE	271
#define	IF	272
#define	THEN	273
#define	END	274
#define	ELSE	275
#define	REPEAT	276
#define	UNTIL	277
#define	NUM	278
#define	IDENTIFIER	279


extern YYSTYPE yylval;
