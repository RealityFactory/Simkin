/*
  Copyright 1996-2000
  Simon Whiteside, All Rights Reserved

  THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

  Demo_Controller.h

  This file defines the interface for the class which controls the demo's view.

  $Id: Demo_Controller.h,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "skScriptedExecutable.h"

#include "Demo_View.h"

class Controller : public skScriptedExecutable, public ViewCallback
//	deriving from skScriptedExecutable means we can be called from Simkin scripts
//	deriving from ViewCallback means we can get notified when 
//	buttons are pressed on the view
{
 public:
  Controller(skString fileName);
  ~Controller();
  void	buttonPressed(int id);
  bool	method(const skString& s,skRValueArray& args,skRValue& ret);
 private:
  void	init();
  View *	m_View;
  skString m_FileName;
};

#endif
