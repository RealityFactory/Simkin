/*
  Copyright 1996-2002
  Simon Whiteside

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

  $Id: skExecutableContext.h,v 1.1 2002/12/13 17:23:09 sdw Exp $
*/
#ifndef SKEXECUTABLECONTEXT_H
#define SKEXECUTABLECONTEXT_H

#include "skGeneral.h"
#ifndef EXCEPTIONS_DEFINED
#include "skScriptError.h"
#endif

class CLASSEXPORT skInterpreter;

/**
* This class holds information passed to all methods via the siExecutable interface
*/
class CLASSEXPORT skExecutableContext
{
public:
                    skExecutableContext(skInterpreter * interp)
                      : m_Interpreter(interp)
                    {
                    }
  /** holds a reference to the calling interpreter */
  skInterpreter *   m_Interpreter;
#ifndef EXCEPTIONS_DEFINED
  /** holds a reference to an error encountered - where exception support is not available */
  skScriptError   m_Error;
#endif
};
#endif
