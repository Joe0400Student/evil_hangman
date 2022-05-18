#include <stdlib.h>
#include "my_string.h"
//#include "String.h"

int main(int argc, char* argv[]){
    FILE* fp = fopen("words_alpha.txt","r");

    printf("%p %d\n",fp,sizeof(fp));
    if(fp == NULL){
        exit(1);
    }

    MY_STRING hMy_string = NULL;
    hMy_string = my_string_init_default();
    while(my_string_extraction(hMy_string,fp)){
        my_string_insertion(hMy_string,stdout);
        printf("\n%d is my size\n",size(hMy_string));
        my_string_push_back(hMy_string,'!');
        printf("\n%s",my_string_c_str(hMy_string));
        my_string_pop_back(hMy_string);
        printf("\n%s",my_string_c_str(hMy_string));
        printf("\n");
        printf("%d is the size\n",size(hMy_string));
        //exit(0);
        if(fgetc(fp)=='\n')
            printf("Found a space after the string\n");
    }
    my_string_destroy(&hMy_string);
    clearerr(fp);
    fclose(fp);
    return 0;
}

