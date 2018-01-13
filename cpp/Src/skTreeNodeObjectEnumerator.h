/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skTreeNodeObjectEnumerator.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef TREENODEOBJECTENUMERATOR_H
#define TREENODEOBJECTENUMERATOR_H

#include "skExecutable.h"
#include "skTreeNode.h"

class skTreeNodeObject;

/**
 * This class enumerates the elements in an TreeNodeObject 
 * 
*/
class skTreeNodeObjectEnumerator : public skExecutable{
 public:
  /**
   * This constructor is for an enumerator that gives *all* the child elements of this element
   */
  skTreeNodeObjectEnumerator(skTreeNodeObject * element);
  /**
   * This constructor is for an enumerator that gives the child elements of this element whose tag name matches that given
   */
  skTreeNodeObjectEnumerator(skTreeNodeObject * element,const skString& tag);
  /**
   * This method exposes the following methods to Simkin scripts:
   * returns the next object in the enumeration - or null if there are no more
     */
  bool method(const skString& s,skRValueArray& args,skRValue& r);
 private:
  void findNextNode();

  skString m_Tag;
  skTreeNodeListIterator m_Iter;
  skTreeNode * m_CurrentNode;
  skTreeNodeObject * m_Object;
};
#endif
