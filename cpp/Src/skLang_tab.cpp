#ifndef lint
static char yysccsid[] = "@(#)yaccpar     1.7 (Berkeley) 09/09/90";
#endif
#define YYBYACC 1
#line 4 "skLang.y"
#include "skParseNode.h"
#include "skosfcn.h"


extern skMethodDefNode * g_TopNode;
extern skParseNodeList g_TempNodes;
#define SAVE(t) g_TempNodes.append(t);
/*#define _DEBUGPARSER*/
#ifdef _DEBUGPARSER
#include <stdio.h>
#define DB(t) printf("%s\n",t);
#define DBN(t,n) printf("%s - %s\n",t,(const char *)n);
#else
#define DB(t) 
#define DBN(t,n) 
#endif
#line 21 "skLang.y"
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
#line 39 "skLang_tab.c"
#define L_CHARACTER 257
#define L_INTEGER 258
#define L_FLOAT 259
#define L_ID 260
#define L_STRING 261
#define L_RETURN 262
#define L_OR 263
#define L_AND 264
#define L_NOT 265
#define L_IF 266
#define L_ELSE 267
#define L_WHILE 268
#define L_GT 269
#define L_LT 270
#define L_SWITCH 271
#define L_DEFAULT 272
#define L_CASE 273
#define UNARY 274
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    2,    2,    5,    5,    9,    9,   10,
   10,   12,   12,   13,   13,   11,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    4,    4,    3,    3,
    1,    1,   14,   14,    6,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,
};
short yylen[] = {                                         2,
    1,    3,    4,    1,    3,    1,    2,    0,    1,    1,
    3,    0,    1,    1,    2,    3,    5,    7,    5,    7,
    9,    3,    4,    6,    2,    1,    4,    3,    1,    3,
    1,    3,    1,    4,    3,    1,    3,    1,    1,    1,
    1,    2,    3,    3,    3,    3,    3,    3,    4,    3,
    3,    3,    3,    2,    3,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    6,    0,    0,   39,   40,   41,    0,   38,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    0,
    0,    0,    0,   25,    7,    0,    0,    0,    9,    0,
   42,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,    0,    0,    0,
    0,    0,    2,    0,    0,    0,    0,   30,   28,    0,
    0,    0,   56,   37,    0,    0,    0,    0,   50,   45,
   55,   48,   51,   52,   53,    0,   32,    0,    0,    0,
    0,    3,    5,   23,    0,    0,   34,   49,    0,   19,
    0,   35,    0,    0,    0,   14,    0,   13,   24,   18,
    0,    0,   20,   15,   16,    0,   21,
};
short yydgoto[] = {                                       8,
   23,   31,    9,   10,   11,   63,   12,   37,   38,   39,
  106,  107,  108,   25,
};
short yysindex[] = {                                    -17,
  -25,  117,  -20,  -16,  -13,  -38,    0,    0,  -39,  -24,
  -27,    0,  -12,  117,    0,    0,    0,    6,    0,  117,
  117,  117,  -22,   39,   10,  117,  117,  117,    0,  -72,
    3,  117, -202,    0,    0, -196,  165,    4,    0,  117,
    0,    0,   60, -194,  117,  117,  117,  117,  117,  117,
  117,  117,  117,  117,  117,   17,    0, -181,   71,   92,
  103,  -27,    0,  -72, -177,  123,   27,    0,    0,    0,
  117,    8,    0,    0,  424,  424,  424,  424,    0,    0,
    0,    0,    0,    0,    0,  117,    0,  -72,  -72,  -34,
   16,    0,    0,    0,  117,  165,    0,    0, -175,    0,
 -174,    0,  134,  -72,  117,    0, -118,    0,    0,    0,
  154,  -72,    0,    0,    0,  -15,    0,
};
short yyrindex[] = {                                      0,
  -40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  111,    0,    0,    9,    0,    0,    0,  -33,    0,    0,
    0,    0,   26,    0,   -4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -29,
    0,    0,    0,    0,   50,  162,  175,  183,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,    0,    0,    1,    0,
 -120,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   57,    0,   81,   84,   61,  182,    5,  428,   82,    0,
   23,    0,    0,  280,
};
#define YYTABLESIZE 533
short yytable[] = {                                      33,
   17,   33,   30,   33,   12,   33,  113,   33,   33,   33,
   33,   33,   33,   33,   14,   35,   34,   29,   33,   26,
   29,   32,    6,   27,   33,   33,   28,   33,   31,   27,
   31,    7,   31,   36,   34,   44,   31,   31,   31,   31,
   31,    7,   31,   64,   70,   40,   65,   71,   97,    8,
   62,   71,    8,   31,   31,   58,   31,   67,   36,   17,
   36,   10,   36,    1,   10,   74,   36,   36,   36,   36,
   36,   56,   36,   51,    7,   55,   11,   86,   18,   11,
   54,   49,   93,   50,   36,   53,   36,   95,  101,   33,
   44,  104,   56,   44,   51,   35,   55,   57,  105,   52,
   73,   54,   49,   56,   50,   51,   53,   55,   44,  117,
    1,   88,   54,   49,   87,   50,   68,   53,   31,   69,
   52,   72,   91,    0,   56,   17,   51,    0,   55,  114,
    0,   52,   89,   54,   49,   56,   50,   51,   53,   55,
  102,    0,    0,   90,   54,   49,    0,   50,   36,   53,
    0,   12,   52,  112,  105,   56,   22,   51,    0,   55,
    0,   21,    0,   52,   54,   49,   56,   50,   51,   53,
   55,    0,   44,    0,    0,   54,   49,    0,   50,    0,
   53,   94,    0,   52,    0,    0,   56,    0,   51,    0,
   55,    0,  109,    0,   52,   54,   49,   56,   50,   51,
   53,   55,   43,    0,    0,   43,   54,   49,    0,   50,
    0,   53,    0,    0,   52,   47,    0,    0,   47,    0,
   43,   29,    0,   46,    0,   52,   46,    0,    0,   33,
   33,    0,    1,   47,    2,   33,   33,    0,    3,    0,
    4,   46,    1,    5,    2,   92,    0,    0,    3,    0,
    4,    0,    0,    5,    0,    0,    0,    0,   31,   31,
   17,    0,   17,    0,   31,   31,   17,    0,   17,   99,
  100,   17,    0,    0,    0,    1,   62,    2,    0,   13,
    0,    3,    0,    4,   43,  110,    5,    0,   36,   36,
   13,    0,  115,  116,   36,   36,    0,   47,    0,    0,
    0,   45,   46,    0,    0,   46,    0,   47,   48,    0,
    0,    0,   44,   44,    0,   13,    0,    0,   44,   44,
    0,    0,   45,   46,    0,    0,    0,    0,   47,   48,
    0,    0,    0,   45,   46,    0,    0,    0,    0,   47,
   48,   13,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,   46,    0,    0,    0,    0,
   47,   48,    0,    0,    0,   45,   46,    0,    0,    0,
   13,   47,   48,   15,   16,   17,   18,   19,    0,    0,
    0,   20,    0,    0,    0,   45,   46,    0,    0,    0,
    0,   47,   48,    0,    0,    0,   45,   46,    0,    0,
    0,    0,   47,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,   46,    0,    0,
    0,    0,   47,   48,   43,   43,    0,   45,   46,   24,
   43,   43,    0,   47,   48,    0,    0,   47,   47,    0,
    0,    0,    0,   47,   47,   46,   46,   41,   42,   43,
    0,   46,   46,   59,   60,   61,   56,    0,   51,   66,
   55,    0,    0,    0,    0,   54,   49,    0,   50,    0,
   53,    0,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,   85,    0,   52,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   96,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   98,    0,    0,    0,    0,    0,    0,
    0,    0,  103,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  111,
};
short yycheck[] = {                                      33,
    0,   35,   41,   37,  125,   46,  125,   41,   42,   43,
   44,   45,   46,   47,   40,   11,   46,   58,   58,   40,
   61,   61,   40,   40,   58,   59,   40,   61,   33,   59,
   35,   59,   37,   46,   59,   58,   41,   42,   43,   44,
   45,   59,   47,   41,   41,   40,   44,   44,   41,   41,
  123,   44,   44,   58,   59,   46,   61,  260,   33,   59,
   35,   41,   37,  260,   44,  260,   41,   42,   43,   44,
   45,   33,   47,   35,   59,   37,   41,   61,  260,   44,
   42,   43,  260,   45,   59,   47,   61,   61,  123,  123,
   41,  267,   33,   44,   35,   91,   37,   59,  273,   61,
   41,   42,   43,   33,   45,   35,   47,   37,   59,  125,
    0,   41,   42,   43,   58,   45,   36,   47,  123,   36,
   61,   40,   62,   -1,   33,  125,   35,   -1,   37,  107,
   -1,   61,   41,   42,   43,   33,   45,   35,   47,   37,
  125,   -1,   -1,   41,   42,   43,   -1,   45,  123,   47,
   -1,  272,   61,  272,  273,   33,   40,   35,   -1,   37,
   -1,   45,   -1,   61,   42,   43,   33,   45,   35,   47,
   37,   -1,  123,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   59,   -1,   61,   -1,   -1,   33,   -1,   35,   -1,
   37,   -1,   59,   -1,   61,   42,   43,   33,   45,   35,
   47,   37,   41,   -1,   -1,   44,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   61,   41,   -1,   -1,   44,   -1,
   59,  260,   -1,   41,   -1,   61,   44,   -1,   -1,  263,
  264,   -1,  260,   59,  262,  269,  270,   -1,  266,   -1,
  268,   59,  260,  271,  262,   64,   -1,   -1,  266,   -1,
  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  263,  264,
  260,   -1,  262,   -1,  269,  270,  266,   -1,  268,   88,
   89,  271,   -1,   -1,   -1,  260,  123,  262,   -1,    0,
   -1,  266,   -1,  268,  123,  104,  271,   -1,  263,  264,
   11,   -1,  111,  112,  269,  270,   -1,  123,   -1,   -1,
   -1,  263,  264,   -1,   -1,  123,   -1,  269,  270,   -1,
   -1,   -1,  263,  264,   -1,   36,   -1,   -1,  269,  270,
   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,  269,  270,
   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,  269,
  270,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,
  269,  270,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,
   91,  269,  270,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  265,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,
   -1,  269,  270,   -1,   -1,   -1,  263,  264,   -1,   -1,
   -1,   -1,  269,  270,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,
   -1,   -1,  269,  270,  263,  264,   -1,  263,  264,    2,
  269,  270,   -1,  269,  270,   -1,   -1,  263,  264,   -1,
   -1,   -1,   -1,  269,  270,  263,  264,   20,   21,   22,
   -1,  269,  270,   26,   27,   28,   33,   -1,   35,   32,
   37,   -1,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   45,   46,   47,   48,   49,   50,   51,   52,
   53,   54,   55,   -1,   61,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   86,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   95,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  105,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,
0,0,0,0,0,0,0,"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"L_CHARACTER","L_INTEGER","L_FLOAT","L_ID",
"L_STRING","L_RETURN","L_OR","L_AND","L_NOT","L_IF","L_ELSE","L_WHILE","L_GT",
"L_LT","L_SWITCH","L_DEFAULT","L_CASE","UNARY",
};
char *yyrule[] = {
"$accept : method_defn",
"method_defn : stat_list",
"method_defn : '(' ')' compound_stat",
"method_defn : '(' param_list ')' compound_stat",
"param_list : L_ID",
"param_list : param_list ',' L_ID",
"stat_list : stat",
"stat_list : stat_list stat",
"expr_list :",
"expr_list : nonnull_expr_list",
"nonnull_expr_list : expr",
"nonnull_expr_list : expr_list ',' expr",
"case_list :",
"case_list : nonnull_case_list",
"nonnull_case_list : case_stat",
"nonnull_case_list : case_list case_stat",
"case_stat : L_CASE expr compound_stat",
"stat : L_IF '(' expr ')' compound_stat",
"stat : L_IF '(' expr ')' compound_stat L_ELSE compound_stat",
"stat : L_WHILE '(' expr ')' compound_stat",
"stat : L_SWITCH '(' expr ')' '{' case_list '}'",
"stat : L_SWITCH '(' expr ')' '{' case_list L_DEFAULT compound_stat '}'",
"stat : L_RETURN expr ';'",
"stat : id_list_id '=' expr ';'",
"stat : id_list_id ':' L_ID '=' expr ';'",
"stat : id_list_fn ';'",
"stat : ';'",
"id_list_fn : L_ID '(' expr_list ')'",
"id_list_fn : id_or_method '.' id_list_fn",
"id_list_id : L_ID",
"id_list_id : id_or_method '.' id_list_id",
"id_list : id_or_method",
"id_list : id_or_method '.' id_list",
"id_or_method : L_ID",
"id_or_method : L_ID '(' expr_list ')'",
"compound_stat : '{' stat_list '}'",
"expr : id_list",
"expr : id_list ':' L_ID",
"expr : L_STRING",
"expr : L_CHARACTER",
"expr : L_INTEGER",
"expr : L_FLOAT",
"expr : L_NOT expr",
"expr : expr L_AND expr",
"expr : expr L_OR expr",
"expr : expr '-' expr",
"expr : expr L_LT expr",
"expr : expr L_GT expr",
"expr : expr '=' expr",
"expr : expr '!' '=' expr",
"expr : expr '+' expr",
"expr : expr '/' expr",
"expr : expr '*' expr",
"expr : expr '%' expr",
"expr : '-' expr",
"expr : expr '#' expr",
"expr : '(' expr ')'",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 600
#define YYMAXDEPTH 600
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 56 "skLang.y"
{ yyval.methodDef=new skMethodDefNode(yyvsp[0].statListNode); SAVE(yyval.methodDef); g_TopNode=yyval.methodDef; }
break;
case 2:
#line 57 "skLang.y"
{yyval.methodDef=new skMethodDefNode(0,yyvsp[0].statListNode); SAVE(yyval.methodDef); g_TopNode=yyval.methodDef; }
break;
case 3:
#line 58 "skLang.y"
{yyval.methodDef=new skMethodDefNode(yyvsp[-2].idListNode,yyvsp[0].statListNode); SAVE(yyval.methodDef); g_TopNode=yyval.methodDef; }
break;
case 4:
#line 61 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); }
break;
case 5:
#line 62 "skLang.y"
{ yyvsp[-2].idListNode->addId(new skIdNode(*yyvsp[0].string,0)); delete yyvsp[0].string; yyval.idListNode=yyvsp[-2].idListNode; }
break;
case 6:
#line 64 "skLang.y"
{	yyval.statListNode=new skStatListNode(); yyval.statListNode->addStat(yyvsp[0].statNode); SAVE(yyval.statListNode);  }
break;
case 7:
#line 65 "skLang.y"
{	yyvsp[-1].statListNode->addStat(yyvsp[0].statNode); yyval.statListNode=yyvsp[-1].statListNode; }
break;
case 8:
#line 67 "skLang.y"
{ yyval.exprListNode=new skExprListNode(); SAVE(yyval.exprListNode); }
break;
case 9:
#line 68 "skLang.y"
{ yyval.exprListNode=yyvsp[0].exprListNode; }
break;
case 10:
#line 70 "skLang.y"
{ yyval.exprListNode=new skExprListNode();yyval.exprListNode->addExpr(yyvsp[0].exprNode);SAVE(yyval.exprListNode);}
break;
case 11:
#line 71 "skLang.y"
{ yyvsp[-2].exprListNode->addExpr(yyvsp[0].exprNode);yyval.exprListNode=yyvsp[-2].exprListNode; }
break;
case 12:
#line 73 "skLang.y"
{ yyval.caseListNode=new skCaseListNode(); SAVE(yyval.caseListNode); }
break;
case 13:
#line 74 "skLang.y"
{ yyval.caseListNode=yyvsp[0].caseListNode; }
break;
case 14:
#line 76 "skLang.y"
{ yyval.caseListNode=new skCaseListNode();yyval.caseListNode->addCase(yyvsp[0].caseNode);SAVE(yyval.caseListNode);}
break;
case 15:
#line 77 "skLang.y"
{ yyvsp[-1].caseListNode->addCase(yyvsp[0].caseNode);yyval.caseListNode=yyvsp[-1].caseListNode; }
break;
case 16:
#line 79 "skLang.y"
{ yyval.caseNode=new skCaseNode(yyvsp[-1].exprNode,yyvsp[0].statListNode); SAVE(yyval.caseNode); }
break;
case 17:
#line 81 "skLang.y"
{ 	DB("IF");yyval.statNode=new skIfNode(yyvsp[-2].exprNode,yyvsp[0].statListNode,0); SAVE(yyval.statNode)}
break;
case 18:
#line 83 "skLang.y"
{ 	DB("IFELSE");yyval.statNode=new skIfNode(yyvsp[-4].exprNode,yyvsp[-2].statListNode,yyvsp[0].statListNode); SAVE(yyval.statNode)}
break;
case 19:
#line 85 "skLang.y"
{ 	DB("WHILE");yyval.statNode=new skWhileNode(yyvsp[-2].exprNode,yyvsp[0].statListNode); SAVE(yyval.statNode)}
break;
case 20:
#line 87 "skLang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yyvsp[-4].exprNode,yyvsp[-1].caseListNode,0); SAVE(yyval.statNode)}
break;
case 21:
#line 89 "skLang.y"
{ 	DB("SWITCH");yyval.statNode=new skSwitchNode(yyvsp[-6].exprNode,yyvsp[-3].caseListNode,yyvsp[-1].statListNode); SAVE(yyval.statNode)}
break;
case 22:
#line 90 "skLang.y"
{   DBN("RETURN",*yyvsp[-2].string);yyval.statNode=new skReturnNode(yyvsp[-1].exprNode); SAVE(yyval.statNode)}
break;
case 23:
#line 92 "skLang.y"
{   DB("ASSIGN");yyval.statNode=new skAssignNode(yyvsp[-3].idListNode,0,yyvsp[-1].exprNode); SAVE(yyval.statNode)}
break;
case 24:
#line 93 "skLang.y"
{ DB("ASSIGN");yyval.statNode=new skAssignNode(yyvsp[-5].idListNode,yyvsp[-3].string,yyvsp[-1].exprNode); SAVE(yyval.statNode); }
break;
case 25:
#line 94 "skLang.y"
{ DB("METHODCALL");yyval.statNode=new skMethodStatNode(yyvsp[-1].idListNode);SAVE(yyval.statNode); }
break;
case 26:
#line 95 "skLang.y"
{	DB("NULL");yyval.statNode=new skStatNode();SAVE(yyval.statNode)}
break;
case 27:
#line 97 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprListNode)); delete yyvsp[-3].string; SAVE(yyval.idListNode); }
break;
case 28:
#line 98 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 29:
#line 101 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); }
break;
case 30:
#line 102 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 31:
#line 104 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(yyvsp[0].idNode); SAVE(yyval.idListNode); }
break;
case 32:
#line 105 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 33:
#line 107 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[0].string,0); delete yyvsp[0].string; SAVE(yyval.idNode) }
break;
case 34:
#line 108 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprListNode); delete yyvsp[-3].string; SAVE(yyval.idNode) }
break;
case 35:
#line 110 "skLang.y"
{	DB("STATLIST");yyval.statListNode=yyvsp[-1].statListNode; }
break;
case 36:
#line 114 "skLang.y"
{   DB("ID_EXPR");yyval.exprNode=yyvsp[0].idListNode; }
break;
case 37:
#line 115 "skLang.y"
{   DB("ID_EXPR");yyvsp[-2].idListNode->m_Attribute=*yyvsp[0].string;delete yyvsp[0].string;yyval.exprNode=yyvsp[-2].idListNode;}
break;
case 38:
#line 116 "skLang.y"
{   DBN("STRING_EXPR",*yyvsp[0].string);yyval.exprNode=new skLiteralNode(yyvsp[0].string); SAVE(yyval.exprNode)}
break;
case 39:
#line 117 "skLang.y"
{   DB("CHARACTER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].character); SAVE(yyval.exprNode)}
break;
case 40:
#line 118 "skLang.y"
{   DB("INTEGER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].integer); SAVE(yyval.exprNode)}
break;
case 41:
#line 119 "skLang.y"
{   DB("FLOAT_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].floating); SAVE(yyval.exprNode)}
break;
case 42:
#line 120 "skLang.y"
{   DB("NOT_EXPR");yyval.exprNode=new skOpNode(s_Not,yyvsp[0].exprNode,0); SAVE(yyval.exprNode)}
break;
case 43:
#line 121 "skLang.y"
{   DB("AND_EXPR");yyval.exprNode=new skOpNode(s_And,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 44:
#line 122 "skLang.y"
{   DB("OR_EXPR");yyval.exprNode=new skOpNode(s_Or,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 45:
#line 123 "skLang.y"
{   DB("SUBTRACT_EXPR");yyval.exprNode=new skOpNode(s_Subtract,yyvsp[-2].exprNode,yyvsp[0].exprNode);SAVE(yyval.exprNode)}
break;
case 46:
#line 124 "skLang.y"
{   DB("LESS_EXPR");yyval.exprNode=new skOpNode(s_Less,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 47:
#line 125 "skLang.y"
{   DB("MORE_EXPR");yyval.exprNode=new skOpNode(s_More,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 48:
#line 126 "skLang.y"
{   DB("EQUALS_EXPR");yyval.exprNode=new skOpNode(s_Equals,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 49:
#line 127 "skLang.y"
{   DB("NOTEQUALS_EXPR");yyval.exprNode=new skOpNode(s_NotEquals,yyvsp[-3].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 50:
#line 128 "skLang.y"
{   DB("PLUS_EXPR");yyval.exprNode=new skOpNode(s_Plus,yyvsp[-2].exprNode,yyvsp[0].exprNode);  SAVE(yyval.exprNode)}
break;
case 51:
#line 129 "skLang.y"
{   DB("DIVIDE_EXPR");yyval.exprNode=new skOpNode(s_Divide,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 52:
#line 130 "skLang.y"
{   DB("MULT_EXPR");yyval.exprNode=new skOpNode(s_Mult,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 53:
#line 131 "skLang.y"
{   DB("MOD_EXPR");yyval.exprNode=new skOpNode(s_Mod,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 54:
#line 132 "skLang.y"
{   DB("MINUS_EXPR");yyval.exprNode=new skOpNode(s_Minus,yyvsp[0].exprNode,0); SAVE(yyval.exprNode)}
break;
case 55:
#line 133 "skLang.y"
{   DB("CONCAT_EXPR");yyval.exprNode=new skOpNode(s_Concat,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 56:
#line 134 "skLang.y"
{   DB("SUB_EXPR");yyval.exprNode=yyvsp[-1].exprNode; }
break;
#line 704 "skLang_tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
