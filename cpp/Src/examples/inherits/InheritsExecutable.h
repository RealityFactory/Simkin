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

  $Id: InheritsExecutable.h,v 1.6 2003/03/18 19:36:13 simkin_cvs Exp $
*/
#ifndef INHERITSEXECUTABLE_H
#define INHERITSEXECUTABLE_H

#include "InheritsElement.h"
#include <xercesc/sax/InputSource.hpp>

/**
 * This class loads an XML file and makes sure any <inherits> tags are resolved.
 */
class InheritsExecutable : public InheritsElement {
 public:
  /**
   * Constructor - passed the name of a file to load an XML document from
   * @param fileName - the filename of the XML document
   */
  InheritsExecutable(const skString& fileName);
  /**
   * This method causes the XML to be reloaded
   * @param scriptLocation - the name of the XML document
   * @param in - stream containing the XML
   */
  void load(const skString& scriptLocation,InputSource& in);
  /**
   * This method causes the XML to be loaded from a file
   * @param fileName - the filename of the XML document
   */
  void load(const skString& fileName);
 private:
  /**
   * Executables can't be copied
   */
  InheritsExecutable(const InheritsExecutable&);
  /**
   * Executables can't be copied
   */
  InheritsExecutable& operator=(const InheritsExecutable&);
};

#endif
