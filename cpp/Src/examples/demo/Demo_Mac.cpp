/*
  Copyright 1996-2000
  Simon Whiteside

  $Id: Demo_Mac.cpp,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/
#include <Windows.h>
#include "Demo_View.h"

int g_ContinueEventLoop=1;

//-----------------------------------------------------------------
void InitializeEventLoop()
  //-----------------------------------------------------------------
{
  ::MaxApplZone();
  ::MoreMasters();
  ::InitGraf(&qd.thePort);
  ::InitFonts();
  ::InitWindows();
  ::InitMenus();
  ::TEInit();
  ::InitDialogs(NULL);
  ::InitCursor();	
  ::FlushEvents(everyEvent,0);	
}
//-----------------------------------------------------------------
void TerminateEventLoop()
  //-----------------------------------------------------------------
{
}
//-----------------------------------------------------------------
int ProcessEventLoop()
  //-----------------------------------------------------------------
{
  EventRecord eventRec;
  long sleep=::LMGetCaretTime();
  while (g_ContinueEventLoop==1){
    ::WaitNextEvent(everyEvent,&eventRec,sleep,0);
    switch(eventRec.what){
    case mouseDown:{
      WindowPtr	windowPtr=0;
      SInt16	partCode = ::FindWindow(eventRec.where,&windowPtr);
      switch(partCode){
      case inContent:{
	::SelectWindow(windowPtr);
	ControlHandle controlHdl;
	::SetPort(windowPtr);
	::GlobalToLocal(&eventRec.where);
	SInt16 controlPartCode=::FindControl(eventRec.where,windowPtr,&controlHdl);
	if (controlHdl){
	  if (::TrackControl(controlHdl,eventRec.where,0)){
	    if (controlPartCode==kControlButtonPart){
	      int id=::GetControlReference(controlHdl);
	      View * view=(View *)::GetWRefCon(windowPtr);
	      if (view)
		view->m_Callback.buttonPressed(id);
	    }
	  }
	}
	break;
      }
      case inSysWindow:
	::SystemClick(&eventRec,windowPtr);
      break;
      case inDrag:
	::DragWindow(windowPtr,eventRec.where,&(**::GetGrayRgn()).rgnBBox);
      break;
      case inGoAway:
	if(::TrackGoAway(windowPtr,eventRec.where) == TRUE){
	  View * view=(View *)::GetWRefCon(windowPtr);
	  if (view)
	    view->close();
	}
	break;
      }
      break;
    }
    case mouseUp:
      break;
    case keyDown:
    case autoKey:{
      WindowPtr windowPtr=::FrontWindow();
      if (windowPtr){
	ControlHandle focusControl=0;
	SInt16 keyCode=(eventRec.message & keyCodeMask)>>8;
	SInt16 charCode=(eventRec.message & charCodeMask);
	::GetKeyboardFocus (windowPtr,&focusControl);
	if (focusControl){
	  ::HandleControlKey (focusControl,keyCode,charCode,eventRec.modifiers);
	}
      }
      break;
    }
    case keyUp:
      g_ContinueEventLoop=0;
      break;
    case updateEvt:
      ::BeginUpdate((WindowPtr)eventRec.message);
    ::UpdateControls((WindowPtr)eventRec.message,((WindowPtr)eventRec.message)->visRgn);
    ::EndUpdate((WindowPtr)eventRec.message);
    break;
    case activateEvt:
      break;
    case nullEvent:{
      WindowPtr windowPtr=::FrontWindow();
      if (windowPtr)
	::IdleControls(windowPtr);
      break;
    }
    case osEvt:
      break;
    case kHighLevelEvent:
      break;
    }		
  }
  return 0;
}
