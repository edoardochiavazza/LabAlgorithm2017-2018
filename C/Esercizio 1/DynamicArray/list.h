#pragma once

typedef struct _List List;

typedef struct _iterator iterator;


/**
 * Make new empty List. It have a pointer to an array of pointers
 * wich have initial size of 100.
 * The pointers's types are void.
 * Parameters:
 * num_elem -> is the number of the elements.
 * capacity_array -> is the max number of the elements wich dinamic array can hold.
 * array -> is the dinamic array wich contains the elements
 **/

 List* list_new();

/**************************************************************************************/
/**
 * Frees the memory alloced to store List.
 * Memory used by elements of the array are to be dealloced by the user.
 */
 void list_free(List *);
/**************************************************************************************/
/**
 * Method check if list is empty
 * It check if num_elem is equal to zero.
**/
 int list_is_empty(List*);

/**************************************************************************************/
/**
 * Method add a void elem in the first not occupied array's box
 * It use num_elem + 1 for the index of array's box
**/
 void list_add_tail(List*,void*);

/**************************************************************************************/
/**
 * Method add a void elem in the choose index of the array's box
 * if the box is occupied, the old element
 * and the following elements will shift to right
**/
 void list_add_at_index(List*,int, void*);

/**************************************************************************************/
/**
 * Method remove the access to the last element
 * num_elem is reduces by one
**/
 void list_delete_in_tail(List*);

/**************************************************************************************/
/**
 * Method remove the access to the last  element
 * the last number will be the element choose to be elemined
 * instead the old last element will be copy
 * in the choose position and
 * num_elem is reduces by one
 **/
 void list_delete_at_index(List*, int);

/**************************************************************************************/
 /**
  * Method return the element wich occuped the choose position
  **/
 void* list_get_elem_at_index(List*, int);

/**************************************************************************************/
 /**
  * Method return num_elem wich is one of the parameters of the list
  **/
 int list_get_num_elem(List* all);

/**************************************************************************************/
/**
 * Make a iterator for the list. It is only forward iterator.
 * iterator start to the first element of list
 * Parameter:
 * index -> is inizialized to zero.
 * ptr -> pointer to the list.
 **/
 iterator* iterator_new();

/**************************************************************************************/
 /**
 * Method return the element wich is point from the iterator
 **/
 void* iterator_get_elem(iterator*);

/**************************************************************************************/
 /**
 * Method incrementing the the iterator. So it point the next element of the list.
 * Method incrementing index increase to one
 **/
 void iterator_get_next(iterator*);

/**************************************************************************************/
/**
* Method check if iterator is still valid.
**/
 int iterator_is_valid(iterator*);

/**************************************************************************************/
/**
* Method check if the two lists are different.
**/
 int lists_is_not_equals(List*, List*);

/**
 * Frees the memory alloced to store iterator.
 * Memory used by Iterator is to be dealloced by the user.
 */
 void iterator_free(iterator*);
/**************************************************************************************/
