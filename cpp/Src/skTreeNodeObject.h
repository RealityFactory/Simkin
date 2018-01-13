/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skTreeNodeObject.h,v 1.13 2001/03/05 16:46:28 sdw Exp $
*/


#ifndef skTREENODEOBJECT_H
#define skTREENODEOBJECT_H

#include "skExecutable.h"
class skTreeNode;
class skMethodTable;

#define TREENODE_TYPE	1

/**
   This class gives an skExecutable wrapper to an skTreeNode object
*/
class skTreeNodeObject : public skExecutable
{
 public:
  /**
   * Default Constructor
   */
  skTreeNodeObject();
  /**
   * Constructor providing a treenode
   * @param location - the location of this treenode (e.g. file or database), this is used in error messages
   * @param node - the node itself
   * @param created - set this to true to allow the TreeNodeObject to delete the node when it is deleted
   */
  skTreeNodeObject(const skString& location,skTreeNode * node,bool created);
  /**
   * Destructor - will delete the associated node if the created flag is set
   */
  ~skTreeNodeObject();
  /**
   * returns the value TREENODE_TYPE to identify this as a TreeNodeObject
   */
  int executableType() const;			
  /**
   * Returns the data field of the node as an integer
   */
  int intValue() const;
  /**
   * Returns the data field of the node as a float
   */
  float floatValue() const;
  /**
   * Returns the data field of the node as a boolean
   */
  bool boolValue() const;
  /**
   * Returns the first character of the data field of the node
   */
  char charValue() const;
  /**
   * Returns the data field of the node as a string
   */
  skString strValue() const;
  /**
   * Sets a value within the node. The field name is matched to a child of the treenode with the same label.
   * If a match is found, the child's data is changed. 
   * @param name - the name of the field
   * @param attribute - the attribute name is ignored
   * @param value - the value to be assigned to the child. If this is a TREENODE_TYPE object, the full treenode is copied
   */
  bool setValue(const skString& name,const skString& attribute,const skRValue& value);
  /**
   * Retrieves a value from within the node. The field name is matched to a child of the treenode with the same label.
   * If a match is found, a new TreeNodeObject encapsulating the child is returned. 
   */
  bool getValue(const skString& name,const skString& attribute,skRValue& v);
  /**
   * This function attempts to call a method defined within the TreeNode. It searches for a child whose label matches the method name, and tries to execute its data as a Simkin script
   * @param name - the name of the method
   * @param args - the arguments to pass to the method
   * @param ret - the RValue to receive the results of the method call
   * @return true if the method was found, otherwise false
   */
  bool method(const skString& name,skRValueArray& args,skRValue& ret);
  /**
   * This function returns the treenode wrapped by this object
   */
  skTreeNode * getNode();
  /**
   * This function changes the node associated with this object
   */
  void setNode(skTreeNode * node);
  /**
   * This function tests if this object is equal to the other object. It does this by checking the string values are equal
   */
  //  bool equals(skExecutable * o) const;
  /**
   * This function returns the location associated with this object (typically a file name)
   */
  skString getLocation() const;
 protected:
  /**
   * the location the node came from
   */
  skString m_Location;
 private:
  /**
   * the underlying node
   */
  skTreeNode * m_Node;
  /**
   * if this flag is true, the TreeNodeObject will delete the underlying node in its destructor
   */
  bool m_Created;
  /**
   * this cache is used to hold parse trees for methods already executed
   */
  skMethodTable * m_MethodCache;
  /**
   * Executables can't be copied
   */
  skTreeNodeObject(const skTreeNodeObject&);
  /**
   * Executables can't be copied
   */
  skTreeNodeObject& operator=(const skTreeNodeObject&);
};
#endif
