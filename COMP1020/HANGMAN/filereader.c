#include "filereader.h"

vector vectorIterGenerator(){
        FILE* f = fopen("dictionary.txt","r");

        vector v = __init__vector();
        while(1){
                MY_STRING n = my_string_init_default();
                if(!my_string_extraction(n,f)){
                        my_string_destroy(&n);
                        break;
                }
                insert(v,n);
        }
        fclose(f);
	return v;
}
vector vectorSplitterSize(vector v){
	vector v2 = __init__vector();
	for(int i = 0;i<30;i++){
		insert(v2,__init__vector());
	}
	for(int i = 0;i<vsize(v);i++){
		insert(get(v2,my_string_get_size(get(v,i))),get(v,i));
	}
	return v2;
}

int vcontains(vector v, int i){
	if(i<=0)
		return 0;
	if(vsize(v)<i)
		return 0;
	return vsize(get(v,i));
}

vector chooseWordGroup(vector* v, int j){
	vector v2 = get(*v,j);
	for(int i = 0;i<vsize(*v);i++){
		if(i != j){
			vector cpy = get(*v,i);
			__del__vector(&cpy);
		}
	}
	__del__vector(v);
	return v2;
}
