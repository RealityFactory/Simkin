/**
	Interpreter implementation class
	$Id: skInterpreterp.h,v 1.22 2001/06/29 09:17:04 sdw Exp $
	Copyright 1996-2001
	Simon Whiteside
*/

#include "skParseNode.h"
#include "skExecutableIterator.h"
#include "skRValueTable.h"

class P_Interpreter 
{   
 public:
    P_Interpreter();
    ~P_Interpreter();
						

    // Expression evaluation
  
    skRValue evaluate(skExecutable * obj,skRValueTable& var,skExprNode * n);
    skRValue evalMethod(skExecutable * obj,skRValueTable& var,skIdListNode * ids);
    void makeMethodCall(skExecutable * obj,skRValueTable& var,skRValue& robject,const skString& method_name,skExprNode * array_index, const skString& attribute,skExprListNode * exprs,skRValue& ret);

    // Statement execution

    void executeAssignStat(skExecutable * obj,skRValueTable& var,skAssignNode * n);

    // the statements below return true to halt further processing (i.e. a return statement has been encountered)

    bool executeStat(skExecutable * obj,skRValueTable& var,skStatNode * pstat,skRValue& r);
    bool executeStats(skExecutable * obj,skRValueTable& var,skStatListNode * n,skRValue& r);
    bool executeReturnStat(skExecutable * obj,skRValueTable& var,skReturnNode * n,skRValue& r);
    bool executeIfStat(skExecutable * obj,skRValueTable& var,skIfNode * n,skRValue& r);
    bool executeWhileStat(skExecutable * obj,skRValueTable& var,skWhileNode * n,skRValue& r);
    bool executeSwitchStat(skExecutable * obj,skRValueTable& var,skSwitchNode * n,skRValue& r);
    bool executeForEachStat(skExecutable * obj,skRValueTable& var,skForEachNode * n,skRValue& r);
    bool executeForStat(skExecutable * obj,skRValueTable& var,skForNode * n,skRValue& r);

    // Misc runtime routines

    void addLocalVariable(skRValueTable& var,const skString& name,skRValue value); // adds a local variable to the current list
    skString checkIndirectId(skExecutable * obj,skRValueTable& var,const skString& name); // checks whether a field name includes the indirection character
    // tries to find a the value of the named variable
    skRValue findValue(skExecutable * obj,skRValueTable& var,const skString& name,skExprNode * array_index,const skString& attribute); 
    void runtimeError(const skString& s); // creates and throws a skRuntimeException
    void followIdList(skExecutable * obj,skRValueTable& var,skIdListNode * idList,skRValue& object); // follows a dotted list of id's
    void trace(const skString& s);

    // extracts a value of the form foo[1] - first dereferencing foo
    bool extractFieldArrayValue(skExecutable * obj,skRValueTable& var,skRValue& robject,const skString& field_name,skExprNode * array_index,const skString& attrib,skRValue& ret);
    // extracts a value of the form robject[1] - assumes robject is already a collection object
    bool extractArrayValue(skExecutable * obj,skRValueTable& var,skRValue& robject,skExprNode * array_index,const skString& attrib,skRValue& ret) ;
    // extracts an instance variable with the given name
    bool extractValue(skRValue& robject,const skString& name,const skString& attrib,skRValue& ret) ;
    
    // wrapper around setValueAt
    bool insertArrayValue(skExecutable * obj,skRValueTable& var,skRValue& robject, skExprNode * array_index,const skString& attr,const skRValue& value);
    // wrapper around setValue
    bool insertValue(skRValue& robject,const skString& name, const skString& attr,const skRValue& value);

    // Variables
    skRValueTable m_GlobalVars; // the global variables
    unsigned int m_StackDepth; // the current stack depth
    bool m_Tracing; // flag for tracing method calls

    skTraceCallback * m_TraceCallback; // the trace callback
    skStatementStepper * m_StatementStepper; // the statement stepper
    skString m_Location; // location during script execution
    int m_LineNum; // line number during script execution
    THREAD static skInterpreter * g_GlobalInterpreter;	//	used by clients - one per thread (on Windows only at the moment)

};    

//---------------------------------------------------
inline skString P_Interpreter::checkIndirectId(skExecutable * obj,skRValueTable& var,const skString& name)
//---------------------------------------------------
{
  // look for an initial "@" in a field name, and de-reference it if necessary
    skString ret=name;
    if (name.at(0)=='@'){
	ret=name.substr(1,name.length()-1);
	skRValue new_name=findValue(obj,var,ret,0,skString());
	ret=new_name.str();
    }
    return ret;
}	
