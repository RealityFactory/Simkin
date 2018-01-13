/*
  Copyright 1996-2001
  Simon Whiteside

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  $Id: skElementObject.cpp,v 1.4 2001/11/22 11:13:21 sdw Exp $
*/

#include "skStringTokenizer.h"
#include "skElementObject.h"
#include "skElementObjectEnumerator.h"
#include "skRValueArray.h"
#include "skElement.h"
#include "skMethodTable.h"
#include "skInterpreter.h"
#include "skTextNode.h"

xskLITERAL(true);

skLITERAL(function);
skLITERAL(name);

//------------------------------------------
skElementObject::skElementObject(const skString& scriptLocation,skElement * elem,bool created)
  //------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  m_Element=elem;
  m_MethodCache=0;
  m_AddIfNotPresent=false;
  m_Created=created;
}
//------------------------------------------
skElementObject::skElementObject()
  //------------------------------------------
{
  m_MethodCache=0;
  m_AddIfNotPresent=false;
}
//------------------------------------------
skElementObject::~skElementObject()
  //------------------------------------------
{
  if (m_Created)
    delete m_Element;
  delete m_MethodCache;
}
//------------------------------------------
void skElementObject::setElement(skElement * elem)
  //------------------------------------------
{
  m_Element=elem;
  delete m_MethodCache;
  m_MethodCache=0;
}
//------------------------------------------
int skElementObject::executableType() const
  //------------------------------------------
{
  return ELEMENT_TYPE;
}
//------------------------------------------
int skElementObject::intValue() const
  //------------------------------------------
{
  return getData(m_Element).to();
}
//------------------------------------------
float skElementObject::floatValue() const
  //------------------------------------------
{
  return getData(m_Element).toFloat();
}
//------------------------------------------
bool skElementObject::boolValue() const
  //------------------------------------------
{
  bool ret=false;
  skString value=getData(m_Element);
  if (value==s_true)
    ret=true;
  return ret;
}
//------------------------------------------
Char skElementObject::charValue() const
  //------------------------------------------
{
  skString value=getData(m_Element);
  return value.at(0);
}
//------------------------------------------
skString skElementObject::strValue() const
  //------------------------------------------
{
  return getData(m_Element);
}
//------------------------------------------
bool skElementObject::setValueAt(const skRValue& array_index,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  skiExecutable * other=0;
  bool otherIs=false;
  if (v.type()==skRValue::T_Object){
    other=v.obj();
    if (other!=0 && other->executableType()==ELEMENT_TYPE)
      otherIs=true;
  }
  int index=array_index.intValue();
  skElement * child=m_Element;
  child=findChild(m_Element,index);
  if (child==0){
    if (m_AddIfNotPresent){
      child=new skElement(skSTR("array_element"));
      m_Element->appendChild(child);
    }else
      bRet=false;
  }
  if (child){
    if (otherIs)
      ((skElementObject *)other)->copyItemsInto(child);
    else
      if (attrib.length()==0)
	setData(child,v.str());
      else
	child->setAttribute(attrib,v.str());
  }
  if (bRet==false)
    bRet=skExecutable::setValueAt(array_index,attrib,v);
  return bRet;
}
//------------------------------------------
bool skElementObject::setValue(const skString& name,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  skiExecutable * other=0;
  bool otherIs=false;
  if (v.type()==skRValue::T_Object){
    other=v.obj();
    if (other!=0 && other->executableType()==ELEMENT_TYPE)
      otherIs=true;
  }
  skElement * child=m_Element;
  if (name.length()>0)
    child=findChild(m_Element,name);
  if (child==0){
    if (m_AddIfNotPresent){
      child=new skElement(name);
      m_Element->appendChild(child);
    }else
      bRet=false;
  }
  if (child){
    if (otherIs)
      ((skElementObject *)other)->copyItemsInto(child);
    else
      if (attrib.length()==0)
	setData(child,v.str());
      else
	child->setAttribute(attrib,v.str());
  }
  if (bRet==false)
    bRet=skExecutable::setValue(name,attrib,v);
  return bRet;
}
//------------------------------------------
void skElementObject::copyItemsInto(skElement * other)
  //------------------------------------------
{
  // first clear the other node
  skNodeList& nodes=other->getChildNodes();
  while (nodes.entries() > 0)
    other->removeAndDestroyChild(nodes[0]);  
  if (m_Element){
    // now copy our nodes in
    skNodeList& our_nodes=m_Element->getChildNodes();
    if (our_nodes.entries()>0){
      int numNodes=our_nodes.entries();
      for (int i=0;i<numNodes;i++)
	  other->appendChild(our_nodes[i]->clone());
    }
  }
}
//------------------------------------------
skElement * skElementObject::getElement()
  //------------------------------------------
{
  return m_Element;
}
//------------------------------------------
bool skElementObject::getValueAt(const skRValue& array_index,const skString& attribute,skRValue& value)
  //------------------------------------------
{
  bool bRet=true;
  int index=array_index.intValue();
  skElement * child=findChild(m_Element,index);
  if (child==0){
    if (m_AddIfNotPresent){
      child=new skElement(skSTR("array_element"));
      m_Element->appendChild(child);
    }else
      bRet=false;
  }
  if (child){
    if (attribute.length()==0)
      value=skRValue(createElementObject(m_ScriptLocation+"["+skString::from(index)+"]",child,false),true);
    else{
      value=skRValue(child->getAttribute(attribute));
    }
  }else
    bRet=skExecutable::getValueAt(array_index,attribute,value);
  return bRet;
}
//------------------------------------------
skElementObject * skElementObject::createElementObject(const skString& location,skElement * element,bool created)
//------------------------------------------
{
  skElementObject * obj= new skElementObject(location,element,created);
  obj->setAddIfNotPresent(getAddIfNotPresent());
  return obj;
}
//------------------------------------------
bool skElementObject::getValue(const skString& name,const skString& attrib,skRValue& v) 
  //------------------------------------------
{
  bool bRet=true;
  skElement * child=m_Element;
  if (name == "nodename"){
    v=m_Element->getTagName();
  }else if (name == "numChildren"){
    v=countChildren(m_Element);
  }else{
    if (name.length()>0){
      child=findChild(m_Element,name);
      if (child==0){
	if (m_AddIfNotPresent){
	  child=new skElement(name);
	  m_Element->appendChild(child);
	}else
	  bRet=false;
      }
    }
    if (child){
      if (attrib.length()==0)
	v=skRValue(createElementObject(m_ScriptLocation+":"+name,child,false),true);
      else{
	v=skRValue(child->getAttribute(attrib));
      }
    }else
      bRet=skExecutable::getValue(name,attrib,v);
  }
  return bRet;
}
//------------------------------------------
skString skElementObject::getData(skElement * element)
  //------------------------------------------
{
  skString str="";
  skNodeList& nodes=element->getChildNodes();
  for (unsigned int i=0;i<nodes.entries();i++){
    skNode * node=nodes[i];
    skNode::NodeType type=node->getNodeType();
    if (type==skNode::CDATA_SECTION_NODE || type==skNode::TEXT_NODE)
      str+=node->getNodeValue();
  }
  return str;
}
//------------------------------------------
void skElementObject::setData(skElement * element,const skString& data)
  //------------------------------------------
{
  skNodeList& nodes=element->getChildNodes();
  bool found=false;
  for (unsigned int i=0;i<nodes.entries();i++){
    skNode * node=nodes[i];
    skNode::NodeType type=node->getNodeType();
    if (type==skNode::CDATA_SECTION_NODE || type==skNode::TEXT_NODE){
      node->setNodeValue(data);
      found=true;
      break;
    }
  }
  if (found==false){
    element->appendChild(new skTextNode(data));
  }
}
//------------------------------------------
skElement * skElementObject::findChild(skElement * parent,int index)
  //------------------------------------------
{
  skElement * ret=0;
  if (parent){
    skNodeList& nodes=parent->getChildNodes();
    if (index<nodes.entries()){
      int element_count=0;
      for (unsigned int i=0;i<nodes.entries();i++){
	skNode * node=nodes[i];
	if (node->getNodeType()==skNode::ELEMENT_NODE){
	  if (element_count==index){
	    ret=(skElement *)node;
	    break;
	  }else
	    element_count++;
	}
      }
    }
  }
  return ret;
}
//------------------------------------------
int skElementObject::countChildren(skElement * parent)
  //------------------------------------------
{
  int count=0;
  if (parent){
    skNodeList& nodes=parent->getChildNodes();
    for (unsigned int i=0;i<nodes.entries();i++){
      skNode * node=nodes[i];
      if (node->getNodeType()==skNode::ELEMENT_NODE){
	count++;
      }
    }
  }
  return count;
}
//------------------------------------------
skElement * skElementObject::findChild(skElement * parent,const skString& tagname)
  //------------------------------------------
{
  skElement * ret=0;
  if (parent){
    skNodeList& nodes=parent->getChildNodes();
    for (unsigned int i=0;i<nodes.entries();i++){
      skNode * node=nodes[i];
      if (node->getNodeType()==skNode::ELEMENT_NODE && ((skElement * )node)->getTagName()==tagname){
	ret=(skElement *)node;
	break;
      }
    }
  }
  return ret;
}
//------------------------------------------
skElement * skElementObject::findChild(skElement * parent,const skString& tagname,const skString& attribute,const skString& value)
  //------------------------------------------
{
  skElement * ret=0;
  if (parent){
    skNodeList& nodes=parent->getChildNodes();
    for (unsigned int i=0;i<nodes.entries();i++){
      skNode * node=nodes[i];
      skNode::NodeType type=node->getNodeType();
      if (type==skNode::ELEMENT_NODE)
	if (((skElement *) node)->getTagName()==tagname){
	  skElement * thisElement=(skElement *)node;
	  if (thisElement->getAttribute(attribute)==value){
	    ret=thisElement;
	    break;
	  }
	}
    }
  }
  return ret;
}
//------------------------------------------
void skElementObject::setAttribute(skString name,const skString& value)
  //------------------------------------------
{
  m_Element->setAttribute(name,value);
}
//------------------------------------------
skString skElementObject::getAttribute(const skString& name)
  //------------------------------------------
{
  return m_Element->getAttribute(name);
}
//------------------------------------------
bool skElementObject::method(const skString& s,skRValueArray& args,skRValue& ret)  
  //------------------------------------------
{
  bool bRet=false;
  if (s=="containsElement"){
    bRet=true;
    skElement * child=findChild(m_Element,args[0].str());
    if (child)
      ret=true;
    else
      ret=false;
  }else if (s=="addElement"){
    bRet=true;
    m_Element->appendChild(new skElement(args[0].str()));
  }else if (s=="tagName"){
    bRet=true;
    ret=m_Element->getTagName();
  }else if (s==("dump")){
    bRet=true;
    cout << m_Element;
  }else if (s=="enumerate" && (args.entries()==0 || args.entries()==1)){
    // return an enumeration object for this element
    bRet=true;
    if (args.entries()==0)
      ret=skRValue(new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation()),true);
    else
      ret=skRValue(new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation(),args[0].str()),true);
  }else{
    skString location=m_ScriptLocation+":"+s;
    if (m_Element){
      skMethodDefNode * methNode=0;
      if (m_MethodCache!=0)
	methNode=m_MethodCache->value(&s);
      if (methNode==0){
	// no parse tree found in the cache - try and construct a new one
	skElement * node=skElementObject::findChild(m_Element,s_function,s_name,s);
	if (node){
	  // we found some  with the script in - now parse it
	  skString code=skElementObject::getData(node);
	  bRet=true;
	  skString params=node->getAttribute(skSTR("params"));
	  skStringList paramList;
	  skStringTokenizer tokenizer(params,", ");
	  while (tokenizer.hasMoreTokens())
	    paramList.append(tokenizer.nextToken());
	  skInterpreter::getInterpreter()->executeStringExternalParams(location,this,paramList,code,args,ret,&methNode);
	  if (methNode){
	    if (m_MethodCache==0)
	      m_MethodCache=new skMethodTable();
	    m_MethodCache->insertKeyAndValue(new skString(s),methNode);
	  }
	}else
	  bRet=skExecutable::method(s,args,ret);
      }else{	
	skInterpreter::getInterpreter()->executeParseTree(location,this,methNode,args,ret);
	bRet=true;
      }
    }else
      bRet=skExecutable::method(s,args,ret);
  }
  return bRet;
}
//------------------------------------------
skElementObject::skElementObject(const skElementObject& other)
  //------------------------------------------
{
}
//------------------------------------------
skElementObject& skElementObject::operator=(const skElementObject& other)
  //------------------------------------------
{
  return *this;
}
//------------------------------------------
skString skElementObject::getLocation() const
  //------------------------------------------
{
  return m_ScriptLocation;
}
//------------------------------------------
void skElementObject::setAddIfNotPresent(bool enable)
//------------------------------------------
{
  m_AddIfNotPresent=enable;
}
//------------------------------------------
bool skElementObject::getAddIfNotPresent()
//------------------------------------------
{
  return m_AddIfNotPresent;
}
//------------------------------------------
skExecutableIterator * skElementObject::createIterator(const skString& qualifier)
//------------------------------------------
{
  return new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation(),qualifier);
}
//------------------------------------------
skExecutableIterator * skElementObject::createIterator()
//------------------------------------------
{
  return new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation());
}
