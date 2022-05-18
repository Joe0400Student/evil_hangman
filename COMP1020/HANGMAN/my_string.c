#include "my_string.h"



MY_STRING my_string_init_c_string(char* cstring){		return __static__init__String(cstring);}
MY_STRING my_string_init_default(void){ 			return __init__String(7);}
MY_STRING my_string_destroy(MY_STRING* phMy_string){ 		return __del__String(phMy_string);}
char* my_string_at(MY_STRING hMy_string, int index){ 		return index>=0&&index<size(hMy_string)?cstring(hMy_string,index):NULL;}
char* my_string_c_str(MY_STRING hMy_string){ 			return my_string_at(hMy_string,0);}

int my_string_get_size(MY_STRING hMy_string){			return size(hMy_string);}
int my_string_get_capacity(MY_STRING hMy_string){		return capacity(hMy_string);}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){ 	return append(hResult, hAppend);}
Boolean my_string_empty(MY_STRING hMy_string){ 			return !size(hMy_string);}

Status my_string_push_back(MY_STRING hMy_string, char item){	return push(hMy_string,item);}
Status my_string_pop_back(MY_STRING hMy_string){		return -1<pop(hMy_string);}

int my_string_compare(MY_STRING hLeft, MY_STRING hRight){	return compareTo(hLeft,hRight);}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){

    hMy_string = __clear__String(hMy_string);
    char c;
    for(int i = 0;(c = fgetc(fp))!=EOF && c != '\n';i++)
	if(c!=' ')
        	push(hMy_string,c);

    if(!size(hMy_string))
        return FAILURE;
    return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string,FILE* fp){
    fprintf(fp,"%s",cstring(hMy_string,0));
    return true;
}
void my_string_assignment(Item* pleft, Item pright){
        if(pright == NULL){
                *pleft = NULL;
                return;
        }
	if(*pleft != NULL)
        	my_string_destroy(pleft);
        *pleft = my_string_init_c_string(cstring(pright,0));
}

MY_STRING replace(MY_STRING s, MY_STRING tokep, char with){
        MY_STRING n = my_string_init_c_string(my_string_c_str(s));
	toLower(n);
        char* c = my_string_c_str(n);
        char* comparator =  my_string_c_str(tokep);
        for(int i = 0;i<my_string_get_size(n);i++){
                char check = 0;
                for(int j = 0;j<my_string_get_size(tokep);j++){
                        if(c[i] == comparator[j]){
                                check = 1;
                                break;
                        }
                }
                if(!check){
                        c[i] = with;
                }
        }
        return n;
}

boolean contains(MY_STRING s, char c){
	for(int i = 0;i<my_string_get_size(s);i++)
		if(my_string_c_str(s)[i] == c)
			return true;
	return false;
}
