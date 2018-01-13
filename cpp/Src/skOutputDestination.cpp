/*
  copyright 1996-2003
  Simon Whiteside

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed out the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  $Id: skOutputDestination.cpp,v 1.4 2003/01/20 18:48:18 simkin_cvs Exp $
*/
#include "skOutputDestination.h"

//-----------------------------------------------------------------
skOutputFile::skOutputFile(const skString& filename)
//-----------------------------------------------------------------
: 
#ifdef STREAMS_ENABLED
m_Out(filename)
#else
m_Out(0)
#endif
{
#ifndef STREAMS_ENABLED
#ifdef UNICODE_STRINGS
  m_Out=_wfopen(filename,skSTR("wb"));
#else
  m_Out=fopen(filename,skSTR("w"));
#endif
#endif
}
//-----------------------------------------------------------------
skOutputFile::~skOutputFile()
//-----------------------------------------------------------------
{
#ifndef STREAMS_ENABLED
  if (m_Out)
    fclose(m_Out);
#endif
}
//-----------------------------------------------------------------
void skOutputFile::write(const skString& s)
//-----------------------------------------------------------------
{
#ifdef STREAMS_ENABLED
  m_Out << s;
#else
  fwrite(s,s.length(),sizeof(Char),m_Out);
#endif
}
//-----------------------------------------------------------------
skOutputString::skOutputString(skStringBuffer& out)
//-----------------------------------------------------------------
: m_Out(out)
{
}
//-----------------------------------------------------------------
void skOutputString::write(const skString& s)
//-----------------------------------------------------------------
{
  m_Out.append(s);
}
