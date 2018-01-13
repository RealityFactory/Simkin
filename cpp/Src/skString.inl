/*
Copyright 1996-2001
Simon Whiteside

$Id: skString.inl,v 1.5 2001/03/05 16:46:28 sdw Exp $
*/

#ifndef _STR_INL
#define _STR_INL

#include "skString.h"
#include <string.h>

class   P_String 
{
 public:
    unsigned char *	m_PString;
    USize			m_Length;
    USize			m_Hash;
    bool			m_Const;
    USize			m_RefCount;
    
    P_String();
    ~P_String();
    void			init();

};    
extern const char * blank;                    

extern P_String * blank_string;

//---------------------------------------------------
inline P_String::~P_String() 
//---------------------------------------------------
{ 
    if (m_Const==0) 
	delete[] m_PString; 
}
//---------------------------------------------------
inline skString::operator const char * () const 
//---------------------------------------------------
{
    return (const char *)pimp->m_PString;
}
//---------------------------------------------------
inline USize skString::length() const 
//---------------------------------------------------
{
    return pimp->m_Length;
}
//---------------------------------------------------
inline  bool skString::operator<(const skString& s) const
//---------------------------------------------------
{
    bool ret=false;
    if (pimp==s.pimp)
	ret=false;
    else{
	int i=strcmp((const char *)pimp->m_PString,(const char *)s.pimp->m_PString);
	if (i<0)
	    ret=true;
    }
    return ret;
}
//---------------------------------------------------
inline  bool skString::operator==(const skString& s) const
//---------------------------------------------------
{
    if (pimp==s.pimp)
      return true;
    else
      if (pimp->m_Hash==s.pimp->m_Hash && pimp->m_Length==s.pimp->m_Length)
	return (strcmp((const char *)pimp->m_PString,(const char *)s.pimp->m_PString)==0);
    else
      return false;
}
//---------------------------------------------------
inline  bool skString::operator==(const unsigned char * s) const
//---------------------------------------------------
{
  if (s)
    return (strcmp((const char *)pimp->m_PString,(const char *)s)==0);
  else
    return false;
}
//---------------------------------------------------
inline  bool skString::operator==(const char * s) const
//---------------------------------------------------
{
  if (s)
    return (strcmp((const char *)pimp->m_PString,s)==0);
  else
    return false;
}
//---------------------------------------------------
inline skString::operator const unsigned char * () const 
//---------------------------------------------------
{
    return pimp->m_PString;
}
//---------------------------------------------------
inline void skString::deRef()
     //---------------------------------------------------
{
    pimp->m_RefCount--;
    if (pimp->m_RefCount==0)
	delete pimp;
}
//---------------------------------------------------
inline void skString::assign(const unsigned char * s,int len)
//---------------------------------------------------
{
    if (s){
	if (len){
	    pimp=new P_String;
	    pimp->m_PString=new unsigned char[len+1];
	    pimp->m_Const=false;
	    memcpy(pimp->m_PString,s,len);
	    pimp->m_PString[len]=0;
	    pimp->init();
	}else{
	    if (strlen((const char *)s)){
		pimp=new P_String;
		pimp->m_PString=new unsigned char[strlen((const char *)s)+1];
		pimp->m_Const=false;
		strcpy((char *)pimp->m_PString,(const char *)s);
		pimp->init();
	    }else{
		if (blank_string==0)
		    blank_string=new P_String;
		pimp=blank_string;	
		pimp->m_RefCount++;
	    }
	}
    }else{
	if (blank_string==0)
	    blank_string=new P_String;
	pimp=blank_string;	
	pimp->m_RefCount++;
    }
}

//---------------------------------------------------
inline  skString::skString()
//---------------------------------------------------
{
    assign(0);
}
//---------------------------------------------------
inline skString& skString::operator=(const skString& s) 
//---------------------------------------------------
{
    if (&s!=this){
	s.pimp->m_RefCount++;
	deRef();
	pimp=s.pimp;
    }	
    return *this;
}
//---------------------------------------------------
inline skString::skString(const skString& s) 
//---------------------------------------------------
    : pimp(s.pimp)
{
    pimp->m_RefCount++;
}
//---------------------------------------------------
inline skString::~skString() 
//---------------------------------------------------
{
    deRef();
}
//---------------------------------------------------
inline USize skString::hash() const 
//---------------------------------------------------
{
    return pimp->m_Hash;
}
//---------------------------------------------------
inline unsigned char skString::at(USize index) const
//---------------------------------------------------
{
  unsigned char c=0;
  if (index<pimp->m_Length)
    c=pimp->m_PString[index];
  return c;	
}

#endif





