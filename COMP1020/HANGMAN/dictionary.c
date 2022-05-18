#include "dictionary.h"

typedef struct{
	vector keys;
	vector strings;
} dictionary;

dict __init__dict(){
	dictionary* d = malloc(sizeof(dictionary));
	if(d == NULL)
		return d;
	d->keys = __init__vector();
	d->strings = __init__vector();
	return d;
}


dict insertDict(dict d, MY_STRING s, MY_STRING characters){
	dictionary* d2 = d;
	vector keys = d2->keys;
	vector elements = d2->strings;
	MY_STRING compto = replace(s,characters,'-');
	int pos = -1;
	for(int i = 0;i<vsize(keys);i++){
		if(!compareTo(get(keys,i),compto)){
			pos = i;
		}
	}
	if(pos > -1){
		my_string_destroy(&compto);
		insert(get(elements,pos),s);
	}
	else{
		insert(keys,compto);
		insert(elements,__init__vector());
		insert(get(elements,vsize(keys)-1),s);
	}
	return d;
}

dict makeDict(vector* v, MY_STRING characters){
	dict d = __init__dict();
	for(int i = 0;i<vsize(*v);i++){
		insertDict(d,get(*v,i),characters);
	}
	__del__vector(v);
	return d;
}
vector getLargest(dict* d){
	int pos = 0;
	dictionary* d2 = *d;
	vector keys = d2->keys;
	vector elements = d2->strings;
	for(int i = 0;i<vsize(elements);i++){
		if(vsize(get(elements,pos))<vsize(get(elements,i))){
			pos = i;
		}
	}
	for(int i = 0;i<vsize(keys);i++){
		MY_STRING s = get(keys,i);
		my_string_destroy(&s);
	}
	__del__vector(&keys);
	vector ret = get(elements,pos);
	for(int i = 0;i<vsize(elements);i++){
		if(i != pos){
			vector v = get(elements,i);
			__del__vector(&v);
		}
	}
	__del__vector(&elements);
	free(*d);
	*d = NULL;
	return ret;
}

void printkeysizes(dict d){
	dictionary* d2 = d;
	vector keys = d2->keys;
	vector elements = d2->strings;

	for(int i = 0;i<vsize(keys);i++){
		printf("%s: %d\n",my_string_c_str(get(keys,i)),vsize(get(elements,i)));
	}
}
