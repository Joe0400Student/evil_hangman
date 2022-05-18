#pragma once
#ifndef MY_STR
#define MY_STR

#include "String.h"
#include "Boolean.h"
#include "Generic.h"

typedef boolean Boolean;
typedef boolean Status;

#define FAILURE 0
#define SUCCESS 1
#define FOUNDBUTEND -1

typedef String MY_STRING;

MY_STRING replace(MY_STRING s, MY_STRING tokep, char with);
MY_STRING my_string_init_default(void);
MY_STRING my_string_destroy(Item* phMy_string);
MY_STRING my_string_init_c_string(char* cstring);

boolean contains(MY_STRING s, char c);

int my_string_get_size(MY_STRING hMy_string);
int my_string_get_capacity(MY_STRING hMy_string);

void my_string_assignment(Item* pleft, Item pright);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_push_back(MY_STRING hMy_String, char item);

Status my_string_pop_back(MY_STRING hMy_string);

//to the reader, these functions will both return c-strings, because c strings
//are determined to always have a null terminator. Why this is important is that
//it makes no sense to make a function that wont return a null terminated string.
//it makes it more compolicated, and less safe. thats why both of these are 
//guarrenteed to return a c string. all c strings of at least 1 size have 
//another c string.
char* my_string_at(MY_STRING hMy_string, int index);
char* my_string_c_str(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

int my_string_compare(MY_STRING hLeft, MY_STRING hRight);

Boolean my_string_empty(MY_STRING hMy_string);

#endif
