/*
  Copyright 1996-2003
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

  $Id: skExecutableContext.h,v 1.4 2003/01/20 18:48:18 simkin_cvs Exp $
*/
#ifndef SKEXECUTABLECONTEXT_H
#define SKEXECUTABLECONTEXT_H

#include "skGeneral.h"
#ifndef EXCEPTIONS_DEFINED
#include "skScriptError.h"
#endif

class CLASSEXPORT skInterpreter;
class CLASSEXPORT skStackFrame;

/**
* This class holds information passed to all methods via the siExecutable interface
*/
class CLASSEXPORT skExecutableContext
{
public:
                    skExecutableContext(skInterpreter * interp)
                      : m_Interpreter(interp),m_TopFrame(0)
                    {
                    }
  skInterpreter *  getInterpreter();
#ifndef EXCEPTIONS_DEFINED
  /** holds a reference to an error encountered - where exception support is not available */
  skScriptError&  getError();
#endif

  void            pushStackFrame(skStackFrame * frame);
  void            popStackFrame();
  skStackFrame *  getTopFrame();
  void            setTopFrame(skStackFrame * frame);
private:
  skStackFrame *  m_TopFrame;
  /** holds a reference to the calling interpreter */
  skInterpreter *   m_Interpreter;
#ifndef EXCEPTIONS_DEFINED
  /** holds a reference to an error encountered - where exception support is not available */
  skScriptError   m_Error;
#endif
};

//------------------------------------------
inline skInterpreter *  skExecutableContext::getInterpreter()
//------------------------------------------
{
  return m_Interpreter;
}
//------------------------------------------
inline void skExecutableContext::setTopFrame(skStackFrame * frame)
//------------------------------------------
{
  m_TopFrame=frame;
}
//------------------------------------------
inline skStackFrame *  skExecutableContext::getTopFrame()
//------------------------------------------
{
  return m_TopFrame;
}
#ifndef EXCEPTIONS_DEFINED
//------------------------------------------
inline skScriptError&  skExecutableContext::getError()
//------------------------------------------
{
  return m_Error;
}
#endif

#endif
