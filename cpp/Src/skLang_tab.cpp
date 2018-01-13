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
    3,   14,   14,   14,   14,    1,    1,    6,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,
};
short yylen[] = {                                         2,
    1,    3,    4,    1,    3,    1,    2,    0,    1,    1,
    3,    0,    1,    1,    2,    3,    5,    7,    5,    7,
    9,    3,    4,    6,    2,    1,    4,    3,    1,    4,
    3,    1,    4,    4,    7,    1,    3,    3,    1,    3,
    1,    1,    1,    1,    2,    3,    3,    3,    3,    3,
    3,    4,    3,    3,    3,    3,    2,    3,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    6,    0,    0,    0,   42,   43,   44,    0,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,
    0,    0,    0,    0,   25,    7,    0,    0,    0,    9,
    0,    0,    0,   45,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
   31,   28,    0,    0,    0,    0,    0,   59,   40,    0,
    0,    0,    0,   53,   48,   58,   51,   54,   55,   56,
    0,   37,    0,    0,    0,    0,    3,    5,   23,    0,
    0,    0,    0,   34,   52,    0,   19,    0,   38,    0,
    0,    0,    0,   14,    0,   13,   24,   35,   18,    0,
    0,   20,   15,   16,    0,   21,
};
short yydgoto[] = {                                       8,
   24,   32,    9,   10,   11,   66,   12,   38,   39,   40,
  114,  115,  116,   26,
};
short yysindex[] = {                                     26,
  -32,  196,  -21,  -16,  -15,  -41,    0,    0,  -35,  -50,
   87,    0,  -12,  196,  196,    0,    0,    0,  -23,    0,
  196,  196,  196,   24,   97,   42,  196,  196,  196,    0,
  -53,    8,  196, -165,    0,    0, -163,  179,   12,    0,
  124,  196,  196,    0,    0,  135, -161,  196,  196,  196,
  196,  196,  196,  196,  196,  196,  196,  196,   40,    0,
 -160,  146,  157,  168,   87,    0,  -53, -151,  209,   49,
    0,    0,   22,  196,    0,   20,  242,    0,    0,  447,
  447,  447,  447,    0,    0,    0,    0,    0,    0,    0,
  196,    0,  -53,  -53,   -9,  -13,    0,    0,    0,  196,
  196,  179,   22,    0,    0, -156,    0, -158,    0,  273,
  303,  -53,  196,    0, -122,    0,    0,    0,    0,  336,
  -53,    0,    0,    0,   -7,    0,
};
short yyrindex[] = {                                      0,
  -11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  116,    0,    0,   37,    0,    0,    0,    0,  -31,    0,
    0,    0,    0,   61,    0,   32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,    0,    0,
    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -39,    0,  -10,    0,    0,    0,    0,  263,
  313,  321,  348,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   43,   -4,    0,    0,    1,    0, -120,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   60,    0,   86,   90,   59,  -49,   11,  501,   89,    0,
   13,    0,    0,   21,
};
#define YYTABLESIZE 618
short yytable[] = {                                      31,
   17,   32,  122,   32,   12,   32,   33,   14,   35,   32,
   32,   32,   32,   32,   32,   32,   42,   97,   27,   27,
   13,   36,   34,   28,   29,   33,   32,   32,   33,   32,
   33,   13,   33,   37,   32,   34,   33,   33,   33,   33,
   33,   33,   33,  106,  107,    7,   29,   30,   67,   29,
   30,   68,   73,   33,   33,   74,   33,   13,   15,   17,
  103,   32,  119,   74,   36,    6,   36,   43,   36,   65,
  124,  125,   36,   36,   36,   36,   36,    8,   36,   10,
    8,   47,   10,   11,    7,   13,   11,   61,   33,   36,
   36,   32,   36,   39,   70,   39,    1,   39,   79,   19,
   91,   39,   39,   39,   39,   39,   36,   39,   98,  100,
  112,  109,  101,  108,  113,    1,   13,  126,   33,   39,
   92,   39,   71,   96,   36,   17,   72,  123,    0,   59,
   76,   54,    0,   58,    0,    0,    0,    0,   57,   52,
    0,   53,    0,   56,    0,    7,    0,    0,    0,  121,
  113,   12,    0,   39,   36,   60,   59,   55,   54,    0,
   58,    0,    0,    0,    0,   57,   52,   59,   53,   54,
   56,   58,    0,    0,    0,   78,   57,   52,   59,   53,
   54,   56,   58,   39,   55,    0,   93,   57,   52,   59,
   53,   54,   56,   58,    0,   55,    0,   94,   57,   52,
   59,   53,   54,   56,   58,    0,   55,    0,   95,   57,
   52,   59,   53,   54,   56,   58,   75,   55,   30,    0,
   57,   52,    0,   53,    0,   56,    0,    0,   55,    0,
    0,   32,   32,    0,    0,   23,    0,   32,   32,   55,
   22,   59,    0,   54,    0,   58,    1,    0,    2,    0,
   57,   52,    3,   53,    4,   56,    0,    5,   33,   33,
   17,    0,   17,    0,   33,   33,   17,   99,   17,   55,
    0,   17,    0,    0,   59,    0,   54,    0,   58,    0,
    0,    0,    0,   57,   52,    1,   53,    2,   56,    0,
    0,    3,    0,    4,   36,   36,    5,    0,    0,    0,
   36,   36,   55,   47,    0,   59,   47,   54,    0,   58,
    0,    0,    0,    0,   57,   52,    0,   53,    0,   56,
    0,   47,    0,   39,   39,    0,    0,    0,    0,   39,
   39,  117,    0,   55,  104,   59,    0,   54,    0,   58,
    0,    0,    0,    0,   57,   52,    1,   53,    2,   56,
    0,    0,    3,   46,    4,   47,   46,    5,    0,   48,
   49,   50,    0,   55,   50,   50,   51,    0,   59,    0,
   54,   46,   58,    0,    0,    0,    0,   57,   52,   50,
   53,    0,   56,    0,    0,   47,   48,   49,   49,    0,
    0,   49,   50,   51,    0,  118,   55,   48,   49,    0,
    0,    0,    0,   50,   51,   46,   49,    0,   48,   49,
    0,    0,    0,   50,   50,   51,    0,    0,    0,   48,
   49,    0,    0,    0,    0,   50,   51,    0,    0,    0,
   48,   49,    0,    0,    0,   46,   50,   51,    0,    0,
   49,   48,   49,   50,    0,    0,    0,   50,   51,    0,
    0,    0,   16,   17,   18,   19,   20,    0,   65,    0,
   21,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   48,   49,    0,    0,    0,    0,   50,   51,   59,
    0,   54,    0,   58,    0,    0,    0,    0,   57,   52,
    0,   53,    0,   56,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,   48,   49,    0,   55,    0,    0,
   50,   51,    0,    0,    0,   41,    0,    0,    0,    0,
    0,   44,   45,   46,    0,   47,   47,   62,   63,   64,
    0,   47,   47,   69,    0,   48,   49,    0,    0,    0,
    0,   50,   51,   77,    0,    0,    0,    0,   80,   81,
   82,   83,   84,   85,   86,   87,   88,   89,   90,    0,
    0,    0,    0,    0,    0,   48,   49,    0,    0,    0,
    0,   50,   51,    0,  102,   46,   46,    0,    0,    0,
    0,   46,   46,   50,   50,    0,    0,    0,    0,   50,
   50,  105,    0,    0,    0,    0,    0,    0,   48,   49,
  110,  111,    0,    0,   50,   51,    0,    0,    0,    0,
   49,   49,    0,  120,    0,    0,   49,   49,
};
short yycheck[] = {                                      41,
    0,   33,  125,   35,  125,   37,   46,   40,   59,   41,
   42,   43,   44,   45,   46,   47,   40,   67,   40,   59,
    0,   11,   58,   40,   40,   61,   58,   59,   33,   61,
   35,   11,   37,   46,   46,   46,   41,   42,   43,   44,
   45,   46,   47,   93,   94,   59,   58,   58,   41,   61,
   61,   44,   41,   58,   59,   44,   61,   37,   91,   59,
   41,   93,  112,   44,   33,   40,   35,   91,   37,  123,
  120,  121,   41,   42,   43,   44,   45,   41,   47,   41,
   44,   58,   44,   41,   59,   65,   44,   46,   93,   58,
   59,  123,   61,   33,  260,   35,  260,   37,  260,  260,
   61,   41,   42,   43,   44,   45,   96,   47,  260,   61,
  267,  125,   91,  123,  273,    0,   96,  125,  123,   59,
   61,   61,   37,   65,   93,  125,   37,  115,   -1,   33,
   42,   35,   -1,   37,   -1,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   59,   -1,   -1,   -1,  272,
  273,  272,   -1,   93,  123,   59,   33,   61,   35,   -1,
   37,   -1,   -1,   -1,   -1,   42,   43,   33,   45,   35,
   47,   37,   -1,   -1,   -1,   41,   42,   43,   33,   45,
   35,   47,   37,  123,   61,   -1,   41,   42,   43,   33,
   45,   35,   47,   37,   -1,   61,   -1,   41,   42,   43,
   33,   45,   35,   47,   37,   -1,   61,   -1,   41,   42,
   43,   33,   45,   35,   47,   37,   93,   61,  260,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   61,   -1,
   -1,  263,  264,   -1,   -1,   40,   -1,  269,  270,   61,
   45,   33,   -1,   35,   -1,   37,  260,   -1,  262,   -1,
   42,   43,  266,   45,  268,   47,   -1,  271,  263,  264,
  260,   -1,  262,   -1,  269,  270,  266,   59,  268,   61,
   -1,  271,   -1,   -1,   33,   -1,   35,   -1,   37,   -1,
   -1,   -1,   -1,   42,   43,  260,   45,  262,   47,   -1,
   -1,  266,   -1,  268,  263,  264,  271,   -1,   -1,   -1,
  269,  270,   61,   41,   -1,   33,   44,   35,   -1,   37,
   -1,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   59,   -1,  263,  264,   -1,   -1,   -1,   -1,  269,
  270,   59,   -1,   61,   93,   33,   -1,   35,   -1,   37,
   -1,   -1,   -1,   -1,   42,   43,  260,   45,  262,   47,
   -1,   -1,  266,   41,  268,   93,   44,  271,   -1,  263,
  264,   41,   -1,   61,   44,  269,  270,   -1,   33,   -1,
   35,   59,   37,   -1,   -1,   -1,   -1,   42,   43,   59,
   45,   -1,   47,   -1,   -1,  123,  263,  264,   41,   -1,
   -1,   44,  269,  270,   -1,   93,   61,  263,  264,   -1,
   -1,   -1,   -1,  269,  270,   93,   59,   -1,  263,  264,
   -1,   -1,   -1,   93,  269,  270,   -1,   -1,   -1,  263,
  264,   -1,   -1,   -1,   -1,  269,  270,   -1,   -1,   -1,
  263,  264,   -1,   -1,   -1,  123,  269,  270,   -1,   -1,
   93,  263,  264,  123,   -1,   -1,   -1,  269,  270,   -1,
   -1,   -1,  257,  258,  259,  260,  261,   -1,  123,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,  263,  264,   -1,   -1,   -1,   -1,  269,  270,   33,
   -1,   35,   -1,   37,   -1,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,    2,   -1,  263,  264,   -1,   61,   -1,   -1,
  269,  270,   -1,   -1,   -1,   15,   -1,   -1,   -1,   -1,
   -1,   21,   22,   23,   -1,  263,  264,   27,   28,   29,
   -1,  269,  270,   33,   -1,  263,  264,   -1,   -1,   -1,
   -1,  269,  270,   43,   -1,   -1,   -1,   -1,   48,   49,
   50,   51,   52,   53,   54,   55,   56,   57,   58,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,
   -1,  269,  270,   -1,   74,  263,  264,   -1,   -1,   -1,
   -1,  269,  270,  263,  264,   -1,   -1,   -1,   -1,  269,
  270,   91,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,
  100,  101,   -1,   -1,  269,  270,   -1,   -1,   -1,   -1,
  263,  264,   -1,  113,   -1,   -1,  269,  270,
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
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"L_CHARACTER","L_INTEGER","L_FLOAT",
"L_ID","L_STRING","L_RETURN","L_OR","L_AND","L_NOT","L_IF","L_ELSE","L_WHILE",
"L_GT","L_LT","L_SWITCH","L_DEFAULT","L_CASE","UNARY",
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
"id_list_id : L_ID '[' expr ']'",
"id_list_id : id_or_method '.' id_list_id",
"id_or_method : L_ID",
"id_or_method : L_ID '(' expr_list ')'",
"id_or_method : L_ID '[' expr ']'",
"id_or_method : L_ID '(' expr_list ')' '[' expr ']'",
"id_list : id_or_method",
"id_list : id_or_method '.' id_list",
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
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); }
break;
case 5:
#line 62 "skLang.y"
{ yyvsp[-2].idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; yyval.idListNode=yyvsp[-2].idListNode; }
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
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[-3].string,0,yyvsp[-1].exprListNode)); delete yyvsp[-3].string;SAVE(yyval.idListNode); }
break;
case 28:
#line 98 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 29:
#line 101 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[0].string,0,0)); delete yyvsp[0].string; SAVE(yyval.idListNode); }
break;
case 30:
#line 102 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprNode,0)); delete yyvsp[-3].string; SAVE(yyval.idListNode); }
break;
case 31:
#line 103 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 32:
#line 105 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[0].string,0,0); delete yyvsp[0].string; SAVE(yyval.idNode); }
break;
case 33:
#line 106 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-3].string,0,yyvsp[-1].exprListNode); delete yyvsp[-3].string; SAVE(yyval.idNode); }
break;
case 34:
#line 107 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-3].string,yyvsp[-1].exprNode,0); delete yyvsp[-3].string; SAVE(yyval.idNode); }
break;
case 35:
#line 108 "skLang.y"
{ yyval.idNode=new skIdNode(*yyvsp[-6].string,yyvsp[-1].exprNode,yyvsp[-4].exprListNode); delete yyvsp[-6].string; SAVE(yyval.idNode); }
break;
case 36:
#line 110 "skLang.y"
{ yyval.idListNode=new skIdListNode(); yyval.idListNode->addId(yyvsp[0].idNode); SAVE(yyval.idListNode); }
break;
case 37:
#line 111 "skLang.y"
{ yyvsp[0].idListNode->prependId(yyvsp[-2].idNode); yyval.idListNode=yyvsp[0].idListNode; }
break;
case 38:
#line 115 "skLang.y"
{	DB("STATLIST");yyval.statListNode=yyvsp[-1].statListNode; }
break;
case 39:
#line 119 "skLang.y"
{   DB("ID_EXPR");yyval.exprNode=yyvsp[0].idListNode; }
break;
case 40:
#line 120 "skLang.y"
{   DB("ID_EXPR");yyvsp[-2].idListNode->m_Attribute=*yyvsp[0].string;delete yyvsp[0].string;yyval.exprNode=yyvsp[-2].idListNode;}
break;
case 41:
#line 121 "skLang.y"
{   DBN("STRING_EXPR",*yyvsp[0].string);yyval.exprNode=new skLiteralNode(yyvsp[0].string); SAVE(yyval.exprNode)}
break;
case 42:
#line 122 "skLang.y"
{   DB("CHARACTER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].character); SAVE(yyval.exprNode)}
break;
case 43:
#line 123 "skLang.y"
{   DB("INTEGER_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].integer); SAVE(yyval.exprNode)}
break;
case 44:
#line 124 "skLang.y"
{   DB("FLOAT_EXPR");yyval.exprNode=new skLiteralNode(yyvsp[0].floating); SAVE(yyval.exprNode)}
break;
case 45:
#line 125 "skLang.y"
{   DB("NOT_EXPR");yyval.exprNode=new skOpNode(s_Not,yyvsp[0].exprNode,0); SAVE(yyval.exprNode)}
break;
case 46:
#line 126 "skLang.y"
{   DB("AND_EXPR");yyval.exprNode=new skOpNode(s_And,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 47:
#line 127 "skLang.y"
{   DB("OR_EXPR");yyval.exprNode=new skOpNode(s_Or,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 48:
#line 128 "skLang.y"
{   DB("SUBTRACT_EXPR");yyval.exprNode=new skOpNode(s_Subtract,yyvsp[-2].exprNode,yyvsp[0].exprNode);SAVE(yyval.exprNode)}
break;
case 49:
#line 129 "skLang.y"
{   DB("LESS_EXPR");yyval.exprNode=new skOpNode(s_Less,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 50:
#line 130 "skLang.y"
{   DB("MORE_EXPR");yyval.exprNode=new skOpNode(s_More,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 51:
#line 131 "skLang.y"
{   DB("EQUALS_EXPR");yyval.exprNode=new skOpNode(s_Equals,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 52:
#line 132 "skLang.y"
{   DB("NOTEQUALS_EXPR");yyval.exprNode=new skOpNode(s_NotEquals,yyvsp[-3].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 53:
#line 133 "skLang.y"
{   DB("PLUS_EXPR");yyval.exprNode=new skOpNode(s_Plus,yyvsp[-2].exprNode,yyvsp[0].exprNode);  SAVE(yyval.exprNode)}
break;
case 54:
#line 134 "skLang.y"
{   DB("DIVIDE_EXPR");yyval.exprNode=new skOpNode(s_Divide,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 55:
#line 135 "skLang.y"
{   DB("MULT_EXPR");yyval.exprNode=new skOpNode(s_Mult,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 56:
#line 136 "skLang.y"
{   DB("MOD_EXPR");yyval.exprNode=new skOpNode(s_Mod,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 57:
#line 137 "skLang.y"
{   DB("MINUS_EXPR");yyval.exprNode=new skOpNode(s_Minus,yyvsp[0].exprNode,0); SAVE(yyval.exprNode)}
break;
case 58:
#line 138 "skLang.y"
{   DB("CONCAT_EXPR");yyval.exprNode=new skOpNode(s_Concat,yyvsp[-2].exprNode,yyvsp[0].exprNode); SAVE(yyval.exprNode)}
break;
case 59:
#line 139 "skLang.y"
{   DB("SUB_EXPR");yyval.exprNode=yyvsp[-1].exprNode; }
break;
#line 738 "skLang_tab.c"
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
