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

  $Id: skOutputDestination.h,v 1.3 2003/01/20 18:48:18 simkin_cvs Exp $
*/
#ifndef skOutputDestination_h
#define skOutputDestination_h

#include "skStringBuffer.h"
#include <stdio.h>

#ifdef STREAMS_ENABLED
#include <fstream.h>
#endif

/**
* this interface encapsulates a destination to which an object can be written
* It is implemented by concrete classes
*/
class CLASSEXPORT skOutputDestination
{
public:
  virtual void  write(const skString& s)=0;
};
class CLASSEXPORT skOutputFile : public skOutputDestination
{
public:
                skOutputFile(const skString& file);
                ~skOutputFile();
  void          write(const skString& s);
private:
#ifdef STREAMS_ENABLED
  ofstream      m_Out;
#else
  FILE *        m_Out;
#endif
};
class CLASSEXPORT skOutputString : public skOutputDestination
{
public:
                skOutputString(skStringBuffer& out);
  void          write(const skString& s);
private:
  skStringBuffer& m_Out;
};

#endif
