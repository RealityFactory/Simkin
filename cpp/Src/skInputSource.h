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

  $Id: skInputSource.h,v 1.4 2003/01/20 18:48:18 simkin_cvs Exp $
*/
#ifndef skInputSource_h
#define skInputSource_h


#include "skString.h"
#include <stdio.h>

#ifdef STREAMS_ENABLED
#include <fstream.h>
#endif

/**
* this interface encapsulates a source from which an object can be read
* It is implemented by concrete classes
*/
class CLASSEXPORT skInputSource
{
public:
  virtual bool          eof() const=0;
  virtual int           get()=0;
  virtual int           peek()=0;
  virtual skString      readAllToString()=0;
//  virtual unsigned int  read(void * buffer,unsigned int buf_len)=0;
};

class CLASSEXPORT skInputFile : public skInputSource
{
public:
                skInputFile(const skString& filename);
                ~skInputFile();
  bool          eof() const;
  int           get();
  int           peek();
  skString      readAllToString();
//  unsigned int  read(void * buffer,unsigned int buf_len);
private:
#ifdef STREAMS_ENABLED
  ifstream      m_In;
#else
  FILE *        m_In;
  bool          m_Peeked;
  int           m_PeekedChar;
#endif
#ifdef UNICODE_STRINGS
  bool          m_FileIsUnicode;
#endif
};
class CLASSEXPORT skInputString : public skInputSource
{
public:
                skInputString(const skString& in);
  bool          eof() const;
  int           get();
  int           peek();
  skString      readAllToString();
//  unsigned int  read(void * buffer,unsigned int buf_len);
private:
  skString      m_In;
  unsigned int  m_Pos;
  bool          m_Peeked;
  int           m_PeekedChar;
};

#endif
