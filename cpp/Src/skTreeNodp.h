/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skTreeNodp.h,v 1.6 2001/03/05 16:46:28 sdw Exp $
*/
#include "skAlist.h"

const int       MAXBUFFER=20000;


class  skTreeNodeList :  public skTAList<skTreeNode>
{           
 public:
  skTreeNodeList();
  skTreeNodeList(const skTreeNodeList&);
  virtual ~skTreeNodeList();
  skTreeNode *      findItem(const skString& label) const;
  skTreeNode *      findItem(const skString& label,const skString& data) const;
  skTreeNode *      nthElt(USize  i) const;
  skTreeNodeList&   operator=(const skTreeNodeList& );
};

#define USECLASSBUFFER

class P_TreeNodeReader 
{
 public:
  P_TreeNodeReader(istream& in);
  enum Lexeme		{ L_IDENT, L_TEXT, L_LBRACE, L_RBRACE, L_EOF, L_ERROR };

  void grabBuffer();
  void error(char * msg);
  Lexeme lex();
  void 	unLex();
  skTreeNode * 	parseTreeNode(skTreeNode * pparent);
  void parseTreeNodeList(skTreeNode *);
  void addToLexText(unsigned char c);

  skString m_FileName;
  int m_UnLex;
  Lexeme m_LastLexeme;
  unsigned char	* m_LexText;
  unsigned short m_Pos;
  unsigned short m_LineNum;
  istream& m_In;
  bool 	m_Error;
  bool	m_UsingClassLexText;
    
#ifdef USECLASSBUFFER
  static unsigned char g_ClassLexText[MAXBUFFER];
  static bool g_LexTextUsed;
#endif
};








