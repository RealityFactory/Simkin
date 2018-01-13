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

* $Id: skExpatParser.h,v 1.11 2002/12/16 16:11:46 sdw Exp $
*/

#ifndef skEXPATPARSER_H
#define skEXPATPARSER_H

#include "skString.h"
#ifdef STREAMS_ENABLED
#include <iostream.h>
#endif
#include "skElement.h"
#include <expat.h>
#include "skExecutableContext.h"

/**
 * This class gives an interface to the Expat parser. It can be used to parse an XML document and return a Simkin Element class.
 * <p>(Note: Expat is an Open Source XML parser library. You can obtain it from <a href="http://expat.sourceforge.net/">http://expat.sourceforge.net/</a>)
 */
class CLASSEXPORT skExpatParser 
{
 public:
  /** Construct a parser */
  skExpatParser();
  ~skExpatParser();

#ifdef STREAMS_ENABLED
  /** 
   * This method parses the given input stream. If there is an error in the format, an skXMLParseException is thrown. Otherwise a new Element object is returned to represent the hierarchy in the XML document stored in the stream. 
   * @throw skXMLParseException
   * @param in - the stream to read from
   * @return a new Element object representing the XML document in the stream
   */
  skElement * parse(istream& in);
#endif

  /** 
   * This method parses an XML document stored within the given string. The method returns a new Element object representing this document. If there is an error in the structure of the document, an skXMLParseException is thrown.
   * @throw skXMLParseException
   * @param in - the string to read from
   * @param context context object to receive errors
   * @return a new Element object representing the XML document in the string
   */
  skElement * parse(const skString& in,skExecutableContext& context);
 private:
  /** prevent C++ from making copies of the parser */
  skExpatParser(const skExpatParser&);
  skExpatParser& operator=(const skExpatParser&);

  static void startElementHandler(void * userData,const Char *name, const Char **atts);
  void startElement(const Char *name, const Char **atts);

  static void endElementHandler(void * userData,const Char *name);
  void endElement(const Char *name);

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

