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
  
  $Id: CSimkinAppUi.h,v 1.1 2003/04/16 21:48:06 simkin_cvs Exp $
*/
#ifndef CSIMKINAPPUI_H
#define CSIMKINAPPUI_H

#include <qikappui.h>
class CSimkinDocument;
class CSimkinAppView;

/**
 * This class provides a controller for the Simkin Demo
 */
class CSimkinAppUi : public CQikAppUi
{
 public:
  CSimkinAppUi(const TDesC& aLocation,CSimkinDocument * aDocument);
  void ConstructL();
  ~CSimkinAppUi();

 private:
  void HandleCommandL(TInt aCommand);


 private:
  CSimkinAppView* iAppView;
  CSimkinDocument * iDocument;
  const TDesC& iLocation;
};

#endif

