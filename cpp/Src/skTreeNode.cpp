/*
  copyright 1996-2001
  Simon Whiteside

  $Id: skTreeNode.cpp,v 1.9 2001/03/05 16:46:28 sdw Exp $
*/

#include <string.h>
#include "skTreeNode.h"
#include "skTreeNodp.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>
#include <ctype.h>

static skString false_string="false";
static skString true_string="true";

//-----------------------------------------------------------------
skTreeNodeList::skTreeNodeList()
//-----------------------------------------------------------------
{
}
//-----------------------------------------------------------------
skTreeNodeList::skTreeNodeList(const skTreeNodeList& l)
//-----------------------------------------------------------------
{
  //	do a deep copy
  if (l.m_Entries){
    growTo(l.m_Entries);
    m_Entries=l.m_Entries;
    for (USize i=0;i<l.m_Entries;i++)
      m_Array[i]=new skTreeNode(*(skTreeNode*)l.m_Array[i]);
  }
}
//-----------------------------------------------------------------
skTreeNode * skTreeNodeList::findItem(const skString& label) const
//-----------------------------------------------------------------
{                                                  
  skTreeNode * pnode=0;
  USize i;
  for (i=0;i<m_Entries;i++){
    pnode=pnode=(skTreeNode *)m_Array[i];
    if (pnode->m_Label==label)
      break;
  }
  if (i==m_Entries)
    pnode=0;
  return pnode;
}
//-----------------------------------------------------------------
skTreeNode * skTreeNodeList::findItem(const skString& label,const skString& data) const
//-----------------------------------------------------------------
{
  skTreeNode * pnode=0;
  USize i;
  for (i=0;i<m_Entries;i++){
    pnode=pnode=(skTreeNode *)m_Array[i];
    if (pnode->m_Label==label && pnode->m_Data==data)
      break;
  }
  if (i==m_Entries)
    pnode=0;
  return pnode;
}
//-----------------------------------------------------------------
skTreeNodeList& skTreeNodeList::operator=(const skTreeNodeList& l)
//-----------------------------------------------------------------
{
  if (&l!=this){
    clearAndDestroy();
    //	do a deep copy
    if (l.m_Entries){
      growTo(l.m_Entries);
      m_Entries=l.m_Entries;
      for (USize i=0;i<l.m_Entries;i++)
      m_Array[i]=new skTreeNode(*(skTreeNode*)l.m_Array[i]);
    }
  }
  return *this;	
}
//-----------------------------------------------------------------
skTreeNode * skTreeNodeList::nthElt(USize  i) const
//-----------------------------------------------------------------
{
  return operator[](i);
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode()
//-----------------------------------------------------------------
: m_Items(0)
{
}
//-----------------------------------------------------------------
skTreeNode::~skTreeNode()
//-----------------------------------------------------------------
{
  delete m_Items;
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skTreeNode& node)
//-----------------------------------------------------------------
: m_Label(node.m_Label),m_Data(node.m_Data),m_Items(0)
{
  if (node.m_Items)
    m_Items=new skTreeNodeList(*node.m_Items);
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label)
//-----------------------------------------------------------------
: m_Label(label),m_Items(0)
{
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label,const skString&  data)
//-----------------------------------------------------------------
: m_Label(label),m_Data(data),m_Items(0)
{
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label,bool data)
//-----------------------------------------------------------------
: m_Label(label),m_Items(0)
{
  if (data==true)
    m_Data=true_string;
  else
    m_Data=false_string;
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label,int data)
//-----------------------------------------------------------------
: m_Label(label),m_Items(0)
{
    char buffer[60];
    sprintf(buffer,"%hd",data);
	m_Data=buffer;
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label,long data)
//-----------------------------------------------------------------
: m_Label(label),m_Items(0)
{
    char  buffer[60];
    sprintf(buffer,"%ld",data);
	m_Data=buffer;
}
//-----------------------------------------------------------------
skTreeNode::skTreeNode(const skString& label,float data)
//-----------------------------------------------------------------
: m_Label(label),m_Items(0)
{
    char  buffer[60];
    sprintf(buffer,"%f",data);
	m_Data=buffer;
}
//-----------------------------------------------------------------
skTreeNode& skTreeNode::operator=(const skTreeNode& node)
//-----------------------------------------------------------------
{
  if(&node!=this){
    m_Label=node.m_Label;
    m_Data=node.m_Data;
    delete m_Items;
    m_Items=0;
    if (node.m_Items)
    m_Items=new skTreeNodeList(*node.m_Items);
  }
  return * this;
}
//-----------------------------------------------------------------
void skTreeNode::boolData(bool b) 
//-----------------------------------------------------------------
{
  if (b==true)
    m_Data=true_string;
  else
    m_Data=false_string;
}
//-----------------------------------------------------------------
void skTreeNode::intData(int i) 
//-----------------------------------------------------------------
{
    char buffer[60];
    sprintf(buffer,"%hd",i);
    m_Data=buffer;
}
//-----------------------------------------------------------------
void skTreeNode::longData(long l)
//-----------------------------------------------------------------
{
    char buffer[60];
    sprintf(buffer,"%ld",l);
    m_Data=buffer;
}
//-----------------------------------------------------------------
void skTreeNode::floatData(float f)
//-----------------------------------------------------------------
{
    char buffer[60];
    sprintf(buffer,"%f",f);
    m_Data=buffer;
}
//-----------------------------------------------------------------
bool skTreeNode::boolData() const
//-----------------------------------------------------------------
{
    return (bool)(m_Data==true_string);
}
//-----------------------------------------------------------------
void skTreeNode::clear()
//-----------------------------------------------------------------
{
  if (m_Items)
    m_Items->clear();
}
//-----------------------------------------------------------------
void skTreeNode::copyItems(skTreeNode& node)
//-----------------------------------------------------------------
{
  delete m_Items;
  m_Items=0;
  if (node.m_Items)
    m_Items=new skTreeNodeList(*node.m_Items);
}
//-----------------------------------------------------------------
void skTreeNode::moveItemsFrom(skTreeNode& node)
//-----------------------------------------------------------------
{
  if (m_Items)
    m_Items->clearAndDestroy();
  else
    m_Items=new skTreeNodeList;
  skTreeNodeListIterator iter(node);
  skTreeNode * item=0;
  while ((item=iter()))
    m_Items->append(item);
  // make sure these items are not stored twice
  node.m_Items->clear();
}
//-----------------------------------------------------------------
USize skTreeNode::numChildren() const
//-----------------------------------------------------------------
{
  USize entries=0;
  if (m_Items)
    entries=m_Items->entries();
  return entries;
}
//-----------------------------------------------------------------
skTreeNode * skTreeNode::nthChild(USize  i) const
//-----------------------------------------------------------------
{
  skTreeNode * node=0;
  if (m_Items)
    node=(*m_Items)[i];
  return node;
}
//-----------------------------------------------------------------
skTreeNodeListIterator::skTreeNodeListIterator(const skTreeNode& l)
//-----------------------------------------------------------------
: m_Node(l),m_Index(0)
{
}
//-----------------------------------------------------------------
skTreeNodeListIterator::~skTreeNodeListIterator()
//-----------------------------------------------------------------
{
}
//-----------------------------------------------------------------
void skTreeNodeListIterator::reset()
//-----------------------------------------------------------------
{
  m_Index=0;
}
//-----------------------------------------------------------------
skTreeNode * skTreeNodeListIterator::operator ()()
//-----------------------------------------------------------------
{
  skTreeNode * node=0;
  if (m_Index<m_Node.numChildren())
    node=m_Node.nthChild(m_Index++);
  return node;
}
//-----------------------------------------------------------------
skTreeNodeList::~skTreeNodeList()
//-----------------------------------------------------------------
{
  clearAndDestroy();
}   
//-----------------------------------------------------------------
skString skTreeNode::label() const
//-----------------------------------------------------------------
{
    return m_Label;
}
//-----------------------------------------------------------------
void skTreeNode::label(const skString& s) 
//-----------------------------------------------------------------
{
    m_Label=s;
}
//-----------------------------------------------------------------
skString skTreeNode::data() const
//-----------------------------------------------------------------
{
    return m_Data;
}
//-----------------------------------------------------------------
void skTreeNode::data(const skString& t) 
//-----------------------------------------------------------------
{
    m_Data=t;
}
//-----------------------------------------------------------------
void skTreeNode::setChild(skTreeNode* child)
//-----------------------------------------------------------------
{              
  skTreeNode * existing=findChild(child->label());
  if (existing){
    existing->data(child->data());
    existing->copyItems(*child);
    delete child;
  }else
    addChild(child);
}
//-----------------------------------------------------------------
void skTreeNode::prependChild(skTreeNode* child)
//-----------------------------------------------------------------
{              
  assert(child!=this);
  if (child!=this){
    if (m_Items==0)
      m_Items=new skTreeNodeList;
    m_Items->prepend(child);
  }
}
//-----------------------------------------------------------------
void skTreeNode::addChild(skTreeNode* child)
//-----------------------------------------------------------------
{              
  assert(child!=this);
  if (child!=this){
    if (m_Items==0)
      m_Items=new skTreeNodeList;
    m_Items->append(child);
  }
}
//-----------------------------------------------------------------
void skTreeNode::deleteChild(skTreeNode* child)
//-----------------------------------------------------------------
{
  if (m_Items){
    m_Items->remove(child);
    delete child;
  }else{
    assert("deleteChild: error, node has no children!"==0);
  }
}
//-----------------------------------------------------------------
int  skTreeNode::intData() const
//-----------------------------------------------------------------
{
    return (int)atoi((const char *)m_Data);
}
//-----------------------------------------------------------------
long skTreeNode::longData() const
//-----------------------------------------------------------------
{
    return atol((const char *)m_Data);
}
//-----------------------------------------------------------------
float skTreeNode::floatData() const
//-----------------------------------------------------------------
{
    return (float)atof((const char *)m_Data);
}
//-----------------------------------------------------------------
skString 	skTreeNode::nthChildData(USize index) const
//-----------------------------------------------------------------
{
  skTreeNode * pchild=nthChild(index);
  if (pchild)
    return pchild->data();
  else
    return skString(); 
}
//-----------------------------------------------------------------
int skTreeNode::nthChildIntData(USize index) const
//-----------------------------------------------------------------
{
  skTreeNode * pchild=nthChild(index);
  if (pchild)
    return pchild->intData();
  else
    return 0;	
}
//-----------------------------------------------------------------
skString skTreeNode::findChildData(const skString& label, const skString& defaultVal) const
//-----------------------------------------------------------------
{             
  skString s = defaultVal;
  skTreeNode * pchild=findChild(label);
  if (pchild)
    s=pchild->data();
  return s;
}
//-----------------------------------------------------------------
bool skTreeNode::findChildboolData(const skString& label,bool defaultVal) const
//-----------------------------------------------------------------
{               
  bool ret=defaultVal;
  skTreeNode * pchild=findChild(label);
  if (pchild)
    ret=pchild->boolData();
  return ret;	
}
//-----------------------------------------------------------------
int skTreeNode::findChildIntData(const skString& label,int defaultVal) const
//-----------------------------------------------------------------
{               
  int ret=defaultVal;
  skTreeNode * pchild=findChild(label);
  if (pchild)
    ret=pchild->intData();
  return ret;	
}
//-----------------------------------------------------------------
float skTreeNode::findChildFloatData(const skString& label,float defaultVal) const
//-----------------------------------------------------------------
{               
  float ret=defaultVal;
  skTreeNode * pchild=findChild(label);
  if (pchild)
    ret=pchild->floatData();
  return ret;	
}
//-----------------------------------------------------------------
long skTreeNode::findChildLongData(const skString& label,long defaultVal) const
//-----------------------------------------------------------------
{             
  long ret=defaultVal;
  skTreeNode * pchild=findChild(label);
  if (pchild)
    ret=pchild->longData();
  return ret;	
}
//-----------------------------------------------------------------
skTreeNode* skTreeNode::findChild(const skString& label) const
//-----------------------------------------------------------------
{                   
  skTreeNode * node=0;
  if (m_Items)
    node=m_Items->findItem(label);
  return node;
}
//-----------------------------------------------------------------
skTreeNode* skTreeNode::findChild(const skString& label,const skString& data) const
//-----------------------------------------------------------------
{
  skTreeNode * node=0;
  if (m_Items)
    node=m_Items->findItem(label,data);
  return node;
}
//-----------------------------------------------------------------
void writeTabs(ostream& out,int tabstops)
//-----------------------------------------------------------------
{
    for (int i=0;i<tabstops;i++)
        out << '\t';
}
//-----------------------------------------------------------------
bool skTreeNode::write(const skString& s) const
//-----------------------------------------------------------------
{   
  bool bRet=false;
  ofstream o(s);
  if (o.good()){
    write(o,0);
    if (o.good())
      bRet=true;
  }
  return bRet;	
}
//-----------------------------------------------------------------
void skTreeNode::write(ostream& out,USize tabstops) const
//-----------------------------------------------------------------
{

  writeTabs(out,tabstops);
  out << m_Label;
  const char * databuffer=m_Data;
  int datalen=strlen(databuffer);
  if (datalen)
	out << " [" << databuffer << "]";
  if (numChildren()){
    out << "\n";
    writeTabs(out,tabstops);
    out << "{\n";
    skTreeNodeListIterator iter(*this);
    skTreeNode * pnode=0;
    while ((pnode=iter())!=0)
      pnode->write(out,tabstops+1);
    writeTabs(out,tabstops);
    out << "}";
  }
  out << "\n";
}
//-----------------------------------------------------------------
skTreeNode * skTreeNode::read(const skString& s)
//-----------------------------------------------------------------
{
  skTreeNode * pnode=0;
#ifdef __MWERKS__
  ifstream i(s,ios::in|ios::binary);
#else
  ifstream i(s,ios::in|ios::nocreate|ios::binary);
#endif
  if (i.good()){
    skTreeNodeReader r(i,s);
    pnode=r.read();
  }
  return pnode;	
}
#ifdef USECLASSBUFFER
unsigned char P_TreeNodeReader::g_ClassLexText[MAXBUFFER];
bool	P_TreeNodeReader::g_LexTextUsed=false;
//	an optimization reusing the same buffer, but costs extra memory
#endif
//-----------------------------------------------------------------
skTreeNodeReader::skTreeNodeReader(istream& in)
//-----------------------------------------------------------------
{
    pimp=new P_TreeNodeReader(in);
    pimp->m_Error=false;
    pimp->grabBuffer();
}
//-----------------------------------------------------------------
void P_TreeNodeReader::grabBuffer()
//-----------------------------------------------------------------
{
#ifdef USECLASSBUFFER
  if (P_TreeNodeReader::g_LexTextUsed==false){
    P_TreeNodeReader::g_LexTextUsed=true;
    m_UsingClassLexText=true;
    m_LexText=g_ClassLexText;
  }else
#endif
    m_LexText=new unsigned char[MAXBUFFER];
}
//-----------------------------------------------------------------
skTreeNodeReader::skTreeNodeReader(istream& in,const char * fileName)
//-----------------------------------------------------------------
{
  pimp=new P_TreeNodeReader(in);
  pimp->m_Error=false;
  pimp->m_FileName=fileName;
  pimp->grabBuffer();
}
//-----------------------------------------------------------------
skTreeNodeReader::~skTreeNodeReader()
//-----------------------------------------------------------------
{
  if (pimp->m_UsingClassLexText==false)
    delete [] pimp->m_LexText;
#ifdef USECLASSBUFFER
  else	
    P_TreeNodeReader::g_LexTextUsed=false;
#endif
  delete pimp;
}
//-----------------------------------------------------------------
P_TreeNodeReader::P_TreeNodeReader(istream& in)
//-----------------------------------------------------------------
: m_In(in),m_UnLex(0),m_LastLexeme(L_EOF),m_Pos(0), m_UsingClassLexText(false)
{
}
//-----------------------------------------------------------------
void P_TreeNodeReader::addToLexText(unsigned char c)
//-----------------------------------------------------------------
{
    if (m_Pos<MAXBUFFER-1)
        m_LexText[m_Pos++]=c;
}
//-----------------------------------------------------------------
void P_TreeNodeReader::unLex()
//-----------------------------------------------------------------
{
    m_UnLex=1;
}
//-----------------------------------------------------------------
void P_TreeNodeReader::error(char * msg)
//-----------------------------------------------------------------
{
  m_Error=true;
  // cut the skString down a bit
  m_LexText[50]=0;
}
//-----------------------------------------------------------------
skTreeNode * skTreeNodeReader::read()
//-----------------------------------------------------------------
{       
  skTreeNode * pret=0;
  pimp->m_LineNum=0;
  pret=pimp->parseTreeNode(0);

  if (pimp->m_Error){
    delete pret;
    pret=0;
    throw skTreeNodeReaderException(pimp->m_FileName,pimp->m_LexText);
  }
  return pret;	
}
//-----------------------------------------------------------------
skTreeNode * P_TreeNodeReader::parseTreeNode(skTreeNode * pparent)
//-----------------------------------------------------------------
{                          
  skTreeNode * pnode=new skTreeNode;
  if (pparent)
    pparent->addChild(pnode);
  Lexeme lexeme=lex();
  switch(lexeme){
  case L_ERROR:
    break;
  case L_IDENT:
    pnode->label(m_LexText);
    lexeme=lex();
    switch (lexeme){
    case L_ERROR:
      break;
    case L_IDENT:
      unLex();
      break;
    case L_TEXT:
      pnode->data(m_LexText);
      lexeme=lex();
      switch (lexeme){
      case L_TEXT:
      case L_IDENT:
	unLex();
	break;
      case L_LBRACE:
	parseTreeNodeList(pnode);
	break;
      case L_RBRACE:
	if (pparent)
	  unLex();
	else
	  error("Unexpected right brace parsing text after label - no parent node");
	break;
      }
      break;
    case L_LBRACE:
      parseTreeNodeList(pnode);
      break;
    case L_RBRACE:
      if (pparent)
	unLex();
      else
	error("Unexpected right brace parsing after label - no parent node");
      break;
    }
    break;
  case L_TEXT:
    pnode->data(m_LexText);
    lexeme=lex();
    switch (lexeme){
    case L_ERROR:
      break;
    case L_IDENT:
    case L_TEXT:
      unLex();
      break;
    case L_LBRACE:
      parseTreeNodeList(pnode);
      break;
    case L_RBRACE:
      if (pparent)
	unLex();
      else
	error("Unexpected right brace parsing text with no label - no parent node");
      break;
    }
    break;
  case L_LBRACE:
    parseTreeNodeList(pnode);
    break;
  case L_RBRACE:
    if (pparent)
      unLex();
    else
      error("Unexpected right brace parsing sublist with no label or text - no parent node");
    break;
  }
  return pnode;
}
//-----------------------------------------------------------------
void P_TreeNodeReader::parseTreeNodeList(skTreeNode * pnode)
//-----------------------------------------------------------------
{
  int loop=1;
  do{
    Lexeme lexeme=lex();
    switch(lexeme){
    case L_IDENT:
    case L_TEXT:
    case L_LBRACE:
      unLex();
      parseTreeNode(pnode);
      break;
    case L_EOF:
      error("Expected right brace parsing sub-list");
    case L_ERROR:
    case L_RBRACE:
      loop=0;
    }
  }while (loop && m_Error==false);
}
//-----------------------------------------------------------------
P_TreeNodeReader::Lexeme P_TreeNodeReader::lex()
//-----------------------------------------------------------------
{
  if (m_UnLex)
    m_UnLex=0;
  else{
    m_Pos=0;
    int c;
    int loop=1;
    while (loop && !m_In.eof() && m_Error==false){
      c=m_In.get();
      if (c=='\n')
	m_LineNum++;
      switch (c){
      case '{':
	addToLexText((unsigned char)c);
	m_LastLexeme=L_LBRACE;
	loop=0;
	break;
      case '}':
	addToLexText((unsigned char)c);
	m_LastLexeme=L_RBRACE;
	loop=0;
	break;
      case EOF:
	m_LastLexeme=L_EOF;
	loop=0;
	break;
      case '[':{
	int textloop=1;
	int num_braces=1;
	m_LastLexeme=L_TEXT;
	while(textloop && !m_In.eof()){
	  c=m_In.get();
	  switch(c){
	  case EOF:
	    m_LastLexeme=L_ERROR;
	    error("Expected EOF in text string");
	    textloop=0;
	    break;
	  case '\\':
	    // let any character through
	    c=m_In.get();
	    addToLexText((unsigned char)c);
	    break;
	  case '[':
	    num_braces++;
	    addToLexText((unsigned char)c);
	    break;
	  case ']':
	    num_braces--;
	    if (num_braces==0)
	      textloop=0;
	    else
	      addToLexText((unsigned char)c);
	    break;
	  default:
	      addToLexText((unsigned char)c);
	  }
	}
	loop=0;
	break;	
      }
      case '/':
      case '.':
      case '\\':
      case '~':
      case '_':
      case '-':
      case ':':
      default:
	if (c==':' || c=='-' || c=='.' || c=='/' || c=='\\' || c=='_' || c=='~' || isalnum(c)){
	  m_LastLexeme=L_IDENT;
	  addToLexText((unsigned char)c);
	  int identloop=1;
	  while (identloop && !m_In.eof())
	    if (isalnum(m_In.peek()) || m_In.peek()=='\\' 
		|| m_In.peek()=='_' || m_In.peek()=='~' || m_In.peek()=='-' 
		|| m_In.peek()=='/' || m_In.peek()=='.' || m_In.peek()==':'){
	      c=m_In.get();
	      addToLexText((unsigned char)c);
	    }else
	      identloop=0;
	  loop=0;	
	}else
	  if (!isspace(c)){
	    m_LastLexeme=L_ERROR;
	    error("Expected ~ _ or alpha numeric character");
	    loop=0;	
	  }
      }
    }
    m_LexText[m_Pos]=0;
  }
  return m_LastLexeme;
}
//-----------------------------------------------------------------
bool skTreeNode::containsChild(skTreeNode* child)
//-----------------------------------------------------------------
{
  bool bRet=false;
  if (m_Items)
    bRet=m_Items->contains(child);
  return bRet;
}
