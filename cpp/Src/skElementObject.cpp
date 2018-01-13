/*
  Copyright 1996-2003
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

  $Id: skElementObject.cpp,v 1.16 2003/02/24 19:59:48 simkin_cvs Exp $
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
static Char c_colon=':';
static skString s_colon=skSTR(":");

//------------------------------------------
skElementObject::skElementObject(const skString& scriptLocation,skElement * elem,bool created)
  //------------------------------------------
  : m_Element(0)
{
  m_ScriptLocation=scriptLocation;
  m_Created=created;
  m_Element=elem;
  m_MethodCache=0;
  m_AddIfNotPresent=false;
  m_Created=created;
}
//------------------------------------------
skElementObject::skElementObject()
  //------------------------------------------
{
  m_Element=0;
  m_MethodCache=0;
  m_AddIfNotPresent=false;
  m_Created=false;
}
//------------------------------------------
skElementObject::~skElementObject()
  //------------------------------------------
{
  delete m_MethodCache;
  if (m_Created)
    delete m_Element;
}
//------------------------------------------
void skElementObject::setElement(skElement * elem,bool created)
  //------------------------------------------
{
  if (m_Created)
    delete m_Element;
  delete m_MethodCache;
  m_MethodCache=0;
  m_Element=elem;
  m_Created=created;
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
  int i=0;
  if (m_Element)
    i=getData(m_Element).to();
  return i;
}
//------------------------------------------
float skElementObject::floatValue() const
  //------------------------------------------
{
  float f=0;
  if (m_Element)
    f=getData(m_Element).toFloat();
  return f;
}
//------------------------------------------
bool skElementObject::boolValue() const
  //------------------------------------------
{
  bool ret=false;
  if (m_Element){
    skString value=getData(m_Element);
    if (value==s_true)
      ret=true;
  }
  return ret;
}
//------------------------------------------
Char skElementObject::charValue() const
  //------------------------------------------
{
  Char c=0;
  if (m_Element){
    skString value=getData(m_Element);
    c=value.at(0);
  }
  return c;
}
//------------------------------------------
skString skElementObject::strValue() const
  //------------------------------------------
{
  skString data;
  if (m_Element)
    data=getData(m_Element);
  return data;
}
//------------------------------------------
bool skElementObject::setValueAt(const skRValue& array_index,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  if (m_Element){
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
        unsigned int num_children=countChildren(m_Element);
        if (index>=num_children){
          int num_to_add=index-num_children+1;
          for (int i=0;i<num_to_add;i++){
            child=new skElement(skSTR("array_element"));
            m_Element->appendChild(child);
          }
        }
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
  }else
    bRet=false;
  if (bRet==false)
    bRet=skExecutable::setValueAt(array_index,attrib,v);
  return bRet;
}
//------------------------------------------
bool skElementObject::setValue(const skString& name,const skString& attrib,const skRValue& v)
  //------------------------------------------
{
  bool bRet=true;
  if (m_Element){
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
  }else
    bRet=false;
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
  if (m_Element==0)
    m_Element=new skElement(other->getTagName());
  // now copy our nodes in
  skNodeList& our_nodes=m_Element->getChildNodes();
  if (our_nodes.entries()>0){
    int numNodes=our_nodes.entries();
    for (int i=0;i<numNodes;i++)
      other->appendChild(our_nodes[i]->clone());
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
  if (m_Element){
    int index=array_index.intValue();
    skElement * child=findChild(m_Element,index);
    if (child==0){
      if (m_AddIfNotPresent){
        unsigned int num_children=countChildren(m_Element);
        if (index>=num_children){
          int num_to_add=index-num_children+1;
          for (int i=0;i<num_to_add;i++){
            child=new skElement(skSTR("array_element"));
            m_Element->appendChild(child);
          }
        }
      }else
        bRet=false;
    }
    if (child){
      if (attribute.length()==0)
        value=skRValue(createElementObject(m_ScriptLocation+skSTR("[")+skString::from(index)+skSTR("]"),child,false),true);
      else{
        value=skRValue(child->getAttribute(attribute));
      }
    }
  }else
    bRet=false;
  if (bRet==false)
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
  if (m_Element){
    skElement * child=m_Element;
    if (name == skSTR("nodename")){
      v=m_Element->getTagName();
    }else if (name == skSTR("numChildren")){
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
          v=skRValue(createElementObject(m_ScriptLocation+s_colon+name,child,false),true);
        else{
          v=skRValue(child->getAttribute(attrib));
        }
      }
    }
  }else
    bRet=false;
  if (bRet==false)
    bRet=skExecutable::getValue(name,attrib,v);
  return bRet;
}
//------------------------------------------
skString skElementObject::getData(skElement * element)
  //------------------------------------------
{
  skString str;
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
  // This needs to be adjusted - the element may have multiple
  // sequential text nodes... these need to be replaced altogether.
  // So the first one will have its data set, and the rest will be deleted.
  // We don't want to delete while we are iterating, though. So add them to a list.
  skNodeList& nodes=element->getChildNodes();
  skNodeList nodesToRemove;
  bool found=false;
  unsigned int i=0;
  for (i=0;i<nodes.entries();i++){
    skNode * node=nodes[i];
    skNode::NodeType type=node->getNodeType();
    if (type==skNode::CDATA_SECTION_NODE || type==skNode::TEXT_NODE){
      if (!found) {			
        node->setNodeValue(data);
        found=true;
      } else {
        nodesToRemove.append(node);
      }
    }
  }
  if (found==false){
    element->appendChild(new skTextNode(data));
  } else {
    for (unsigned int j = 0; j < nodesToRemove.entries(); j++)
      element->removeChild(nodesToRemove[i]);
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
  if (m_Element)
    m_Element->setAttribute(name,value);
}
//------------------------------------------
skString skElementObject::getAttribute(const skString& name) const
  //------------------------------------------
{
  skString a;
  if (m_Element)
    a=m_Element->getAttribute(name);
  return a;
}
//------------------------------------------
bool skElementObject::method(const skString& s,skRValueArray& args,skRValue& ret,skExecutableContext& ctxt)  
  //------------------------------------------
{
  bool bRet=false;
  if (m_Element){
    if (s==skSTR("containsElement")){
      bRet=true;
      skElement * child=findChild(m_Element,args[0].str());
      if (child)
        ret=true;
      else
        ret=false;
    }else if (s==skSTR("addElement")){
      bRet=true;
      m_Element->appendChild(new skElement(args[0].str()));
    }else if (s==skSTR("tagName")){
      bRet=true;
      ret=m_Element->getTagName();
#ifdef STREAMS_ENABLED
    }else if (s==skSTR("dump")){
      bRet=true;
      cout << m_Element;
#endif
    }else if (s==skSTR("enumerate") && (args.entries()==0 || args.entries()==1)){
      // return an enumeration object for this element
      bRet=true;
      if (args.entries()==0)
        ret=skRValue(new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation()),true);
      else
        ret=skRValue(new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation(),args[0].str()),true);
    }else{
      skString location=m_ScriptLocation+s_colon+s;
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
            skStringTokenizer tokenizer(params,skSTR(", "));
            while (tokenizer.hasMoreTokens())
              paramList.append(tokenizer.nextToken());
            ctxt.getInterpreter()->executeStringExternalParams(location,this,paramList,code,args,ret,&methNode,ctxt);
            if (methNode){
              if (m_MethodCache==0)
                m_MethodCache=new skMethodTable();
              m_MethodCache->insertKeyAndValue(new skString(s),methNode);
            }
          }else
            bRet=skExecutable::method(s,args,ret,ctxt);
        }else{	
          ctxt.getInterpreter()->executeParseTree(location,this,methNode,args,ret,ctxt);
          bRet=true;
        }
      }
    }
  }else
    bRet=false;
  if (bRet==false)
    bRet=skExecutable::method(s,args,ret,ctxt);
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
void skElementObject::setLocation(const skString& loc) 
  //------------------------------------------
{
  m_ScriptLocation=loc;
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
  skExecutableIterator * iter=0;
  if (m_Element)
    iter=new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation(),qualifier);
  return iter;
}
//------------------------------------------
skExecutableIterator * skElementObject::createIterator()
//------------------------------------------
{
  skExecutableIterator * iter=0;
  if (m_Element)
    iter=new skElementObjectEnumerator(m_Element,m_AddIfNotPresent,getLocation());
  return iter;
}
//------------------------------------------
skString skElementObject::getSource(const skString& location)
//------------------------------------------
{
  skString src;
  if (m_Element){
    // extract the object name
    int index=location.indexOfLast(c_colon);
    skString name=location;
    if (index!=-1)
      name=location.substr(index+1);
    skElement * node=skElementObject::findChild(m_Element,s_function,s_name,name);
    if (node)
      src=skElementObject::getData(node);
  }
  return src;
}
//------------------------------------------
void skElementObject::getInstanceVariables(skRValueTable& table)
//------------------------------------------
{
  if (m_Element){
    skNodeList& nodes=m_Element->getChildNodes();
    for (unsigned int i=0;i<nodes.entries();i++){
      skNode * node=nodes[i];
      skNode::NodeType type=node->getNodeType();
      if (type==skNode::ELEMENT_NODE){
        skElement * element=(skElement *)node;
        skString name=element->getTagName();
        table.insertKeyAndValue(new skString(name),
                    new skRValue(new skElementObject(name,element,false)));
      }
    }
  }
}
