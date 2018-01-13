/*
  Copyright 1996-2000
  Simon Whiteside, All Rights Reserved

  THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

  Demo_Win32.cpp

  This file provides Windows-specific event handling


  $Id: Demo_Win32.cpp,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/
#ifdef WIN32
#include <windows.h>

extern int main(int argc,char * argv[]);

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
		if (g_MainWindow==0 || IsDialogMessage(g_MainWindow,&msg)==FALSE){
			TranslateMessage (&msg) ;
			DispatchMessage (&msg) ;
		}
	}
	return 0;
}
//-----------------------------------------------------------------
int PASCAL WinMain(HINSTANCE hinstCurrent, HINSTANCE hinstPrevious,
    LPSTR lpszCmdLine, int nCmdShow)
//-----------------------------------------------------------------
{
	g_ModuleHandle=hinstCurrent;
	return main(1,&lpszCmdLine);
}
#endif
