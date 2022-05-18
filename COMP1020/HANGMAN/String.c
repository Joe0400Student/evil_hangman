
#include "String.h"

struct string{
    int size;
    int capc;
    char* memr;
};

typedef struct string sstring;

boolean resize(String,int);

String toLower(String s){
	sstring* s2 = s;
	char* cs = s2->memr;
	for(int i = 0;i<size(s);i++){
		if(cs[i] >= 'A' && cs[i] <= 'Z'){
			cs[i] += 32;
		}
	}
	return s;
}

String __init__String(int size){

    sstring* s = malloc(sizeof(sstring));

    if(s == NULL)
        return s;

    s->size = 0;
    s->capc = size;

    s->memr = malloc(size);

    if(s->memr == NULL){
        free(s);
        return NULL;
    }

    for(int i = 0;i<size;i++)
        s->memr[i] = 0;

    return (String)(s);
}

String __static__init__String(char* cstring){

    sstring* s = malloc(sizeof(sstring));

    if(s == NULL)
        return s;

    int i;

    for(i = 0;*(cstring + i) != 0;i++);

    s->size = i;
    s->capc = i+2;

    s->memr = malloc(i+3);

    if(s->memr == NULL){
        free(s);
        return NULL;
    }

    for(int j = 0;j<=i;j++)
        *(s->memr + j) = *(cstring + j);

    return s;
}
boolean push(String str, char a){
    if(capacity(str) <= size(str)+2)
	if(!resize(str,size(str)*2))
	    return false;
    ((sstring*)(str))->memr[size(str)] = a;
    ((sstring*)(str))->size++;
    return true;
}

char pop(String str){

    if(size(str) == 0)
        return -1;

    else{
        char a = getChar(str,size(str));

        setChar(str,size(str)-1,0);
        ((sstring*)(str))->size -= 1;

        return a;
    }
}

boolean resize(String str, int siz){

    sstring* s = (sstring*)(str);

    char* a = calloc(siz,1);
    if(a == NULL)
        return false;
    for(int i = 0;i<size(str);i++)
        a[i] = getChar(str,i);

    s->capc = siz;

    free(s->memr);
    s->memr = a;

    return true;
}




int size(String str){			return ((sstring*)(str))->size;		}
int capacity(String str){		return ((sstring*)(str))->capc;		}
char* cstring(String str, int i){	return ((sstring*)(str))->memr+i;	}
char getChar(String str, int i){	return *cstring(str,i);			}

char setChar(String str, int i, char a){

    if(i+1>=capacity(str))
        if(!resize(str, i+1 > capacity(str)*2 ? i+1: capacity(str)*2))
            return -1;

    char ret = getChar(str, i);
    ((sstring*)(str))->memr[i] = a;
    if(size(str)<=i)
        ((sstring*)(str))->size = i+1;
    return ret;
}

boolean insertChar(String str, int i, char a){

    for(int j = size(str);j>i;j++)
        if(-1==setChar(str,j,getChar(str,j-1)))
            return false;
    setChar(str,i,a);
    return true;

}


int compareTo(String str, String str2){
    int maxheight = size(str)<size(str2)?size(str2):size(str);
    for(int i = 0;i<maxheight;i++)
	if(getChar(str,i)!=getChar(str2,i)){
		return getChar(str,i)-getChar(str2,i);
	}
    if(size(str)!=size(str2)){
	if(size(str)<size(str2))
		return -getChar(str2,size(str));
	else
		return getChar(str,size(str2));
    }
    return 0;
}

boolean append(String str, String str2){
    for(int i = 0;i<size(str2);i++)
    	if(!push(str,getChar(str2,i))){
	    while(i!=0){
		pop(str);
		i--;
	    }
	    return false;
	}
    return true;

}


String __del__String(String* str){

    sstring* s = ((sstring*)(*str));

    free(s->memr);
    s->size = 0;
    s->capc = 0;
    free(s);

    return *str = NULL;
}

String __clear__String(String str){
    sstring* s = ((sstring*)(str));
    for(int i = 0;i< s->capc;i++)
        s->memr[i] = 0;
    s->size = 0;
    return str;
}
