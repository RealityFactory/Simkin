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

  $Id: skStringBuffer.cpp,v 1.3 2002/01/08 23:04:40 sdw Exp $
*/
#include "skStringBuffer.h"

//---------------------------------------------------
skStringBuffer::skStringBuffer(USize length,USize growth_increment)
//---------------------------------------------------
  : m_GrowthIncrement(growth_increment),m_Length(0),m_Buffer(0),m_Capacity(length+1)
{
  if (m_Capacity){
    m_Buffer=new Char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
  }
}
//---------------------------------------------------
skStringBuffer::skStringBuffer(const skString& str,USize growth_increment)
//---------------------------------------------------
  : m_GrowthIncrement(growth_increment),m_Length(str.length()),m_Buffer(0),m_Capacity(str.length()+1)
{
  if (m_Capacity){
    m_Buffer=new Char[m_Capacity];
    STRCPY(m_Buffer,str);
  }
}
//---------------------------------------------------
skStringBuffer::skStringBuffer(const skStringBuffer& s)
//---------------------------------------------------
  : m_GrowthIncrement(s.m_GrowthIncrement),m_Length(s.m_Length),m_Buffer(0),m_Capacity(s.m_Capacity)
{
  if (m_Capacity){
    m_Buffer=new Char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
    STRCPY(m_Buffer,s.m_Buffer);
  }
}
//---------------------------------------------------
skStringBuffer& skStringBuffer::operator=(const skStringBuffer& s)
//---------------------------------------------------
{
  if (m_Buffer)
    delete [] m_Buffer;
  m_GrowthIncrement=s.m_GrowthIncrement;
  m_Length=s.m_Length;
  m_Buffer=0;
  m_Capacity=s.m_Capacity;
  if (m_Capacity){
    m_Buffer=new Char[m_Capacity];
    memset(m_Buffer,0,m_Capacity);
    STRCPY(m_Buffer,s.m_Buffer);
  }
  return *this;
}
//---------------------------------------------------
skStringBuffer::~skStringBuffer()
//---------------------------------------------------
{
  if (m_Buffer)
    delete [] m_Buffer;
}
//---------------------------------------------------
void skStringBuffer::append(Char ch)
//---------------------------------------------------
{
  ensureCapacity(m_Length+1);
  m_Buffer[m_Length++]=ch;
  m_Buffer[m_Length]=0;
}
//---------------------------------------------------
void skStringBuffer::append(const skString& s)
//---------------------------------------------------
{
  ensureCapacity(m_Length+s.length()+1);
  STRCAT(m_Buffer,s);
  m_Length+=s.length();
}
//---------------------------------------------------
void skStringBuffer::append(const Char * s)
//---------------------------------------------------
{
  if (s){
    USize length=STRLEN(s);
    if (length){
      ensureCapacity(m_Length+length+1);
      STRCAT(m_Buffer,s);
      m_Length+=length;
    }
  }
}
//---------------------------------------------------
skString skStringBuffer::toString() 
//---------------------------------------------------
{
  skString ret=skString::fromBuffer(m_Buffer);
  // new string now owns the buffer, so zero ourselves out
  m_Capacity=0;
  m_Length=0;
  m_Buffer=0;
  return ret;
}
//---------------------------------------------------
skString skStringBuffer::toStringCopy() const
//---------------------------------------------------
{
  return skString(m_Buffer);
}
//---------------------------------------------------
void skStringBuffer::ensureCapacity(USize capacity)
//---------------------------------------------------
{
  if (capacity>m_Capacity){
    USize increment=max(capacity-m_Capacity,m_GrowthIncrement);
    USize new_capacity=m_Capacity+increment;
	assert(new_capacity>=capacity);
    Char * new_buffer=new Char[new_capacity];
    memset(new_buffer,0,new_capacity);
    if (m_Buffer){
      STRCPY(new_buffer,m_Buffer);
      delete [] m_Buffer;
    }
    m_Buffer=new_buffer;
    m_Capacity=new_capacity;
  }
}
//---------------------------------------------------
skStringBuffer::operator const Char * () const
//---------------------------------------------------
{
  return m_Buffer;
}
//---------------------------------------------------
USize skStringBuffer::length() const
//---------------------------------------------------
{
  return m_Length;
}
//---------------------------------------------------
USize skStringBuffer::capacity() const
//---------------------------------------------------
{
  return m_Capacity;
}
