#include "unity.h"
#include "list.h"
#include "list_merge.h"

List *test_list, *test_list2;
int i1, i2, i3;
iterator *test_iterator;
void setUp() {
        test_list = list_new();
        test_list2 = list_new();
        test_iterator = iterator_new(test_list);

        i1 = 1;
        i2 = 2;
        i3 = 3;
}

void tearDown() {
        list_free(test_list);
        iterator_free(test_iterator);
}

void test_empty_list(){
        TEST_ASSERT_TRUE(list_is_empty(test_list));
}

void test_not_empty_list_insert_at_tail(){
        list_add_tail(test_list,&i1);
        list_add_tail(test_list,&i2);
        TEST_ASSERT_FALSE(list_is_empty(test_list));
}

void test_empty_list_with_delete_in_tail(){
        list_add_tail(test_list,&i1);
        list_delete_in_tail(test_list);
        TEST_ASSERT_TRUE(list_is_empty(test_list));
}

void test_list_insert_at_index(){
        list_add_tail(test_list, &i1);
        list_add_tail(test_list, &i2);
        list_add_at_index(test_list, 1, &i3);
        list_add_tail(test_list2, &i1);
        list_add_tail(test_list2, &i3);
        list_add_tail(test_list2, &i2);
        TEST_ASSERT_EQUAL(0,lists_is_not_equals(test_list, test_list2));
}

void test_get_elem_at_index(){
        list_add_tail(test_list, &i1);
        TEST_ASSERT_EQUAL(list_get_elem_at_index(test_list, 0), &i1);
}

void test_get_num_elem(){
        list_add_tail(test_list, &i1);
        TEST_ASSERT_EQUAL_INT(list_get_num_elem(test_list), 1);
}

void test_iterator_get_elem(){
        list_add_tail(test_list, &i1);
        TEST_ASSERT_EQUAL(iterator_get_elem(test_iterator), &i1);
}

void test_iterator_is_valid(){
        list_add_tail(test_list, &i1);
        list_add_tail(test_list, &i2);
        list_add_tail(test_list, &i1);
        iterator_get_next(test_iterator);
        TEST_ASSERT_TRUE(iterator_is_valid(test_iterator));
}

void test_iterator_is_not_valid(){
        list_add_tail(test_list, &i2);
        iterator_get_next(test_iterator);
        TEST_ASSERT_FALSE(iterator_is_valid(test_iterator));
}

void test_iterator_get_next_elem(){
        list_add_tail(test_list, &i1);
        list_add_tail(test_list, &i2);
        iterator_get_next(test_iterator);
        TEST_ASSERT_EQUAL(&i2, (int*)iterator_get_elem(test_iterator));
}

int compare(void *first, void *second){
  if(first > second) return 1;
  return 0;
}

void test_list_merge(){
        list_add_tail(test_list, &i1);
        list_add_tail(test_list, &i2);

        list_add_tail(test_list2, &i1);
        list_add_tail(test_list2, &i3);


        List *new_list = list_merge(test_list, test_list2, compare);

        List *merged_list = list_new();
        list_add_tail(merged_list, &i1);
        list_add_tail(merged_list, &i2);
        list_add_tail(merged_list, &i3);

        TEST_ASSERT_EQUAL_INT(0, lists_is_not_equals(merged_list, new_list));
}

int main(){
        UNITY_BEGIN();
        RUN_TEST(test_empty_list);
        RUN_TEST(test_not_empty_list_insert_at_tail);
        RUN_TEST(test_empty_list_with_delete_in_tail);
        RUN_TEST(test_list_insert_at_index);
        RUN_TEST(test_get_elem_at_index);
        RUN_TEST(test_get_num_elem);
        RUN_TEST(test_iterator_get_elem);
        RUN_TEST(test_iterator_is_valid);
        RUN_TEST(test_iterator_is_not_valid);
        RUN_TEST(test_iterator_get_next_elem);
        RUN_TEST(test_list_merge);
        return UNITY_END();
}
