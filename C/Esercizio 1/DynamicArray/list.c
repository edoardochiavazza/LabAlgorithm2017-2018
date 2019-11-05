#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define INITIAL_CAPACITY 100

struct _List {
    void** array;
    long num_elem;
    long capacity_array;
};

struct _iterator{
        List* ptr;
        int index;
};

void list_expand (List* result);
void list_cut(List* result);
void list_shift_dx(List* shift_dx, int index);
int lists_is_not_equals(List*, List*);



List* list_new(){
        List* result = (List*) malloc(sizeof(List));
        assert(result != NULL);
        result -> array = (void**) malloc(sizeof(void*) * INITIAL_CAPACITY);
        assert( result != NULL);
        result -> num_elem = 0;
        result -> capacity_array = INITIAL_CAPACITY;
        return result;
}

iterator* iterator_new (List* to_iterator){
        iterator* list_iterator = (iterator*) malloc(sizeof(iterator));
        list_iterator -> index = 0;
        list_iterator -> ptr = to_iterator;
        return list_iterator;
}

void* iterator_get_elem(iterator* iterator){
        assert (iterator_is_valid(iterator));
        return iterator -> ptr -> array[iterator -> index];
}
void iterator_free(iterator *iterator){
        free(iterator);
}


void iterator_get_next(iterator* iterator){
        if(iterator_is_valid(iterator))
                iterator -> index++;
}

int iterator_is_valid(iterator* iterator){
        assert(iterator != NULL);
        return(iterator -> index < iterator -> ptr -> num_elem);
}
void list_expand (List* result){
        assert(result -> num_elem == result -> capacity_array );
        result -> array = (void**) realloc(result -> array, sizeof(void*) * (unsigned int) result -> num_elem * 2);
        result -> capacity_array = result -> capacity_array * 2;
}

void list_cut(List* result){
        if(result -> capacity_array / result -> num_elem ==  (1/4)){
                result -> array = (void**) realloc( result -> array, sizeof(void*) * (unsigned int) result -> num_elem / 2 );
                result -> capacity_array = result -> capacity_array / 2;
        }else
                printf("Impossibile tagliare l'array\n");

}

void list_free(List* to_deallocate){
        assert(to_deallocate != NULL);
        free(to_deallocate -> array);
        free(to_deallocate);

}

int list_is_empty(List* to_test){
        return (to_test -> num_elem == 0);
}

void list_add_tail(List* to_add, void* elem){
        assert(to_add != NULL && elem != NULL);
        if(to_add -> num_elem == to_add -> capacity_array)
                list_expand(to_add);
        to_add -> array[to_add -> num_elem] = elem;
        to_add -> num_elem++;
}

void list_add_at_index(List* to_add,int index, void* elem){
        assert(to_add != NULL && elem != NULL && index >= 0 && index < to_add->num_elem);
        list_shift_dx(to_add,index);
        to_add -> array[index] = elem;

}

void list_shift_dx(List* shift_dx, int index){
        assert(shift_dx != NULL && index >= 0 && index < shift_dx -> num_elem);
        if(shift_dx -> num_elem == shift_dx -> capacity_array)
                list_expand(shift_dx);
        for(int i = shift_dx -> num_elem - 1 ; i > index; i--)
                shift_dx -> array[i + 1] = shift_dx -> array[i];
}

int lists_is_not_equals(List* uno, List* due){
        for(int i = 0; i < uno -> num_elem && due -> num_elem; i++)
                for(int j = 0; j < uno -> num_elem && due -> num_elem; j++)
                        if(uno -> array[i] == due -> array[j])
                                return 0;
        return 1;
}

void list_delete_in_tail(List* result){
        assert(result != NULL);
        result -> num_elem--;
}

void list_delete_at_index(List* result, int index){
        assert(result != NULL);
        result -> array[index] = result -> array[result -> num_elem - 1];
        list_delete_in_tail(result);
}

void* list_get_elem_at_index(List* result, int index){
        assert(result != NULL && index >= 0 && index < result -> num_elem);
        return result -> array[index];
}

int list_get_num_elem(List* all){
        return all -> num_elem;
}
