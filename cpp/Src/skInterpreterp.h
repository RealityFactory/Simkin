/**
	Interpreter implementation class
	$Id: skInterpreterp.h,v 1.16 2001/05/22 10:56:38 sdw Exp $
	Copyright 1996-2001
	Simon Whiteside
*/

class skTreeNode;
#include "skHashTable.h"
#include "skParseNode.h"


class skRValueTable: public skTHashTable<skString,skRValue>
{
 public:
    skRValueTable(unsigned short  size);
    skRValueTable();
    ~skRValueTable();

};

const unsigned int MAX_LOCAL_VARS_CACHE=5;

class P_Interpreter 
{   
 public:
    P_Interpreter();
    ~P_Interpreter();
						

    // Expression evaluation
  
    skRValue evaluate(skExecutable * obj,skRValueTable& var,skExprNode * n);
    skRValue evalMethod(skExecutable * obj,skRValueTable& var,skIdListNode * ids);
    void makeMethodCall(skExecutable * obj,skRValueTable& var,skRValue& robject,const skString& method_name,skExprNode * array_index, skExprListNode * exprs,skRValue& ret);

    // Statement execution

    void executeAssignStat(skExecutable * obj,skRValueTable& var,skAssignNode * n);

    // the statements below return true to halt further processing (i.e. a return statement has been encountered)

    bool executeStat(skExecutable * obj,skRValueTable& var,skStatNode * pstat,skRValue& r);
    bool executeStats(skExecutable * obj,skRValueTable& var,skStatListNode * n,skRValue& r);
    bool executeReturnStat(skExecutable * obj,skRValueTable& var,skReturnNode * n,skRValue& r);
    bool executeIfStat(skExecutable * obj,skRValueTable& var,skIfNode * n,skRValue& r);
    bool executeWhileStat(skExecutable * obj,skRValueTable& var,skWhileNode * n,skRValue& r);
    bool executeSwitchStat(skExecutable * obj,skRValueTable& var,skSwitchNode * n,skRValue& r);

    // Misc runtime routines

    void addLocalVariable(skRValueTable& var,const skString& name,skRValue value); // adds a local variable to the current list
    skString checkIndirectId(skExecutable * obj,skRValueTable& var,const skString& name); // checks whether a field name includes the indirection character
    skRValue findValue(skExecutable * obj,skRValueTable& var,const skString& name,skExprNode * array_index,const skString& attribute); // tries to find a the value of the named variable
    void runtimeError(const char * buffer,...); // creates and throws a skRuntimeException
    void followIdList(skExecutable * obj,skRValueTable& var,skIdListNode * idList,skRValue& object); // follows a dotted list of id's
    bool extractValue(skExecutable * obj,skRValueTable& var,skRValue& robject,const skString& name,skExprNode * array_index,const skString& attrib,skRValue& ret) ;
    bool insertValue(skExecutable * obj,skRValueTable& var,skRValue& robject,const skString& name, skExprNode * array_index,const skString& attr,const skRValue& value);

    // Variables
    skRValueTable m_GlobalVars; // the global variables
    skRValueTable m_LocalVars[MAX_LOCAL_VARS_CACHE]; // a pool of local variable tables
    unsigned int m_StackDepth; // the current stack depth
    bool m_Tracing; // flag for tracing method calls

    skString m_Location; // location during script execution
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
