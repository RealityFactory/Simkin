
/*  A Bison parser, made from sklang.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define YYLSP_NEEDED

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
#define	L_GE	269
#define	L_GT	270
#define	L_LE	271
#define	L_LT	272
#define	L_SWITCH	273
#define	L_DEFAULT	274
#define	L_CASE	275
#define	L_FOR	276
#define	L_EACH	277
#define	L_IN	278
#define	L_TO	279
#define	L_STEP	280
#define	L_NEQ	281
#define	UNARY	282

#line 23 "sklang.y"

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

#line 44 "sklang.y"
typedef union{
  Char		character; 
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
  skParseNode * parseNode;
} YYSTYPE;
#line 61 "sklang.y"

int yylex(YYSTYPE * lvalp,void * yylloc, void* context);
void real_yyerror(Char * msg, void* context);
#define yyerror(x) real_yyerror(x, YYPARSE_PARAM)

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		164
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 282 ? yytranslate[x] : 66)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,    31,     2,    37,    34,     2,    42,
    43,    35,    32,    44,    33,    40,    36,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    38,    47,    29,
    28,    30,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    39,     2,    48,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    45,     2,    46,     2,     2,     2,     2,     2,
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
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    41
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    13,    18,    20,    24,    26,
    29,    30,    32,    34,    38,    39,    41,    43,    46,    50,
    56,    64,    70,    78,    88,    95,   103,   111,   121,   125,
   130,   137,   140,   142,   147,   151,   153,   158,   162,   164,
   169,   174,   182,   184,   188,   192,   194,   198,   200,   202,
   204,   206,   209,   213,   217,   221,   225,   229,   233,   238,
   242,   246,   250,   255,   259,   263,   267,   271,   275,   279,
   282,   286,   290
};

static const short yyrhs[] = {    51,
     0,    50,     0,    28,    65,     0,    53,     0,    42,    43,
    64,     0,    42,    52,    43,    64,     0,     6,     0,    52,
    44,     6,     0,    59,     0,    53,    59,     0,     0,    55,
     0,    65,     0,    54,    44,    65,     0,     0,    57,     0,
    58,     0,    56,    58,     0,    21,    65,    64,     0,    12,
    42,    65,    43,    64,     0,    12,    42,    65,    43,    64,
    13,    64,     0,    14,    42,    65,    43,    64,     0,    19,
    42,    65,    43,    45,    56,    46,     0,    19,    42,    65,
    43,    45,    56,    20,    64,    46,     0,    22,    23,     6,
    24,    65,    64,     0,    22,    23,     6,     6,    24,    65,
    64,     0,    22,     6,    28,    65,    25,    65,    64,     0,
    22,     6,    28,    65,    25,    65,    26,    65,    64,     0,
     8,    65,    47,     0,    61,    28,    65,    47,     0,    61,
    38,     6,    28,    65,    47,     0,    60,    47,     0,    47,
     0,     6,    42,    54,    43,     0,    62,    40,    60,     0,
     6,     0,     6,    39,    65,    48,     0,    62,    40,    61,
     0,     6,     0,     6,    42,    54,    43,     0,     6,    39,
    65,    48,     0,     6,    42,    54,    43,    39,    65,    48,
     0,    62,     0,    62,    40,    63,     0,    45,    53,    46,
     0,    63,     0,    63,    38,     6,     0,     7,     0,     3,
     0,     4,     0,     5,     0,    11,    65,     0,    65,    10,
    65,     0,    65,     9,    65,     0,    65,    33,    65,     0,
    65,    18,    65,     0,    65,    29,    65,     0,    65,    17,
    65,     0,    65,    29,    28,    65,     0,    65,    16,    65,
     0,    65,    30,    65,     0,    65,    15,    65,     0,    65,
    30,    28,    65,     0,    65,    28,    65,     0,    65,    27,
    65,     0,    65,    32,    65,     0,    65,    36,    65,     0,
    65,    35,    65,     0,    65,    37,    65,     0,    33,    65,
     0,    65,    31,    65,     0,    65,    34,    65,     0,    42,
    65,    43,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    98,    99,   101,   104,   105,   106,   109,   110,   112,   113,
   115,   116,   118,   119,   121,   122,   124,   125,   127,   128,
   130,   132,   134,   136,   138,   140,   143,   145,   147,   149,
   150,   151,   152,   154,   155,   158,   159,   160,   162,   163,
   164,   165,   167,   168,   172,   174,   177,   178,   179,   180,
   181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
   201,   202,   203
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","L_CHARACTER",
"L_INTEGER","L_FLOAT","L_ID","L_STRING","L_RETURN","L_OR","L_AND","L_NOT","L_IF",
"L_ELSE","L_WHILE","L_GE","L_GT","L_LE","L_LT","L_SWITCH","L_DEFAULT","L_CASE",
"L_FOR","L_EACH","L_IN","L_TO","L_STEP","L_NEQ","'='","'<'","'>'","'#'","'+'",
"'-'","'&'","'*'","'/'","'%'","':'","'['","'.'","UNARY","'('","')'","','","'{'",
"'}'","';'","']'","start","start_expr","method_defn","param_list","stat_list",
"expr_list","nonnull_expr_list","case_list","nonnull_case_list","case_stat",
"stat","id_list_fn","id_list_id","id_or_method","id_list","compound_stat","expr", NULL
};
#endif

static const short yyr1[] = {     0,
    49,    49,    50,    51,    51,    51,    52,    52,    53,    53,
    54,    54,    55,    55,    56,    56,    57,    57,    58,    59,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    60,    60,    61,    61,    61,    62,    62,
    62,    62,    63,    63,    64,    65,    65,    65,    65,    65,
    65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
    65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
    65,    65,    65
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     3,     4,     1,     3,     1,     2,
     0,     1,     1,     3,     0,     1,     1,     2,     3,     5,
     7,     5,     7,     9,     6,     7,     7,     9,     3,     4,
     6,     2,     1,     4,     3,     1,     4,     3,     1,     4,
     4,     7,     1,     3,     3,     1,     3,     1,     1,     1,
     1,     2,     3,     3,     3,     3,     3,     3,     4,     3,
     3,     3,     4,     3,     3,     3,     3,     3,     3,     2,
     3,     3,     3
};

static const short yydefact[] = {     0,
    36,     0,     0,     0,     0,     0,     0,     0,    33,     2,
     1,     4,     9,     0,     0,     0,     0,    11,    49,    50,
    51,    39,    48,     0,     0,     0,    43,    46,     0,     0,
     0,     0,     0,     0,     3,     7,     0,     0,    10,    32,
     0,     0,     0,     0,     0,    12,    13,     0,    11,    52,
    70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    29,     0,     0,     0,     0,     0,     0,     5,     0,
     0,     0,     0,    35,    38,    37,    34,     0,     0,     0,
    73,    44,    47,    54,    53,    62,    60,    58,    56,    65,
    64,     0,    57,     0,    61,    71,    66,    55,    72,    68,
    67,    69,     0,     0,     0,     0,     0,     0,     0,     6,
     8,    30,     0,     0,    14,    41,    40,    59,    63,    20,
    22,    15,     0,     0,     0,    45,     0,     0,     0,     0,
     0,    16,    17,     0,     0,    25,    31,    42,    21,     0,
     0,    23,    18,     0,    27,    26,    19,     0,     0,    24,
    28,     0,     0,     0
};

static const short yydefgoto[] = {   162,
    10,    11,    38,    12,    45,    46,   141,   142,   143,    13,
    14,    15,    27,    28,    79,    47
};

static const short yypact[] = {   111,
    38,   268,   -22,   -17,   -15,     3,   268,     0,-32768,-32768,
-32768,    26,-32768,   -29,   -24,    -9,   268,   268,-32768,-32768,
-32768,   -23,-32768,   268,   268,   268,     7,    -1,   287,   268,
   268,   268,    21,    46,   593,-32768,    30,    -8,-32768,-32768,
   268,    79,    92,   132,    27,-32768,   593,   268,   268,-32768,
-32768,   448,    93,    98,   268,   268,   268,   268,   268,   268,
   268,   268,   225,   236,   268,   268,   268,   268,   268,   268,
   268,-32768,   477,   506,   535,   268,    -3,    26,-32768,    30,
    99,   320,    78,-32768,-32768,    67,     2,   268,   161,    40,
-32768,-32768,-32768,   616,   616,   150,   150,   150,   150,   150,
   593,   268,   150,   268,   150,    57,   -25,   -25,   -25,-32768,
-32768,-32768,    30,    30,    65,   564,    88,   268,    89,-32768,
-32768,-32768,   268,   268,   593,-32768,    74,   593,   593,   101,
-32768,    94,   268,   268,   417,-32768,   353,   190,    30,   268,
   -13,-32768,-32768,   386,   417,-32768,-32768,-32768,-32768,   417,
    30,-32768,-32768,   268,-32768,-32768,-32768,    72,   417,-32768,
-32768,   124,   126,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,    49,    80,-32768,-32768,-32768,    -7,   -10,
    85,    97,     1,    84,   -63,    -2
};


#define	YYLAST		653


static const short yytable[] = {    29,
    16,    39,   117,    41,    35,    36,   151,   140,    33,    69,
    70,    71,    16,    42,    44,    48,   120,    40,    49,    30,
   118,    50,    51,    52,    31,    34,    32,    73,    74,    75,
    43,     1,   152,     2,    80,    81,    54,     3,    82,     4,
   124,   -40,    37,    16,     5,    89,    53,     6,    76,   130,
   131,    77,    94,    95,    96,    97,    98,    99,   100,   101,
   103,   105,   106,   107,   108,   109,   110,   111,   112,    87,
    88,   146,     9,   116,    78,   149,    17,   -39,    16,    18,
   155,   156,   127,    88,    83,   125,   157,   158,    66,    67,
    68,    69,    70,    71,     1,   161,     2,     1,    22,   128,
     3,   129,     4,    93,   121,   123,   -41,     5,    39,   132,
     6,   134,   124,   139,   140,   135,     1,   160,     2,    16,
   137,   138,     3,   163,     4,   164,   119,    84,    90,     5,
   144,   145,     6,   153,   136,     9,    92,   150,     7,    85,
    55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
     0,   159,     8,     0,     0,     0,     0,     9,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    55,
    56,     0,     0,     0,     0,    57,    58,    59,    60,    86,
    65,    66,    67,    68,    69,    70,    71,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    55,    56,
     0,     0,     0,     0,    57,    58,    59,    60,   126,     0,
     0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    19,    20,    21,
    22,    23,     0,     0,     0,    24,     0,   148,    19,    20,
    21,    22,    23,     0,     0,     0,    24,     0,     0,     0,
     0,     0,   102,     0,     0,     0,     0,    25,     0,     0,
     0,     0,     0,   104,     0,     0,    26,     0,    25,     0,
    19,    20,    21,    22,    23,     0,     0,    26,    24,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    55,    56,     0,     0,     0,
    25,    57,    58,    59,    60,     0,     0,     0,     0,    26,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,     0,     0,     0,     0,    55,    56,
     0,     0,     0,    72,    57,    58,    59,    60,     0,     0,
     0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
     0,    55,    56,     0,     0,     0,   122,    57,    58,    59,
    60,     0,     0,     0,     0,     0,     0,     0,     0,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     0,     0,     0,     0,    55,    56,     0,     0,     0,   147,
    57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
     0,   154,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,     0,     0,    55,    56,     0,     0,     0,
    78,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,     0,     0,    55,    56,     0,     0,
     0,    78,    57,    58,    59,    60,     0,     0,     0,     0,
     0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    55,    56,     0,     0,     0,
    91,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    55,    56,     0,     0,     0,   113,
    57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
     0,     0,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    55,    56,     0,     0,     0,   114,    57,
    58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
     0,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    55,    56,     0,     0,     0,   115,    57,    58,
    59,    60,     0,     0,     0,     0,     0,     0,   133,     0,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    55,    56,     0,     0,     0,     0,    57,    58,    59,
    60,     0,     0,     0,     0,     0,     0,     0,     0,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
     0,     0,    61,     0,    63,    64,    65,    66,    67,    68,
    69,    70,    71
};

static const short yycheck[] = {     2,
     0,    12,     6,    28,     7,     6,    20,    21,     6,    35,
    36,    37,    12,    38,    17,    39,    80,    47,    42,    42,
    24,    24,    25,    26,    42,    23,    42,    30,    31,    32,
    40,     6,    46,     8,    43,    44,    38,    12,    41,    14,
    39,    40,    43,    43,    19,    48,    40,    22,    28,   113,
   114,     6,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    43,
    44,   135,    47,    76,    45,   139,    39,    40,    78,    42,
   144,   145,    43,    44,     6,    88,   150,   151,    32,    33,
    34,    35,    36,    37,     6,   159,     8,     6,     6,   102,
    12,   104,    14,     6,     6,    28,    40,    19,   119,    45,
    22,    24,    39,    13,    21,   118,     6,    46,     8,   119,
   123,   124,    12,     0,    14,     0,    78,    43,    49,    19,
   133,   134,    22,   141,    46,    47,    53,   140,    28,    43,
     9,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
    -1,   154,    42,    -1,    -1,    -1,    -1,    47,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,     9,
    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    48,
    31,    32,    33,    34,    35,    36,    37,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,     9,    10,
    -1,    -1,    -1,    -1,    15,    16,    17,    18,    48,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,     3,     4,     5,
     6,     7,    -1,    -1,    -1,    11,    -1,    48,     3,     4,
     5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,
    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
    -1,    -1,    -1,    28,    -1,    -1,    42,    -1,    33,    -1,
     3,     4,     5,     6,     7,    -1,    -1,    42,    11,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,
    33,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    42,
    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    -1,    -1,    -1,    -1,     9,    10,
    -1,    -1,    -1,    47,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
    -1,     9,    10,    -1,    -1,    -1,    47,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    47,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    -1,    -1,     9,    10,    -1,    -1,    -1,
    45,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    -1,    -1,     9,    10,    -1,    -1,
    -1,    45,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,     9,    10,    -1,    -1,    -1,
    43,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,     9,    10,    -1,    -1,    -1,    43,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,     9,    10,    -1,    -1,    -1,    43,    15,
    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,     9,    10,    -1,    -1,    -1,    43,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,     9,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
    35,    36,    37
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "../Src/bison.simple"
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
    { yyerror (skSTR("syntax error: cannot back up")); YYERROR; }	\
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
     Char *to;
     Char *from;
     unsigned int count;
{
  register Char *f = from;
  register Char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (Char *to, Char *from, unsigned int count)
{
  register Char *t = to;
  register Char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "../Src/bison.simple"

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
	  yyerror(skSTR("parser stack overflow"));
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
      __yy_memcpy ((Char *)yyss, (Char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((Char *)yyvs, (Char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((Char *)yyls, (Char *)yyls1,
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
#line 98 "sklang.y"
{ yyval.parseNode=yyvsp[0].parseNode; SETTOPNODE(yyvsp[0].parseNode);;
    break;}
case 2:
#line 99 "sklang.y"
{ yyval.parseNode=yyvsp[0].parseNode; SETTOPNODE(yyvsp[0].parseNode);;
    break;}
case 3:
#line 101 "sklang.y"
{yyval.parseNode=yyvsp[0].exprNode; ;
    break;}
case 4:
#line 104 "sklang.y"
{ yyval.parseNode=new skMethodDefNode(yylsp[0].first_line,yyvsp[0].statListNode); SAVE(yyval.parseNode);  ;
    break;}
case 5:
#line 105 "sklang.y"
{yyval.parseNode=new skMethodDefNode(yylsp[-2].first_line,0,yyvsp[0].statListNode); SAVE(yyval.parseNode);  ;
    break;}
case 6:
#line 106 "sklang.y"
{yyval.parseNode=new skMethodDefNode(yylsp[-3].first_line,yyvsp[-2].idListNode,yyvsp[0].statListNode); SAVE(yyval.parseNode);  ;
    break;}
case 7:
#line 109 "sklang.y"
{ yyval.idListNode=new skIdListNode(yylsp[0].first_line); yyval.idListNode->addId(new skIdNode(yylsp[0].first_line,*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); ;
    break;}
case 8:
#line 110 "sklang.y"
{ yyvsp[-2].idListNode->addId(new skIdNode(yylsp[-2].first_line,*yyvsp[0].string,0,0)); delete yyvsp[0].string; yyval.idListNode=yyvsp[-2].idListNode; ;
    break;}
case 9:
#line 112 "sklang.y"
{	yyval.statListNode=new skStatListNode(yylsp[0].first_line); yyval.statListNode->addStat(yyvsp[0].statNode); SAVE(yyval.statListNode);  ;
    break;}
case 10:
#line 113 "sklang.y"
{	yyvsp[-1].statListNode->addStat(yyvsp[0].statNode); yyval.statListNode=yyvsp[-1].statListNode; ;
    break;}
case 11:
#line 115 "sklang.y"
{ yyval.exprListNode=new skExprListNode(yylsp[1].first_line); SAVE(yyval.exprListNode); ;
    break;}
case 12:
#line 116 "sklang.y"
{ yyval.exprListNode=yyvsp[0].exprListNode; ;
    break;}
case 13:
#line 118 "sklang.y"
{ yyval.exprListNode=new skExprListNode(yylsp[0].first_line);yyval.exprListNode->addExpr(yyvsp[0].exprNode);SAVE(yyval.exprListNode);;
    break;}
case 14:
#line 119 "sklang.y"
{ yyvsp[-2].exprListNode->addExpr(yyvsp[0].exprNode);yyval.exprListNode=yyvsp[-2].exprListNode; ;
    break;}
case 15:
#line 121 "sklang.y"
{ yyval.caseListNode=new skCaseListNode(yylsp[1].first_line); SAVE(yyval.caseListNode); ;
    break;}
case 16:
#line 122 "sklang.y"
{ yyval.caseListNode=yyvsp[0].caseListNode; ;
    break;}
case 17:
#line 124 "sklang.y"
{ yyval.caseListNode=new skCaseListNode(yylsp[0].first_line);yyval.caseListNode->addCase(yyvsp[0].caseNode);SAVE(yyval.caseListNode);;
    break;}
case 18:
#line 125 "sklang.y"
{ yyvsp[-1].caseListNode->addCase(yyvsp[0].caseNode);yyval.caseListNode=yyvsp[-1].caseListNode; ;
    break;}
case 19:
#line 127 "sklang.y"
{ yyval.caseNode=new skCaseNode(yylsp[-2].first_line,yyvsp[-1].exprNode,yyvsp[0].statListNode); SAVE(yyval.caseNode); ;
    break;}
case 20:
#line 129 "sklang.y"
{ 	DB("IF");yyval.statNode=new skIfNode(yylsp[-4].first_line,yyvsp[-2].exprNode,yyvsp[0].statListNode,0); SAVE(yyval.statNode);
    break;}
case 21:
#line 131 "sklang.y"
{ 	DB("IFELSE");yyval.statNode=new skIfNode(yylsp[-6].first_line,yyvsp[-4].exprNode,yyvsp[-2].statListNode,yyvsp[0].statListNode); SAVE(yyval.statNode);
    break;}
case 22:
#line 133 "sklang.y"
{ 	DB("WHILE");yyval.statNode=new skWhileNode(yylsp[-4].first_line,yyvsp[-2].exprNode,yyvsp[0].statListNode); SAVE(yyval.statNode);
    break;}
case 23:
#line 135 "sklang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yylsp[-6].first_line,yyvsp[-4].exprNode,yyvsp[-1].caseListNode,0); SAVE(yyval.statNode);
    break;}
case 24:
#line 137 "sklang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yylsp[-8].first_line,yyvsp[-6].exprNode,yyvsp[-3].caseListNode,yyvsp[-1].statListNode); SAVE(yyval.statNode);
    break;}
case 25:
#line 139 "sklang.y"
{ 	DB("FOREACH");yyval.statNode=new skForEachNode(yylsp[-5].first_line,*yyvsp[-3].string,yyvsp[-1].exprNode,yyvsp[0].statListNode); delete yyvsp[-3].string;SAVE(yyval.statNode);
    break;}
case 26:
#line 141 "sklang.y"
{ 	DB("FOREACH_QUALIFIED");yyval.statNode=new skForEachNode(yylsp[-6].first_line,*yyvsp[-4].string,*yyvsp[-3].string,yyvsp[-1].exprNode,yyvsp[0].statListNode); delete yyvsp[-4].string;delete yyvsp[-3].string;SAVE(yyval.statNode);
    break;}
case 27:
#line 144 "sklang.y"
{ 	DB("FOR");yyval.statNode=new skForNode(yylsp[-6].first_line,*yyvsp[-5].string,yyvsp[-3].exprNode,yyvsp[-1].exprNode,yyvsp[0].statListNode); delete yyvsp[-5].string;SAVE(yyval.statNode);
    break;}
case 28:
#line 146 "sklang.y"
{ 	DB("FOR_STEP");yyval.statNode=new skForNode(yylsp[-8].first_line,*yyvsp[-7].string,yyvsp[-5].exprNode,yyvsp[-3].exprNode,yyvsp[-1].exprNode,yyvsp[0].statListNode); delete yyvsp[-7].string;SAVE(yyval.statNode);
    break;}
case 29:
#line 147 "sklang.y"
{   DBN("RETURN",*yyvsp[-2].string);yyval.statNode=new skReturnNode(yylsp[-2].first_line,yyvsp[-1].exprNode); SAVE(yyval.statNode);
    break;}
case 30:
#line 149 "sklang.y"
{   DB("ASSIGN");yyval.statNode=new skAssignNode(yylsp[-3].first_line,yyvsp[-3].idListNode,0,yyvsp[-1].exprNode); SAVE(yyval.statNode);
    break;}
case 31:
#line 150 "sklang.y"
{ DB("ASSIGN");yyval.statNode=new skAssignNode(yylsp[-5].first_line,yyvsp[-5].idListNode,yyvsp[-3].string,yyvsp[-1].exprNode); SAVE(yyval.statNode); ;
    break;}
case 32:
#line 151 "sklang.y"
{ DB("METHODCALL");yyval.statNode=new skMethodStatNode(yylsp[-1].first_line,yyvsp[-1].idListNode);SAVE(yyval.statNode); ;
    break;}
case 33:
#line 152 "sklang.y"
{	DB("NULL");yyval.statNode=new skStatNode(yylsp[0].first_line);SAVE(yyval.statNode);
    break;}
case 34:
#line 154 "sklang.y"
{ yyval.idListNode=new skIdListNode(yylsp[-3].first_line); yyval.idListNode->addId(new skIdNode(yylsp[-3].first_line,*yyvsp[-3].string,0,yyvsp[-1].exprListNode)); delete yyvsp[-3].string;SAVE(yyval.idListNode); ;
    break;}
case 35:
#line 155 "sklang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 36:
#line 158 "sklang.y"
{ yyval.idListNode=new skIdListNode(yylsp[0].first_line); yyval.idListNode->addId(new skIdNode(yylsp[0].first_line,*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); ;
    break;}
case 37:
#line 159 "sklang.y"
{ yyval.idListNode=new skIdListNode(yylsp[-3].first_line); yyval.idListNode->addId(new skIdNode(yylsp[-3].first_line,*yyvsp[-3].string,yyvsp[-1].exprNode,0)); delete yyvsp[-3].string; SAVE(yyval.idListNode); ;
    break;}
case 38:
#line 160 "sklang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 39:
#line 162 "sklang.y"
{ yyval.idNode=new skIdNode(yylsp[0].first_line,*yyvsp[0].string,0,0); delete yyvsp[0].string; SAVE(yyval.idNode); ;
    break;}
case 40:
#line 163 "sklang.y"
{ yyval.idNode=new skIdNode(yylsp[-3].first_line,*yyvsp[-3].string,0,yyvsp[-1].exprListNode); delete yyvsp[-3].string; SAVE(yyval.idNode); ;
    break;}
case 41:
#line 164 "sklang.y"
{ yyval.idNode=new skIdNode(yylsp[-3].first_line,*yyvsp[-3].string,yyvsp[-1].exprNode,0); delete yyvsp[-3].string; SAVE(yyval.idNode); ;
    break;}
case 42:
#line 165 "sklang.y"
{ yyval.idNode=new skIdNode(yylsp[-6].first_line,*yyvsp[-6].string,yyvsp[-1].exprNode,yyvsp[-4].exprListNode); delete yyvsp[-6].string; SAVE(yyval.idNode); ;
    break;}
case 43:
#line 167 "sklang.y"
{ yyval.idListNode=new skIdListNode(yylsp[0].first_line); yyval.idListNode->addId(yyvsp[0].idNode); SAVE(yyval.idListNode); ;
    break;}
case 44:
#line 168 "sklang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; ;
    break;}
case 45:
#line 172 "sklang.y"
{	DB("STATLIST");yyval.statListNode=yyvsp[-1].statListNode; ;
    break;}
case 46:
#line 176 "sklang.y"
{   DB("ID_EXPR");yyval.exprNode=yyvsp[0].idListNode; ;
    break;}
case 47:
#line 177 "sklang.y"
{   DB("ID_EXPR");yyvsp[-2].idListNode->m_Attribute=*yyvsp[0].string;delete yyvsp[0].string;yyval.exprNode=yyvsp[-2].idListNode;;
    break;}
case 48:
#line 178 "sklang.y"
{   DBN("STRING_EXPR",*yyvsp[0].string);yyval.exprNode=new skLiteralNode(yylsp[0].first_line,yyvsp[0].string); SAVE(yyval.exprNode);
    break;}
case 49:
#line 179 "sklang.y"
{   DB("CHARACTER_EXPR");yyval.exprNode=new skLiteralNode(yylsp[0].first_line,(Char)yyvsp[0].character); SAVE(yyval.exprNode);
    break;}
case 50:
#line 180 "sklang.y"
{   DB("INTEGER_EXPR");yyval.exprNode=new skLiteralNode(yylsp[0].first_line,yyvsp[0].integer); SAVE(yyval.exprNode);
    break;}
case 51:
#line 181 "sklang.y"
{   DB("FLOAT_EXPR");yyval.exprNode=new skLiteralNode(yylsp[0].first_line,yyvsp[0].floating); SAVE(yyval.exprNode);
    break;}
case 52:
#line 182 "sklang.y"
{   DB("NOT_EXPR");yyval.exprNode=new skOpNode(yylsp[-1].first_line,s_Not,yyvsp[0].exprNode,0); SAVE(yyval.exprNode);
    break;}
case 53:
#line 183 "sklang.y"
{   DB("AND_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_And,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 54:
#line 184 "sklang.y"
{   DB("OR_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Or,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 55:
#line 185 "sklang.y"
{   DB("SUBTRACT_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Subtract,yyvsp[-2].exprNode,yyvsp[0].exprNode);SAVE(yyval.exprNode);
    break;}
case 56:
#line 186 "sklang.y"
{   DB("LESS_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Less,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 57:
#line 187 "sklang.y"
{   DB("LESS_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Less,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 58:
#line 188 "sklang.y"
{   DB("LESSEQUAL_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_LessEqual,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 59:
#line 189 "sklang.y"
{   DB("LESSEQUAL_EXPR");yyval.exprNode=new skOpNode(yylsp[-3].first_line,s_LessEqual,yyvsp[-3].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 60:
#line 190 "sklang.y"
{   DB("MORE_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_More,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 61:
#line 191 "sklang.y"
{   DB("MORE_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_More,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 62:
#line 192 "sklang.y"
{   DB("MOREEQUAL_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_MoreEqual,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 63:
#line 193 "sklang.y"
{   DB("MOREEQUAL_EXPR");yyval.exprNode=new skOpNode(yylsp[-3].first_line,s_MoreEqual,yyvsp[-3].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 64:
#line 194 "sklang.y"
{   DB("EQUALS_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Equals,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 65:
#line 195 "sklang.y"
{   DB("NOTEQUALS_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_NotEquals,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 66:
#line 196 "sklang.y"
{   DB("PLUS_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Plus,yyvsp[-2].exprNode,yyvsp[0].exprNode);  SAVE(yyval.exprNode);
    break;}
case 67:
#line 197 "sklang.y"
{   DB("DIVIDE_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Divide,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 68:
#line 198 "sklang.y"
{   DB("MULT_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Mult,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 69:
#line 199 "sklang.y"
{   DB("MOD_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Mod,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 70:
#line 200 "sklang.y"
{   DB("MINUS_EXPR");yyval.exprNode=new skOpNode(yylsp[-1].first_line,s_Minus,yyvsp[0].exprNode,0); SAVE(yyval.exprNode);
    break;}
case 71:
#line 201 "sklang.y"
{   DB("CONCAT_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Concat,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 72:
#line 202 "sklang.y"
{   DB("CONCAT_EXPR");yyval.exprNode=new skOpNode(yylsp[-2].first_line,s_Concat,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode);
    break;}
case 73:
#line 203 "sklang.y"
{   DB("SUB_EXPR");yyval.exprNode=yyvsp[-1].exprNode; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "../Src/bison.simple"

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
	  Char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(Char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (Char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      STRCPY(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(Char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			STRCAT(msg, count == 0 ? skSTR(", expecting `") : skSTR(" or `"));
			STRCAT(msg, yytname[x]);
			STRCAT(msg, skSTR("'"));
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror (skSTR("parse error; also virtual memory exceeded"));
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror(skSTR("parse error"));
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
#line 205 "sklang.y"
