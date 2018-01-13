/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skAlist.cpp,v 1.7 2001/06/13 16:48:21 sdw Exp $
*/
#include <iostream.h>
#include "skAlist.h"


const USize	skAList::DEFAULT_SIZE=0;				// so nothing is allocated until needed
const USize	skAList::DEFAULT_GROWTH_INCREMENT=4;	// value of 0 means 'double in size'

//-----------------------------------------------------------------
void skAList::clearAndDestroy()
//-----------------------------------------------------------------
{
    for (USize x=0;x<m_Entries;x++){
	deleteItem(m_Array[x]);
	m_Array[x]=0;
    }
    m_Entries=0;
}
//-----------------------------------------------------------------
void skAList::clear()
//-----------------------------------------------------------------
{
    for (USize x=0;x<m_Entries;x++)
	m_Array[x]=0;
    m_Entries=0;
}
//-----------------------------------------------------------------
void skAList::insert(void * p,USize index)
//-----------------------------------------------------------------
{
    assert(p);
    assert(index<=m_Entries);
    assert(contains(p)==false);
    if (index>m_Entries)
	throw skBoundsException(skSTR("Invalid index to insert"),__FILE__,__LINE__);

    if (m_ArraySize==m_Entries)
	grow();
    if (index<m_Entries)
	for (USize x=m_Entries;x>index;x--)
	    m_Array[x]=m_Array[x-1];		
    m_Array[index]=p;
    m_Entries++;
}
//-----------------------------------------------------------------
void skAList::prepend(void * i)
//-----------------------------------------------------------------
{
    assert(i);
    assert(contains(i)==false);
    if (m_ArraySize==m_Entries)
	grow();
    for (USize x=m_Entries;x>=1;x--)
	m_Array[x]=m_Array[x-1];
    m_Entries++;
    m_Array[0]=i;
}
//-----------------------------------------------------------------
void skAList::remove(void * i)
//-----------------------------------------------------------------
{   
    assert(i);
    int index = findElt(i);
    assert(index>=0 && "AList does not contain item"!=0);
    for (USize x=(USize)index;x<m_Entries-1;x++)
	m_Array[x]=m_Array[x+1];
    m_Entries--;
}
//-----------------------------------------------------------------
void skAList::removeAndDestroy(void * i)
//-----------------------------------------------------------------
{   
    assert(i);
    int index = findElt(i);
    assert(index>=0 && "AList does not contain item"!=0);

    deleteItem(m_Array[index]);
    for (USize x=index;x<m_Entries-1;x++)
	m_Array[x]=m_Array[x+1];

    m_Entries--;
}
//-----------------------------------------------------------------
void skAList::deleteElt(USize index)
//-----------------------------------------------------------------
{
    assert(index<m_Entries);
    if (index>=m_Entries)
	throw skBoundsException(skSTR("Invalid index to deleteElt"),__FILE__,__LINE__);
    deleteItem(m_Array[index]);
    for (USize x=index;x<m_Entries-1;x++)
	m_Array[x]=m_Array[x+1];
    m_Entries--;
}
//-----------------------------------------------------------------
void skAList::growTo(USize new_size)
//-----------------------------------------------------------------
{
    if (new_size>m_ArraySize){
	m_ArraySize = new_size;

	void ** new_array=new void *[m_ArraySize];
	if(m_Array){
	    for (USize x=0;x<m_Entries;x++){
		new_array[x]=m_Array[x];
		m_Array[x]=0;
	    }
	    delete [] m_Array;
	}
	m_Array=new_array;
    }
}
//-----------------------------------------------------------------
void skAList::grow()
//-----------------------------------------------------------------
{
    if(m_GrowthIncrement != 0)
	m_ArraySize += m_GrowthIncrement;	// constant increase in size
    else{
	if(m_ArraySize==0)
	    m_ArraySize = 1;
	else
	    m_ArraySize *= 2;			// double size
    }

    void ** new_array=new void *[m_ArraySize];
    if(m_Array){
	for (USize x=0;x<m_Entries;x++){
	    new_array[x]=m_Array[x];
	    m_Array[x]=0;
	}
	delete [] m_Array;
    }
    m_Array=new_array;
}
//-----------------------------------------------------------------
void skAList::test() const
//-----------------------------------------------------------------
{   
#ifdef MICROSOFT_C
    _heapchk();
#endif
    assert(m_Entries<=m_ArraySize);
    assert(!(m_Array==0 && m_ArraySize > 0));
}
