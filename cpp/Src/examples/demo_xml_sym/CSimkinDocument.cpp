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
  
  $Id: CSimkinDocument.cpp,v 1.2 2003/04/19 13:22:24 simkin_cvs Exp $
*/

#include "CSimkinDocument.h"
#include "skStringBuffer.h"
#include "skInputSource.h"
#include "skOutputDestination.h"
#include "CSimkinAppUi.h"
#include "skExpatParser.h"
#include "skElementObject.h"

//-----------------------------------------------------------------
CSimkinDocument::CSimkinDocument(CEikApplication& aApp,const TDesC& aFileName)
//-----------------------------------------------------------------
  : CQikDocument(aApp),iInterpreter(0),iFileName(aFileName),iElement(0)
{
}
//-----------------------------------------------------------------
CSimkinDocument::~CSimkinDocument()
//-----------------------------------------------------------------
{
  delete iElement;
  delete iInterpreter;
  CloseSTDLIB();
}
//-----------------------------------------------------------------
CEikAppUi* CSimkinDocument::CreateAppUiL()
//-----------------------------------------------------------------
{
  // create an interpreter
  iInterpreter=new (ELeave) skInterpreter;
  // call the interpreter init() function
  iInterpreter->init();
  LoadScriptL();
  return new(ELeave) CSimkinAppUi(iFileName,this);
}
//-----------------------------------------------------------------
TBool CSimkinDocument::LoadScriptFromStringL(const skString& code)
//-----------------------------------------------------------------
{
  TBool success=EFalse;
  skInputString in(code);
  skExecutableContext ctxt(iInterpreter);
  skExpatParser * parser=new (ELeave)skExpatParser;
  CleanupStack::PushL(parser);
  skElement * element=parser->parse(in,ctxt);
  CleanupStack::PopAndDestroy(parser);
  if (element){
    delete iElement;
    iElement=element;
    success=ETrue;
  }
  return success;
}
//-----------------------------------------------------------------
skString CSimkinDocument::GetScriptAsStringL()
//-----------------------------------------------------------------
{
  skString s;
  skStringBuffer buffer(2048);
  skOutputString out(buffer);
  iElement->write(out);
  return buffer.toString();
}
//-----------------------------------------------------------------
void CSimkinDocument::LoadScriptL()
//-----------------------------------------------------------------
{
  delete iElement;
  skExecutableContext ctxt(iInterpreter);
  skInputFile * file=new (ELeave) skInputFile;
  CleanupStack::PushL(file);
  file->open(iFileName);
  if (file->eof()==false){
    skExpatParser * parser=new (ELeave)skExpatParser;
    CleanupStack::PushL(parser);
    iElement=parser->parse(*file,ctxt);
    CleanupStack::PopAndDestroy(parser);
  }else{
    _LIT(KNoScript,"Could not open script file");
    CEikonEnv::Static()->AlertWin(KNoScript);
  }
  CleanupStack::PopAndDestroy(file);
}
//-----------------------------------------------------------------
skElement *  CSimkinDocument::script()
//-----------------------------------------------------------------
{
  return iElement;
}
//-----------------------------------------------------------------
skInterpreter * CSimkinDocument::interpreter()
//-----------------------------------------------------------------
{
  return iInterpreter;
}
