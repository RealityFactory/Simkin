/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skXMLElementObject.cpp,v 1.19 2001/05/14 09:27:40 sdw Exp $
*/

#include "skStringTokenizer.h"
#include "skXMLElementObject.h"
#include "skXMLElementObjectEnumerator.h"
#include "dom/DOMString.hpp"
#include "dom/DOM_NodeList.hpp"
#include "dom/DOM_CharacterData.hpp"
#include "skRValueArray.h"
#include "skXMLElement.h"
#include "skMethodTable.h"
#include "skInterpreter.h"

static skString s_true="true";

#include "dom/DOM_NamedNodeMap.hpp"
ostream& operator<<(ostream& target, const DOMString& toWrite);
LITERAL(function);
LITERAL(name);

//------------------------------------------
skXMLElementObject::skXMLElementObject(const skString& scriptLocation,DOM_Element elem)
  //------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  m_Element=elem;
  m_MethodCache=0;
}
//------------------------------------------
skXMLElementObject::skXMLElementObject()
  //------------------------------------------
{
  m_MethodCache=0;
}
//------------------------------------------
skXMLElementObject::~skXMLElementObject()
  //------------------------------------------
{
  delete m_MethodCache;
}
//------------------------------------------
void skXMLElementObject::setElement(DOM_Element elem)
  //------------------------------------------
{
  m_Element=elem;
  delete m_MethodCache;
  m_MethodCache=0;
}
//------------------------------------------
int skXMLElementObject::executableType() const
  //------------------------------------------
{
  return XMLELEMENT_TYPE;
}
//------------------------------------------
int skXMLElementObject::intValue() const
  //------------------------------------------
{
  return getData(m_Element).to();
}
//------------------------------------------
float skXMLElementObject::floatValue() const
  //------------------------------------------
{
  return getData(m_Element).toFloat();
}
//------------------------------------------
bool skXMLElementObject::boolValue() const
  //------------------------------------------
{
  bool ret=false;
  skString value=getData(m_Element);
  if (value==s_true)
    ret=true;
  return ret;
}
//------------------------------------------
char skXMLElementObject::charValue() const
  //------------------------------------------
{
  skString value=getData(m_Element);
  return value.at(0);
}
//------------------------------------------
skString skXMLElementObject::strValue() const
  //------------------------------------------
{
  return getData(m_Element);
}
//------------------------------------------
bool skXMLElementObject::setValueAt(const skRValue& array_index,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  skExecutable * other=0;
  bool otherIsXML=false;
  if (v.type()==skRValue::T_Object){
    other=v.obj();
    if (other!=0 && other->executableType()==XMLELEMENT_TYPE)
      otherIsXML=true;
  }
  int index=array_index.intValue();
  DOM_Element child=m_Element;
  child=findChild(m_Element,index);
  if (child.isNull())
    bRet=false;
  else{
    if (otherIsXML)
      ((skXMLElementObject *)other)->copyItemsInto(child);
    else
      if (attrib.length()==0)
	setData(child,v.str());
      else
	child.setAttribute(DOMString((const char *)attrib),DOMString((const char *)v.str()));
  }
  if (bRet==false)
    bRet=skExecutable::setValueAt(array_index,attrib,v);
  return bRet;
}
//------------------------------------------
bool skXMLElementObject::setValue(const skString& name,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  skExecutable * other=0;
  bool otherIsXML=false;
  if (v.type()==skRValue::T_Object){
    other=v.obj();
    if (other!=0 && other->executableType()==XMLELEMENT_TYPE)
      otherIsXML=true;
  }
  DOM_Element child=m_Element;
  if (name.length()>0)
    child=findChild(m_Element,name);
  if (child.isNull())
    bRet=false;
  else{
    if (otherIsXML)
      ((skXMLElementObject *)other)->copyItemsInto(child);
    else
      if (attrib.length()==0)
	setData(child,v.str());
      else
	child.setAttribute(DOMString((const char *)attrib),DOMString((const char *)v.str()));
  }
  if (bRet==false)
    bRet=skExecutable::setValue(name,attrib,v);
  return bRet;
}
//------------------------------------------
void skXMLElementObject::copyItemsInto(DOM_Element other)
  //------------------------------------------
{
  // first clear the other node
  DOM_NodeList nodes=other.getChildNodes();
  if (nodes.getLength()>0){
    int numNodes=nodes.getLength();
    // take a copy in case the list gets cleared as we go along
    DOM_NodeList theNodes(nodes);
    for (int i=0;i<numNodes;i++)
      other.removeChild(theNodes.item(i));
  }
  if (m_Element.isNull()==false){
    // now copy our nodes in
    nodes=m_Element.getChildNodes();
    if (nodes.getLength()>0){
      int numNodes=nodes.getLength();
      for (int i=0;i<numNodes;i++)
	other.appendChild(nodes.item(i).cloneNode(true));
    }
  }
}
//------------------------------------------
DOM_Element skXMLElementObject::getElement()
  //------------------------------------------
{
  return m_Element;
}
//------------------------------------------
bool skXMLElementObject::getValueAt(const skRValue& array_index,const skString& attribute,skRValue& value)
  //------------------------------------------
{
  bool bRet=true;
  int index=array_index.intValue();
  DOM_Element child=findChild(m_Element,index);
  if (child.isNull())
    bRet=false;
  if (bRet==true){
    if (attribute.length()==0)
      value=skRValue(new skXMLElementObject(m_ScriptLocation+"["+skString::from(index)+"]",child),true);
    else{
      DOMString attrName=fromString(attribute);
      DOMString attrValue=child.getAttribute(attrName);
      value=skRValue(toString(attrValue));
    }
  }else
    bRet=skExecutable::getValueAt(array_index,attribute,value);
  return bRet;
}
//------------------------------------------
bool skXMLElementObject::getValue(const skString& name,const skString& attrib,skRValue& v) 
  //------------------------------------------
{
  bool bRet=true;
  DOM_Element child=m_Element;
  if (name == "nodename"){
    v=toString(m_Element.getNodeName());
  }else if (name == "numChildren"){
    v=countChildren(m_Element);
  }else{
    if (name.length()>0){
      child=findChild(m_Element,name);
      if (child.isNull())
	bRet=false;
    }
    if (bRet==true){
      if (attrib.length()==0)
	v=skRValue(new skXMLElementObject(m_ScriptLocation+":"+name,child),true);
      else{
	DOMString attrName=fromString(attrib);
	DOMString attrValue=child.getAttribute(attrName);
	v=skRValue(toString(attrValue));
      }
    }else
      bRet=skExecutable::getValue(name,attrib,v);
  }
  return bRet;
}
//------------------------------------------
skString skXMLElementObject::getData(DOM_Element element)
  //------------------------------------------
{
  DOMString str="";
  DOM_NodeList nodes=element.getChildNodes();
  for (unsigned int i=0;i<nodes.getLength();i++){
    DOM_Node node=nodes.item(i);
    int type=node.getNodeType();
    if (type==DOM_Node::CDATA_SECTION_NODE || type==DOM_Node::TEXT_NODE)
      str+=node.getNodeValue();
  }
  return toString(str);
}
//------------------------------------------
void skXMLElementObject::setData(DOM_Element element,const skString& data)
  //------------------------------------------
{
  DOM_NodeList nodes=element.getChildNodes();
  bool found=false;
  for (unsigned int i=0;i<nodes.getLength();i++){
    DOM_Node node=nodes.item(i);
    int type=node.getNodeType();
    if (type==DOM_Node::CDATA_SECTION_NODE || type==DOM_Node::TEXT_NODE){
      node.setNodeValue(fromString(data));
      found=true;
      break;
    }
  }
  if (found==false){
    element.appendChild(element.getOwnerDocument().createTextNode(fromString(data)));
  }
}
//------------------------------------------
DOM_Element skXMLElementObject::findChild(DOM_Element parent,int index)
  //------------------------------------------
{
  DOM_Element ret;
  if (parent.isNull()==false){
    DOM_NodeList nodes=parent.getChildNodes();
    if (index<nodes.getLength()){
      int element_count=0;
      for (unsigned int i=0;i<nodes.getLength();i++){
	DOM_Node node=nodes.item(i);
	if (node.getNodeType()==DOM_Node::ELEMENT_NODE){
	  if (element_count==index){
	    ret=*(DOM_Element *)&node;
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
int skXMLElementObject::countChildren(DOM_Element parent)
  //------------------------------------------
{
  int count=0;
  if (parent.isNull()==false){
    DOM_NodeList nodes=parent.getChildNodes();
    for (unsigned int i=0;i<nodes.getLength();i++){
      DOM_Node node=nodes.item(i);
      if (node.getNodeType()==DOM_Node::ELEMENT_NODE){
	count++;
      }
    }
  }
  return count;
}
//------------------------------------------
DOM_Element skXMLElementObject::findChild(DOM_Element parent,const skString& tagname)
  //------------------------------------------
{
  DOM_Element ret;
  if (parent.isNull()==false){
    DOM_NodeList nodes=parent.getChildNodes();
    DOMString sTagName=fromString(tagname);
    for (unsigned int i=0;i<nodes.getLength();i++){
      DOM_Node node=nodes.item(i);
      if (node.getNodeType()==DOM_Node::ELEMENT_NODE && node.getNodeName().equals(sTagName)){
	ret=*(DOM_Element *)&node;
	break;
      }
    }
  }
  return ret;
}
//------------------------------------------
DOM_Element skXMLElementObject::findChild(DOM_Element parent,const skString& tagname,const skString& attribute,const skString& value)
  //------------------------------------------
{
  DOM_Element ret;
  if (parent.isNull()==false){
    DOM_NodeList nodes=parent.getChildNodes();
    DOMString sTagName=fromString(tagname);
    DOMString sValue=fromString(value);
    DOMString sAttribute=fromString(attribute);
    for (unsigned int i=0;i<nodes.getLength();i++){
      DOM_Node node=nodes.item(i);
      int type=node.getNodeType();
      DOMString nodeName=node.getNodeName();
      //    skString sNodeName=skString::fromBuffer((unsigned char *)(nodeName.transcode()));
      DOMString nodeValue=node.getNodeValue();
      //    skString sNodeValue=skString::fromBuffer((unsigned char *)(nodeValue.transcode()));
      if (type==DOM_Node::ELEMENT_NODE)
	if (nodeName.equals(sTagName)){
	  DOM_Element thisElement=*(DOM_Element *)&node;
	  if (thisElement.getAttribute(sAttribute).equals(sValue)){
	    ret=thisElement;
	    break;
	  }
	}
    }
  }
  return ret;
}
//------------------------------------------
void skXMLElementObject::setAttribute(skString name,const skString& value)
  //------------------------------------------
{
  m_Element.setAttribute(fromString(name),fromString(value));
}
//------------------------------------------
skString skXMLElementObject::getAttribute(const skString& name)
  //------------------------------------------
{
  return toString(m_Element.getAttribute(fromString(name)));
}
//------------------------------------------
bool skXMLElementObject::method(const skString& s,skRValueArray& args,skRValue& ret)  
  //------------------------------------------
{
  bool bRet=false;
  if (s=="containsElement"){
    bRet=true;
    DOM_Element child=findChild(m_Element,args[0].str());
    if (child.isNull()==false)
      ret=true;
    else
      ret=false;
  }else if (s=="addElement"){
    bRet=true;
    m_Element.appendChild(m_Element.getOwnerDocument().createElement(fromString(args[0].str())));
  }else if (s=="tagName"){
    bRet=true;
    ret=toString(m_Element.getNodeName());
  }else if (s==("dump")){
    bRet=true;
    cout << m_Element;
  }else if (s=="enumerate" && (args.entries()==0 || args.entries()==1)){
    // return an enumeration object for this element
    bRet=true;
    if (args.entries()==0)
      ret=skRValue(new skXMLElementObjectEnumerator(this),true);
    else
      ret=skRValue(new skXMLElementObjectEnumerator(this,args[0].str()),true);
  }else{
    skString location=m_ScriptLocation+":"+s;
    if (m_Element.isNull()==false){
      skMethodDefNode * methNode=0;
      if (m_MethodCache!=0)
	methNode=m_MethodCache->value(&s);
      if (methNode==0){
	// no parse tree found in the cache - try and construct a new one
	DOM_Element node=skXMLElementObject::findChild(m_Element,s_function,s_name,s);
	if (node.isNull()==false){
	  // we found some XML with the script in - now parse it
	  skString code=skXMLElementObject::getData(node);
	  bRet=true;
	  skString params=toString(node.getAttribute("params"));
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
// ---------------------------------------------------------------------------
//  ostream << DOM_Node   
//
//  Stream out a DOM node, and, recursively, all of its children. This
//  function is the heart of writing a DOM tree out as XML source. Give it
//  a document node and it will do the whole thing.
// ---------------------------------------------------------------------------
ostream& operator<<(ostream& target, DOM_Node& toWrite)
{
  // Get the name and value out for convenience
  DOMString   nodeName = toWrite.getNodeName();
  DOMString   nodeValue = toWrite.getNodeValue();
  unsigned long lent = nodeValue.length();
  
  switch (toWrite.getNodeType()){
  case DOM_Node::TEXT_NODE:
    target << nodeValue;break;
  case DOM_Node::ELEMENT_NODE :{
    target << "<" << nodeName;
    DOM_NamedNodeMap attributes = toWrite.getAttributes();
    int attrCount = attributes.getLength();
    for (int i = 0; i < attrCount; i++){
      DOM_Node  attribute = attributes.item(i);
      target << " " << attribute.getNodeName() << "=\"" << attribute.getNodeValue() << "\"";
    }
    DOM_Node child = toWrite.getFirstChild();
    if (child != 0){
      target << ">";
      while( child != 0){
	target << child;
	child = child.getNextSibling();
      }
      target << "</" << nodeName << ">";
    }else
      target << "/>";
  }
  break;        
  default:
    cerr << "Unrecognized node type = "
	 << (long)toWrite.getNodeType() << endl;
  }
  return target;
}
// ---------------------------------------------------------------------------
//  ostream << DOMString
//
//  Stream out a DOM string. Doing this requires that we first transcode
//  to char * form in the default code page for the system
// ---------------------------------------------------------------------------
ostream& operator<< (ostream& target, const DOMString& s)
{
  char *p = s.transcode();
  target << p;
  delete [] p;
  return target;
}
// ---------------------------------------------------------------------------
skString skXMLElementObject::toString(DOMString str)
  // ---------------------------------------------------------------------------
{
  // nb this now owns the buffer, but does not delete it
  return skString::fromBuffer((unsigned char *)str.transcode());
}
// ---------------------------------------------------------------------------
DOMString skXMLElementObject::fromString(const skString& str)
  // ---------------------------------------------------------------------------
{
  return DOMString((const char *)str);
}
//------------------------------------------
skXMLElementObject::skXMLElementObject(const skXMLElementObject& other)
  //------------------------------------------
{
}
//------------------------------------------
skXMLElementObject& skXMLElementObject::operator=(const skXMLElementObject& other)
  //------------------------------------------
{
  return *this;
}
//------------------------------------------
skString skXMLElementObject::getLocation() const
  //------------------------------------------
{
  return m_ScriptLocation;
}
