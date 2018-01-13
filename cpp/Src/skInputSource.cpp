/*
  copyright 1996-2003
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

  $Id: skInputSource.cpp,v 1.6 2003/02/14 10:43:21 simkin_cvs Exp $
*/
#include "skInputSource.h"
#include "skStringBuffer.h"
#ifdef UNICODE_STRINGS
#include "skAsciiStringBuffer.h"
#include "skEncodingUtils.h"
#endif
//-----------------------------------------------------------------
skInputFile::skInputFile(const skString& filename)
//-----------------------------------------------------------------
:
#ifdef UNICODE_STRINGS
m_FileIsUnicode(true),
#endif
#ifdef STREAMS_ENABLED
m_In(filename)
#else
m_In(0),m_Peeked(false),m_PeekedChar(0)
#endif
{
#ifndef STREAMS_ENABLED
#ifdef UNICODE_STRINGS
  m_In=_wfopen(filename,skSTR("rb"));
#else
  m_In=fopen(filename,skSTR("r"));
#endif
#endif
#ifdef UNICODE_STRINGS
  if(m_In){
    // check what the encoding of the file is
    int first_word=peek();
    int first_byte=first_word & 0xff;
    int second_byte=(first_word & 0xff00) >> 8;
    if (first_byte==0xFF && second_byte==0xFE)
      m_FileIsUnicode=true;
    else{
      m_FileIsUnicode=false;
      // Make last peek invalid and re-seek. 
      fseek(m_In, 0, SEEK_SET);
      m_Peeked=false;    
    }
  }
#endif
}
//-----------------------------------------------------------------
skInputFile::~skInputFile()
//-----------------------------------------------------------------
{
#ifndef STREAMS_ENABLED
  if (m_In)
    fclose(m_In);
#endif
}
//-----------------------------------------------------------------
bool skInputFile::eof() const
//-----------------------------------------------------------------
{
#ifdef STREAMS_ENABLED
  return m_In.eof()==1;
#else
  bool eof=true;
  if (m_In)
    eof=feof(m_In)!=0;
  return eof;
#endif
}
//-----------------------------------------------------------------
int skInputFile::get()
//-----------------------------------------------------------------
{
#ifdef STREAMS_ENABLED
  return m_In.get();
#else
  int c=0;
  if (m_Peeked){
    c=m_PeekedChar;
    m_Peeked=false;
  }else
#ifdef UNICODE_STRINGS
    if (m_FileIsUnicode)
      c=fgetwc(m_In);
    else
      c=fgetc(m_In);
#else
    c=fgetc(m_In);
#endif
  return c;
#endif
}
//-----------------------------------------------------------------
skString skInputFile::readAllToString()
//-----------------------------------------------------------------
{
  const int BUF_SIZE=1024;
#ifdef STREAMS_ENABLED
  skStringBuffer s_buffer(BUF_SIZE);
  Char buffer[BUF_SIZE];
  while (eof()==false){
    memset(buffer,0,BUF_SIZE*sizeof(Char));
    m_In.read(buffer,(BUF_SIZE-1)*sizeof(Char));
    s_buffer.append(buffer);
  }
  return s_buffer.toString();
#else
#ifndef UNICODE_STRINGS
  // reset file pointer
  fseek(m_In,0,SEEK_SET);
  skStringBuffer s_buffer(BUF_SIZE);
  Char buffer[BUF_SIZE];
  while (eof()==false){
    memset(buffer,0,BUF_SIZE*sizeof(Char));
    fread(buffer,sizeof(Char),BUF_SIZE-1,m_In);
    s_buffer.append(buffer);
  }
  return s_buffer.toString();
#else
  if (m_FileIsUnicode){
    // reset file pointer
    fseek(m_In,sizeof(wchar_t),SEEK_SET);
    skStringBuffer s_buffer(BUF_SIZE);
    Char buffer[BUF_SIZE];
    while (eof()==false){
      memset(buffer,0,BUF_SIZE*sizeof(Char));
      int num_read=fread(buffer,sizeof(Char),BUF_SIZE-1,m_In);
      s_buffer.append(buffer);
    }
    return s_buffer.toString();
  }else{
    // reading an ASCII file
    // reset file pointer
    fseek(m_In,0,SEEK_SET);
    skAsciiStringBuffer s_buffer(BUF_SIZE);
    char buffer[BUF_SIZE];
    while (eof()==false){
      memset(buffer,0,BUF_SIZE);
      fread(buffer,1,BUF_SIZE-1,m_In);
      s_buffer.append(buffer);
    }
    return skEncodingUtils::fromAscii(s_buffer.toString());
  }
#endif
#endif
}
//-----------------------------------------------------------------
int skInputFile::peek()
//-----------------------------------------------------------------
{
#ifdef STREAMS_ENABLED
  return m_In.peek();
#else
  if (m_Peeked==false){
    m_Peeked=true;
#ifdef UNICODE_STRINGS
    if (m_FileIsUnicode)
      m_PeekedChar=fgetwc(m_In);
    else
      m_PeekedChar=fgetc(m_In);
#else
    m_PeekedChar=fgetc(m_In);
#endif
  }
  return m_PeekedChar;
#endif
}
//-----------------------------------------------------------------
skInputString::skInputString(const skString& in)
//-----------------------------------------------------------------
: m_In(in),m_Pos(0),m_Peeked(false),m_PeekedChar(0)
{
}
//-----------------------------------------------------------------
bool skInputString::eof() const
//-----------------------------------------------------------------
{
  return m_Pos<m_In.length();
}
//-----------------------------------------------------------------
int skInputString::get()
//-----------------------------------------------------------------
{
  int c=0;
  if (m_Peeked){
    c=m_PeekedChar;
    m_Peeked=false;
  }else{
    if (m_Pos<m_In.length())
      c=m_In.at(m_Pos++);
    else
      c=-1;
  }
  return c;
}
//-----------------------------------------------------------------
int skInputString::peek()
//-----------------------------------------------------------------
{
  if (m_Peeked==false){
    m_Peeked=true;
    if (m_Pos<m_In.length())
      m_PeekedChar=m_In.at(m_Pos++);
    else
      m_PeekedChar=-1;
  }
  return m_PeekedChar;
}
//-----------------------------------------------------------------
skString skInputString::readAllToString()
//-----------------------------------------------------------------
{
  return m_In;
}
