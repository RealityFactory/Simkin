/*
  Copyright 1996-2002
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


  Demo_View_Win32.cpp

  This file implements the class View for the Windows platform

  $Id: Demo_View_Win32.cpp,v 1.4 2003/01/07 11:47:24 simkin_cvs Exp $
*/
#if defined(WIN32) || defined(_WIN32_WCE)
#include <windows.h>
#ifdef _WIN32_WCE
#include <sipapi.h>
#define USER_SHOWIM WM_USER+1000
#endif


#include "Demo_View.h"

extern HINSTANCE g_ModuleHandle;
extern HWND	g_MainWindow;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);

//-----------------------------------------------------------------
View::View(ViewCallback& callback,skString title,int x,int y,int width,int height)
  //-----------------------------------------------------------------
  : m_Callback(callback),m_Handle(0)
{
  WNDCLASS wc;
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WndProc ;
  wc.cbClsExtra = 0 ;
  wc.cbWndExtra = 0;
  wc.hInstance = g_ModuleHandle;
#ifdef _WIN32_WCE
  wc.hIcon = 0;
  wc.hCursor = 0;
  wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
#else
  wc.hIcon = LoadIcon (0, IDI_APPLICATION) ;
  wc.hCursor = LoadCursor (0, IDC_ARROW) ;
  wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1); 
#endif
  wc.lpszMenuName = 0;
  wc.lpszClassName = skSTR("View");
  ::RegisterClass (&wc);
  m_Handle=::CreateWindow(skSTR("View"),title,WS_OVERLAPPED|WS_CAPTION|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,width,height,0,0,g_ModuleHandle,0);
  if (m_Handle)
    ::SetWindowLong((HWND)m_Handle,GWL_USERDATA,(long)this);
#ifdef _WIN32_WCE
  // post a message to show the IM
  PostMessage((HWND)m_Handle,USER_SHOWIM,0,0);
#endif
}
//-----------------------------------------------------------------
View::~View()
  //-----------------------------------------------------------------
{
  ::DestroyWindow((HWND)m_Handle);
}
//-----------------------------------------------------------------
void View::close()
  //-----------------------------------------------------------------
{
  ::PostThreadMessage(::GetCurrentThreadId(),WM_QUIT,0,0);
}
//-----------------------------------------------------------------
void View::run(skString file)
  //-----------------------------------------------------------------
{
#ifdef _WIN32_WCE
  CreateProcess(file,NULL,NULL,NULL,FALSE,0,NULL,NULL,NULL,NULL);
#else
  ::WinExec(file,TRUE);
#endif
}
//-----------------------------------------------------------------
skString View::getText(int id) const
  //-----------------------------------------------------------------
{
  Char buffer[256];
  ::GetDlgItemText((HWND)m_Handle,id,buffer,256);
  return skString(buffer);
}
//-----------------------------------------------------------------
void View::setFocus(int id)
  //-----------------------------------------------------------------
{
  HWND hChild=::GetDlgItem((HWND)m_Handle,id);
  if (hChild)
    ::SetFocus(hChild);
}
//-----------------------------------------------------------------
void View::user(skString msg)
  //-----------------------------------------------------------------
{
  ::MessageBox((HWND)m_Handle,msg,skString(),MB_OK);
}
//-----------------------------------------------------------------
void View::addControl(skString type,int id,skString text,int x,int y,int width,int height)
  //-----------------------------------------------------------------
{
  skString className;
  DWORD dwStyle=WS_CHILD|WS_VISIBLE;
  if (type==skSTR("Static")){
    className=skSTR("STATIC");
    dwStyle|=SS_LEFT|WS_GROUP;
  }else
    if (type==skSTR("Edit")){
      className=skSTR("EDIT");
      dwStyle|=ES_LEFT|WS_BORDER|WS_TABSTOP;
    }else
      if (type==skSTR("Button")){
        className=skSTR("BUTTON");
        dwStyle|=BS_PUSHBUTTON|WS_TABSTOP;
      }
  HWND hwndChild=::CreateWindow(className,text,dwStyle,x,y,width,height,(HWND)m_Handle,(HMENU)id,g_ModuleHandle,0);
}
//-----------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
  //-----------------------------------------------------------------
{
  LRESULT r=0;
  switch(msg){
  case WM_ACTIVATE:
    if (LOWORD(wParam))
      g_MainWindow=hwnd;
    break;
  case WM_COMMAND:{
    WORD wID = LOWORD(wParam);
    HWND hwndCtl = (HWND) lParam;
    Char className[256];
    ::GetClassName(hwndCtl,className,256);
    if (skString(className).equalsIgnoreCase(skSTR("Button"))){
      View * view=(View *)::GetWindowLong(hwnd,GWL_USERDATA);
      if (view)
        view->m_Callback.buttonPressed(wID);
    }
    break;
  }
#ifdef _WIN32_WCE
  case WM_DESTROY:
    SipShowIM(SIPF_OFF);
    break;
  case USER_SHOWIM:
    SipShowIM(SIPF_ON);
    break;
#endif
 case WM_CLOSE:{
    View * view=(View *)::GetWindowLong(hwnd,GWL_USERDATA);
    if (view)
      view->close();
    break;
  }
  default:
    r=::DefWindowProc(hwnd,msg,wParam,lParam);
  }
  return r;
}

#endif
