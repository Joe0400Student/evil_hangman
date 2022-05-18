
#include "vector.h"
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "dictionary.h"

int main(int argc, char* argv){
        vector v = __init__vector();
	insert(v,my_string_init_c_string("the"));
	insert(v,my_string_init_c_string("Truck"));
	insert(v,my_string_init_c_string("happy"));
	insert(v,my_string_init_c_string("awesome"));
        vector v2 = vectorSplitterSize(v);
        for(int i = 0;i<vsize(v2);i++){
  //              printf("size:%d\nvectorsize:%d\n",i,vsize(get(v2,i)));
        }
        vector chosen = chooseWordGroup(&v2,3);
	v2 = vectorSplitterSize(v);
	vector chosen2 = chooseWordGroup(&v2,5);
	v2= vectorSplitterSize(v);
	vector chosen3 = chooseWordGroup(&v2,7);
//      dict d = __init__dict();
        for(int i = 0;i<vsize(chosen);i++){
//                printf("%s\n",my_string_c_str(get(chosen,i)));
        }
        MY_STRING s = my_string_init_c_string("t");
        dict d = makeDict(&chosen,s);
	MY_STRING s2 = my_string_init_c_string("rhpy");
	MY_STRING s3 = my_string_init_c_string("e");
	dict d2 = makeDict(&chosen2,s2);
	dict d3 = makeDict(&chosen3,s3);
        printkeysizes(d);
	printkeysizes(d2);
	printkeysizes(d3);
	vector a = getLargest(&d);
	__del__vector(&a);
	a = getLargest(&d2);
	__del__vector(&a);
	a = getLargest(&d3);
	__del__vector(&a);
	my_string_destroy(&s);
	my_string_destroy(&s2);
	my_string_destroy(&s3);
        while(vsize(v)){
//                printf("%s\n",my_string_c_str(get(v,0)));
                MY_STRING c = get(v,0);
                my_string_destroy(&c);
                rem(v,0);
        }

        __del__vector(&v);
        return 0;
}


