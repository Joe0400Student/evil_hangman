#include "assvec.h"

typedef vector asvec;

assvec __init__assvec(int size){
	vector ret = __init__vector();
	for(;size;size--)
		insert(ret,__init__vector());
	return ret;
}

assvec insertassvec(assvec a, MY_STRING s, char c){
	insert(get(a,occurenceloc(s,c)),s);
	return a;
}


assvec __del__assvec(assvec* a){
	return __del__vector(a);
}

associated getlargestwordfamily(assvec* a){
	int largest = 0;
	for(int i = 0;i<vsize(*a);i++){
		if(vsize(get(*a,i)) > vsize(get(*a,largest))){
			largest = i;
		}
	}
	vector v = get(*a,largest);
	associated l;
	l.v = v;
	l.signature = largest;
	for(int i = 0;i<vsize(*a);i++){
		if(i != largest){
			__del__vector(getPosition(*a,i));
		}
	}
	__del__assvec(a);
	return l;
}
