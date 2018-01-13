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

  Demo_Controller.cpp

  This file implements the class which controls the behaviour of the
  view in the demo.

  $Id: Demo_Controller.cpp,v 1.5 2003/01/20 23:07:01 simkin_cvs Exp $
*/
#include "Demo_Controller.h"
#include "skTreeNode.h"
#include "skRValueArray.h"

skLITERAL(View);
skLITERAL(Title);
skLITERAL(X);
skLITERAL(Y);
skLITERAL(Height);
skLITERAL(Controls);
skLITERAL(Text);
skLITERAL(Type);
skLITERAL(Width);
skLITERAL(Id);
skLITERAL(Method);
skLITERAL(reload);
skLITERAL(setFocus);
skLITERAL(run);
skLITERAL(getText);
skLITERAL(user);
skLITERAL(close);
skLITERAL(init);

//-----------------------------------------------------------------
Controller::Controller(skString fileName,skExecutableContext& ctxt)
  //-----------------------------------------------------------------
  //	this class loads the demo script file, whose methods
  //	are an extension of the class functionality
  : skScriptedExecutable(fileName,ctxt),m_View(0),m_FileName(fileName),m_Interpreter(ctxt.getInterpreter())
{
  init();
}
//-----------------------------------------------------------------
Controller::~Controller()
  //-----------------------------------------------------------------
{
  delete m_View;
}
//-----------------------------------------------------------------
void Controller::init()
  //-----------------------------------------------------------------
{
  //	load the view description from the file
  //	and create the controls contained within the view definition
  skTreeNode * code=getNode();
  if (code){
    skTreeNode * viewNode=code->findChild(s_View);
    if (viewNode){
      skString title=viewNode->findChildData(s_Title);
      int x_pos=viewNode->findChildIntData(s_X);
      int y_pos=viewNode->findChildIntData(s_Y);
      int width=viewNode->findChildIntData(s_Width);
      int height=viewNode->findChildIntData(s_Height);
      m_View=new View(*this,title,x_pos,y_pos,width,height);
      //	look for some controls
      skTreeNode * controls=viewNode->findChild(s_Controls);
      if (controls){
        skTreeNodeListIterator iter(*controls);
        skTreeNode * control=0;
        while ((control=iter())){
	        skString type=control->findChildData(s_Type);
	        int id=control->findChildIntData(s_Id);
	        skString text=control->findChildData(s_Text);
	        int x_pos=control->findChildIntData(s_X);
	        int y_pos=control->findChildIntData(s_Y);
	        int width=control->findChildIntData(s_Width);
	        int height=control->findChildIntData(s_Height);
	        m_View->addControl(type,id,text,x_pos,y_pos,width,height);
        }
      }
    }
    // call the init function
    skRValueArray args;
    skRValue ret;
    skExecutableContext context(m_Interpreter);
    method(s_init,args,ret,context);
  }
}//-----------------------------------------------------------------
void Controller::buttonPressed(int id)
  //-----------------------------------------------------------------
  //	this method is a virtual from ViewCallback, it is called when the user
  //	presses a button
{
  skTreeNode * code=getNode();
  if (code){
    //	look for the node for this control, matching on id
    skTreeNode * viewNode=code->findChild(s_View);
    if (viewNode){
      skTreeNode * controls=viewNode->findChild(s_Controls);
      if (controls){
        skTreeNodeListIterator iter(*controls);
        skTreeNode * control=0;
        while ((control=iter())){
	        int this_id=control->findChildIntData(s_Id);
	        if (this_id==id){
	          skString methodName=control->findChildData(s_Method);
	          if (methodName.length()){
	            //	call a method on ourselves, if one is set up
	            skRValueArray args;
	            skRValue ret;
              skExecutableContext context(m_Interpreter);
	            method(methodName,args,ret,context);
	          }
	          break;
	        }
        }
      }
    }
  }
}
//-----------------------------------------------------------------
bool Controller::method(const skString& s,skRValueArray& args,skRValue& ret,skExecutableContext& ctxt)
  //-----------------------------------------------------------------
  //	this is the function called by the Simkin interpreter when a method 
  //	is invoked on this object
{
  bool bRet=false;
  if (IS_METHOD(s,s_reload)){
    //	this code causes the script file to be re-read and
    //	the view recreated
    skTreeNode * newCode=skTreeNode::read(m_FileName,ctxt);
    if (newCode){
      delete m_View;
      m_View=0;
      setNode(newCode);
    }else{
      m_View->user(skSTR("You changed Demo.s so that it cannot be loaded, please check its syntax!;"));
    }
    init();
    bRet=true;
  }else if (IS_METHOD(s,s_setFocus) && m_View && args.entries()==1){
    //	sets focus to a control
    m_View->setFocus(args[0].intValue());
    bRet=true;
  }else if (IS_METHOD(s,s_close) && m_View){
    //	closes the view and the application
    m_View->close();
    bRet=true;
  }else if (IS_METHOD(s,s_run) && m_View && args.entries()==1){
	  //	run a command as a separate process
	  m_View->run(args[0].str());
	  bRet=true;
	}else if (IS_METHOD(s,s_getText) && m_View && args.entries()==1){
	  //	retrieves the text for a control
	  ret=m_View->getText(args[0].intValue());
	  bRet=true;
	}else if (IS_METHOD(s,s_user) && m_View && args.entries()==1){
	  //	shows a message box to the user
	  m_View->user(args[0].str());
	  bRet=true;
	}else
	  //	we pass any other method up to the base class, which in turn looks inside
	  //	the demo script file for a matching method
	  bRet=skScriptedExecutable::method(s,args,ret,ctxt);
  return bRet;
}
