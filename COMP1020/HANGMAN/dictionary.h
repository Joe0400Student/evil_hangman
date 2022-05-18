#ifndef DICT
#define DICT

#include "my_string.h"
#include "vector.h"

typedef void* dict;

dict __init__dict();

dict makeDict(vector* v, MY_STRING letters);

dict insertdict(dict d, MY_STRING value, MY_STRING letters);

vector getLargest(dict* d);

void printkeysizes(dict d);

#endif DICT
