/*
  Copyright 1996-2000
  Simon Whiteside

  $Id: Demo_View_Mac.cpp,v 1.2 2000/12/21 15:59:35 sdw Exp $
*/
#include "Demo_View.h"
#include <Windows.h>
#include <TextUtils.h>

extern int g_ContinueEventLoop;

//-----------------------------------------------------------------
inline void CopyToPascalString(Str255 dest,skString& src)
  //-----------------------------------------------------------------
{
  dest[0]=max(src.length(),254);
  strncpy((char *)(dest+1),(const char *)src,(long)dest[0]);
}
//-----------------------------------------------------------------
View::View(ViewCallback& callback,skString title,int x,int y,int width,int height)
  //-----------------------------------------------------------------
  : m_Callback(callback),m_Handle(0)
{
  Rect rc;
  rc.left=x;rc.right=x+width;
  rc.top=y;rc.bottom=y+height;
  Str255 ptitle;
  CopyToPascalString(ptitle,title);
  m_Handle=::NewCWindow(0,&rc,ptitle,TRUE,documentProc,(WindowPtr)-1,TRUE,(long)this);
  ControlHandle rootControl;
  ::CreateRootControl((WindowPtr)m_Handle,&rootControl);

}
//-----------------------------------------------------------------
View::~View()
  //-----------------------------------------------------------------
{
  if (m_Handle)
    ::DisposeWindow((WindowPtr)m_Handle);
}
//-----------------------------------------------------------------
void View::close()
  //-----------------------------------------------------------------
{
  g_ContinueEventLoop=0;
}
//-----------------------------------------------------------------
void View::addControl(skString type,int id,skString text,int x,int y,int width,int height)
  //-----------------------------------------------------------------
{
  Rect rc;
  rc.left=x;rc.right=x+width;
  rc.top=y;rc.bottom=y+height;
  Str255 ptext;
  CopyToPascalString(ptext,text);
  if (type=="Static"){
    ControlHandle handle=::NewControl((WindowPtr)m_Handle,&rc,0,TRUE,0,0,0,kControlStaticTextProc,id);
    ::SetControlData(handle,0,kControlStaticTextTextTag,
		     text.length(),(Ptr)(const char *)text);	
  }else
    if (type=="Edit"){
      ControlHandle handle=::NewControl((WindowPtr)m_Handle,&rc,0,TRUE,0,0,0,kControlEditTextProc,id);
      ::SetControlData(handle,0,kControlEditTextTextTag,text.length(),(Ptr)(const char *)text);
    }else
      if (type=="Button"){
	::NewControl((WindowPtr)m_Handle,&rc,ptext,TRUE,0,0,0,pushButProc,id);
      }
}
//-----------------------------------------------------------------
static ControlHandle FindControlFromId(WindowPtr windowPtr,int id)
  //-----------------------------------------------------------------
{
  WindowPeek windowPeek=(WindowPeek)windowPtr;
  ControlHandle child=(ControlHandle)(windowPeek->controlList);
  while (child){
    if (::GetControlReference(child)==id)
      break;
    else
      child=(*child)->nextControl;
  }
  return child;
}
//-----------------------------------------------------------------
void View::run(skString file)
  //-----------------------------------------------------------------
{
  user("Sorry, running apps is not implemented in the Mac Demo");
}
//-----------------------------------------------------------------
skString View::getText(int id) const
  //-----------------------------------------------------------------
{
  skString s;
  ControlHandle child=FindControlFromId((WindowPtr)m_Handle,id);
  if (child){
    //	naughty! assume the control is an edit field
    Size len=0;
    ::GetControlDataSize(child,0,kControlEditTextTextTag,&len);
    if (len){
      unsigned char * buffer=new unsigned char[len+1];
      SInt32 actualLen=0;
      ::GetControlData(child,0,kControlEditTextTextTag,len,(Ptr)buffer,&actualLen);
      buffer[actualLen]=0;
      s=skString::fromBuffer(buffer);
    }
  }
  return s;
}
//-----------------------------------------------------------------
void View::setFocus(int id)
  //-----------------------------------------------------------------
{
  ControlHandle child=FindControlFromId((WindowPtr)m_Handle,id);
  if (child)
    ::SetKeyboardFocus((WindowPtr)m_Handle,child,kControlEditTextPart);
}
//-----------------------------------------------------------------
void View::user(skString msg)
  //-----------------------------------------------------------------
{
  Str255 ptext;
  CopyToPascalString(ptext,msg);
  SInt16 itemHit;
  StandardAlert (kAlertNoteAlert,ptext,0,0,&itemHit);
}

