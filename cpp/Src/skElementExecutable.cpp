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

* $Id: skElementExecutable.cpp,v 1.3 2001/11/22 11:13:21 sdw Exp $
*/

#include "skElementExecutable.h"
#include "skExpatParser.h"
#include <fstream.h>

//------------------------------------------
skElementExecutable::skElementExecutable() 
//------------------------------------------
{
}
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& scriptLocation,istream& in)
//------------------------------------------
{
  load(scriptLocation,in);
}
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& scriptLocation,const skString& in)
//------------------------------------------
{
  load(scriptLocation,in);
}
//------------------------------------------
skElementExecutable::skElementExecutable(const skString& fileName)
//------------------------------------------
{
  load(fileName);
}
//------------------------------------------
void skElementExecutable::load(const skString& scriptLocation,const skString& in) 
//------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  skExpatParser parser;
  skElement * elem=parser.parse(in);
  setElement(elem);
}
//------------------------------------------
void skElementExecutable::load(const skString& scriptLocation,istream& in) 
//------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  skExpatParser parser;
  skElement * elem=parser.parse(in);
  setElement(elem);
}
//------------------------------------------
void skElementExecutable::load(const skString& fileName) 
//------------------------------------------
{
  ifstream in (fileName);
  load(fileName,in);
}
//------------------------------------------
void skElementExecutable::save(ostream& out) 
//------------------------------------------
{
  out << *getElement();
}
//------------------------------------------
void skElementExecutable::save(const skString& fileName) 
//------------------------------------------
{
  ofstream out(fileName);
  save(out);
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
