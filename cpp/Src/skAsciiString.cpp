/*
  Copyright 1996-2003
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

  $Id: skAsciiString.cpp,v 1.3 2003/04/04 17:04:25 simkin_cvs Exp $
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "skAsciiString.h"

const char * blank_ascii="";

class skBlankAsciiString : public P_AsciiString
{
public:
  skBlankAsciiString()
  {
    m_RefCount++;
  }
};
skBlankAsciiString g_blank_ascii_string;
P_AsciiString * blank_ascii_string=&g_blank_ascii_string;

//---------------------------------------------------
void P_AsciiString::init()
  //---------------------------------------------------
{
  const char * buffer=m_PString;
  m_Hash=0;
  while (*buffer){
    m_Hash^=*buffer;
    buffer++;
  }
  m_Length=(USize)strlen(m_PString);
}
//---------------------------------------------------
skAsciiString::skAsciiString(const char * s,int /* i */)
  //---------------------------------------------------
{                          
  //	create literal string
  pimp=new P_AsciiString;
  pimp->m_PString=(char *)s;
  pimp->init();
}
//---------------------------------------------------
skAsciiString::skAsciiString(const char repeatchar, USize len)
  //---------------------------------------------------
{
  // create skAsciiString of length len with repeated unsigned char
  pimp=new P_AsciiString;
  pimp->m_Const=false;
  char * str = new char[(len+1)];
  USize i;
  for (i = 0; i < len; i++)
    str[i] = repeatchar;
  str[i] = 0;	// NULL string terminator
  pimp->m_PString=str;
  pimp->init();
}
//---------------------------------------------------
skAsciiString::skAsciiString(P_AsciiString * p)
  //---------------------------------------------------
{                          
  pimp=p;
  pimp->init();
}
//---------------------------------------------------
int skAsciiString::indexOf(char c) const
  //---------------------------------------------------
{
  int pos=-1;
  char * ppos=strchr(pimp->m_PString,c);
  if (ppos!=0)
    pos=ppos-pimp->m_PString;
  return pos;
}
//---------------------------------------------------
int skAsciiString::indexOfLast(char c) const
  //---------------------------------------------------
{
  int pos=-1;
  char * ppos=strrchr(pimp->m_PString,c);
  if (ppos!=0)
    pos=ppos-pimp->m_PString;
  return pos;
}
//---------------------------------------------------
int skAsciiString::indexOf(const skAsciiString& s) const
  //---------------------------------------------------
{
  int pos=-1;
  char * ppos=strstr(pimp->m_PString,s.pimp->m_PString);
  if (ppos!=0)
    pos=ppos-pimp->m_PString;
  return pos;
}
//---------------------------------------------------
skAsciiString skAsciiString::substr(USize start) const
  //---------------------------------------------------
{
  if (start <= pimp->m_Length)
    return substr(start,pimp->m_Length-start);
  else
    return blank_ascii;
}
//---------------------------------------------------
skAsciiString skAsciiString::substr(USize start,USize length) const
  //---------------------------------------------------
{
  if (start <= pimp->m_Length){
    char * buffer=new char[length+1];
    strncpy(buffer,pimp->m_PString+start,length);
    buffer[length]=0;
    P_AsciiString * pnew=new P_AsciiString;
    pnew->m_Const=false;
    pnew->m_PString=buffer;
    // call internal non-copying constructor
    return skAsciiString(pnew);
  }else
    return blank_ascii;
}
//---------------------------------------------------
skAsciiString& skAsciiString::operator+=(const skAsciiString& s)
  //---------------------------------------------------
{
  operator=(operator+(s));
  return *this;
}
//---------------------------------------------------
skAsciiString operator+(const char * s1,const skAsciiString& s2)
//---------------------------------------------------
{
  USize len=strlen(s1)+s2.length()+1;
  char * buffer=new char[len];
  strcpy(buffer,s1);
  strcat(buffer,(const char *)s2);
  return skAsciiString::fromBuffer(buffer);
}
//---------------------------------------------------
skAsciiString skAsciiString::operator+(const skAsciiString& s)  const
  //---------------------------------------------------
{
  USize len=pimp->m_Length+s.pimp->m_Length+1;
  char * buffer=new char[len];
  strcpy(buffer,pimp->m_PString);
  strcat(buffer,s.pimp->m_PString);
  P_AsciiString * pnew=new P_AsciiString;
  pnew->m_Const=false;
  pnew->m_PString=buffer;
  // call internal non-copying constructor
  return skAsciiString(pnew);
}
//---------------------------------------------------
skAsciiString& skAsciiString::operator=(const char * s) 
  //---------------------------------------------------
{
  if (s!=pimp->m_PString){
    deRef();
    assign(s);
  }	
  return *this;
}
//---------------------------------------------------
bool skAsciiString::operator!=(const skAsciiString& s) const
  //---------------------------------------------------
{
  if (pimp==s.pimp)
    return false;
  else
    if (pimp->m_Hash==s.pimp->m_Hash)
      return (strcmp(pimp->m_PString,s.pimp->m_PString)!=0);
    else
      return true;
}
//---------------------------------------------------
bool skAsciiString::operator!=(const char * s) const
  //---------------------------------------------------
{
  if (s)
    return (strcmp(pimp->m_PString,s)!=0);
  else
    return true;
}
//---------------------------------------------------
P_AsciiString::P_AsciiString():m_Length(0),m_Hash(0),m_RefCount(1), m_PString((char *)blank_ascii),m_Const(true)
  //---------------------------------------------------
{
}
//---------------------------------------------------
skAsciiString skAsciiString::fromBuffer(char * buffer)
  //---------------------------------------------------
{
  //	create literal string
  P_AsciiString * pimp=new P_AsciiString;
  pimp->m_PString=buffer;
  pimp->m_Const=false;
  pimp->init();
  return skAsciiString(pimp);
}
//---------------------------------------------------
skAsciiString skAsciiString::from(int i)
  //---------------------------------------------------
{
  char buffer[100];
  sprintf(buffer,"%d",i);
  return skAsciiString(buffer);
}
#ifdef USE_FLOATING_POINT
//---------------------------------------------------
skAsciiString skAsciiString::from(float i)
  //---------------------------------------------------
{
  char buffer[100];
  sprintf(buffer,"%f",i);
  return skAsciiString(buffer);
}
#endif
//---------------------------------------------------
skAsciiString skAsciiString::from(USize i)
  //---------------------------------------------------
{
  char buffer[100];
  sprintf(buffer,"%u",i);
  return skAsciiString(buffer);
}
//---------------------------------------------------
int skAsciiString::to(void) const
  //---------------------------------------------------
{
  return atoi(pimp->m_PString);
}
#ifdef USE_FLOATING_POINT
//---------------------------------------------------
float skAsciiString::toFloat(void) const
  //---------------------------------------------------
{
  return (float)atof(pimp->m_PString);
}
#endif
//---------------------------------------------------
skAsciiString::skAsciiString(const char * s, USize len)
  //---------------------------------------------------
{   
  assign(s,len);
}
//---------------------------------------------------
skAsciiString::skAsciiString(const char * s) 
  //---------------------------------------------------
{   
  assign(s);
}
//---------------------------------------------------
skAsciiString skAsciiString::from(char ch)
  //---------------------------------------------------
{
  char	s[2];

  s[0] = ch;
  s[1] = '\0';

  return skAsciiString(s);
}
//---------------------------------------------------
skAsciiString skAsciiString::literal(const char * s)
  //---------------------------------------------------
{
  return skAsciiString(s,1);
}
//---------------------------------------------------
skAsciiString skAsciiString::ltrim() const
  //---------------------------------------------------
{
  char * p=pimp->m_PString;
  while (*p && isspace(*p))
    p++;
  return skAsciiString(p);
}
//---------------------------------------------------
void skAsciiString::assign(const char * s,int len)
//---------------------------------------------------
{
  if (s){
    if (len){
      pimp=new P_AsciiString;
      pimp->m_PString=new char[len+1];
      pimp->m_Const=false;
      memcpy(pimp->m_PString,s,sizeof(char)*len);
      pimp->m_PString[len]=0;
      pimp->init();
    }else{
      int s_len=strlen(s);
      if (s_len){
        pimp=new P_AsciiString;
        pimp->m_PString=new char[s_len+1];
        pimp->m_Const=false;
        strcpy((char *)pimp->m_PString,s);
        pimp->init();
      }else{
        pimp=blank_ascii_string;	
        pimp->m_RefCount++;
      }
    }
  }else{
    pimp=blank_ascii_string;	
    pimp->m_RefCount++;
  }
}
//-----------------------------------------------------------------
bool skAsciiString::equalsIgnoreCase(const skAsciiString& s) const
//-----------------------------------------------------------------
{
  return (_stricmp(pimp->m_PString,s.pimp->m_PString)==0);
}
#ifdef STREAMS_ENABLED
//-----------------------------------------------------------------
ostream& operator<<(ostream& out,const skAsciiString& s)
  //-----------------------------------------------------------------
{
  out << (const char *)s;
  return out;
}
#endif
