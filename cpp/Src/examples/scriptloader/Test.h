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
*/
/*
 * This small class can be used to trace calls into an iterator from a foreach statement in a script
 */
class skTestIterator : public skExecutableIterator {
  int m_Count;
public:
  skTestIterator() : m_Count(0){
  }
  bool next(skRValue& v){
    bool ret=false;
    if (m_Count<10){
      v=m_Count;
      skTracer::trace(skSTR("skTestIterator::next\n"));
      m_Count++;
      ret=true;
    }
    return ret;
  }
};
/*
 * You can use this small class to trace calls into a C++ object from a script. The class supports the method "createObject" and an instance is put as a global variable called "Test". This means you can do the following in Simkin script:
 * <pre>
 * a=Test.createObject();
 * b=a:name;
 * </pre>
 * And watch a trace of the "getValue" function being called
 */

class skTest : public skExecutable{
public:
  skTest(){
  }
  skExecutableIterator * createIterator(const skString& qualifier){
    skTracer::trace(skSTR("skTest::createIterator qualified by ")+qualifier+skSTR("\n"));
    return new skTestIterator();
  }
  skExecutableIterator * createIterator(){
    skTracer::trace(skSTR("skTest::createIterator\n"));
    return new skTestIterator();
  }
  bool getValue(const skString& field_name,const skString& attribute,skRValue& value){
    skTracer::trace(skSTR("skTest::getValue field_name=")+field_name+skSTR(" attribute=")+attribute+skSTR("\n"));
    return true;
  }
  bool setValue(const skString& field_name,const skString& attribute,const skRValue& value){
    skTracer::trace(skSTR("skTest::setValue field_name=")+field_name+skSTR(" attribute=")+attribute+skSTR("\n"));
    return true;
  }
  bool setValueAt(const skRValue& array_index, const skString& attribute,const skRValue& value)
  {
    skTracer::trace(skSTR("skTest::setValueAt array_index")+array_index.str()+skSTR(" attribute=")+attribute+skSTR(" value=")+value.str()+skSTR("\n"));
    return true;
  }

  bool getValueAt(const skRValue& array_index, const skString& attribute, skRValue& value)
  {
    skTracer::trace(skSTR("skTest::getValueAt array_index=")+array_index.str()+skSTR(" attribute=")+attribute+skSTR("\n"));
    return true;
  }
  bool method(const skString& method_name,skRValueArray& arguments,skRValue& return_value,skExecutableContext& ctxt)
  {
    skTracer::trace(skSTR("skTest::method method_name=")+method_name+skSTR("\n"));
    bool bRet=false;
    if (method_name==skSTR("createObject")){
      return_value=skRValue(new skTest(),true);
      bRet=true;
    }else{
      bRet=skExecutable::method(method_name,arguments,return_value,ctxt);
    }
    return bRet;
  }
};

