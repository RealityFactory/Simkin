/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skStringTokenizer.cpp,v 1.2 2001/03/05 16:46:28 sdw Exp $
*/
#include "skStringTokenizer.h"

//------------------------------------------
void skStringTokenizer::setMaxDelimChar() 
//------------------------------------------
{
  if (delimiters.length() == 0) {
    maxDelimChar = 0;
    return;
  }
  
  char m = 0;
  for (unsigned int i = 0; i < delimiters.length(); i++) {
    char c = delimiters.at(i);
    if (m < c)
      m = c;
  }
  maxDelimChar = m;
}
//------------------------------------------
skStringTokenizer::skStringTokenizer(skString str, skString delim, bool returnDelims) 
//------------------------------------------
{
  init(str, delim, returnDelims);
}
//------------------------------------------
void skStringTokenizer::init(skString str, skString delim, bool returnDelims)
//------------------------------------------
{
  currentPosition = 0;
  newPosition = -1;
  delimsChanged = false;
  this->str = str;
  maxPosition = str.length();
  delimiters = delim;
  retDelims = returnDelims;
  setMaxDelimChar();
}
//------------------------------------------
skStringTokenizer::skStringTokenizer(skString str, skString delim) 
//------------------------------------------
{
  init(str, delim, false);
}
//------------------------------------------
skStringTokenizer::skStringTokenizer(skString str) 
//------------------------------------------
{
  init(str, " \t\n\r\f", false);
}
//------------------------------------------
int skStringTokenizer::skipDelimiters(int startPos) 
//------------------------------------------
{
  int position = startPos;
  while (!retDelims && position < maxPosition) {
    char c = str.at(position);
    if ((c > maxDelimChar) || (delimiters.indexOf(c) < 0))
      break;
    position++;
  }
  return position;
}
//------------------------------------------
int skStringTokenizer::scanToken(int startPos) 
//------------------------------------------
{
  int position = startPos;
  while (position < maxPosition) {
    char c = str.at(position);
    if ((c <= maxDelimChar) && (delimiters.indexOf(c) >= 0))
      break;
    position++;
  }
  if (retDelims && (startPos == position)) {
    char c = str.at(position);
    if ((c <= maxDelimChar) && (delimiters.indexOf(c) >= 0))
      position++;
  }
  return position;
}
//------------------------------------------
bool skStringTokenizer::hasMoreTokens() 
//------------------------------------------
{
  /*
   * Temporary store this position and use it in the following
   * nextToken() method only if the delimiters have'nt been changed in
   * that nextToken() invocation.
   */
  newPosition = skipDelimiters(currentPosition);
  return (newPosition < maxPosition);
}
//------------------------------------------
skString skStringTokenizer::nextToken() 
  //------------------------------------------
{
  /* 
   * If next position already computed in hasMoreElements() and
   * delimiters have changed between the computation and this invocation,
   * then use the computed value.
   */
  
  currentPosition = (newPosition >= 0 && !delimsChanged) ?  
    newPosition : skipDelimiters(currentPosition);
  
  /* Reset these anyway */
  delimsChanged = false;
  newPosition = -1;
  
  int start = currentPosition;
  currentPosition = scanToken(currentPosition);
  return str.substr(start, currentPosition-start);
}
//------------------------------------------
skString skStringTokenizer::nextToken(skString delim) 
  //------------------------------------------
{
  delimiters = delim;
  
  /* delimiter string specified, so set the appropriate flag. */
  delimsChanged = true;
  
  setMaxDelimChar();
  return nextToken();
}
//------------------------------------------
int skStringTokenizer::countTokens() 
  //------------------------------------------
{
  int count = 0;
  int currpos = currentPosition;
  while (currpos < maxPosition) {
    currpos = skipDelimiters(currpos);
    if (currpos >= maxPosition)
      break;
    currpos = scanToken(currpos);
    count++;
  }
  return count;
}
