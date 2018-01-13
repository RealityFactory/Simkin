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

  $Id: msxmldefs.h,v 1.2 2003/02/24 19:59:48 simkin_cvs Exp $
*/
#ifndef MSXMLDEFS_H
#define MSXMLDEFS_H

#import <msxml2.dll>
using namespace MSXML2;

typedef IXMLDOMDocumentPtr XMLDoc;
typedef IXMLDOMElementPtr XMLElement;
typedef IXMLDOMNodePtr XMLNode;
typedef IXMLDOMNodeListPtr XMLNodeList;


#endif
