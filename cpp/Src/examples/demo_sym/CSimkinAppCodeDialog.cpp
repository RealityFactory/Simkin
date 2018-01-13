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
  
  $Id: CSimkinAppCodeDialog.cpp,v 1.2 2003/04/14 15:06:19 simkin_cvs Exp $
*/
#include "CSimkinAppCodeDialog.h"
#include <eikdialg.h>
#include "SimkinDemo.hrh"
#include <eikedwin.h>

//-----------------------------------------------------------------
CSimkinAppCodeDialog::~CSimkinAppCodeDialog()
//-----------------------------------------------------------------
{
}
//-----------------------------------------------------------------
void CSimkinAppCodeDialog::PreLayoutDynInitL()
//-----------------------------------------------------------------
{
  iSCode->replaceInPlace('\n',CEditableText::EParagraphDelimiter);
  iCode.Set(iSCode->ptr());
  CEikEdwin* edwin;
  edwin=STATIC_CAST(CEikEdwin*, Control(ECodeId));
  edwin->SetTextL(&iCode);
  edwin->SetSelectionL(1,1);
}
//-----------------------------------------------------------------
TBool CSimkinAppCodeDialog::OkToExitL(TInt aKeycode)
//-----------------------------------------------------------------
{
  CEikEdwin* edwin;
  edwin=STATIC_CAST(CEikEdwin*, Control(ECodeId));
  HBufC* text=edwin->GetTextInHBufL();
  CleanupStack::PushL(text);
  *iSCode=*text;
  CleanupStack::PopAndDestroy(text);
  iSCode->replaceInPlace(CEditableText::EParagraphDelimiter,'\n');
  return ETrue;
}
