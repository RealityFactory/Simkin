/*
  Copyright 1996-2002
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

* $Id: skElementExecutable.cpp,v 1.9 2002/12/13 17:28:15 sdw Exp $
*/

#include "skElementExecutable.h"
#include "skExpatParser.h"
#ifdef STREAMS_ENABLED
#include <fstream.h>
#else
#include "skStringBuffer.h"
#endif
//------------------------------------------
skElementExecutable::skElementExecutable() 
//------------------------------------------
{
}
#ifdef STREAMS_ENABLED
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& scriptLocation,istream& in)
//------------------------------------------
{
  load(scriptLocation,in);
}
#endif
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& scriptLocation,const skString& in,skExecutableContext& context)
//------------------------------------------
{
  load(scriptLocation,in,context);
}
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& fileName,skExecutableContext& context)
//------------------------------------------
{
  load(fileName,context);
}
//------------------------------------------
void skElementExecutable::load(const skString& scriptLocation,const skString& in,skExecutableContext& context)
//------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  skExpatParser parser;
  skElement * elem=parser.parse(in,context);
  setElement(elem);
}
#ifdef STREAMS_ENABLED
//------------------------------------------
void skElementExecutable::load(const skString& scriptLocation,istream& in) 
//------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  skExpatParser parser;
  skElement * elem=parser.parse(in);
  setElement(elem);
}
#endif
//------------------------------------------
void skElementExecutable::load(const skString& fileName,skExecutableContext& context)
//------------------------------------------
{
#ifdef STREAMS_ENABLED
  ifstream in (fileName);
  load(fileName,in);
#else
  skString text=skString::readFromFile(fileName);
	load(fileName,text,context);
#endif
}
#ifdef STREAMS_ENABLED
//------------------------------------------
void skElementExecutable::save(ostream& out) 
//------------------------------------------
{
  out << *getElement();
}
#endif
//------------------------------------------
void skElementExecutable::save(const skString& fileName) 
//------------------------------------------
{
#ifdef STREAMS_ENABLED
  ofstream out(fileName);
  save(out);
#else
  skString text=m_Element->toString();
  text.writeToFile(fileName);
#endif
}
//------------------------------------------
skElementExecutable::skElementExecutable(const skElementExecutable& other)
//------------------------------------------
{
}
//------------------------------------------
skElementExecutable& skElementExecutable::operator=(const skElementExecutable& other)
//------------------------------------------
{
  return *this;
}
