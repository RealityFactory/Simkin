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
  
  $Id: CSimkinAppUi.cpp,v 1.1 2003/04/11 10:17:39 simkin_cvs Exp $
*/
#include "CSimkinAppUi.h"
#include "CSimkinAppView.h"
#include "CSimkinAppCodeDialog.h"
#include "skStringBuffer.h"
#include "skOutputDestination.h"
#include <SimkinDemo.rsg>
#include "SimkinDemo.hrh"
#include "CSimkinDocument.h"

//-----------------------------------------------------------------
CSimkinAppUi::CSimkinAppUi(const TDesC& aLocation,CSimkinDocument * aDocument)
//-----------------------------------------------------------------
  : iLocation(aLocation),iDocument(aDocument)
{
}
//-----------------------------------------------------------------
void CSimkinAppUi::ConstructL()
//-----------------------------------------------------------------
{
  BaseConstructL();
  iAppView = CSimkinAppView::NewL(ClientRect(),this,iLocation,iDocument);
  AddToStackL(iAppView);
}
//-----------------------------------------------------------------
CSimkinAppUi::~CSimkinAppUi()
//-----------------------------------------------------------------
{
  if (iAppView){
    RemoveFromStack(iAppView);
    delete iAppView;
  }
}
//-----------------------------------------------------------------
void CSimkinAppUi::HandleCommandL(TInt aCommand)
//-----------------------------------------------------------------
{
  switch (aCommand){
  case EEikCmdEditCode:{
    skString code;
    SAVE_VARIABLE(code);
    code=iDocument->GetScriptAsStringL();
    CSimkinAppCodeDialog * dialog=new (ELeave) CSimkinAppCodeDialog(&code);
    if (dialog->ExecuteLD(R_EDIT_CODE_DIALOG)){
      if (iDocument->LoadScriptFromStringL(code)){
	iAppView->ReloadL();
      }else{
	_LIT(KNoScript,"You had a syntax error in your script");
	CEikonEnv::Static()->AlertWin(KNoScript);
      }
    }
    RELEASE_VARIABLE(code);
    break;
  }
  case EEikCmdExit: 
    Exit();
    break;
  }
}

