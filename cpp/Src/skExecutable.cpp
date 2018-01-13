/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skExecutable.cpp,v 1.20 2001/06/29 09:17:04 sdw Exp $
*/
#include <iostream.h>
#include "skExecutable.h"
#include "skRValue.h"
#include "skRValueArray.h"
#include "skTracer.h"
#include "skInterpreter.h"

skLITERAL(trace);
skLITERAL(isObject);
skLITERAL(length);
skLITERAL(charAt);

//------------------------------------------
skExecutable::skExecutable()
//------------------------------------------
{
}
//------------------------------------------
skExecutable::skExecutable(const skExecutable& other)
//------------------------------------------
{
}
//------------------------------------------
skExecutable& skExecutable::operator=(const skExecutable& other)
//------------------------------------------
{
  return *this;
}
//------------------------------------------
skExecutable::~skExecutable()
  //------------------------------------------
{
}
//------------------------------------------
int	skExecutable::executableType() const
  //------------------------------------------
{
  return UNDEFINED_TYPE;
}
//------------------------------------------
int skExecutable::intValue() const
  //------------------------------------------
{
  return 0;
}
//------------------------------------------
float skExecutable::floatValue() const
  //------------------------------------------
{
  return 0.0f;
}
//------------------------------------------
bool skExecutable::boolValue() const
  //------------------------------------------
{
  return false;
}
//------------------------------------------
Char skExecutable::charValue() const
  //------------------------------------------
{
  return ' ';
}
//------------------------------------------
skString skExecutable::strValue() const
  //------------------------------------------
{
  return skString();
}
//------------------------------------------
bool skExecutable::setValue(const skString& s,const skString& attribute,const skRValue& r)
  //------------------------------------------
{
  return false;
}
//------------------------------------------
bool skExecutable::setValueAt(const skRValue& array_index,const skString& attribute,const skRValue& r)
  //------------------------------------------
{
  return false;
}
//------------------------------------------
bool skExecutable::getValue(const skString& s,const skString& attribute,skRValue& r)
  //------------------------------------------
{
  return false;
}
//------------------------------------------
bool skExecutable::getValueAt(const skRValue& array_index,const skString& attribute,skRValue& r)
  //------------------------------------------
{
  return false;
}
//------------------------------------------
bool skExecutable::method(const skString& s,skRValueArray& args,skRValue& r)
  //------------------------------------------
{
  bool bRet=false;
  if (s==s_trace){
    skInterpreter::getInterpreter()->trace(args[0].str()+skSTR("\n"));
    bRet=true;
  }else  if (s==s_isObject){
    if (args.entries()==1){
      bRet=true;
      r=skRValue((bool)(args[0].type()==skRValue::T_Object));
    }
  }else
    if (s==s_length){
      if (args.entries()==1){
	bRet=true;
	r=skRValue(args[0].str().length());
      }
    }else
      if (s==s_charAt){
	if (args.entries()==2){
	  bRet=true;
	  r=(char)(args[0].str().at((char)args[1].intValue()));
	}
      }
  return bRet;
}
//------------------------------------------
bool skExecutable::equals(skExecutable * o) const
  //------------------------------------------
{
  return (this==o);
}
//------------------------------------------
skExecutableIterator * skExecutable::createIterator(const skString& qualifier)
//------------------------------------------
{
  return 0;
}
//------------------------------------------
skExecutableIterator * skExecutable::createIterator()
//------------------------------------------
{
  return 0;
}

