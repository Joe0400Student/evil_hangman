#ifndef UNIT_TEST_H
#define UNIT_TEST_H
	
#include "my_string.h"
#include "Generic.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_push_succeds(char* buffer, int length);
//2
Status test_get_size_on_push_returns_increment(char* buffer, int length);
Status my_string_concat_concatenates(char* buffer, int length);
//4
Status my_string_concat_changes_size(char* buffer, int length);
Status my_string_at_returns_c_string(char* buffer, int length);
//6
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status my_string_pop_remove(char* buffer,int length);
//8
Status my_string_pop_decrements(char* buffer, int length);
Status my_string_push_actually_push(char* buffer, int length);
//10
Status my_string_pop_succeds(char* buffer, int length);
Status destructor_changes_handle_null(char* buffer, int length);
//12
Status destructor_returns_null(char* buffer, int length);
Status my_string_init_capc_at_7(char* buffer, int length);
//14
Status my_string_empty_true(char* buffer, int length);
Status my_string_at_bounds_check(char* buffer, int length);
//16
Status my_string_init_c_string_copys(char* buffer,int length);
Status my_string_init_c_string_size_matches(char* buffer, int length);
//18
Status my_string_compare_equal(char* buffer, int length);
Status my_string_compare_equal_dif_len(char* buffer, int length);
//20
Status my_string_compare_diff(char* buffer, int length);
Status my_string_init_c_string_capc_above_size(char* buffer, int length);
//22
Status my_string_insertion_succeds(char* buffer, int length);
Status my_string_my_string_c_str_equals_my_string_at(char* buffer, int length);
//24
Status my_string_pop_back_0_size(char* buffer, int length);
//25
#endif
