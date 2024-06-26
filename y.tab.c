
/*  A Bison parser, made from op.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "op.y"

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

#line 23 "op.y"
typedef union{
  int inum;
  char* id;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		61
#define	YYFLAG		-32768
#define	YYNTBASE	26

#define YYTRANSLATE(x) ((unsigned)(x) <= 279 ? yytranslate[x] : 41)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     6,     9,    11,    13,    15,    17,    19,    25,
    33,    38,    42,    45,    48,    52,    56,    60,    64,    68,
    70,    74,    78,    80,    84,    88,    90,    92,    96,    98,
   100,   102
};

static const short yyrhs[] = {    27,
     0,    27,    28,     3,     0,    28,     3,     0,    29,     0,
    30,     0,    31,     0,    32,     0,    33,     0,    39,    34,
    19,    27,    20,     0,    39,    34,    19,    27,    21,    27,
    20,     0,    40,    27,    23,    34,     0,    38,     4,    34,
     0,    16,    38,     0,    17,    38,     0,    35,     6,    35,
     0,    35,     5,    35,     0,    35,     7,    35,     0,    35,
     8,    35,     0,    35,     9,    35,     0,    35,     0,    35,
    10,    36,     0,    35,    11,    36,     0,    36,     0,    36,
    12,    37,     0,    36,    13,    37,     0,    37,     0,    38,
     0,    14,    34,    15,     0,    24,     0,    25,     0,    18,
     0,    22,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    41,    43,    44,    50,    51,    52,    53,    54,    56,    57,
    59,   153,   167,   172,   179,   198,   218,   237,   258,   277,
   279,   285,   291,   293,   299,   305,   306,   308,   309,   311,
   318,   320
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","FIN","ASS",
"GT","LT","EQ","GQ","LQ","ADD","SUB","MUL","DIV","LB","RB","READ","WRITE","IF",
"THEN","END","ELSE","REPEAT","UNTIL","NUM","IDENTIFIER","program","stmt_sequence",
"statement","if_stmt","repeat_stmt","assign_stmt","read_stmt","write_stmt","exp",
"simple_exp","term","factor","var_name","if_flag","re_flag", NULL
};
#endif

static const short yyr1[] = {     0,
    26,    27,    27,    28,    28,    28,    28,    28,    29,    29,
    30,    31,    32,    33,    34,    34,    34,    34,    34,    34,
    35,    35,    35,    36,    36,    36,    36,    37,    37,    38,
    39,    40
};

static const short yyr2[] = {     0,
     1,     3,     2,     1,     1,     1,     1,     1,     5,     7,
     4,     3,     2,     2,     3,     3,     3,     3,     3,     1,
     3,     3,     1,     3,     3,     1,     1,     3,     1,     1,
     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    31,    32,    30,     1,     0,     4,     5,     6,
     7,     8,     0,     0,     0,    13,    14,     0,     3,     0,
     0,    29,     0,    20,    23,    26,    27,     0,     2,    12,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    28,     0,    16,    15,    17,    18,    19,    21,
    22,    24,    25,    11,     9,     0,     0,    10,     0,     0,
     0
};

static const short yydefgoto[] = {    59,
     6,     7,     8,     9,    10,    11,    12,    23,    24,    25,
    26,    27,    14,    15
};

static const short yypact[] = {    52,
   -20,   -20,-32768,-32768,-32768,    52,    15,-32768,-32768,-32768,
-32768,-32768,    22,    -5,    52,-32768,-32768,    24,-32768,    -5,
    -5,-32768,    11,    73,     1,-32768,-32768,    30,-32768,-32768,
    16,    52,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -2,
    -2,    -5,-32768,    17,     6,     6,     6,     6,     6,     1,
     1,-32768,-32768,-32768,-32768,    52,    42,-32768,    36,    40,
-32768
};

static const short yypgoto[] = {-32768,
   -11,    -3,-32768,-32768,-32768,-32768,-32768,   -13,    53,   -28,
   -17,     0,-32768,-32768
};


#define	YYLAST		90


static const short yytable[] = {    13,
    16,    17,    18,    28,     5,    13,    30,    31,    21,    50,
    51,    21,    40,    41,    13,    38,    39,    19,    22,     5,
    44,    22,    52,    53,    18,    20,    29,    13,    54,    32,
    43,    13,     1,     2,     3,    60,    55,    56,     4,    61,
    18,     5,     0,    13,    57,     1,     2,     3,     0,     0,
     0,     4,    42,    18,     5,    13,    13,     1,     2,     3,
     0,    58,     0,     4,     0,     0,     5,     1,     2,     3,
     0,     0,     0,     4,     0,     0,     5,    33,    34,    35,
    36,    37,    38,    39,     0,    45,    46,    47,    48,    49
};

static const short yycheck[] = {     0,
     1,     2,     6,    15,    25,     6,    20,    21,    14,    38,
    39,    14,    12,    13,    15,    10,    11,     3,    24,    25,
    32,    24,    40,    41,    28,     4,     3,    28,    42,    19,
    15,    32,    16,    17,    18,     0,    20,    21,    22,     0,
    44,    25,    -1,    44,    56,    16,    17,    18,    -1,    -1,
    -1,    22,    23,    57,    25,    56,    57,    16,    17,    18,
    -1,    20,    -1,    22,    -1,    -1,    25,    16,    17,    18,
    -1,    -1,    -1,    22,    -1,    -1,    25,     5,     6,     7,
     8,     9,    10,    11,    -1,    33,    34,    35,    36,    37
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 44 "op.y"
{
			if(!isEmpty(if_flag)) {
				pop(if_exp);
			}
		;
    break;}
case 10:
#line 57 "op.y"
{if(!isEmpty(if_flag)){pop(if_flag);};
    break;}
case 11:
#line 59 "op.y"
{
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
	;
    break;}
case 12:
#line 153 "op.y"
{
			if(isEmpty(if_flag)|| peek(if_exp)){
				insert(map, yyvsp[-2].id, (void*)yyvsp[0].inum);
			}
			if(!isEmpty(repeat_flag)) {
				char* op = popStringStack(op_num);
				char* num2 = popStringStack(op_num);
				char* num1 = popStringStack(op_num);
				char* num3 = popStringStack(op_num);
				Quater* quater = createQuater(op, (void*)num1, (void*)num2, (void*)num3);
				enqueue(que, quater);
			} 
		;
    break;}
case 13:
#line 167 "op.y"
{
			int v = read();
			insert(map, yyvsp[0].id, (void*)v);
		;
    break;}
case 14:
#line 172 "op.y"
{
			int* value = (int*)get(map, yyvsp[0].id);
			if(isEmpty(if_flag) || peek(if_exp)){
				printf("%s = %d\n", yyvsp[0].id, value);
			}
		;
    break;}
case 15:
#line 179 "op.y"
{
			yyval.inum=yyvsp[-2].inum<yyvsp[0].inum;
			if(!isEmpty(if_flag)){ 
				if(yyvsp[-2].inum<yyvsp[0].inum){
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
		;
    break;}
case 16:
#line 198 "op.y"
{
			yyval.inum=yyvsp[-2].inum>yyvsp[0].inum;
			if(!isEmpty(if_flag)){ 
				if(yyvsp[-2].inum>yyvsp[0].inum){
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
									
	;
    break;}
case 17:
#line 218 "op.y"
{
			yyval.inum=yyvsp[-2].inum==yyvsp[0].inum;
			if(!isEmpty(if_flag)){ 
				if(yyvsp[-2].inum==yyvsp[0].inum){
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
		;
    break;}
case 18:
#line 237 "op.y"
{
			yyval.inum=yyvsp[-2].inum>=yyvsp[0].inum;
			if(!isEmpty(if_flag)){ 
				if(yyvsp[-2].inum>=yyvsp[0].inum){
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


			;
    break;}
case 19:
#line 258 "op.y"
{
			yyval.inum=yyvsp[-2].inum<=yyvsp[0].inum;
			if(!isEmpty(if_flag)){ 
				if(yyvsp[-2].inum<=yyvsp[0].inum){
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
		;
    break;}
case 20:
#line 277 "op.y"
{yyval.inum=yyvsp[0].inum;
    break;}
case 21:
#line 279 "op.y"
{
				yyval.inum=yyvsp[-2].inum+yyvsp[0].inum;
				if(!isEmpty(repeat_flag)) {
					pushStringStack(op_num, "ADD");
				}
			;
    break;}
case 22:
#line 285 "op.y"
{
				yyval.inum=yyvsp[-2].inum-yyvsp[0].inum;
				if(!isEmpty(repeat_flag)) {
					pushStringStack(op_num, "SUB");
				}
			;
    break;}
case 23:
#line 291 "op.y"
{yyval.inum=yyvsp[0].inum;
    break;}
case 24:
#line 293 "op.y"
{
			yyval.inum=yyvsp[-2].inum*yyvsp[0].inum;
			if(!isEmpty(repeat_flag)) {
				pushStringStack(op_num, "MUL");
			}
		;
    break;}
case 25:
#line 299 "op.y"
{
			yyval.inum=yyvsp[-2].inum/yyvsp[0].inum;
			if(!isEmpty(repeat_flag)) {
				pushStringStack(op_num, "DIV");
			}
		;
    break;}
case 26:
#line 305 "op.y"
{yyval.inum=yyvsp[0].inum;
    break;}
case 27:
#line 306 "op.y"
{int* value = (int*)get(map, yyvsp[0].id); yyval.inum = (int)value;;
    break;}
case 28:
#line 308 "op.y"
{yyval.inum=yyvsp[-1].inum;
    break;}
case 29:
#line 309 "op.y"
{yyval.inum=yyvsp[0].inum;
    break;}
case 30:
#line 311 "op.y"
{
		yyval.id=yyvsp[0].id;
		if(!isEmpty(repeat_flag)) {
			pushStringStack(op_num, yyvsp[0].id);
		}	
	;
    break;}
case 31:
#line 318 "op.y"
{push(if_flag, 1);;
    break;}
case 32:
#line 320 "op.y"
{push(repeat_flag, 1);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 323 "op.y"

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
