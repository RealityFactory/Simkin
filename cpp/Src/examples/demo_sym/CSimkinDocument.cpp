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
  
  $Id: CSimkinDocument.cpp,v 1.3 2003/04/14 15:23:55 simkin_cvs Exp $
*/

#include "CSimkinDocument.h"
#include "skStringBuffer.h"
#include "skInputSource.h"
#include "skOutputDestination.h"
#include "CSimkinAppUi.h"

//-----------------------------------------------------------------
CSimkinDocument::CSimkinDocument(CEikApplication& aApp,const TDesC& aFileName)
//-----------------------------------------------------------------
  : CQikDocument(aApp),iInterpreter(0),iFileName(aFileName),iScript(0)
{
}
//-----------------------------------------------------------------
CSimkinDocument::~CSimkinDocument()
//-----------------------------------------------------------------
{
  delete iScript;
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
  skTreeNodeReader reader;
  skExecutableContext ctxt(iInterpreter);
  skTreeNode * node=reader.read(&in,iFileName,ctxt);
  if (node){
    delete iScript;
    iScript=node;
    success=ETrue;
  }
  return success;
}
//-----------------------------------------------------------------
skString CSimkinDocument::GetScriptAsStringL()
//-----------------------------------------------------------------
{
  skStringBuffer buffer(2048);
  skOutputString out(buffer);
  iScript->write(out,0,false);
  return buffer.toString();
}
//-----------------------------------------------------------------
void CSimkinDocument::LoadScriptL()
//-----------------------------------------------------------------
{
  delete iScript;
  skExecutableContext ctxt(iInterpreter);
  skInputFile * file=new (ELeave) skInputFile;
  CleanupStack::PushL(file);
  file->open(iFileName);
  if (file->eof()==false){
    skTreeNodeReader * aReader=new (ELeave) skTreeNodeReader;
    CleanupStack::PushL(aReader);
    iScript=aReader->read(file,iFileName,ctxt);
    CleanupStack::PopAndDestroy(aReader);
  }else{
    _LIT(KNoScript,"Could not open script file");
    CEikonEnv::Static()->AlertWin(KNoScript);
  }
  CleanupStack::PopAndDestroy(file);
}
//-----------------------------------------------------------------
skTreeNode * CSimkinDocument::script()
//-----------------------------------------------------------------
{
  return iScript;
}
//-----------------------------------------------------------------
skInterpreter * CSimkinDocument::interpreter()
//-----------------------------------------------------------------
{
  return iInterpreter;
}
