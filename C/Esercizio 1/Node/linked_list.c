#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

struct _Node {
        void* data;
        Node *next;
        Node *previous;
};

struct _List{
        int num_node;
        Node *head;
        Node *tail;

};

struct _Iterator{
        Node** current;
};

List* list_new(){
        List* new = (List*) malloc(sizeof(List));
        assert(new != NULL);
        new -> num_node = 0;
        new -> head = NULL;
        new -> tail = NULL;
        return new;
}

Node* node_new(void* elem){
        Node* new = (Node*) malloc (sizeof(Node));
        assert(new != NULL);
        new -> data = elem;
        new -> next = NULL;
        new -> previous = NULL;
        return new;
}

iterator* iterator_new(List *to_iterator){
        iterator *iteratore = (iterator *) malloc (sizeof(iterator));
        iteratore -> current = &(to_iterator -> head);
        return iteratore;
}

void iterator_free(iterator* iterator){
        free(iterator);
}

int list_is_empty(List* to_check){
        return to_check -> num_node == 0;
}

int lists_is_not_equals(List* uno, List* due){
        Node* uno_test = uno -> head;
        Node* due_test = due -> head;
        if(uno -> num_node != due -> num_node)
                return 0;
        while(uno_test == NULL || due_test == NULL){
                if(uno_test -> data != due_test -> data)
                        return 0;
                uno_test = uno_test -> next;
                due_test = due_test -> next;
        }
        return 1;

}

void list_add_tail(List* to_add, void* elem){
        Node* new = node_new(elem);
        if(to_add -> head == NULL){
                to_add -> head = new;
                to_add -> tail = new;
        }else{
                Node * ptr = to_add -> tail;
                ptr -> next = new;
                new -> previous = ptr;
                to_add -> tail = new;

        }
        to_add -> num_node++;
}

void list_add_head(List *to_add, void* elem){
        assert(to_add != NULL);
        Node *new = node_new(elem);
        Node *ptr = to_add -> head;
        if(to_add -> head != NULL){
                to_add -> head = new;
                ptr -> previous = new;
                new -> next = ptr;
                ptr -> next = NULL;
        }
        to_add -> num_node++;
}

void list_add_at_index(List *to_add,int index, void* elem){
        assert(index <= to_add -> num_node && to_add != NULL);
        if(index == 0)
                list_add_head(to_add, elem);
        else if(index == to_add -> num_node + 1)
                list_add_tail(to_add, elem);
        else{
                Node *new = node_new(elem);
                Node *ptr = to_add -> head;
                while(index > 0){
                        ptr = ptr -> next;
                        index--;
                }
                Node *previous = ptr -> previous;
                new -> previous = previous;
                new -> next = ptr;
                ptr -> previous = new;
                previous -> next = new;
                to_add -> num_node++;
        }
}


void list_free(List* to_deallocate){
        assert(to_deallocate != NULL);
        Node* curr = to_deallocate -> head;
        Node* tmp;

        while(curr != NULL) {
                tmp = curr;
                curr = curr -> next;
                free(tmp);
        }

        free(to_deallocate);
}

void list_delete_in_head(List* to_delete){
        Node *prev = to_delete -> head;
        Node *ptr =  prev -> next;
        if(ptr == NULL){
                to_delete -> head =  NULL;
                to_delete -> tail = NULL;
        }else{
                ptr -> previous = NULL;
                to_delete -> head = ptr;
                ptr = NULL;
        }
        to_delete -> num_node--;
}

void list_delete_in_tail(List* to_delete){
        assert(to_delete != NULL);
        if(to_delete -> num_node == 1)
                list_delete_in_head(to_delete);
        else{
                Node *prev = to_delete -> tail;
                Node *ptr = prev -> previous;
                ptr -> next = NULL;
                to_delete -> tail = ptr;
                to_delete -> num_node--;
                ptr = NULL;
        }
}


void list_delete_at_index(List* to_delete, int index){
        assert(to_delete -> num_node > index);
        Node *ptr = to_delete -> tail;
        if(index == 0)
                list_delete_in_head(to_delete);
        else if(index == to_delete -> num_node - 1)
                list_delete_in_tail(to_delete);
        for(;index >= 0; index --){
                ptr = ptr -> previous;
        }
        Node *prev = ptr -> previous;
        prev -> next = ptr -> next;
        prev = ptr;
        ptr = ptr -> next;
        ptr -> previous = prev -> previous;
        ptr = NULL;
        prev = NULL;
        free(ptr);
        free(prev);
        to_delete -> num_node--;
}


void* list_get_elem_at_index(List* to_get, int index){
        Node *ptr = to_get -> tail;
        while(index > 0){
                ptr = ptr -> previous;
                index--;
        }
        return ptr -> data;
}

int list_get_num_elem(List* to_get){
        return to_get -> num_node;

}

void* iterator_get_elem(iterator* iterator){
        assert (iterator_is_valid(iterator));
        return (*iterator -> current) -> data;
}

void iterator_get_next(iterator* iterator){
        assert(iterator_is_valid(iterator));
        iterator -> current = &((*iterator -> current) -> next);
}

int iterator_is_valid(iterator* iterator){
        if((*iterator -> current) != NULL)
                return 1;
        else
                return 0;
}
