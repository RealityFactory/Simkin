/*
  Copyright 1996-2000
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

  $Id: InheritsElement.cpp,v 1.3 2001/11/22 11:13:21 sdw Exp $
*/
#include "InheritsElement.h"
#include "parsers/DOMParser.hpp"
#include "framework/LocalFileInputSource.hpp"
#include "skXMLErrorHandler.h"

//------------------------------------------
InheritsElement::InheritsElement()
//------------------------------------------
{
}
//------------------------------------------
InheritsElement::InheritsElement(const skString& location,DOM_Element elem)
//------------------------------------------
  : skXMLElementObject(location,elem)
{
  replaceInherits(getElement());
}
//------------------------------------------
skXMLElementObject * InheritsElement::createXMLElementObject(const skString& location,DOM_Element element)
//------------------------------------------
{
  return new InheritsElement(location,element);
}
//------------------------------------------
void InheritsElement::setElement(DOM_Element elem)
//------------------------------------------
{
  skXMLElementObject::setElement(elem);
  replaceInherits(elem);
}
//------------------------------------------
void InheritsElement::replaceInherits(DOM_Element elem)
  //------------------------------------------
{
  // go through the list of children looking for an <inherits> tag.
  DOM_NodeList nodes=elem.getChildNodes();
  int count=0;
  DOM_Document owner=elem.getOwnerDocument();
  DOMString sInheritsTag("inherits");
  for (int i=0;i<nodes.getLength();i++){
    DOM_Node node=nodes.item(i);
    if (node.getNodeType()==DOM_Node::ELEMENT_NODE){
      if (node.getNodeName().equals(sInheritsTag)){
	// the data within the inherits tag is the the file name to import
	skString file_name=getData(*(DOM_Element *)&node);
	DOMString sFileName((const char *)file_name);
	const XMLCh * buffer=sFileName.rawBuffer();
	LocalFileInputSource in(buffer);
	DOMParser * parser = new DOMParser;
	skXMLErrorHandler handler;
	parser->setErrorHandler(&handler);
	parser->parse(in);
	DOM_Element parent=parser->getDocument().getDocumentElement();
	delete parser;
	// check if this element has any inherits tags
	replaceInherits(parent);
	DOM_NodeList parent_nodes=parent.getChildNodes();
	for (int j=0;j<parent_nodes.getLength();j++){
	  elem.insertBefore(owner.importNode(parent_nodes.item(j),true),node);
	}
	elem.removeChild(node);
	i--;
      }
    }
  }
}

