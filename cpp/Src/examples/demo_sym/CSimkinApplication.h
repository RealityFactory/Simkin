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
  
  $Id: CSimkinApplication.h,v 1.3 2003/04/25 18:21:46 simkin_cvs Exp $
*/

#ifndef CSIMKINAPPLICATION_H
#define CSIMKINAPPLICATION_H

#include "Platform.h"

#ifdef QUARTZ_SDK
#include <qikdocument.h>
#include <qikapplication.h>
#else
#include <akndoc.h>
#include <aknapp.h>
#endif

/**
 * This class represents the Simkin Demo Application
 */
class CSimkinApplication 
#ifdef QUARTZ_SDK
: public CQikApplication
#else
: public CAknApplication
#endif
{
 private: 
  // Inherited from class CApaApplication
  CApaDocument* CreateDocumentL();
  TUid AppDllUid() const;
};

#endif
