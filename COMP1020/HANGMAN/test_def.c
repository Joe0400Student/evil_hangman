
#include "test_def.h"
#include "String.h"
#include <string.h>

Status test_init_default_returns_nonNULL(char* buffer, int length){
	MY_STRING hString = NULL;
	
	hString = my_string_init_default();
	
	if(hString == NULL){
		my_string_destroy(&hString);
		strncpy(buffer,"test_init_default_returns_nonNULL\n",length);
		return FAILURE;
	}
	
	else{
		my_string_destroy(&hString);
		strncpy(buffer,"\ttest_init_defualt_Returns_nonNULL\n",length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length){
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	if(my_string_get_size(hString) != 0)
	{
		status = FAILURE;
		printf("Expected size 0 but got %d\n",my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n",length);
	}
	else{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n",length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_push_succeds(char* buffer, int length){
	
	MY_STRING hString = my_string_init_default();
	
	Status s = my_string_push_back(hString,'a');
	hString = my_string_destroy(&hString);

	return s;
}

Status test_get_size_on_push_returns_increment(char* buffer, int length){

	MY_STRING hString = my_string_init_default();
	
	my_string_push_back(hString,'a');
	
	Status s = 1 == my_string_get_size(hString);
	
	hString = my_string_destroy(&hString);
	
	return s;
}

Status my_string_concat_concatenates(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("abcdef");
	MY_STRING hString2 = __static__init__String("ghijkl");
	char* concatenated = "abcdefghijkl";
	
	for(int i = 0;i<my_string_get_size(hString);i++){
		if(*my_string_at(hString,i) != concatenated[i]){
			hString = my_string_destroy(&hString);
			hString2 = my_string_destroy(&hString2);
			return FAILURE;
		}
	}
	hString = my_string_destroy(&hString);
	hString2 = my_string_destroy(&hString2);
	return SUCCESS;
}

Status my_string_concat_changes_size(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("abcdef");
	MY_STRING hString2 = __static__init__String("ghijkl");
	int presize = my_string_get_size(hString);
	my_string_concat(hString,hString2);
	int postsize = my_string_get_size(hString);
	hString = my_string_destroy(&hString);
	hString2 = my_string_destroy(&hString2);
	if(postsize - presize == 6)
		return SUCCESS;
	return FAILURE;
}


Status my_string_at_returns_c_string(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("asbasdfa");
	for(int i = 0;i<my_string_get_size(hString);i++){
		if(my_string_at(hString,i)[my_string_get_size(hString)-i]!= 0){
			hString = my_string_destroy(&hString);
			return FAILURE;
		}
	}
	hString = my_string_destroy(&hString);
	return SUCCESS;
}

Status my_string_pop_remove(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("ab");
	
	my_string_pop_back(hString);
	
	if(my_string_at(hString, 0)[1] == 0){
		hString = my_string_destroy(&hString);
		return SUCCESS;
	}
	hString = my_string_destroy(&hString);
	return FAILURE;
}

Status my_string_pop_decrements(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("ab");
	int size = my_string_get_size(hString);
	my_string_pop_back(hString);
	if(size-my_string_get_size(hString) == 1){
		hString = my_string_destroy(&hString);
		return SUCCESS;
	}
	hString = my_string_destroy(&hString);
	return FAILURE;
}

Status my_string_push_actually_push(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("a");
	my_string_push_back(hString,'b');
	if(my_string_at(hString,0)[my_string_get_size(hString)-1] == 'b'){
		hString = my_string_destroy(&hString);
		return SUCCESS;
	}
	hString = my_string_destroy(&hString);
	return FAILURE;

}

Status my_string_pop_succeds(char* buffer, int length){
	
	MY_STRING hString = __static__init__String("ab");
	Status s = my_string_pop_back(hString);
	hString = my_string_destroy(&hString);
	return s;

}

Status destructor_changes_handle_null(char* buffer, int length){

	MY_STRING hString = my_string_init_default();
	my_string_destroy(&hString);
	return hString == NULL;

}

Status destructor_returns_null(char* buffer, int length){
	
	MY_STRING hString = my_string_init_default();
	MY_STRING ret = my_string_destroy(&hString);
	return ret == NULL;
}


Status my_string_init_capc_at_7(char* buffer, int length){
	
	MY_STRING hString = my_string_init_default();
	
	int capc = my_string_get_capacity(hString);
	
	hString = my_string_destroy(&hString);
	
	return capc == 7;

}
Status my_string_empty_true(char* buffer, int length){
	
	MY_STRING hString = my_string_init_default();
	
	Status s = my_string_empty(hString);
	
	hString = my_string_destroy(&hString);
	
	return s;
}

Status my_string_at_bounds_check(char* buffer, int length){

	MY_STRING hString = my_string_init_default();

	Status s = NULL == my_string_at(hString,1);
	hString = my_string_destroy(&hString);

	return s;
}

Status my_string_init_c_string_copys(char* buffer, int length){
	
	MY_STRING hString = my_string_init_c_string("abcdef");
	for(int i = 0;i<6;i++){
		if(*my_string_at(hString,i) != "abcdef"[i]){
			hString = my_string_destroy(&hString);
			return FAILURE;
		}
	}
	hString = my_string_destroy(&hString);
	return SUCCESS;
}

Status my_string_init_c_string_size_matches(char* buffer, int length){
	
	MY_STRING hString = my_string_init_c_string("abcdef");
	Status s = my_string_get_size(hString) == 6;
	hString = my_string_destroy(&hString);
	return s;
}
Status my_string_compare_equal(char* buffer, int length){
	MY_STRING hString = my_string_init_c_string("abc");
	Status s = 0 == my_string_compare(hString,hString);
	hString = my_string_destroy(&hString);
	return s;
}
Status my_string_compare_equal_dif_len(char* buffer, int length){
	
	MY_STRING hleft = my_string_init_c_string("abc");
	MY_STRING hright = my_string_init_c_string("abcd");
	Status s = 0 != my_string_compare(hleft,hright);
	hleft = my_string_destroy(&hleft);
	hright = my_string_destroy(&hright);
	return s;
}

Status my_string_compare_diff(char* buffer, int length){
	
	MY_STRING hLeft = my_string_init_c_string("abc");
	MY_STRING hRight = my_string_init_c_string("def");
	
	Status s = 0 != my_string_compare(hLeft,hRight);
	
	hLeft = my_string_destroy(&hLeft);
	hRight = my_string_destroy(&hRight);
	
	return s;
}


Status my_string_init_c_string_capc_above_size(char* buffer, int length){
	MY_STRING hLeft = my_string_init_c_string("abc");
	Status s = 4 == my_string_get_capacity(hLeft);
	hLeft= my_string_destroy(&hLeft);
	return s;
}

Status my_string_insertion_succeds(char* buffer, int length){
	MY_STRING hLeft = my_string_init_c_string("abc");
	Status s = my_string_insertion(hLeft,stdout);
	hLeft = my_string_destroy(&hLeft);
	return s;
}
Status my_string_my_string_c_str_equals_my_string_at(char* buffer, int length){
	
	MY_STRING hLeft = my_string_init_c_string("abc");
	Status s = my_string_at(hLeft,0) == my_string_c_str(hLeft);
	hLeft = my_string_destroy(&hLeft);
	return s;
}

Status my_string_pop_back_0_size(char* buffer, int length){
	
	MY_STRING hLeft = my_string_init_default();
	Status s = my_string_pop_back(hLeft);
	hLeft = my_string_destroy(&hLeft);
	return !s;
}
