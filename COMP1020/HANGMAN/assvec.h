#ifndef ASS_H
#define ASS_H

//	hahha

#include "vector.h"
#include "my_string.h"

typedef struct {
	vector v;
	unsigned int signature;
} associated;

typedef void* assvec;

assvec __init__assvec(int size);

assvec insertassvec(assvec a, MY_STRING s,char c);

assvec __del__assvec(assvec* a);

associated getlargestwordfamily(assvec* a);

#endif
