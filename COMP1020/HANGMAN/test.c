#include "my_string.h"
#include <stdio.h>

int main(){

        MY_STRING arr[100];
	for(int i = 0;i<100;i++)
		arr[i] = NULL;
        arr[0] = my_string_init_c_string("COPY ME!");
        for(int i = 1;i<100;i++){
                my_string_assignment(arr+i,arr[0]);
        }
        for(int i = 0;i<100;i++){
                my_string_insertion(arr[i],stdout);
               // my_string_destroy(arr+i);
        }
        return 0;
}



