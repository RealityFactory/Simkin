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
  
  $Id: CSimkinAppView.cpp,v 1.5 2003/04/19 13:22:24 simkin_cvs Exp $
*/

#include "CSimkinAppView.h"
#include "CSimkinAppUi.h"
#include "CSimkinDocument.h"
#include <eiklabel.h>
#include <eikcmbut.h>

_LIT(KTitle,"Title");
_LIT(KX,"X");
_LIT(KY,"Y");
_LIT(KHeight,"Height");
_LIT(KControls,"Controls");
_LIT(KText,"Text");
_LIT(KType,"Type");
_LIT(KWidth,"Width");
_LIT(KId,"Id");
_LIT(KMethod,"Method");
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
    CEikEdwin * editor=iView->FindEditor(args[0].str());
    if (editor!=0){
      iView->SetFocus(editor);
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
      //      label->Invalidate();
      label->SetTextL(args[1].str().ptr());
      //      label->DrawReferred();
      iView->DrawNow();
      // should be able to do this
      //label->DrawNow();
    }
    bRet=true;
  // handles the user(text) method - shows the given text in an alert window
  }else if (method_name==Kuser && args.entries()==1){
    CEikonEnv::Static()->AlertWin(args[0].str().ptr());
    bRet=true;
  }else
    //    we pass any other method up to the base class, which in turn looks inside
    //    the demo script file for a matching method
    bRet=skTreeNodeObject::method(method_name,args,ret,ctxt);
  return bRet;
}
//-----------------------------------------------------------------
CSimkinAppView::CSimkinAppView()
//-----------------------------------------------------------------
  : iDocument(0)
{
}
//-----------------------------------------------------------------
CSimkinAppView* CSimkinAppView::NewL(const TRect& aRect,CSimkinAppUi * aUi,const TDesC& aLocation,CSimkinDocument * aDocument)
//-----------------------------------------------------------------
{
  CSimkinAppView* self = new(ELeave) CSimkinAppView();
  CleanupStack::PushL(self);
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
  iScript->setNode(iScript->getLocation(),iDocument->script(),false);
  CreateControlsL(iDocument->script());
  ActivateL();
  DrawNow();
  // call the init function
  CallMethodL(Kinit);
}
//-----------------------------------------------------------------
void CSimkinAppView::CreateControlsL(skTreeNode * script)
//-----------------------------------------------------------------
{
  if (script){
    skTreeNode * controls=script->findChild(KControls);
    if (controls){
      iNumControls=0;
      USize num_controls=controls->numChildren();
      if (num_controls){
        iControls=new (ELeave) CCoeControl*[num_controls];
        iControlNodes=new (ELeave) skTreeNode*[num_controls];
	USize i=0;
        for (i=0;i<num_controls;i++){
	  iControls[i]=0;
	  iControlNodes[i]=0;
	}
        for (i=0;i<num_controls;i++){
          skTreeNode * control=controls->nthChild(i);
          skString type=control->findChildData(KType);
          int id=control->findChildIntData(KId);
          skString text=control->findChildData(KText);
          TInt x_pos=control->findChildIntData(KX);
          TInt y_pos=control->findChildIntData(KY);
          TInt width=control->findChildIntData(KWidth);
          TInt height=control->findChildIntData(KHeight);
          CCoeControl * coe=AddControlL(type,id,text,x_pos,y_pos,width,height);
          if (coe){
            iControlNodes[iNumControls]=control;
            iControls[iNumControls]=coe;
            iNumControls++;
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
    iScript->setNode(aLocation,aDocument->script(),false);
    CreateControlsL(aDocument->script());
  }
  ActivateL();
  if (iFocusControl)
    iFocusControl->SetFocus(ETrue);
  SetRect(aRect);
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
    control=label;
    CleanupStack::Pop(label);
  // type Edit 
  }else if (type==KEdit){
    CEikEdwin * edit=new (ELeave)CEikEdwin;
    CleanupStack::PushL(edit);
    edit->ConstructL(CEikEdwin::EWidthInPixels+CEikEdwin::EAllowPictures+EEikEdwinNoWrap,width,0,1);
    edit->SetContainerWindowL(*this);
    edit->SetExtent(pos,edit->MinimumSize());
    edit->SetObserver(this);
    edit->SetFocusing(ETrue);
    iFocusControl=edit;
    control=edit;
    CleanupStack::Pop(edit);
  // type Button
  }else if (type==KButton){
    CEikTextButton * button=new (ELeave)CEikTextButton;
    CleanupStack::PushL(button);
    button->SetContainerWindowL(*this);
    button->SetTextL(text.ptr());
    button->SetExtent(pos,button->MinimumSize());
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
  // might be able to do without this
  CWindowGc& gc = SystemGc();
  gc.Clear();
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
    if (iControlNodes[i]->findChildData(KId)==id && iControlNodes[i]->findChildData(KType)==KEdit){
      editor=reinterpret_cast<CEikEdwin *>(iControls[i]);
      break;
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
    if (iControlNodes[i]->findChildData(KId)==id && iControlNodes[i]->findChildData(KType)==KStatic){
      label=reinterpret_cast<CEikLabel *>(iControls[i]);
      break;
    }
  }
  return label;
}
//-----------------------------------------------------------------
skTreeNode * CSimkinAppView::FindControlNode(CCoeControl* aControl)
//-----------------------------------------------------------------
{
  skTreeNode * node=0;
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
    if (iFocusControl)
      iFocusControl->SetFocus(EFalse);
    iFocusControl=aControl;
    iFocusControl->SetFocus(ETrue);
    break;
  }
  case EEventStateChanged:{
    skTreeNode * node=FindControlNode(aControl);
    if (node){
      // look for a method associated with this control
      skString method_name=node->findChildData(KMethod);
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
    if (iFocusControl)
      response = iFocusControl->OfferKeyEventL(aKeyEvent, aType);
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
void CSimkinAppView::SetFocus(CCoeControl * ctl)
//-----------------------------------------------------------------
{
  if (iFocusControl!=ctl){
    if (iFocusControl)
      iFocusControl->SetFocus(EFalse);
    iFocusControl=ctl;
    if (iFocusControl)
      iFocusControl->SetFocus(ETrue);
  }
}
