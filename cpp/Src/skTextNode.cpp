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

* $Id: skTextNode.cpp,v 1.2 2001/11/22 11:13:21 sdw Exp $
*/
#include "skTextNode.h"

//------------------------------------------
skTextNode::skTextNode(const skString& text)
//------------------------------------------
  :m_Text(text)
{
}
//------------------------------------------
skString skTextNode::getNodeValue() const
//------------------------------------------
{
  return m_Text;
}
//------------------------------------------
void skTextNode::setNodeValue(const skString& text)
//------------------------------------------
{
  m_Text=text;
}
//------------------------------------------
skNode::NodeType skTextNode::getNodeType() const
//------------------------------------------
{
  return TEXT_NODE;
}
//------------------------------------------
skNode * skTextNode::clone()
//------------------------------------------
{
  return new skTextNode(m_Text);
}
//------------------------------------------
void skTextNode::write(ostream& out) const
//------------------------------------------
{
  out << escapeXMLDelimiters(m_Text);
}
