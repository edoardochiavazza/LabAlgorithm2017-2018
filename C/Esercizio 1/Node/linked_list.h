#pragma once

typedef struct _Node Node;

typedef struct _List List;

typedef struct _Iterator iterator;


/**
 * Make new empty double linked List .
 * The pointers's types are void.
 * Parameters:
 * num_node -> is the number of the elements.
 * head -> pointer to the first node of the list
 * tail ->  pointer to the last element of the list
 **/
 List* list_new();

/**************************************************************************************/
/**
 * Make new node for the linked list
 * Parameters:
 * data -> store the void elem
 * next -> pointer to the next node of the list
 * previous -> pointer to the previous node of the list
 **/
 Node* node_new(void*);

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
 *
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
 *
**/
 void list_delete_in_tail(List*);

/**************************************************************************************/
/**
 * Method remove the access to the last  element
 * the last number will be the element choose to be elemined
 * instead the old last element will be copy
 * in the choose position and
 * num_node is reduces by one
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
 int list_get_num_elem(List*);

/**************************************************************************************/
/**
 * Make a iterator for the list. It is only forward iterator.
 * iterator start to the first element of list
 * Parameter:
 * current -> double pointer to the head of the list
 **/
 iterator* iterator_new();

/**************************************************************************************/
 /**
 * Method return the element wich is point from the iterator
 **/
 void *iterator_get_elem(iterator* iterator);

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
 * Frees the memory alloced to store iterator.
 * Memory used by Iterator is to be dealloced by the user.
 */
 void iterator_free(iterator*);

/**************************************************************************************/
/**
* Method check if the two lists are different.
**/
int lists_is_not_equals(List*, List*);

 /**************************************************************************************/
