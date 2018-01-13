/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skStatementStepper.h,v 1.1 2001/06/29 09:18:21 sdw Exp $
*/
#ifndef skSTATEMENTSTEPPER_H
#define skSTATEMENTSTEPPER_H

#include "skRValueTable.h"

/**
 * This abstract class is used to provide an interface for the Interpreter to call
 * each time a statement is executed
 */

class skStatementStepper {
 public:
  /** This method is called each time a statement is executed by the interpreter, just before the statement is performed
   * @return false to halt the execution of the current method
   * @param location the location of the script
   * @param line the line the statement was on
   * @param obj the object owning the current method
   * @param local_vars the local variables for the current method
   * @param statement_type an integer indicating the type of statement, a constant s_ value from skParseNode.h 
   */
  virtual bool statementExecuted(const skString& location, int line_num,skExecutable * obj,skRValueTable& local_vars,int statement_type)=0;
  /** This method is called each time a compound statement is executed by the interpreter, just before the statement is performed
   * @return false to halt the execution of the current method
   * @param location the location of the script
   * @param line the line the statement was on
   * @param obj the object owning the current method
   * @param local_vars the local variables for the current method
   */
  virtual bool compoundStatementExecuted(const skString& location, int line_num,skExecutable * obj,skRValueTable& local_vars)=0;
};
#endif
