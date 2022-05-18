#include "vector.h"
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "dictionary.h"

int main(int argc, char* argv){
	vector v = vectorIterGenerator();
	vector v2 = vectorSplitterSize(v);
	for(int i = 0;i<vsize(v2);i++){
		printf("size:%d\nvectorsize:%d\n",i,vsize(get(v2,i)));
	}
	vector chosen = chooseWordGroup(&v2,7);
//	dict d = __init__dict();
	for(int i = 0;i<vsize(chosen);i++){
		printf("%s\n",my_string_c_str(get(chosen,i)));
	}
	MY_STRING s = my_string_init_c_string("a");
	dict d = makeDict(&chosen,s);
	printkeysizes(d);
	
        while(vsize(v)){
//                printf("%s\n",my_string_c_str(get(v,0)));
                MY_STRING c = get(v,0);
                my_string_destroy(&c);
                rem(v,0);
        }
	
	__del__vector(&v);
	return 0;
}
