/*
  Copyright 2003
  Simon Whiteside, All Rights Reserved
  
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
  
  $Id: CSimkinDocument.h,v 1.3 2003/04/25 18:21:46 simkin_cvs Exp $
*/
#ifndef CSIMKINDOCUMENT_H
#define CSIMKINDOCUMENT_H

#include "Platform.h"

#ifdef QUARTZ_SDK
#include <qikdocument.h>
#include <qikapplication.h>
#else
#include <akndoc.h>
#include <aknapp.h>
#endif
#include "skInterpreter.h"
#include "skTreeNode.h"

/**
 * This class represents the document for the Simkin Demo.
 * The class contains the current Simkin script and an instance of the interpreter
 */
class CSimkinDocument 
#ifdef QUARTZ_SDK
: public CQikDocument
#else
: public CAknDocument
#endif
{
 public:
  CSimkinDocument(CEikApplication& aApp,const TDesC& aFileName);
  ~CSimkinDocument();
  /**
   * @return the current script
   */
  skTreeNode * script();
  /**
   * @return the current Interpreter
   */
  skInterpreter * interpreter();
  /**
   * Returns the current script as a string
   */
  skString GetScriptAsStringL();
  /**
   * Updates the script from the given string.
   * @return ETrue if the script could be parsed from the string, otherwise EFalse
   */
  TBool LoadScriptFromStringL(const skString& code);
 private: 
  /**
   * loads the script
   */
  void LoadScriptL();
  CEikAppUi* CreateAppUiL();

  /**
   * The Simkin interpreter
   */  
  skInterpreter * iInterpreter;
  /**
   * The filename of the file containing the script
   */
  const TDesC& iFileName;
  /**
   * The Simkin script
   */
  skTreeNode * iScript;
};

#endif
