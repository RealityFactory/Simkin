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
  
  $Id: CSimkinAppView.h,v 1.2 2003/04/19 13:22:24 simkin_cvs Exp $
*/
#ifndef CSIMKINAPPVIEW_H
#define CSIMKINAPPVIEW_H

#include "skRValueArray.h"
#include "skElementObject.h"
#include <coecobs.h>
#include <eikedwin.h>
#include <eiklabel.h>

class CSimkinAppView;
class CSimkinAppUi;
class CSimkinDocument;

/**
 * This class provides a wrapper for the Simkin script methods
 */
class CSimkinAppViewScript : public skElementObject
{
 public:
  CSimkinAppViewScript(CSimkinAppView * aView);
  /**
   * This is called when a script calls a method
   */
  bool method(const skString& method_name,skRValueArray& args,skRValue& ret,skExecutableContext& ctxt);
 private:
  CSimkinAppView * iView;
};
/**
 * This class provides the view for the Simkin Demo
 */
class CSimkinAppView : public CCoeControl ,public MCoeControlObserver
{
 public:
  virtual ~CSimkinAppView();
  /** Creates a new view */
  static CSimkinAppView* NewL(const TRect& aRect,CSimkinAppUi * aUi,const TDesC& aLocation,CSimkinDocument * aDocument);
  /** returns number of controls on the view */
  TInt CountComponentControls() const;
  /** returns the given control on the view */
  CCoeControl* ComponentControl(TInt aIndex) const;
  /** handles button press and focus change events */
  void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
  /** passes key events to the focussed control */
  TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);
  /** reloads the view from a changed script */
  void ReloadL();
 private:
  CSimkinAppView();
  /** Initialization phase */
  void ConstructL(const TRect& aRect,CSimkinAppUi * aUi,const TDesC& aLocation,CSimkinDocument * aDocument);
  /** Creates controls on the view from the list specified in the script */
  void CreateControlsL(skElement * script);
  /** Deletes the controls on the view */
  void ClearControls();
  void Draw(const TRect& /*aRect*/) const;
  /** Creates a control from the given specification */
  CCoeControl * AddControlL(const skString& type,int id,const skString& text,TInt x_pos,TInt y_pos,TInt width,TInt height);
  /** Finds the script information associated with a particular control 
   * @return the script, or 0 if none was found
   */
  skElement * FindControlNode(CCoeControl* aControl);
  /** Finds the editor control with the given id 
   * @return the editor, or 0 if none was found
   */
  CEikEdwin * FindEditor(const skString& id);
  /** Finds the label control with the given id 
   * @return the label, or 0 if none was found
   */
  CEikLabel * FindLabel(const skString& id);
 private:
  /** Sets focus on a control */
  void SetFocus(CCoeControl * ctl);
  /** Calls a method within the script*/
  void CallMethodL(const TDesC& method_name);
  /** An array of controls on the view */
  CCoeControl** iControls;
  /** An array of references to the corresponding script entries */
  skElement ** iControlNodes;
  /** the number of controls on the view */
  TInt iNumControls;
  /** the control with the current keyboard focus */
  CCoeControl* iFocusControl;
  /** the underlying Simkin document, which contains the script */
  CSimkinDocument * iDocument;
  /** This object wraps the script to provide an executable interface for Simkin scripts */
  CSimkinAppViewScript * iScript;
  friend class CSimkinAppViewScript;
  /** The associated UI */
  CSimkinAppUi * iUi;
};


#endif
