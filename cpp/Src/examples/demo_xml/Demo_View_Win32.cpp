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

  $Id: Demo_View_Win32.cpp,v 1.3 2002/12/13 17:21:54 sdw Exp $
*/
#ifdef WIN32
#include <windows.h>

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
  wc.style = CS_BYTEALIGNWINDOW;
  wc.lpfnWndProc = WndProc ;
  wc.cbClsExtra = 0 ;
  wc.cbWndExtra = 0;
  wc.hInstance = g_ModuleHandle;
  wc.hIcon = LoadIcon (0, IDI_APPLICATION) ;
  wc.hCursor = LoadCursor (0, IDC_ARROW) ;
  wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1); 
  wc.lpszMenuName = 0;
  wc.lpszClassName = skSTR("View");
  ::RegisterClass (&wc);
  m_Handle=::CreateWindow(skSTR("View"),title,WS_OVERLAPPED|WS_CAPTION|WS_VISIBLE,x,y,width,height,0,0,g_ModuleHandle,0);
  if (m_Handle)
    ::SetWindowLong((HWND)m_Handle,GWL_USERDATA,(long)this);
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
  ::WinExec(file,TRUE);
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
  ::MessageBox((HWND)m_Handle,(const char *)msg,"",MB_OK);
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
