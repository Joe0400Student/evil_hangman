#include "unit_test.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	
	Status (*tests[])(char*,int)=
		{
			test_init_default_returns_nonNULL,
			test_push_succeds,
			test_get_size_on_push_returns_increment,
			my_string_concat_concatenates,
			my_string_concat_changes_size,
			my_string_at_returns_c_string,
			test_get_size_on_init_default_returns_0,
			my_string_pop_remove,
			my_string_pop_decrements,
			my_string_push_actually_push,
			my_string_pop_succeds,
			destructor_changes_handle_null,
			destructor_returns_null,
			my_string_init_capc_at_7,
			my_string_empty_true,
			my_string_at_bounds_check,
			my_string_init_c_string_copys,
			my_string_init_c_string_size_matches,
			my_string_compare_equal,
			my_string_compare_equal_dif_len,
			my_string_compare_diff,
			my_string_init_c_string_capc_above_size,
			my_string_insertion_succeds,
			my_string_my_string_c_str_equals_my_string_at,
			my_string_pop_back_0_size
		};
	int number_of_functions = sizeof(tests)/sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;
	
	for(i = 0;i<number_of_functions;i++){
		if(tests[i](buffer,500) == FAILURE){
			printf("FAILED: Test %d failed miserably\n",i);
			printf("\t%s\n",buffer);
			failure_count++;
		}
		else{
			printf("%d:PASS\n",i);
			success_count++;
		}
	}
	printf("total number of tests:%d\n",number_of_functions);
	printf("pass: %d, fail: %d\n",success_count,failure_count);
	return 0;
}
