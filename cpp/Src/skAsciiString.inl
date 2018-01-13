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

$Id: skAsciiString.inl,v 1.1 2003/01/16 19:25:22 simkin_cvs Exp $
*/

#ifndef skASCIISTRING_INL
#define skASCIISTRING_INL

#include "skAsciiString.h"
#include <string.h>
#include <ctype.h>

class   P_AsciiString 
{
 public:
    char *		m_PString;
    USize			m_Length;
    USize			m_Hash;
    bool			m_Const;
    USize			m_RefCount;
    
    P_AsciiString();
    ~P_AsciiString();
    void			init();

};    
extern const char * ascii_blank;                    

extern P_AsciiString * ascii_blank_string;


//---------------------------------------------------
inline P_AsciiString::~P_AsciiString() 
//---------------------------------------------------
{ 
    if (m_Const==0) 
	delete[] m_PString; 
}
//---------------------------------------------------
inline skAsciiString::operator const char * () const 
//---------------------------------------------------
{
    return (const char *)pimp->m_PString;
}
//---------------------------------------------------
inline USize skAsciiString::length() const 
//---------------------------------------------------
{
    return pimp->m_Length;
}
//---------------------------------------------------
inline  bool skAsciiString::operator<(const skAsciiString& s) const
//---------------------------------------------------
{
  bool ret=false;
  if (pimp==s.pimp)
	  ret=false;
  else{
    int i=strcmp((const char *)pimp->m_PString,(const char *)s.pimp->m_PString);
    if (i<0)
      ret=true;
  }
  return ret;
}
//---------------------------------------------------
inline  bool skAsciiString::operator==(const skAsciiString& s) const
//---------------------------------------------------
{
  if (pimp==s.pimp)
    return true;
  else
    if (pimp->m_Hash==s.pimp->m_Hash && pimp->m_Length==s.pimp->m_Length)
      return (strcmp(pimp->m_PString,s.pimp->m_PString)==0);
    else
      return false;
}
//---------------------------------------------------
inline  bool skAsciiString::operator==(const char * s) const
//---------------------------------------------------
{
  if (s)
    return (strcmp(pimp->m_PString,s)==0);
  else
    return false;
}
//---------------------------------------------------
inline void skAsciiString::deRef()
     //---------------------------------------------------
{
  pimp->m_RefCount--;
  if (pimp->m_RefCount==0)
    delete pimp;
}

//---------------------------------------------------
inline  skAsciiString::skAsciiString()
//---------------------------------------------------
{
  assign(0);
}
//---------------------------------------------------
inline skAsciiString& skAsciiString::operator=(const skAsciiString& s) 
//---------------------------------------------------
{
  if (&s!=this){
    s.pimp->m_RefCount++;
    deRef();
    pimp=s.pimp;
  }	
  return *this;
}
//---------------------------------------------------
inline skAsciiString::skAsciiString(const skAsciiString& s) 
//---------------------------------------------------
    : pimp(s.pimp)
{
    pimp->m_RefCount++;
}
//---------------------------------------------------
inline skAsciiString::~skAsciiString() 
//---------------------------------------------------
{
    deRef();
}
//---------------------------------------------------
inline USize skAsciiString::hash() const 
//---------------------------------------------------
{
    return pimp->m_Hash;
}
//---------------------------------------------------
inline char skAsciiString::at(USize index) const
//---------------------------------------------------
{
  char c=0;
  if (index<pimp->m_Length)
    c=pimp->m_PString[index];
  return c;	
}

#endif





