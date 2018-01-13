/*
  Copyright 1996-2001
  Simon Whiteside

 * $Id: skParseNode.h,v 1.16 2001/05/08 14:21:51 sdw Exp $
*/

#ifndef PARSENODE_H
#define PARSENODE_H
#include "skStringList.h"
#include "skAlist.h"


static const int s_If=4;
static const int s_While=5;
static const int s_Return=6;
static const int s_Assign=7;
static const int s_Method=8;
static const int s_IdList=9;
static const int s_String=10;
static const int s_Integer=11;
static const int s_Not=12;
static const int s_And=13;
static const int s_Or=14;
static const int s_Less=15;
static const int s_More=16;
static const int s_Equals=17;
static const int s_Plus=18;
static const int s_Minus=19;
static const int s_Subtract=20;
static const int s_Concat=21;
static const int s_Divide=22;
static const int s_Mult=23;
static const int s_Mod=24;
static const int s_Float=25;
static const int s_Character=26;
static const int s_CaseList=27;
static const int s_Case=28;
static const int s_Switch=29;
static const int s_Id=30;
static const int s_NotEquals=31;

/**
 * This is the base class for Simkin parse nodes
 */
class skParseNode {
 public:
  skParseNode(){
  }
  virtual ~skParseNode(){
  }
  virtual int getType(){
    return 0;
  }
  virtual void clear(){
  }
 private:
  skParseNode(const skParseNode& ){
  }
  skParseNode& operator=(const skParseNode&){
    return *this;
  }
};
class skParseNodeList : public skTAList<skParseNode>{
};
typedef  skTAListIterator<skParseNode> skParseNodeListIterator;
class skStatNode : public skParseNode {
 public:
  virtual ~skStatNode(){
  }
};
class skExprNode : public skParseNode {
 public:
  skExprNode(){
  }
  virtual ~skExprNode(){
  }
};
typedef skTAList<skStatNode> skStatList;
typedef skTAListIterator<skStatNode> skStatListIterator;

class skStatListNode : public skParseNode {
 public:
  skStatList m_Stats;
  inline ~skStatListNode(){
    m_Stats.clearAndDestroy();
  }
  inline void addStat(skStatNode * stat){
    m_Stats.append(stat);
  }
  inline void clear(){
    m_Stats.clear();
  }
  inline int numStats(){
    return m_Stats.entries();
  }
};
typedef skTAList<skExprNode> skExprList;
typedef skTAListIterator<skExprNode> skExprListIterator;
class skExprListNode : public skParseNode {
 public:
  skExprList m_Exprs;
  inline ~skExprListNode(){
    m_Exprs.clearAndDestroy();
  }
  inline void addExpr(skExprNode * expr){
    m_Exprs.append(expr);
  }
  inline int numExprs(){
    return m_Exprs.entries();;
  }
  inline void clear(){
    m_Exprs.clear();
  }
};
class skIdNode : public skExprNode {
 public:
  skString m_Id;
  skExprListNode * m_Exprs;
  skExprNode * m_ArrayIndex;
  inline skIdNode(skString id,skExprNode * arrayIndex,skExprListNode * exprs){
    m_Id=id;
    m_Exprs=exprs;
    m_ArrayIndex=arrayIndex;
  }
  inline ~skIdNode(){
    delete m_Exprs;
  }
  inline void clear(){
    m_Exprs=0;
    m_ArrayIndex=0;
  }
  inline int getType(){
    return s_Id;
  }
};
class skIdNodeList : public skTAList<skIdNode>{
};
typedef  skTAListIterator<skIdNode> skIdNodeListIterator;
class skIdListNode : public skExprNode {
 public:
  skIdNodeList m_Ids;
  skString m_Attribute;
  inline skIdListNode(){
  }
  inline ~skIdListNode(){
  }
  inline void addId(skIdNode * node){
    m_Ids.append(node);
  }
  inline void prependId(skIdNode * node){
    m_Ids.prepend(node);
  }
  inline int numIds(){
    return m_Ids.entries();
  }
  inline void clear(){
    m_Ids.clear();
  }
  inline skIdNode * getLastId(){
    return m_Ids[m_Ids.entries()-1];
  }
  inline int getType(){
    return s_IdList;
  }
};
class skCaseNode : public skParseNode {
 public:
  skExprNode * m_Expr;
  skStatListNode * m_Stats;
  inline skCaseNode(skExprNode * expr,skStatListNode * stat){
    m_Expr=expr;
    m_Stats=stat;
  }
  inline ~skCaseNode(){
    delete m_Expr;
    delete m_Stats;
  }
  inline void clear(){
    m_Expr=0;
    m_Stats=0;
  }
  inline int getType(){
    return s_Case;
  }
};
typedef skTAList<skCaseNode> skCaseList;
typedef skTAListIterator<skCaseNode> skCaseListIterator;
class skCaseListNode : public skParseNode {
 public:
  skCaseList m_Cases;
  inline ~skCaseListNode(){
    m_Cases.clearAndDestroy();
  }
  inline void addCase(skCaseNode * expr){
    m_Cases.append(expr);
  }
  inline int numCases(){
    return m_Cases.entries();;
  }
  inline void clear(){
    m_Cases.clear();
  }
};
class skSwitchNode : public skStatNode {
 public:
  skExprNode * m_Expr;
  skCaseListNode * m_Cases;
  skStatListNode * m_Default;
  inline skSwitchNode(skExprNode * expr,skCaseListNode * cases,skStatListNode * defaultStat){
    m_Expr=expr;
    m_Cases=cases;
    m_Default=defaultStat;
  }
  inline ~skSwitchNode(){
    delete m_Expr;
    delete m_Cases;
    delete m_Default;
  }
  inline void clear(){
    m_Expr=0;
    m_Cases=0;
    m_Default=0;
  }
  inline int getType(){
    return s_Switch;
  }
};
class skIfNode : public skStatNode {
 public:
  skExprNode * m_Expr;
  skStatListNode * m_Stats;
  skStatListNode * m_Else;
  inline skIfNode(skExprNode * expr,skStatListNode * stat,skStatListNode * elseStat){
    m_Expr=expr;
    m_Stats=stat;
    m_Else=elseStat;
  }
  inline ~skIfNode(){
    delete m_Expr;
    delete m_Stats;
    delete m_Else;
  }
  inline void clear(){
    m_Expr=0;
    m_Stats=0;
    m_Else=0;
  }
  inline int getType(){
    return s_If;
  }
};
class skReturnNode : public skStatNode {
 public:
  skExprNode * m_Expr;
  inline skReturnNode(skExprNode * expr){
    m_Expr=expr;
  }
  inline ~skReturnNode(){
    delete m_Expr;
  }
  inline void clear(){
    m_Expr=0;
  }
  inline int getType(){
    return s_Return;
  }
};
class skWhileNode : public skStatNode {
 public:
  skExprNode * m_Expr;
  skStatListNode * m_Stats;
  inline skWhileNode(skExprNode * expr,skStatListNode * stat){
    m_Expr=expr;
    m_Stats=stat;
  }
  inline ~skWhileNode(){
    delete m_Expr;
    delete m_Stats;
  }
  inline void clear(){
    m_Expr=0;
    m_Stats=0;
  }
  inline int getType(){
    return s_While;
  }
};
class skAssignNode : public skStatNode {
 public:
  skIdListNode * m_Ids;
  skExprNode * m_Expr;
  inline skAssignNode(skIdListNode * idlist, skString * attribute,skExprNode * expr){
    m_Ids=idlist;
    if (attribute)
      m_Ids->m_Attribute=*attribute;
    delete attribute;
    m_Expr=expr;
  }
  inline ~skAssignNode(){
    delete m_Ids;
    delete m_Expr;
  }
  inline void clear(){
    m_Ids=0;
    m_Expr=0;
  }
  inline int getType(){
    return s_Assign;
  }
};
class skMethodStatNode : public skStatNode {
 public:
  skIdListNode * m_Ids;
  inline skMethodStatNode(skIdListNode * idlist){
    m_Ids=idlist;
  }
  inline ~skMethodStatNode(){
    delete m_Ids;
  }
  inline void clear(){
    m_Ids->clear();
    m_Ids=0;
  }
  inline int getType(){
    return s_Method;
  }
};
class skLiteralNode : public skExprNode {
 public:
  int m_Type;
  union {
    float m_Float;
    int m_Int;
    char m_Char;
    skString * m_String;
  };
  inline skLiteralNode(skString * s){
    m_String=s;
    m_Type=s_String;
  }
  inline skLiteralNode(int i){
    m_Int=i;
    m_Type=s_Integer;
  }
  inline skLiteralNode(char i){
    m_Char=i;
    m_Type=s_Character;
  }
  inline skLiteralNode(float f){
    m_Float=f;
    m_Type=s_Float;
  }
  inline ~skLiteralNode(){
    if (m_Type==s_String)
      delete m_String;
  }
  inline void clear(){
    m_String=0;
  }
  inline int getType(){
    return m_Type;
  }
};
class skOpNode : public skExprNode {
 public:
  skExprNode * m_Expr1;
  skExprNode * m_Expr2;
  int m_Type;
  inline skOpNode(int type,skExprNode * expr1,skExprNode * expr2){
    m_Expr1=expr1;
    m_Expr2=expr2;
    m_Type=type;
  }
  virtual ~skOpNode(){
    delete m_Expr1;
    delete m_Expr2;
  }
  inline void clear(){
    m_Expr1=0;
    m_Expr2=0;
  }
  inline int getType(){
    return m_Type;
  }
};
/**
 * This class represents the parse tree for a whole method in Simkin.
 * You should not modify any of its data members.
 */
class skMethodDefNode : public skParseNode {
 public:
  skStatListNode * m_Stats;
  skIdListNode * m_Params;
  inline skMethodDefNode(skStatListNode * stats){
    m_Stats=stats;
    m_Params=0;
  }
  inline skMethodDefNode(skIdListNode * params,skStatListNode * stats){
    m_Stats=stats;
    m_Params=params;
  }
  inline ~skMethodDefNode(){
    delete m_Stats;
    delete m_Params;
  }
  inline void clear(){
    m_Stats=0;
    m_Params=0;
  }
 private:
  skMethodDefNode(const skMethodDefNode& ){
  }
  skMethodDefNode& operator=(const skMethodDefNode&){
    return *this;
  }
};
#endif



