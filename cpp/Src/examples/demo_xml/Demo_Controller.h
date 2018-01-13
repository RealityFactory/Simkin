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

  Demo_Controller.h

  This file defines the interface for the class which controls the demo's view.

  $Id: Demo_Controller.h,v 1.4 2003/01/20 23:07:01 simkin_cvs Exp $
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "skXMLExecutable.h"

#include "Demo_View.h"

class Controller : public skXMLExecutable, public ViewCallback
//	deriving from skXMLExecutable means we can be called from Simkin scripts
//	deriving from ViewCallback means we can get notified when 
//	buttons are pressed on the view
{
 public:
  Controller(const skString& fileName,skInterpreter * interp);
  ~Controller();
  void	buttonPressed(int id);
  bool	method(const skString& s,skRValueArray& args,skRValue& ret,skExecutableContext& ctxt);
 private:
  void	init();
  skString getStringAttribute(DOM_Element elem,const skString& name);
  int getIntegerAttribute(DOM_Element elem,const skString& name);
  View *	m_View;
  skString m_FileName;
  skInterpreter * m_Interpreter;
};

#endif
