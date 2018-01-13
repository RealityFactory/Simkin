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

* $Id: skExpatParser.h,v 1.5 2001/11/22 11:13:21 sdw Exp $
*/

#ifndef skEXPATPARSER_H
#define skEXPATPARSER_H

#include "skString.h"
#include <iostream.h>
#include "skElement.h"
#include "expat.h"

/**
 * This class gives an interface to the Expat parser. It can be used to parse an XML document and return a Simkin Element class.
 * <p>(Note: Expat is an Open Source XML parser library. You can obtain it from <a href="http://expat.sourceforge.net/">http://expat.sourceforge.net/</a>)
 */
class CLASSEXPORT skExpatParser 
{
 public:
  /** Construct a parser */
  skExpatParser();

  /** 
   * This method parses the given input stream. If there is an error in the format, an skXMLParseException is thrown. Otherwise a new Element object is returned to represent the hierarchy in the XML document stored in the stream. 
   * @throw skXMLParseException
   * @param in - the stream to read from
   * @return a new Element object representing the XML document in the stream
   */
  skElement * parse(istream& in);

  /** 
   * This method parses an XML document stored within the given string. The method returns a new Element object representing this document. If there is an error in the structure of the document, an skXMLParseException is thrown.
   * @throw skXMLParseException
   * @param in - the string to read from
   * @return a new Element object representing the XML document in the string
   */
  skElement * parse(const skString& in);
 private:
  /** prevent C++ from making copies of the parser */
  skExpatParser(const skExpatParser&);
  skExpatParser& operator=(const skExpatParser&);

  static void startElementHandler(void * userData,const char *name, const char **atts);
  void startElement(const char *name, const char **atts);

  static void endElementHandler(void * userData,const char *name);
  void endElement(const char *name);

  static void characterDataHandler(void *userData, const XML_Char *s,int len);
  void characterData(const XML_Char *s,int len);

  static  void startCDataHandler(void *userData);
  void startCData();

  static void endCDataHandler(void *userData);
  void endCData ();

  skNodeList m_ElementStack;
  bool m_InCData;
  skElement * m_RootElement;
};
#endif

