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

* $Id: skCDataNode.cpp,v 1.7 2003/03/24 15:51:32 simkin_cvs Exp $
*/
#include "skCDataNode.h"
#include "skOutputDestination.h"
//------------------------------------------
skCDataNode::skCDataNode(const skString& text)
//------------------------------------------
  : skTextNode(text)
{
}
//------------------------------------------
skCDataNode::~skCDataNode()
//------------------------------------------
{
}
//------------------------------------------
skNode::NodeType skCDataNode::getNodeType() const
//------------------------------------------
{
  return CDATA_SECTION_NODE;
}
//------------------------------------------
skNode * skCDataNode::clone()
//------------------------------------------
{
  return new skCDataNode(m_Text);
}
//------------------------------------------
void skCDataNode::write(skOutputDestination& out) const
//------------------------------------------
{
  out.write(skSTR("![CDATA["));
  out.write(m_Text);
  out.write(skSTR("!]]"));
}
