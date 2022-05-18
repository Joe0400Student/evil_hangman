#include "vector.h"

typedef struct{
	
	void** arr;
	int size;
	int capc;

} vec;

vector __init__vector(){
	
	vec* v = malloc(sizeof(vec));
	if(v == NULL){
		return v;
	}
	v->arr = malloc(sizeof(void*)*8);
	if(v->arr == NULL){
		free(v);
		return NULL;
	}
	v->size = 0;
	v->capc = 8;
	return v;
}

vec* resze(vec* a){
	a->arr = realloc(a->arr, sizeof(void*)*(a->capc*=2));
	return a;
}

void** getPosition(vector v, int i){
	return (((vec*)(v))->arr+i);
}
vector insert(vector v, void* obj){
	vec* v2 = (vec*)(v);
	if(v2 == NULL)
		v2 = __init__vector();
	if(v2->size + 1>= v2->capc)
		resze(v);
	v2->arr[v2->size++] = obj;
	return v2;
}

vector rem(vector v, int i){
	vec* v2 = (vec*)(v);
	if(v2 == NULL)
		return v2;
	if(i<0 || i >= v2->size){
		return v2;
	}
	v2->arr[i] = v2->arr[v2->size-1];
	v2->size--;
	return v2;
}

void* get(vector v, int i){
	if(v == NULL || i < 0 || i >= ((vec*)(v))->size)
		return NULL;
	return ((vec*)(v))->arr[i];
}

int vsize(vector v){
	if(v == NULL)
		return -1;
	return ((vec*)(v))->size;
}
int vcapc(vector v){
	if(v == NULL)
		return -1;
	return ((vec*)(v))->capc;
}
vector __del__vector(vector* v){
	if(v == NULL || *v == NULL){
		return NULL;
	}
	free(((vec*)(*v))->arr);
	free(*v);
	return *v = NULL;
}
