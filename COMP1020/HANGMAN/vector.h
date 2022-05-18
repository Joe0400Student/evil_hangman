#ifndef VEC_H
#define VEC_H
#include <stdlib.h>

typedef void* vector;

vector __init__vector();

vector insert(vector obj, void* v);

void** getPosition(vector v, int i);

int vsize(vector v);
int vcapc(vector v);

void* get(vector obj, int i);

vector rem(vector obj, int i);

vector __del__vector(vector* obj);

#endif
