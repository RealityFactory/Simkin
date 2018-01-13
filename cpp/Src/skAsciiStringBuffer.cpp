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

  $Id: skAsciiStringBuffer.cpp,v 1.2 2003/01/20 18:48:18 simkin_cvs Exp $
*/
#include "skAsciiStringBuffer.h"

//---------------------------------------------------
skAsciiStringBuffer::skAsciiStringBuffer(USize length,USize growth_increment)
//---------------------------------------------------
  : m_GrowthIncrement(growth_increment),m_Length(0),m_Buffer(0),m_Capacity(length+1)
{
  if (m_Capacity){
    m_Buffer=new char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
  }
}
//---------------------------------------------------
skAsciiStringBuffer::skAsciiStringBuffer(const skAsciiString& str,USize growth_increment)
//---------------------------------------------------
  : m_GrowthIncrement(growth_increment),m_Length(str.length()),m_Buffer(0),m_Capacity(str.length()+1)
{
  if (m_Capacity){
    m_Buffer=new char[m_Capacity];
    strcpy(m_Buffer,str);
  }
}
//---------------------------------------------------
skAsciiStringBuffer::skAsciiStringBuffer(const skAsciiStringBuffer& s)
//---------------------------------------------------
  : m_GrowthIncrement(s.m_GrowthIncrement),m_Length(s.m_Length),m_Buffer(0),m_Capacity(s.m_Capacity)
{
  if (m_Capacity){
    m_Buffer=new char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
    strcpy(m_Buffer,s.m_Buffer);
  }
}
//---------------------------------------------------
skAsciiStringBuffer& skAsciiStringBuffer::operator=(const skAsciiStringBuffer& s)
//---------------------------------------------------
{
  if (m_Buffer)
    delete [] m_Buffer;
  m_GrowthIncrement=s.m_GrowthIncrement;
  m_Length=s.m_Length;
  m_Buffer=0;
  m_Capacity=s.m_Capacity;
  if (m_Capacity){
    m_Buffer=new char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
    strcpy(m_Buffer,s.m_Buffer);
  }
  return *this;
}
//---------------------------------------------------
skAsciiStringBuffer::~skAsciiStringBuffer()
//---------------------------------------------------
{
  if (m_Buffer)
    delete [] m_Buffer;
}
//---------------------------------------------------
void skAsciiStringBuffer::append(char ch)
//---------------------------------------------------
{
  ensureCapacity(m_Length+1+1);
  m_Buffer[m_Length++]=ch;
  m_Buffer[m_Length]=0;
}
//---------------------------------------------------
void skAsciiStringBuffer::append(const skAsciiString& s)
//---------------------------------------------------
{
  ensureCapacity(m_Length+s.length()+1);
  strcat(m_Buffer,s);
  m_Length+=s.length();
}
//---------------------------------------------------
void skAsciiStringBuffer::append(const char * s)
//---------------------------------------------------
{
  if (s){
    USize length=strlen(s);
    if (length){
      ensureCapacity(m_Length+length+1);
      strcat(m_Buffer,s);
      m_Length+=length;
    }
  }
}
//---------------------------------------------------
skAsciiString skAsciiStringBuffer::toString() 
//---------------------------------------------------
{
  skAsciiString ret=skAsciiString::fromBuffer(m_Buffer);
  // new string now owns the buffer, so zero ourselves out
  m_Capacity=0;
  m_Length=0;
  m_Buffer=0;
  return ret;
}
//---------------------------------------------------
skAsciiString skAsciiStringBuffer::toStringCopy() const
//---------------------------------------------------
{
  return skAsciiString(m_Buffer);
}
//---------------------------------------------------
void skAsciiStringBuffer::ensureCapacity(USize capacity)
//---------------------------------------------------
{
  if (capacity+1>m_Capacity){
    USize increment=max(capacity-m_Capacity,m_GrowthIncrement);
    USize new_capacity=m_Capacity+increment;
    assert(new_capacity>=capacity);
    char * new_buffer=new char[new_capacity];
    memset(new_buffer,0,new_capacity);
    if (m_Buffer){
      strcpy(new_buffer,m_Buffer);
      delete [] m_Buffer;
    }
    m_Buffer=new_buffer;
    m_Capacity=new_capacity;
  }
}
//---------------------------------------------------
skAsciiStringBuffer::operator const char * () const
//---------------------------------------------------
{
  return m_Buffer;
}
//---------------------------------------------------
USize skAsciiStringBuffer::length() const
//---------------------------------------------------
{
  return m_Length;
}
//---------------------------------------------------
USize skAsciiStringBuffer::capacity() const
//---------------------------------------------------
{
  return m_Capacity;
}
