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
*/
#include "skInterpreter.h"
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include "skTreeNode.h"
#include "skTreeNodeObject.h"
#include "skInputSource.h"
#include "skTraceCallback.h"

/**
 * This example shows Simkin can be used with a CGI program.
 * The CGI program is supplied with Simkin script, which it executes, and passes the output back to the calling browser.
 */

#include <stdio.h>
#include <stdlib.h>

skLITERAL(main);

/** 
* A TraceCallback object that puts output to stdout via printf
*/
class CGITracer : public skTraceCallback
{
public:
  void trace(const skString& msg){
    printf("%s",(const Char *)msg);
  }
};

#define MAXLEN 800
#define EXTRA 5
/* 4 for field name "data", 1 for "=" */
#define MAXINPUT MAXLEN+EXTRA+2

void unencode(char *src, char *last, char *dest);
/**
* Entry point for the cgi program
*/
int main(void)
{
  char *lenstr;
  char input[MAXINPUT], data[MAXINPUT];
  long len;
  // Output some HTTP headers
  printf("Content-Type:text/html;charset=iso-8859-1\n\n",13,10);
  printf("<HTML><HEAD>");
  printf("<TITLE>Response</TITLE>\n");
  // Read length of the input
  lenstr = getenv("CONTENT_LENGTH");
  if(lenstr == NULL || sscanf(lenstr,"%ld",&len)!=1 || len > MAXLEN)
    printf("<P>Error in invocation - wrong FORM probably.");
  else {
    // Read input from stdin
    fgets(input, len+1, stdin);
    // decode the input
    unencode(input+EXTRA, input+len, data);

    // create an interpreter
    skInterpreter interpreter;
    // and a tracer
    CGITracer tracer;
    interpreter.setTraceCallback(&tracer);
    // create a context
    skExecutableContext ctxt(&interpreter);

    // read the input into a TreeNode
    skInputString in(data);
    skTreeNodeReader reader(in,skString("Web"));
    skTreeNode * node=reader.read(ctxt);

    // Wrap the node in an executable object
    skTreeNodeObject obj(skString("Web"),node,true);

    // Call the "main" method - this executes the script that has been sent
    skRValueArray args;
    skRValue return_value;
    if (obj.method(s_main,args,return_value,ctxt)==false)
      printf("method main not found:<p>");
    
  }
  printf("</HEAD></HTML>");
  return 0;
}
/**
* This function unencodes the CGI input
* @param src encoded string
* @param last last position within string to be decoded
* @param dest buffer into which decoded text is put
*/
void unencode(char *src, char *last, char *dest){
  for(; src != last; src++, dest++)
   if(*src == '+')
     *dest = ' ';
   else if(*src == '%') {
     int code;
     if(sscanf(src+1, "%2x", &code) != 1) code = '?';
     *dest = code;
     src +=2; }     
   else
     *dest = *src;
  *dest = '\n';
  *++dest = '\0';
}
