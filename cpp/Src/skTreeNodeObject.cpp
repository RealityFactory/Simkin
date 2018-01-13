/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skTreeNodeObject.cpp,v 1.14 2001/03/05 16:46:28 sdw Exp $
*/

#include "skTreeNodeObject.h"
#include "skTreeNode.h"
#include "skTreeNodeObjectEnumerator.h"
#include "skRValueArray.h"
#include "skInterpreter.h"
#include "skMethodTable.h"

//------------------------------------------
skTreeNodeObject::skTreeNodeObject()
//------------------------------------------
  : m_Node(0),m_Created(false),m_MethodCache(0)
{
}
//------------------------------------------
skTreeNodeObject::skTreeNodeObject(const skString& location,skTreeNode * node,bool created)
//------------------------------------------
  : m_Node(node),m_Created(created),m_Location(location),m_MethodCache(0)
{
}
//------------------------------------------
skTreeNodeObject::~skTreeNodeObject()
//------------------------------------------
{
  if (m_Created)
    delete m_Node;
  delete m_MethodCache;
}
//------------------------------------------
int	skTreeNodeObject::executableType() const
//------------------------------------------
{
  return TREENODE_TYPE;
}
//------------------------------------------
int	skTreeNodeObject::intValue() const
//------------------------------------------
{
  return m_Node->intData();
}
//------------------------------------------
float	skTreeNodeObject::floatValue() const
//------------------------------------------
{
  return m_Node->floatData();
}
//------------------------------------------
bool skTreeNodeObject::boolValue() const
//------------------------------------------
{
  return m_Node->boolData();
}
//------------------------------------------
char skTreeNodeObject::charValue() const
//------------------------------------------
{
  return m_Node->data().at(0);
}
//------------------------------------------
skString skTreeNodeObject::strValue() const
//------------------------------------------
{
  return m_Node->data();
}
//------------------------------------------
bool skTreeNodeObject::setValue(const skString& s,const skString& attrib,const skRValue& v)
//------------------------------------------
{
  bool bRet=false;
  skTreeNode * child=m_Node->findChild(s);
  if (child){
    bRet=true;
    skExecutable * other=v.obj();
    if (other && other->executableType()==TREENODE_TYPE)
      child->copyItems(*((skTreeNodeObject *)other)->m_Node);
    else
      child->data(v.str());
  }else
    bRet=skExecutable::setValue(s,attrib,v);
  return bRet;
}
/*
//------------------------------------------
bool skTreeNodeObject::equals(skExecutable * o) const
//------------------------------------------
{
  return (bool)(strValue()==o->strValue());
}
*/
//------------------------------------------
skTreeNode *	skTreeNodeObject::getNode()
//------------------------------------------
{
  return m_Node;
}
//------------------------------------------
void skTreeNodeObject::setNode(skTreeNode * n)
//------------------------------------------
{
  m_Node=n;
  delete m_MethodCache;
}
//------------------------------------------
bool skTreeNodeObject::getValue(const skString& s,const skString& attrib,skRValue& v)
//------------------------------------------
{
  bool bRet=false;
  skTreeNode * child=m_Node->findChild(s);
  if (child){
    bRet=true;
    v=skRValue(new skTreeNodeObject(m_Location+":"+s,child,false),true);
  }else
    bRet=skExecutable::getValue(s,attrib,v);
  return bRet;
}
//------------------------------------------
bool skTreeNodeObject::method(const skString& s,skRValueArray& args,skRValue& ret)
//------------------------------------------
{
  bool bRet=false;
  if (s=="enumerate" && (args.entries()==0 || args.entries()==1)){
    // return an enumeration object for this element
    bRet=true;
    if (args.entries()==0)
      ret=skRValue(new skTreeNodeObjectEnumerator(this),true);
    else
      ret=skRValue(new skTreeNodeObjectEnumerator(this,args[0].str()),true);
  }else{
    skString location=m_Location+":"+s;
    if (m_Node){
      skMethodDefNode * methNode=0;
      if (m_MethodCache!=0)
	methNode=m_MethodCache->value(&s);
      if (methNode==0){
	// if no parse tree is found - try and build one
	skTreeNode * func_node=0;
	func_node=m_Node->findChild(s);
	if (func_node){
	  bRet=true;
	  assert(skInterpreter::getInterpreter());
	  skInterpreter::getInterpreter()->executeString(location,this,func_node->data(),args,ret,&methNode);
	  if (methNode){
	    if (m_MethodCache==0)
	      m_MethodCache=new skMethodTable();
	    m_MethodCache->insertKeyAndValue(new skString(s),methNode);
	  }
	}else
	  bRet=skExecutable::method(s,args,ret);
      }else{
	// otherwise execute the parse tree immediately
	skInterpreter::getInterpreter()->executeParseTree(location,this,methNode,args,ret);
	bRet=true;
      }
    }else
      bRet=skExecutable::method(s,args,ret);
  }
  return bRet;
}
//------------------------------------------
skTreeNodeObject::skTreeNodeObject(const skTreeNodeObject& other)
//------------------------------------------
{
}
//------------------------------------------
skTreeNodeObject& skTreeNodeObject::operator=(const skTreeNodeObject& other)
//------------------------------------------
{
  return *this;
} 
//------------------------------------------
skString skTreeNodeObject::getLocation() const
//------------------------------------------
{
  return m_Location;
}

