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
  
  $Id: CSimkinAppView.cpp,v 1.4 2003/04/25 21:05:12 simkin_cvs Exp $
*/

#include "CSimkinAppView.h"
#include "CSimkinAppUi.h"
#include "CSimkinDocument.h"
#include <eiklabel.h>
#include <eikcmbut.h>

_LIT(KTitle,"title");
_LIT(KX,"x");
_LIT(KY,"y");
_LIT(KHeight,"height");
_LIT(KControls,"controls");
_LIT(KText,"text");
_LIT(KType,"type");
_LIT(KWidth,"width");
_LIT(KId,"id");
_LIT(KMethod,"method");
_LIT(KeditCode,"editCode");
_LIT(KgetText,"getText");
_LIT(KsetText,"setText");
_LIT(Kuser,"user");
_LIT(Kinit,"init");
_LIT(KStatic,"Static");
_LIT(KEdit,"Edit");
_LIT(KNumericEdit,"NumericEdit");
_LIT(KButton,"Button");
_LIT(KsetFocus,"setFocus");


//-----------------------------------------------------------------
CSimkinAppViewScript::CSimkinAppViewScript(CSimkinAppView * aView)
  //-----------------------------------------------------------------
  : iView(aView)
{
}
//-----------------------------------------------------------------
bool CSimkinAppViewScript::method(const skString& method_name,skRValueArray& args,skRValue& ret,skExecutableContext& ctxt)
  //-----------------------------------------------------------------
{
  bool bRet=false;
  // handles the setFocus(id) method - sets focus to the given editor control
  if (method_name==KsetFocus && args.entries()==1){
    bRet=true;
    CEikEdwin * editor=iView->FindEditor(args[0].str());
    if (editor!=0){
      iView->SetFocusToControl(editor);
    }
  // handles the getText(id) method - returns the text in the named edit control
  }else if (method_name==KgetText && args.entries()==1){
    CEikEdwin * editor=iView->FindEditor(args[0].str());
    if (editor!=0){
      skString s_text;
      HBufC* text=editor->GetTextInHBufL();
      if (text){
        CleanupStack::PushL(text);
        // this might leave
        s_text=*text;
        CleanupStack::PopAndDestroy(text);
      }
      ret=s_text;
    }
    bRet=true;
    // handles the setText(id,text) method - sets the text in the given named label
  }else if (method_name==KsetText && args.entries()==2){
    CEikLabel * label=iView->FindLabel(args[0].str());
    if (label!=0){
      label->SetTextL(args[1].str().ptr());
      iView->DrawNow();
    }
    bRet=true;
    // handles the user(text) method - shows the given text in an alert window
  }else if (method_name==Kuser && args.entries()==1){
    CEikonEnv::Static()->AlertWin(args[0].str().ptr());
    bRet=true;
  }else
    //    we pass any other method up to the base class, which in turn looks inside
    //    the demo script file for a matching method
    bRet=skElementObject::method(method_name,args,ret,ctxt);
  return bRet;
}
//-----------------------------------------------------------------
CSimkinAppView::CSimkinAppView()
  //-----------------------------------------------------------------
  : iDocument(0),iFocusControlIndex(-1)
{
}
//-----------------------------------------------------------------
CSimkinAppView* CSimkinAppView::NewL(const TRect& aRect,CSimkinAppUi * aUi,const TDesC& aLocation,CSimkinDocument * aDocument)
  //-----------------------------------------------------------------
{
  CSimkinAppView* self = new(ELeave) CSimkinAppView();
  CleanupStack::PushL(self);
#ifdef SERIES_60
  self->SetMopParent(aUi);
#endif
  self->ConstructL(aRect,aUi,aLocation,aDocument);
  CleanupStack::Pop();
  return self;
}
//-----------------------------------------------------------------
CSimkinAppView::~CSimkinAppView()
  //-----------------------------------------------------------------
{
  ClearControls();
  delete iScript;
  iScript=0;
}
//-----------------------------------------------------------------
void CSimkinAppView::ClearControls()
  //-----------------------------------------------------------------
{
  if (iControls){
    if (iFocusControlIndex!=-1){
      iControls[iFocusControlIndex]->SetFocus(EFalse);
      iFocusControlIndex=-1;
    }
    for (TInt i=0;i<iNumControls;i++){
      delete iControls[i];
      iControls[i]=0;
    }
    delete [] iControls;
    iControls=0;
    delete [] iControlNodes;
    iControlNodes=0;
  }
}
//-----------------------------------------------------------------
void CSimkinAppView::ReloadL()
  //-----------------------------------------------------------------
{
  ClearControls();
  iScript->setElement(iScript->getLocation(),iDocument->script(),false);
  CreateControlsL(iDocument->script());
  ActivateL();
  DrawNow();
  // call the init function
  CallMethodL(Kinit);
}
//-----------------------------------------------------------------
void CSimkinAppView::CreateControlsL(skElement * script)
  //-----------------------------------------------------------------
{
  if (script){
    skElement * controls=skElementObject::findChild(script,KControls);
    if (controls){
      iNumControls=0;
      USize num_controls=skElementObject::countChildren(controls);
      if (num_controls){
        iControls=new (ELeave) CCoeControl*[num_controls];
        iControlNodes=new (ELeave) skElement*[num_controls];
        USize i=0;
        for (i=0;i<num_controls;i++){
          iControls[i]=0;
          iControlNodes[i]=0;
        }
        skNodeList& nodes=controls->getChildNodes();
        for (i=0;i<nodes.entries();i++){
          skNode * control_node=nodes[i];
          if (control_node->getNodeType()==skNode::ELEMENT_NODE){
            skElement * control=reinterpret_cast<skElement *>(control_node);
            skString type=control->getAttribute(KType);
            int id=control->getAttribute(KId).to();
            skString text=control->getAttribute(KText);
            TInt x_pos=control->getAttribute(KX).to();
            TInt y_pos=control->getAttribute(KY).to();
            TInt width=control->getAttribute(KWidth).to();
            TInt height=control->getAttribute(KHeight).to();
            CCoeControl * coe=AddControlL(type,id,text,x_pos,y_pos,width,height);
            if (coe){
#ifdef SERIES_60
              coe->SetMopParent(this);
#endif            
              iControlNodes[iNumControls]=control;
              iControls[iNumControls]=coe;
              iNumControls++;
            }
          }
        }
      }
    }
  }else{
    _LIT(KNoScript,"No script to load!");
    CEikonEnv::Static()->AlertWin(KNoScript);
  }
}
//-----------------------------------------------------------------
void CSimkinAppView::ConstructL(const TRect& aRect,CSimkinAppUi * aUi,const TDesC& aLocation,CSimkinDocument * aDocument)
  //-----------------------------------------------------------------
{
  iUi=aUi;
  iDocument=aDocument;
  iScript=new (ELeave) CSimkinAppViewScript(this);
   
  CreateWindowL();
  if (aDocument->script()){
    skString location;
    SAVE_VARIABLE(location);
    location=aLocation;
    iScript->setElement(location,aDocument->script(),false);
    CreateControlsL(aDocument->script());
    RELEASE_VARIABLE(location);
  }
  if (iFocusControlIndex!=-1)
    iControls[iFocusControlIndex]->SetFocus(ETrue);
  SetRect(aRect);
  ActivateL();
  // call the init function
  CallMethodL(Kinit);
}
//-----------------------------------------------------------------
CCoeControl * CSimkinAppView::AddControlL(const skString& type,int id,const skString& text,TInt x_pos,TInt y_pos,TInt width,TInt height)
  //-----------------------------------------------------------------
{
  CCoeControl * control=0;
  TPoint pos(x_pos,y_pos);
  // type Static maps to a label
  if (type==KStatic){
    CEikLabel * label=new (ELeave) CEikLabel;
    CleanupStack::PushL(label);
    label->SetContainerWindowL(*this);
    label->SetTextL(text.ptr());
    if (width){
      TSize size=label->MinimumSize();
      size.iWidth=width;
      label->SetExtent(pos,size);
    }else
      label->SetExtent(pos,label->MinimumSize());
    label->SetFocusing(EFalse);
    control=label;
    CleanupStack::Pop(label);
    // type Edit 
  }else if (type==KEdit || type==KNumericEdit){
    CEikEdwin * edit=new (ELeave)CEikEdwin;
    CleanupStack::PushL(edit);
    edit->ConstructL(CEikEdwin::EWidthInPixels,width,0,1);
    if (type==KNumericEdit){
      TCoeInputCapabilities inputCapabilities(TCoeInputCapabilities::ENavigation | TCoeInputCapabilities::EWesternNumericIntegerPositive | TCoeInputCapabilities::EWesternNumericIntegerNegative);
      edit->SetInputCapabilitiesL(inputCapabilities);
    }
    edit->SetContainerWindowL(*this);
    edit->SetExtent(pos,edit->MinimumSize());
    edit->SetObserver(this);
    edit->SetFocusing(ETrue);
    control=edit;
    CleanupStack::Pop(edit);
    // type Button
  }else if (type==KButton){
    CEikTextButton * button=new (ELeave)CEikTextButton;
    CleanupStack::PushL(button);
    button->SetContainerWindowL(*this);
    button->SetTextL(text.ptr());
    button->SetExtent(pos,button->MinimumSize());
#ifdef SERIES_60
    button->SetFocusing(ETrue);
#endif
    control=button;
    button->SetObserver(this);
    CleanupStack::Pop(button);
  }
  return control;
}
//-----------------------------------------------------------------
void CSimkinAppView::Draw(const TRect& /*aRect*/) const
  //-----------------------------------------------------------------
{
  CWindowGc& gc = SystemGc();
  gc.Clear();
#ifdef SERIES_60
  if (iFocusControlIndex!=-1){
    // draw a border around the control with focus for the Series 60
    TRect size=iControls[iFocusControlIndex]->Rect();
    size.Grow(2,2);
    gc.DrawRect(size);
  }
#endif
}
//-----------------------------------------------------------------
TInt CSimkinAppView::CountComponentControls() const
  //-----------------------------------------------------------------
{
  return iNumControls;
}
//-----------------------------------------------------------------
CEikEdwin * CSimkinAppView::FindEditor(const skString& id)
  //-----------------------------------------------------------------
{
  CEikEdwin * editor=0;
  for (TInt i=0;i<iNumControls;i++){
    if (iControlNodes[i]->getAttribute(KId)==id){
      skString type=iControlNodes[i]->getAttribute(KType);
      if (type==KEdit || type==KNumericEdit){
        editor=reinterpret_cast<CEikEdwin *>(iControls[i]);
        break;
      }
    }
  }
  return editor;
}
//-----------------------------------------------------------------
CEikLabel * CSimkinAppView::FindLabel(const skString& id)
  //-----------------------------------------------------------------
{
  CEikLabel * label=0;
  for (TInt i=0;i<iNumControls;i++){
    if (iControlNodes[i]->getAttribute(KId)==id && 
        iControlNodes[i]->getAttribute(KType)==KStatic){
      label=reinterpret_cast<CEikLabel *>(iControls[i]);
      break;
    }
  }
  return label;
}
//-----------------------------------------------------------------
skElement * CSimkinAppView::FindControlNode(CCoeControl* aControl)
  //-----------------------------------------------------------------
{
  skElement * node=0;
  for (TInt i=0;i<iNumControls;i++){
    if (iControls[i]==aControl){
      node=iControlNodes[i];
      break;
    }
  }
  return node;
}
//-----------------------------------------------------------------
void CSimkinAppView::CallMethodL(const TDesC& method_name)
//-----------------------------------------------------------------
{
  skRValueArray args;
  skRValue aReturnValue;
  skExecutableContext context(iDocument->interpreter());
  // call the method
  skString s_method_name;
  SAVE_VARIABLE(s_method_name);
  // make sure we have a Simkin string method name
  s_method_name=method_name;
  iScript->method(s_method_name,args,aReturnValue,context);
  RELEASE_VARIABLE(s_method_name);
}
//-----------------------------------------------------------------
void CSimkinAppView::HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType)
  //-----------------------------------------------------------------
{
  switch(aEventType){
  case EEventRequestFocus:{
    if (iFocusControlIndex!=-1)
      iControls[iFocusControlIndex]->SetFocus(EFalse);
    iFocusControlIndex=-1;
    for (TInt i=0;i<iNumControls;i++){
      if (iControls[i]==aControl){
        iFocusControlIndex=i;
        aControl->SetFocus(ETrue);
        break;
      }
    }
    break;
  }
  case EEventStateChanged:{
    skElement * node=FindControlNode(aControl);
    if (node){
      // look for a method associated with this control
      skString method_name=node->getAttribute(KMethod);
      if (method_name.length())
        CallMethodL(method_name.ptr());
    }
    break;
  }
  }
}
//-----------------------------------------------------------------
TKeyResponse CSimkinAppView::OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType)
  //-----------------------------------------------------------------
{
  TKeyResponse response = EKeyWasNotConsumed;
  if (aType==EEventKey){
#ifdef SERIES_60
    // There's no pointer on a Series 60, so we support a moving focus 
    if (aKeyEvent.iCode==EKeyDownArrow){
      // focus on the next control
      if (iFocusControlIndex!=-1){
        iControls[iFocusControlIndex]->SetFocus(EFalse);
        do{
          iFocusControlIndex++;
          iFocusControlIndex%=iNumControls;
        }while(iControls[iFocusControlIndex]->IsNonFocusing());
        iControls[iFocusControlIndex]->SetFocus(ETrue);
        DrawNow();
      }else{
        iFocusControlIndex=0;
        iControls[iFocusControlIndex]->SetFocus(ETrue);
        DrawNow();
      }
    }else if (aKeyEvent.iCode==EKeyUpArrow){
      // focus on the previous control
      if (iFocusControlIndex!=-1){
        iControls[iFocusControlIndex]->SetFocus(EFalse);
        do{
          if (iFocusControlIndex==0){
            iFocusControlIndex=iNumControls-1;
          }else{
            iFocusControlIndex--;
            iFocusControlIndex%=iNumControls;
          }
        }while(iControls[iFocusControlIndex]->IsNonFocusing());
        iControls[iFocusControlIndex]->SetFocus(ETrue);
        DrawNow();
      }else{
        iFocusControlIndex=0;
        iControls[iFocusControlIndex]->SetFocus(ETrue);
        DrawNow();
      }
    }else if (aKeyEvent.iCode==EKeyDevice3){
      // It seems that EKeyDevice3 represents the OK button on a Series 60 - is this a valid assumption?
      if (iFocusControlIndex!=-1){
        skElement * node=FindControlNode(iControls[iFocusControlIndex]);
        if (node){
          // look for a method associated with this control
          skString method_name=node->getAttribute(KMethod);
          if (method_name.length())
            CallMethodL(method_name.ptr());
        }
      }
    }else 
#endif
      if (iFocusControlIndex!=-1)
        response = iControls[iFocusControlIndex]->OfferKeyEventL(aKeyEvent, aType);
  }
  return(response);
}
//-----------------------------------------------------------------
CCoeControl* CSimkinAppView::ComponentControl(TInt aIndex) const
  //-----------------------------------------------------------------
{
  CCoeControl* aControl=0;
  if (aIndex<iNumControls)
    aControl=iControls[aIndex];
  return aControl;
}
//-----------------------------------------------------------------
void CSimkinAppView::SetFocusToControl(CCoeControl * ctl)
//-----------------------------------------------------------------
{
  TInt new_focus=-1;
  for (TInt i=0;i<iNumControls;i++){
    if (ctl==iControls[i])
      new_focus=i;
  }
  if (iFocusControlIndex!=new_focus){
    if (iFocusControlIndex!=-1)
      iControls[iFocusControlIndex]->SetFocus(EFalse);
    iFocusControlIndex=new_focus;
    if (iFocusControlIndex!=-1)
      iControls[iFocusControlIndex]->SetFocus(ETrue);
  }
}
