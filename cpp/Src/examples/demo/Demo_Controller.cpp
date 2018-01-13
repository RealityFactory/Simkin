/*
  Copyright 1996-2000
  Simon Whiteside, All Rights Reserved

  THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

  Demo_Controller.cpp

  This file implements the class which controls the behaviour of the
  view in the demo.

  $Id: Demo_Controller.cpp,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/
#include "Demo_Controller.h"
#include "skTreeNode.h"
#include "skRValueArray.h"

//-----------------------------------------------------------------
Controller::Controller(skString fileName)
  //-----------------------------------------------------------------
  //	this class loads the demo script file, whose methods
  //	are an extension of the class functionality
  : skScriptedExecutable(fileName),m_View(0),m_FileName(fileName)
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
    skTreeNode * viewNode=code->findChild("View");
    if (viewNode){
      skString title=viewNode->findChildData("Title","");
      int x_pos=viewNode->findChildIntData("X");
      int y_pos=viewNode->findChildIntData("Y");
      int width=viewNode->findChildIntData("Width");
      int height=viewNode->findChildIntData("Height");
      m_View=new View(*this,title,x_pos,y_pos,width,height);
      //	look for some controls
      skTreeNode * controls=viewNode->findChild("Controls");
      if (controls){
	skTreeNodeListIterator iter(*controls);
	skTreeNode * control=0;
	while ((control=iter())){
	  skString type=control->findChildData("Type","");
	  int id=control->findChildIntData("Id");
	  skString text=control->findChildData("Text","");
	  int x_pos=control->findChildIntData("X");
	  int y_pos=control->findChildIntData("Y");
	  int width=control->findChildIntData("Width");
	  int height=control->findChildIntData("Height");
	  m_View->addControl(type,id,text,x_pos,y_pos,width,height);
	}
      }
    }
    skRValueArray args;
    skRValue ret;
    method("init",args,ret);
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
    skTreeNode * viewNode=code->findChild("View");
    if (viewNode){
      skTreeNode * controls=viewNode->findChild("Controls");
      if (controls){
	skTreeNodeListIterator iter(*controls);
	skTreeNode * control=0;
	while ((control=iter())){
	  int this_id=control->findChildIntData("Id");
	  if (this_id==id){
	    skString methodName=control->findChildData("Method","");
	    if (methodName.length()){
	      //	call a method on ourselves, if one is set up
	      skRValueArray args;
	      skRValue ret;
	      method(methodName,args,ret);
	    }
	    break;
	  }
	}
      }
    }
  }
}
//-----------------------------------------------------------------
bool Controller::method(const skString& s,skRValueArray& args,skRValue& ret)
  //-----------------------------------------------------------------
  //	this is the function called by the Simkin interpreter when a method 
  //	is invoked on this object
{
  bool bRet=false;
  if (IS_METHOD(s,"Reload")){
    //	this code causes the script file to be re-read and
    //	the view recreated
    skTreeNode * newCode=skTreeNode::read(m_FileName);
    if (newCode){
      delete m_View;
      m_View=0;
      setNode(newCode);
    }else{
      m_View->user("You changed Demo.s so that it cannot be loaded, please check its syntax!");
    }
    init();
    bRet=true;
  }else
    if (IS_METHOD(s,"setFocus") && m_View && args.entries()==1){
      //	sets focus to a control
      m_View->setFocus(args[0].intValue());
      bRet=true;
    }else
      if (IS_METHOD(s,"close") && m_View){
	//	closes the view and the application
	m_View->close();
	bRet=true;
      }else
	if (IS_METHOD(s,"run") && m_View && args.entries()==1){
	  //	run a command as a separate process
	  m_View->run(args[0].str());
	  bRet=true;
	}else
	  if (IS_METHOD(s,"getText") && m_View && args.entries()==1){
	    //	retrieves the text for a control
	    ret=m_View->getText(args[0].intValue());
	    bRet=true;
	  }else
	    if (IS_METHOD(s,"user") && m_View && args.entries()==1){
	      //	shows a message box to the user
	      m_View->user(args[0].str());
	      bRet=true;
	    }else
	      //	we pass any other method up to the base class, which in turn looks inside
	      //	the demo script file for a matching method
	      bRet=skScriptedExecutable::method(s,args,ret);
  return bRet;
}
