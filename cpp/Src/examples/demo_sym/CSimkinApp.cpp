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
  
  $Id: CSimkinApp.cpp,v 1.1 2003/04/11 10:17:39 simkin_cvs Exp $
*/


#include "CSimkinApplication.h"

//-----------------------------------------------------------------
EXPORT_C CApaApplication* NewApplication()
//-----------------------------------------------------------------
{
  return new CSimkinApplication;
}
//-----------------------------------------------------------------
GLDEF_C TInt E32Dll(TDllReason)
//-----------------------------------------------------------------
{
  return KErrNone;
}

