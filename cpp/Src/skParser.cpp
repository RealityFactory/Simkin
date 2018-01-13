/*
  Copyright 1996-2001
  Simon Whiteside
  $Id: skParser.cpp,v 1.1 2001/05/22 10:22:53 sdw Exp $
*/
#include "skParser.h"
#include "skLang_tab.h"
#include <ctype.h>

extern int yyparse (void *);

// define DEBUGLEXER to get a verbose output of the workings of the lexer
//#define _DEBUGLEXER
#ifdef _DEBUGLEXER
#define DB(t) skTracer::trace("%d: %s\n",m_Pos,t);
#define DBN(t,n) skTracer::trace("%d: %s - %s\n",m_Pos,t,(const char *)n);
#define DBI(t,n) skTracer::trace("%d: %s - %d\n",m_Pos,t,n);
#define DBC(t,c) skTracer::trace("%d: %s - (%d) %c \n",m_Pos,t,(int)c,(char)c);
#else
#define DB(t) 
#define DBN(t,n) 
#define DBI(t,n) 
#define DBC(t,c) 
#endif
struct KeyWord{
  skString * m_Text;
  int			m_Token;
};
KeyWord keywords[]={
  {new skString("while"),L_WHILE},
  {new skString("if"),L_IF},
  {new skString("else"),L_ELSE},
  {new skString("or"),L_OR},
  {new skString("and"),L_AND},
  {new skString("not"),L_NOT},
  {new skString("return"),L_RETURN},
  {new skString("lt"),L_LT},
  {new skString("gt"),L_GT},
  {new skString("switch"),L_SWITCH},
  {new skString("case"),L_CASE},
  {new skString("default"),L_DEFAULT}
};
const int NUMKEYS=sizeof(keywords)/sizeof(KeyWord);
const int MAX_ARGS=256;

//------------------------------------------
inline int skParser::nextChar()
//------------------------------------------
{
  int c=0;
  if (m_PutBack){
    c=m_PutBack;
    m_PutBack=0;
  }else{
    c=((const char *)m_InputBuffer)[m_Pos++];
  }
  return c;
}
//------------------------------------------
inline void skParser::putbackchar(int i)
  //------------------------------------------
{
  DBC("**putback",i);
  m_PutBack=i;
}
//------------------------------------------
inline bool skParser::eof()
  //------------------------------------------
{
  bool e=false;
  if (!m_PutBack)
    e=(m_Pos==m_InputBuffer.length()+1);
#ifdef _DEBUG        
  if (e){
    DB("Eof");
  }
#endif    	
  return e;  
}


//---------------------------------------------------
skParser::skParser(const skString& code,const skString& location)
  //---------------------------------------------------
  : m_PutBack(0),m_Pos(0),m_InputBuffer(code),m_LineNum(0),m_Location(location),m_TopNode(0)
{
}
//---------------------------------------------------
skParser::~skParser()
  //---------------------------------------------------
{
  clearTempNodes();
}
//------------------------------------------
int skParser::lex(void * lvalp)
  //------------------------------------------
  // Lexical Analyser
{
  YYSTYPE * yylval=(YYSTYPE *)lvalp;
  int c=0;
  int yypos=0;
  m_LexBuffer[0]=0;
  while (!eof()){
    c=nextChar();
    if (c=='\n')
      m_LineNum++;
    // Whitespace----------------------------------------
    if (isspace(c)){
      continue;
    }
    // Identifier/Keyword--------------------------------
    if (isalpha(c) || c=='_' || c=='@'){
      do{
	if (yypos<MAXYYTEXT-2)
	  m_LexBuffer[yypos++]=c;
	else
	  break;
	c=nextChar();
      }while (!eof() && ( isalnum(c) || c=='_' ));
      if (!eof())
	putbackchar(c);
      m_LexBuffer[yypos]=0;
      int x=0;
      for (x=0;x<NUMKEYS;x++)
	if ((*keywords[x].m_Text)==m_LexBuffer){
	  c=keywords[x].m_Token;
	  yylval->string=keywords[x].m_Text;
	  DBN("keyword",*yylval->string);
	  break;
	}
      if (x==NUMKEYS){
	c=L_ID;
	yylval->string=new skString(m_LexBuffer);
	DBN("id",*yylval->string);
      }
      break;
    }
    // character--------------------------------------------
    if (c=='\''){
      c=nextChar();
      if (c=='\\'){
	c=nextChar();
	if (c=='n')
	  c='\n';
	else
	  if (c=='t')
	    c='\t';
      }
      nextChar();
      yylval->character=c;
      c=L_CHARACTER;
      DBN("character",yylval->character);
      break;
    }
    // string--------------------------------------------
    if (c=='"'){
      while(!eof()){
	c=nextChar();
	if (c=='\\'){
	  c=nextChar();
	  if (c=='n')
	    c='\n';
	  else
	    if (c=='t')
	      c='\t';
	}else
	  if (c=='"')
	    break;
	if (yypos<MAXYYTEXT-2)
	  m_LexBuffer[yypos++]=c;
	else
	  break;
      }
      m_LexBuffer[yypos]=0;
      c=L_STRING;
      yylval->string=new skString(m_LexBuffer);
      DBN("string",*yylval->string);
      break;    
    }
    // Integer or float----------------------------------
    if (isdigit(c)){
      enum {
	NUM_INTEGER,
	NUM_ZERO,
	NUM_HEX,
	NUM_FRACTION,
	NUM_EXPONENT_SIGN,
	NUM_EXPONENT,
	NUM_END
      } state;
      bool floating=false;
	  
      state = NUM_INTEGER;
      while (state != NUM_END) {
	switch (state) {
	case NUM_INTEGER:
	  if (isdigit(c)) 
	    m_LexBuffer[yypos++]=c;
	  else if (c == '.') {
	    m_LexBuffer[yypos++]=c;
	    state = NUM_FRACTION;
	    floating=true;
	  } else if (c == 'e' || c == 'E') {
	    floating=true;
	    m_LexBuffer[yypos++]=c;
	    state = NUM_EXPONENT_SIGN;
	  } else
	    state = NUM_END;
	  break;
	case NUM_FRACTION:
	  if (isdigit(c)) 
	    m_LexBuffer[yypos++]=c;
	  else if (c == 'e' || c == 'E') {
	    m_LexBuffer[yypos++]=c;
	    state = NUM_EXPONENT_SIGN;
	  } else
	    state = NUM_END;
	  break;
	case NUM_EXPONENT_SIGN:
	  if (c == '+' || c == '-' || isdigit(c)) {
	    m_LexBuffer[yypos++]=c;
	    state = NUM_EXPONENT;
	  }else
	    state = NUM_END;
	  break;
	case NUM_EXPONENT:
	  if (isdigit(c)) 
	    m_LexBuffer[yypos++]=c;
	  else
	    state = NUM_END;
	  break;
	}
	if (state != NUM_END)
	  c = nextChar();
      }
      putbackchar(c);
      m_LexBuffer[yypos++]=0;
      if (floating){
	yylval->floating=(float)(atof(m_LexBuffer));
	c=L_FLOAT;
      }else{
	yylval->integer=atoi(m_LexBuffer);
	c=L_INTEGER;
      }
      DBI("integer",(yylval->integer));
      break;    
    }
    // Comment-------------------------------------------
    if (c=='/'){
      int c1=nextChar();
      if (c1=='*'){
	do{
	  c1=nextChar();
	  if (c1=='*'){
	    c1=nextChar();
	    if (c1=='/')
	      break;
	  }
	}while (!eof());
	continue;
      }else
	if (c1=='/'){
	  do{
	    c1=nextChar();
	    if (c1=='\n'){
	      m_LineNum++;
	      break;
	    }
	  }while (!eof());
	  continue;
	}else
	  putbackchar(c1);
      break;
    }
    // Default case
    DBC("char",c);
    break;
  }
  return c;
}
//---------------------------------------------------
void skParser::cleanupTempNodes()
  //---------------------------------------------------
{
  // delete the list of nodes accumulated during the parse - in the event of an error
  skParseNodeListIterator iter(m_TempNodes);
  skParseNode * node=0;
  while ((node=iter())!=0)
    node->clear();
  m_TempNodes.clearAndDestroy();
}
//---------------------------------------------------
void skParser::setTopNode(skMethodDefNode* pNode) 
//---------------------------------------------------
{
  m_TopNode = pNode; 
}
//---------------------------------------------------
skMethodDefNode *  skParser::getTopNode()
//---------------------------------------------------
{
  return m_TopNode;
}
//---------------------------------------------------
void  skParser::addParseNode(skParseNode* pNode) 
//---------------------------------------------------
{
  m_TempNodes.append(pNode); 
}
//---------------------------------------------------
void  skParser::appendError(char * msg)
//---------------------------------------------------
{
  //    m_ErrList.append(pErr);
}
//---------------------------------------------------
const skCompileErrorList&  skParser::getErrList()
//---------------------------------------------------
{
  return m_ErrList;
}
//---------------------------------------------------
void skParser::parse()
//---------------------------------------------------
{
  yyparse(this);
}

//---------------------------------------------------
void  skParser::clearTempNodes()
//---------------------------------------------------
{
  m_TempNodes.clear();
}
//------------------------------------------
int yylex(YYSTYPE * lvalp, void* context)
  //------------------------------------------
{
  // this global function is called by the generated yyparse() function to produce the next token
  return ((skParser *)context)->lex((void *)lvalp);
}
//------------------------------------------
void real_yyerror(char * msg, void* context)
  //------------------------------------------
{ 
  // this global function is called by the generated yyparse() function if there is an error
  ((skParser *)context)->appendError(msg);
}
