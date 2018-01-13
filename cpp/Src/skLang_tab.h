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
} YYSTYPE;

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
#define	L_FOR	274
#define	L_EACH	275
#define	L_IN	276
#define	UNARY	277

