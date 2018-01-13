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

* $Id: skElementExecutable.h,v 1.8 2002/12/16 16:11:46 sdw Exp $
*/

#ifndef skELEMENTEXECUTABLE_H
#define skELEMENTEXECUTABLE_H

#include "skElementObject.h"
#ifdef STREAMS_ENABLED
#include <iostream.h>
#endif
/**
 * This class is a base class for objects which store their data and methods in an XML document
 * Each instance is associated with an XML document which is loaded on construction. 
 * This version uses the Expat XML parser to read documents.
 */
class CLASSEXPORT skElementExecutable : public skElementObject {
 public:
  /**
   * Default Constructor.
   */ 
  skElementExecutable();
  /**
   * Constructor - passed the name of a file to load an XML document from
   * @param fileName name of XML file
   * @param context context object to receive errors
   */
  skElementExecutable(const skString& fileName,skExecutableContext& context);
#ifdef STREAMS_ENABLED
  /**
   * Constructor taking an input stream containing an XML document
   * @param scriptLocation the name of the XML source
   * @param in a stream containing the XML document
   */
  skElementExecutable(const skString& scriptLocation,istream& in);
#endif
  /**
   * Constructor taking a String containing an XML document
   * @param scriptLocation the name of the XML source
   * @param in a stream containing the XML document
   * @param context context object to receive errors
   */
  skElementExecutable(const skString& scriptLocation,const skString& in,skExecutableContext& context);
#ifdef STREAMS_ENABLED
  /**
   * This method causes the  to be reloaded
   * @param in - stream containing the 
   */
  void load(const skString& scriptLocation,istream& in);
#endif
  /**
   * This method causes the  to be reloaded
   * @param scriptLocation the name of the XML source
   * @param in - string containing the XML document
   * @param context context object to receive errors
   */
  void load(const skString& scriptLocation,const skString& in,skExecutableContext& context);
  /**
   * This method causes the  to be loaded from a file
   * @param fileName name of XML file
   * @param context context object to receive errors
   */
  void load(const skString& fileName,skExecutableContext& context);
#ifdef STREAMS_ENABLED
  /**
   * Call this method to save the state of the object back to a stream
   * @exception IOException if there was an error writing to the stream
   */
  void save(ostream& out);
#endif
  /**
   * This method saves the current state as an  document out to the given file
   */
  void save(const skString& fileName);
 private:
  /**
   * ElementExecutables can't be copied
   */
  skElementExecutable(const skElementExecutable&);
  /**
   * ElementExecutables can't be copied
   */
  skElementExecutable& operator=(const skElementExecutable&);
};
#endif
