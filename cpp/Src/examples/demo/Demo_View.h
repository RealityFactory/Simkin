/*
  Copyright 1996-2000
  Simon Whiteside, All Rights Reserved

  THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

  Demo_View.h

  This class describes the interface for a class that shows windows within
  widgets.

  The class is implemented separately for each target platform.

  $Id: Demo_View.h,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/
#ifndef DEMO_VIEW_H
#define DEMO_VIEW_H

#include "skString.h"

class ViewCallback
{
 public:
  virtual void	buttonPressed(int id)=0;
};
class View
{
 public:
  View(ViewCallback& callback,skString title,int x,int y,int width,int height);
  ~View();
  void addControl(skString type,int id,skString text,int x,int y,int width,int height);
  void close();
  skString getText(int id) const;
  void user(skString msg);
  void setFocus(int id);
  void run(skString file);

  ViewCallback&	m_Callback;
  void * m_Handle;
};
#endif

