/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skString.cpp,v 1.7 2001/03/05 16:46:28 sdw Exp $
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "skString.h"


const char * blank="";                    

P_String * blank_string=0;

//---------------------------------------------------
void P_String::init()
  //---------------------------------------------------
{
  const unsigned char * buffer=m_PString;
  m_Hash=0;
  while (*buffer){
    m_Hash^=*buffer;
    buffer++;
  }
  m_Length=(USize)strlen((const char *)m_PString);
}
//---------------------------------------------------
skString::skString(const unsigned char * s,int /* i */)
  //---------------------------------------------------
{                          
  //	create literal string
  pimp=new P_String;
  pimp->m_PString=(unsigned char *)s;
  pimp->init();
}
//---------------------------------------------------
skString::skString(const unsigned char repeatChar, USize len)
  //---------------------------------------------------
{
  // create skString of length len with repeated unsigned char
  pimp=new P_String;
  pimp->m_Const=false;
  unsigned char * str = new unsigned char[(len+1)];
  USize i;
  for (i = 0; i < len; i++)
    str[i] = repeatChar;
  str[i] = 0;	// NULL string terminator
  pimp->m_PString=str;
  pimp->init();
}
//---------------------------------------------------
skString::skString(P_String * p)
  //---------------------------------------------------
{                          
  pimp=p;
  pimp->init();
}
//---------------------------------------------------
int skString::indexOf(char c)
//---------------------------------------------------
{
  int pos=-1;
  char * ppos=strchr((const char *)pimp->m_PString,c);
  if (ppos!=0)
    pos=ppos-(const char *)pimp->m_PString;
  return pos;
}
//---------------------------------------------------
skString skString::substr(USize start) const
  //---------------------------------------------------
{
  if (start <= pimp->m_Length)
    return substr(start,pimp->m_Length-start);
  else
    return skString("");
}
//---------------------------------------------------
skString skString::substr(USize start,USize length) const
  //---------------------------------------------------
{
  if (start <= pimp->m_Length){
    unsigned char * buffer=new unsigned char[length+1];
    strncpy((char *)buffer,(const char *)pimp->m_PString+start,length);
    buffer[length]=0;
    P_String * pnew=new P_String;
    pnew->m_Const=false;
    pnew->m_PString=buffer;
    // call internal non-copying constructor
    return skString(pnew);
  }else
    return skString("");
}
//---------------------------------------------------
skString& skString::operator+=(const skString& s)
  //---------------------------------------------------
{
  operator=(operator+(s));
  return *this;
}
//---------------------------------------------------
skString skString::operator+(const skString& s)  const
  //---------------------------------------------------
{
  USize len=pimp->m_Length+s.pimp->m_Length+1;
  unsigned char * buffer=new unsigned char[len];
  strcpy((char *)buffer,(const char *)pimp->m_PString);
  strcat((char *)buffer,(const char *)s.pimp->m_PString);
  P_String * pnew=new P_String;
  pnew->m_Const=false;
  pnew->m_PString=buffer;
  // call internal non-copying constructor
  return skString(pnew);
}
//---------------------------------------------------
skString& skString::operator=(const unsigned char * s) 
  //---------------------------------------------------
{
  if (s!=pimp->m_PString){
    deRef();
    assign(s);
  }	
  return *this;
}
//---------------------------------------------------
skString& skString::operator=(const char * s) 
  //---------------------------------------------------
{
  if (s!=(const char *)pimp->m_PString){
    deRef();
    assign((const unsigned char *)s);
  }	
  return *this;
}
//---------------------------------------------------
bool skString::operator!=(const skString& s) const
  //---------------------------------------------------
{
  if (pimp==s.pimp)
    return false;
  else
    if (pimp->m_Hash==s.pimp->m_Hash)
      return (strcmp((const char *)pimp->m_PString,(const char *)s.pimp->m_PString)!=0);
    else
      return true;
}
//---------------------------------------------------
bool skString::operator!=(const unsigned char * s) const
  //---------------------------------------------------
{
  if (s)
    return (strcmp((const char *)pimp->m_PString,(const char *)s)!=0);
  else
    return true;
}
//---------------------------------------------------
bool skString::operator!=(const char * s) const
  //---------------------------------------------------
{
  if (s)
    return (strcmp((const char *)pimp->m_PString,s)!=0);
  else
    return true;
}
//---------------------------------------------------
P_String::P_String():m_Length(0),m_Hash(0),m_RefCount(1), m_PString((unsigned char *)blank),m_Const(true)
  //---------------------------------------------------
{
}
//---------------------------------------------------
skString skString::fromBuffer(unsigned char * buffer)
  //---------------------------------------------------
{
  //	create literal string
  P_String * pimp=new P_String;
  pimp->m_PString=buffer;
  pimp->m_Const=false;
  pimp->init();
  return skString(pimp);
}
//---------------------------------------------------
skString skString::from(int i)
  //---------------------------------------------------
{
  unsigned char buffer[100];
  sprintf((char *)buffer,"%d",i);
  return skString(buffer);
}
//---------------------------------------------------
skString skString::from(float i)
  //---------------------------------------------------
{
  unsigned char buffer[100];
  sprintf((char *)buffer,"%f",i);
  return skString(buffer);
}
//---------------------------------------------------
skString skString::from(USize i)
  //---------------------------------------------------
{
  unsigned char buffer[100];
  sprintf((char *)buffer,"%u",i);
  return skString(buffer);
}
//---------------------------------------------------
int skString::to(void) const
  //---------------------------------------------------
{
  return atoi((const char *)pimp->m_PString);
}
//---------------------------------------------------
float skString::toFloat(void) const
  //---------------------------------------------------
{
  return (float)atof((const char *)pimp->m_PString);
}
//---------------------------------------------------
skString::skString(const unsigned char * s, USize len)
  //---------------------------------------------------
{   
  assign(s,len);
}
//---------------------------------------------------
skString::skString(const unsigned char * s) 
  //---------------------------------------------------
{   
  assign(s);
}
//---------------------------------------------------
skString::skString(const char * s) 
  //---------------------------------------------------
{   
  assign((const unsigned char *)s);
}
//---------------------------------------------------
skString skString::from(unsigned char ch)
  //---------------------------------------------------
{
  unsigned char	s[2];

  s[0] = ch;
  s[1] = '\0';

  return skString(s);
}
//---------------------------------------------------
skString skString::literal(const char * s)
  //---------------------------------------------------
{
  return skString((const unsigned char * )s,1);
}
#include <iostream.h>
//-----------------------------------------------------------------
ostream& operator<<(ostream& out,const skString& s)
  //-----------------------------------------------------------------
{
  out << (const char *)(const unsigned char *)s;
  return out;
}


