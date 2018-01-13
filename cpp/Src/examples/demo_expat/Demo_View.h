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

  Demo_View.h

  This class describes the interface for a class that shows windows within
  widgets.

  The class is implemented separately for each target platform.

  $Id: Demo_View.h,v 1.1 2002/12/16 14:53:18 sdw Exp $
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

