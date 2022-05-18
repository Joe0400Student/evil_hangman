#pragma once
#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include "Boolean.h"


typedef void* String;


String __init__String(int size);
String __static__init__String(char* cstring);

String toLower(String s);

int size(String str);
int capacity(String str);

boolean push(String str, char a);
char pop(String str);



char getChar(String str, int i);
char setChar(String str, int i, char a);
boolean insertChar(String str, int i, char a);


int compareTo(String str, String str2);

char* cstring(String str, int i);


boolean append(String str, String str2);
String __del__String(String* str);

String __clear__String(String str);

#endif
