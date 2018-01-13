
/*  A Bison parser, made from skLang.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	L_CHARACTER	257
#define	L_INTEGER	258
#define	L_FLOAT	259
#define	L_ID	260
#define	L_STRING	261
#define	L_RETURN	262
#define	L_OR	263
#define	L_AND	264
#define	L_NOT	265
#define	L_IF	266
#define	L_ELSE	267
#define	L_WHILE	268
#define	L_GT	269
#define	L_LT	270
#define	L_SWITCH	271
#define	L_DEFAULT	272
#define	L_CASE	273
#define	UNARY	274

#line 4 "skLang.y"

#include "skParser.h"

#define YYPARSE_PARAM parser
#define YYINTERP ((skParser*)YYPARSE_PARAM)
#define YYLEX_PARAM parser


#define SAVE(t) YYINTERP->addParseNode(t);
#define SETTOPNODE(t) YYINTERP->setTopNode(t);

//#define _DEBUGPARSER
#ifdef _DEBUGPARSER
#include <stdio.h>
#define DB(t) printf("%s\n",t);
#define DBN(t,n) printf("%s - %s\n",t,(const char *)n);
#else
#define DB(t) 
#define DBN(t,n) 
#endif

#line 25 "skLang.y"
typedef union{
  char		character; 
  int		integer; 
  float		floating;
  skStatListNode * statListNode;
  skStatNode * statNode;
  skExprListNode * exprListNode;
  skExprNode * exprNode;
  skCaseListNode * caseListNode;
  skCaseNode * caseNode;
  skIdListNode * idListNode;
  skIdNode * idNode;
  skString * string;
  skMethodDefNode * methodDef;
} YYSTYPE;
#line 41 "skLang.y"

int yylex(YYSTYPE * lvalp, void* context);
void real_yyerror(char * msg, void* context);
#define yyerror(x) real_yyerror(x, YYPARSE_PARAM)
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		128
#define	YYFLAG		-32768
#define	YYNTBASE	39

#define YYTRANSLATE(x) ((unsigned)(x) <= 274 ? yytranslate[x] : 54)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    29,     2,    22,     2,    27,     2,     2,    31,
    32,    26,    20,    33,    21,    23,    25,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    28,    36,     2,
    24,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    37,     2,    38,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    34,     2,    35,     2,     2,     2,     2,     2,
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
    17,    18,    19,    30
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     6,    11,    13,    17,    19,    22,    23,    25,
    27,    31,    32,    34,    36,    39,    43,    49,    57,    63,
    71,    81,    85,    90,    97,   100,   102,   107,   111,   113,
   118,   122,   124,   129,   134,   142,   144,   148,   152,   154,
   158,   160,   162,   164,   166,   169,   173,   177,   181,   185,
   189,   193,   198,   202,   206,   210,   214,   217,   221
};

static const short yyrhs[] = {    41,
     0,    31,    32,    52,     0,    31,    40,    32,    52,     0,
     6,     0,    40,    33,     6,     0,    47,     0,    41,    47,
     0,     0,    43,     0,    53,     0,    42,    33,    53,     0,
     0,    45,     0,    46,     0,    44,    46,     0,    19,    53,
    52,     0,    12,    31,    53,    32,    52,     0,    12,    31,
    53,    32,    52,    13,    52,     0,    14,    31,    53,    32,
    52,     0,    17,    31,    53,    32,    34,    44,    35,     0,
    17,    31,    53,    32,    34,    44,    18,    52,    35,     0,
     8,    53,    36,     0,    49,    24,    53,    36,     0,    49,
    28,     6,    24,    53,    36,     0,    48,    36,     0,    36,
     0,     6,    31,    42,    32,     0,    50,    23,    48,     0,
     6,     0,     6,    37,    53,    38,     0,    50,    23,    49,
     0,     6,     0,     6,    31,    42,    32,     0,     6,    37,
    53,    38,     0,     6,    31,    42,    32,    37,    53,    38,
     0,    50,     0,    50,    23,    51,     0,    34,    41,    35,
     0,    51,     0,    51,    28,     6,     0,     7,     0,     3,
     0,     4,     0,     5,     0,    11,    53,     0,    53,    10,
    53,     0,    53,     9,    53,     0,    53,    21,    53,     0,
    53,    16,    53,     0,    53,    15,    53,     0,    53,    24,
    53,     0,    53,    29,    24,    53,     0,    53,    20,    53,
     0,    53,    25,    53,     0,    53,    26,    53,     0,    53,
    27,    53,     0,    21,    53,     0,    53,    22,    53,     0,
    31,    53,    32,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    67,    68,    69,    72,    73,    75,    76,    78,    79,    81,
    82,    84,    85,    87,    88,    90,    91,    93,    95,    97,
    99,   101,   103,   104,   105,   106,   108,   109,   112,   113,
   114,   116,   117,   118,   119,   121,   122,   126,   128,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","L_CHARACTER",
"L_INTEGER","L_FLOAT","L_ID","L_STRING","L_RETURN","L_OR","L_AND","L_NOT","L_IF",
"L_ELSE","L_WHILE","L_GT","L_LT","L_SWITCH","L_DEFAULT","L_CASE","'+'","'-'",
"'#'","'.'","'='","'/'","'*'","'%'","':'","'!'","UNARY","'('","')'","','","'{'",
"'}'","';'","'['","']'","method_defn","param_list","stat_list","expr_list","nonnull_expr_list",
"case_list","nonnull_case_list","case_stat","stat","id_list_fn","id_list_id",
"id_or_method","id_list","compound_stat","expr", NULL
};
#endif

static const short yyr1[] = {     0,
    39,    39,    39,    40,    40,    41,    41,    42,    42,    43,
    43,    44,    44,    45,    45,    46,    47,    47,    47,    47,
    47,    47,    47,    47,    47,    47,    48,    48,    49,    49,
    49,    50,    50,    50,    50,    51,    51,    52,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53
};

static const short yyr2[] = {     0,
     1,     3,     4,     1,     3,     1,     2,     0,     1,     1,
     3,     0,     1,     1,     2,     3,     5,     7,     5,     7,
     9,     3,     4,     6,     2,     1,     4,     3,     1,     4,
     3,     1,     4,     4,     7,     1,     3,     3,     1,     3,
     1,     1,     1,     1,     2,     3,     3,     3,     3,     3,
     3,     4,     3,     3,     3,     3,     2,     3,     3
};

static const short yydefact[] = {     0,
    29,     0,     0,     0,     0,     0,    26,     1,     6,     0,
     0,     0,     8,     0,    42,    43,    44,    32,    41,     0,
     0,     0,    36,    39,     0,     0,     0,     0,     4,     0,
     0,     7,    25,     0,     0,     0,     0,     9,    10,     0,
     8,     0,    45,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
     0,     0,     0,     0,     2,     0,     0,     0,     0,    28,
    31,    27,     0,    30,     0,     0,    59,    37,    40,    47,
    46,    50,    49,    53,    48,    58,    51,    54,    55,    56,
     0,     0,     0,     0,     0,     3,     5,    23,     0,     0,
    11,    33,    34,    52,    17,    19,    12,    38,     0,     0,
     0,     0,     0,    13,    14,    24,    35,    18,     0,     0,
    20,    15,    16,     0,    21,     0,     0,     0
};

static const short yydefgoto[] = {   126,
    31,     8,    37,    38,   113,   114,   115,     9,    10,    11,
    23,    24,    65,    39
};

static const short yypact[] = {    -1,
     8,   161,   -25,   -23,   -17,    -4,-32768,    68,-32768,   -19,
    33,     0,   161,   161,-32768,-32768,-32768,   -27,-32768,   161,
   161,   161,     4,     5,   164,   161,   161,   161,-32768,     2,
    26,-32768,-32768,   161,    28,    38,    30,-32768,   335,    91,
   161,   161,-32768,-32768,   251,    61,    67,   161,   161,   161,
   161,   161,   161,   161,   161,   161,   161,   161,    55,-32768,
   272,   293,   314,    68,-32768,     2,    75,   186,    59,-32768,
-32768,     6,   161,    63,    45,   112,-32768,-32768,-32768,   345,
   345,   345,   345,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   161,     2,     2,    50,    58,-32768,-32768,-32768,   161,   161,
   335,    51,-32768,-32768,    74,-32768,    72,-32768,   208,   133,
     2,   161,     3,-32768,-32768,-32768,-32768,-32768,   230,     2,
-32768,-32768,-32768,    57,-32768,    95,    99,-32768
};

static const short yypgoto[] = {-32768,
-32768,    39,    64,-32768,-32768,-32768,   -11,    -5,    73,    78,
     1,    62,   -51,    -2
};


#define	YYLAST		374


static const short yytable[] = {    25,
    12,    29,    32,    41,     1,    26,     2,    27,    12,    42,
     3,    40,     4,    28,    96,     5,    33,    43,    44,    45,
   120,   112,    36,    61,    62,    63,    46,    30,   -33,     6,
   -32,    68,    47,    69,     7,    64,    12,   121,    13,    76,
   105,   106,   100,     1,    14,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    34,    66,    67,   118,
    35,    72,    73,     1,    12,     2,    18,   123,   124,     3,
   101,     4,    79,     1,     5,     2,   102,    73,    91,     3,
    97,     4,    99,   107,     5,   -34,   111,   100,   104,    32,
   112,   125,   108,     7,   127,    12,   109,   110,   128,    48,
    49,   122,    95,     7,    75,    50,    51,    78,    70,   119,
    52,    53,    54,    71,    55,    56,    57,    58,     0,    59,
    48,    49,     0,     0,     0,     0,    50,    51,    74,     0,
     0,    52,    53,    54,     0,    55,    56,    57,    58,     0,
    59,    48,    49,     0,     0,     0,     0,    50,    51,   103,
     0,     0,    52,    53,    54,     0,    55,    56,    57,    58,
     0,    59,     0,    15,    16,    17,    18,    19,     0,     0,
   117,    20,    48,    49,     0,     0,     0,     0,    50,    51,
     0,    21,     0,    52,    53,    54,     0,    55,    56,    57,
    58,    22,    59,     0,    48,    49,     0,     0,     0,    60,
    50,    51,     0,     0,     0,    52,    53,    54,     0,    55,
    56,    57,    58,     0,    59,     0,    48,    49,     0,     0,
     0,    98,    50,    51,     0,     0,     0,    52,    53,    54,
     0,    55,    56,    57,    58,     0,    59,     0,    48,    49,
     0,     0,     0,   116,    50,    51,     0,     0,     0,    52,
    53,    54,     0,    55,    56,    57,    58,     0,    59,    48,
    49,     0,     0,    64,     0,    50,    51,     0,     0,     0,
    52,    53,    54,     0,    55,    56,    57,    58,     0,    59,
    48,    49,    77,     0,     0,     0,    50,    51,     0,     0,
     0,    52,    53,    54,     0,    55,    56,    57,    58,     0,
    59,    48,    49,    92,     0,     0,     0,    50,    51,     0,
     0,     0,    52,    53,    54,     0,    55,    56,    57,    58,
     0,    59,    48,    49,    93,     0,     0,     0,    50,    51,
     0,     0,     0,    52,    53,    54,     0,    55,    56,    57,
    58,     0,    59,    48,    49,    94,     0,     0,     0,    50,
    51,     0,     0,     0,    52,    53,    54,     0,    55,    56,
    57,    58,     0,    59,    52,    53,    54,     0,    55,    56,
    57,    58,     0,    59
};

static const short yycheck[] = {     2,
     0,     6,     8,    31,     6,    31,     8,    31,     8,    37,
    12,    14,    14,    31,    66,    17,    36,    20,    21,    22,
    18,    19,    23,    26,    27,    28,    23,    32,    23,    31,
    23,    34,    28,     6,    36,    34,    36,    35,    31,    42,
    92,    93,    37,     6,    37,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    24,    32,    33,   111,
    28,    32,    33,     6,    64,     8,     6,   119,   120,    12,
    73,    14,     6,     6,    17,     8,    32,    33,    24,    12,
     6,    14,    24,    34,    17,    23,    13,    37,    91,    95,
    19,    35,    35,    36,     0,    95,    99,   100,     0,     9,
    10,   113,    64,    36,    41,    15,    16,    46,    36,   112,
    20,    21,    22,    36,    24,    25,    26,    27,    -1,    29,
     9,    10,    -1,    -1,    -1,    -1,    15,    16,    38,    -1,
    -1,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
    29,     9,    10,    -1,    -1,    -1,    -1,    15,    16,    38,
    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,    27,
    -1,    29,    -1,     3,     4,     5,     6,     7,    -1,    -1,
    38,    11,     9,    10,    -1,    -1,    -1,    -1,    15,    16,
    -1,    21,    -1,    20,    21,    22,    -1,    24,    25,    26,
    27,    31,    29,    -1,     9,    10,    -1,    -1,    -1,    36,
    15,    16,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
    25,    26,    27,    -1,    29,    -1,     9,    10,    -1,    -1,
    -1,    36,    15,    16,    -1,    -1,    -1,    20,    21,    22,
    -1,    24,    25,    26,    27,    -1,    29,    -1,     9,    10,
    -1,    -1,    -1,    36,    15,    16,    -1,    -1,    -1,    20,
    21,    22,    -1,    24,    25,    26,    27,    -1,    29,     9,
    10,    -1,    -1,    34,    -1,    15,    16,    -1,    -1,    -1,
    20,    21,    22,    -1,    24,    25,    26,    27,    -1,    29,
     9,    10,    32,    -1,    -1,    -1,    15,    16,    -1,    -1,
    -1,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
    29,     9,    10,    32,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,    27,
    -1,    29,     9,    10,    32,    -1,    -1,    -1,    15,    16,
    -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,
    27,    -1,    29,     9,    10,    32,    -1,    -1,    -1,    15,
    16,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,
    26,    27,    -1,    29,    20,    21,    22,    -1,    24,    25,
    26,    27,    -1,    29
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
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

#line 217 "/usr/lib/bison.simple"

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

case 1:
#line 67 "skLang.y"
{ yyval.methodDef=new skMethodDefNode(yyvsp[0].statListNode); SAVE(yyval.methodDef); SETTOPNODE(yyval.methodDef); ;
    break;}
case 2:
#line 68 "skLang.y"
{yyval.methodDef=new skMethodDefNode(0,yyvsp[0].statListNode); SAVE(yyval.methodDef); SETTOPNODE(yyval.methodDef); ;
    break;}
case 3:
#line 69 "skLang.y"
{yyval.methodDef=new skMethodDefNode(yyvsp[-2].idListNode,yyvsp[0].statListNode); SAVE(yyval.methodDef); SETTOPNODE(yyval.methodDef); ;
    break;}
case 4:
#line 72 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); ;
    break;}
case 5:
#line 73 "skLang.y"
{ yyvsp[-2].idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; yyval.idListNode=yyvsp[-2].idListNode; ;
    break;}
case 6:
#line 75 "skLang.y"
{	yyval.statListNode=new skStatListNode(); yyval.statListNode->addStat(yyvsp[0].statNode); SAVE(yyval.statListNode);  ;
    break;}
case 7:
#line 76 "skLang.y"
{	yyvsp[-1].statListNode->addStat(yyvsp[0].statNode); yyval.statListNode=yyvsp[-1].statListNode; ;
    break;}
case 8:
#line 78 "skLang.y"
{ yyval.exprListNode=new skExprListNode(); SAVE(yyval.exprListNode); ;
    break;}
case 9:
#line 79 "skLang.y"
{ yyval.exprListNode=yyvsp[0].exprListNode; ;
    break;}
case 10:
#line 81 "skLang.y"
{ yyval.exprListNode=new skExprListNode();yyval.exprListNode->addExpr(yyvsp[0].exprNode);SAVE(yyval.exprListNode);;
    break;}
case 11:
#line 82 "skLang.y"
{ yyvsp[-2].exprListNode->addExpr(yyvsp[0].exprNode);yyval.exprListNode=yyvsp[-2].exprListNode; ;
    break;}
case 12:
#line 84 "skLang.y"
{ yyval.caseListNode=new skCaseListNode(); SAVE(yyval.caseListNode); ;
    break;}
case 13:
#line 85 "skLang.y"
{ yyval.caseListNode=yyvsp[0].caseListNode; ;
    break;}
case 14:
#line 87 "skLang.y"
{ yyval.caseListNode=new skCaseListNode();yyval.caseListNode->addCase(yyvsp[0].caseNode);SAVE(yyval.caseListNode);;
    break;}
case 15:
#line 88 "skLang.y"
{ yyvsp[-1].caseListNode->addCase(yyvsp[0].caseNode);yyval.caseListNode=yyvsp[-1].caseListNode; ;
    break;}
case 16:
#line 90 "skLang.y"
{ yyval.caseNode=new skCaseNode(yyvsp[-1].exprNode,yyvsp[0].statListNode); SAVE(yyval.caseNode); ;
    break;}
case 17:
#line 92 "skLang.y"
{ 	DB("IF");yyval.statNode=new skIfNode(yyvsp[-2].exprNode,yyvsp[0].statListNode,0); SAVE(yyval.statNode);
    break;}
case 18:
#line 94 "skLang.y"
{ 	DB("IFELSE");yyval.statNode=new skIfNode(yyvsp[-4].exprNode,yyvsp[-2].statListNode,yyvsp[0].statListNode); SAVE(yyval.statNode);
    break;}
case 19:
#line 96 "skLang.y"
{ 	DB("WHILE");yyval.statNode=new skWhileNode(yyvsp[-2].exprNode,yyvsp[0].statListNode); SAVE(yyval.statNode);
    break;}
case 20:
#line 98 "skLang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yyvsp[-4].exprNode,yyvsp[-1].caseListNode,0); SAVE(yyval.statNode);
    break;}
case 21:
#line 100 "skLang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yyvsp[-6].exprNode,yyvsp[-3].caseListNode,yyvsp[-1].statListNode); SAVE(yyval.statNode);
    break;}
case 22:
#line 101 "skLang.y"
{   DBN("RETURN",*yyvsp[-2].string);yyval.statNode=new skReturnNode(yyvsp[-1].exprNode); SAVE(yyval.statNode);
    break;}
case 23:
#line 103 "skLang.y"
{   DB("ASSIGN");yyval.statNode=new skAssignNode(yyvsp[-3].idListNode,0,yyvsp[-1].exprNode); SAVE(yyval.statNode);
    break;}
case 24:
#line 104 "skLang.y"
{ DB("ASSIGN");yyval.statNode=new skAssignNode(yyvsp[-5].idListNode,yyvsp[-3].string,yyvsp[-1].exprNode); SAVE(yyval.statNode); ;
    break;}
case 25:
#line 105 "skLang.y"
{ DB("METHODCALL");yyval.statNode=new skMethodStatNode(yyvsp[-1].idListNode);SAVE(yyval.statNode); ;
    break;}
case 26:
#line 106 "skLang.y"
{	DB("NULL");yyval.statNode=new skStatNode();SAVE(yyval.statNode);
    break;}
case 27:
#line 108 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[-3].string,0,yyvsp[-1].exprListNode)); delete yyvsp[-3].string;SAVE(yyval.idListNode); ;
    break;}
case 28:
#line 109 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 29:
#line 112 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); ;
    break;}
case 30:
#line 113 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprNode,0)); delete yyvsp[-3].string; SAVE(yyval.idListNode); ;
    break;}
case 31:
#line 114 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 32:
#line 116 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[0].string,0,0); delete yyvsp[0].string; SAVE(yyval.idNode); ;
    break;}
case 33:
#line 117 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-3].string,0,yyvsp[-1].exprListNode); delete yyvsp[-3].string; SAVE(yyval.idNode); ;
    break;}
case 34:
#line 118 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprNode,0); delete yyvsp[-3].string; SAVE(yyval.idNode); ;
    break;}
case 35:
#line 119 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-6].string,yyvsp[-1].exprNode,yyvsp[-4].exprListNode); delete yyvsp[-6].string; SAVE(yyval.idNode); ;
    break;}
case 36:
#line 121 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(yyvsp[0].idNode); SAVE(yyval.idListNode); ;
    break;}
case 37:
#line 122 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 38:
#line 126 "skLang.y"
{	DB("STATLIST");yyval.statListNode=yyvsp[-1].statListNode; ;
    break;}
case 39:
#line 130 "skLang.y"
{   DB("ID_EXPR");yyval.exprNode=yyvsp[0].idListNode; ;
    break;}
case 40:
#line 131 "skLang.y"
{   DB("ID_EXPR");yyvsp[-2].idListNode->m_Attribute=*yyvsp[0].string;delete yyvsp[0].string;yyval.exprNode=yyvsp[-2].idListNode;;
    break;}
case 41:
#line 132 "skLang.y"
{   DBN("STRING_EXPR",*yyvsp[0].string);yyval.exprNode=new skLiteralNode(yyvsp[0].string); SAVE(yyval.exprNode);
    break;}
case 42:
#line 133 "skLang.y"
{   DB("CHARACTER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].character); SAVE(yyval.exprNode);
    break;}
case 43:
#line 134 "skLang.y"
{   DB("INTEGER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].integer); SAVE(yyval.exprNode);
    break;}
case 44:
#line 135 "skLang.y"
{   DB("FLOAT_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].floating); SAVE(yyval.exprNode);
    break;}
case 45:
#line 136 "skLang.y"
{   DB("NOT_EXPR");yyval.exprNode=new skOpNode(s_Not,yyvsp[0].exprNode,0); SAVE(yyval.exprNode);
    break;}
case 46:
#line 137 "skLang.y"
{   DB("AND_EXPR");yyval.exprNode=new skOpNode(s_And,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 47:
#line 138 "skLang.y"
{   DB("OR_EXPR");yyval.exprNode=new skOpNode(s_Or,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 48:
#line 139 "skLang.y"
{   DB("SUBTRACT_EXPR");yyval.exprNode=new skOpNode(s_Subtract,yyvsp[-2].exprNode,yyvsp[0].exprNode);SAVE(yyval.exprNode);
    break;}
case 49:
#line 140 "skLang.y"
{   DB("LESS_EXPR");yyval.exprNode=new skOpNode(s_Less,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 50:
#line 141 "skLang.y"
{   DB("MORE_EXPR");yyval.exprNode=new skOpNode(s_More,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 51:
#line 142 "skLang.y"
{   DB("EQUALS_EXPR");yyval.exprNode=new skOpNode(s_Equals,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 52:
#line 143 "skLang.y"
{   DB("NOTEQUALS_EXPR");yyval.exprNode=new skOpNode(s_NotEquals,yyvsp[-3].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 53:
#line 144 "skLang.y"
{   DB("PLUS_EXPR");yyval.exprNode=new skOpNode(s_Plus,yyvsp[-2].exprNode,yyvsp[0].exprNode);  SAVE(yyval.exprNode);
    break;}
case 54:
#line 145 "skLang.y"
{   DB("DIVIDE_EXPR");yyval.exprNode=new skOpNode(s_Divide,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 55:
#line 146 "skLang.y"
{   DB("MULT_EXPR");yyval.exprNode=new skOpNode(s_Mult,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 56:
#line 147 "skLang.y"
{   DB("MOD_EXPR");yyval.exprNode=new skOpNode(s_Mod,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 57:
#line 148 "skLang.y"
{   DB("MINUS_EXPR");yyval.exprNode=new skOpNode(s_Minus,yyvsp[0].exprNode,0); SAVE(yyval.exprNode);
    break;}
case 58:
#line 149 "skLang.y"
{   DB("CONCAT_EXPR");yyval.exprNode=new skOpNode(s_Concat,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 59:
#line 150 "skLang.y"
{   DB("SUB_EXPR");yyval.exprNode=yyvsp[-1].exprNode; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/lib/bison.simple"

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
#line 152 "skLang.y"
