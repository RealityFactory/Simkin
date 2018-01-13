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

* $Id: skExpatParser.h,v 1.14 2003/01/24 09:16:27 simkin_cvs Exp $
*/

#ifndef skEXPATPARSER_H
#define skEXPATPARSER_H

#include "skString.h"
#include "skElement.h"
#include <expat.h>
#include "skExecutableContext.h"

class CLASSEXPORT skInputSource;

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

  skElement * parse(skInputSource& in,skExecutableContext& context);
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

