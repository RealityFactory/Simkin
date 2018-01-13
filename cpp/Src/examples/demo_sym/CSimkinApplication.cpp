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
  
  $Id: CSimkinApplication.cpp,v 1.2 2003/04/14 15:06:19 simkin_cvs Exp $
*/

#include "CSimkinApplication.h"
#include "CSimkinDocument.h"

const TUid KUidSimkin = { 0x101FAE0B }; 
_LIT(KScriptFileName,"c:\\documents\\simkin\\SimkinDemo.dat");

//-----------------------------------------------------------------
TUid CSimkinApplication::AppDllUid() const
//-----------------------------------------------------------------
{
  return KUidSimkin;
}
//-----------------------------------------------------------------
CApaDocument* CSimkinApplication::CreateDocumentL()
//-----------------------------------------------------------------
{
  return new (ELeave) CSimkinDocument(*this,KScriptFileName);
}
