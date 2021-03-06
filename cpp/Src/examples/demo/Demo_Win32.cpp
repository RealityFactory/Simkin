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

  Demo_Win32.cpp

  This file provides Windows-specific event handling


  $Id: Demo_Win32.cpp,v 1.4 2002/12/20 15:06:32 sdw Exp $
*/
#if defined(WIN32) || defined(_WIN32_WCE)
#include "skString.h"

#include <windows.h>

extern int main(int argc,Char * argv[]);

HINSTANCE g_ModuleHandle;
HWND g_MainWindow;

//-----------------------------------------------------------------
void InitializeEventLoop()
  //-----------------------------------------------------------------
{
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
  MSG msg;
  while (GetMessage (&msg, NULL, 0, 0)){
#ifdef _WIN32_WCE
    if (g_MainWindow==0 || IsDialogMessage(g_MainWindow,&msg)==FALSE){
#endif
      TranslateMessage (&msg) ;
      DispatchMessage (&msg) ;
#ifdef _WIN32_WCE
    }
#endif
  }
  return 0;
}
// Entry point for Windows CE applications
#ifdef _WIN32_WCE
//-----------------------------------------------------------------
int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)
//-----------------------------------------------------------------
{
  g_ModuleHandle=hInstance;
  return main(1,&lpCmdLine);
}
#else
//-----------------------------------------------------------------
int PASCAL WinMain(HINSTANCE hinstCurrent, HINSTANCE hinstPrevious,
		   LPSTR lpszCmdLine, int nCmdShow)
  //-----------------------------------------------------------------
{
  g_ModuleHandle=hinstCurrent;
  return main(1,&lpszCmdLine);
}
#endif

#endif
