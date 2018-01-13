/*
  Copyright 1996-2001
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

* $Id: skStatStepper.h,v 1.3 2001/11/22 11:13:21 sdw Exp $
*/
#ifndef skSTATSTEPPER_H
#define skSTATSTEPPER_H

#include "skRValueTable.h"

/**
 * This abstract class is used to provide an interface for the Interpreter to call
 * each time a statement is executed
 */

class CLASSEXPORT skStatStepper {
 public:
  /** This method is called each time a statement is executed by the interpreter
   * @param msg  the trace message
   */
  virtual void statementExecuted(const skString& location, int line_num,skRValueTable& local_vars)=0;
};
#endif
