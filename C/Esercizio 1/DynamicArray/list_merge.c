#include "list_merge.h"

/**
 * ...
 *
 */
List *list_merge(List *first, List *second, int (*compare)(void *, void *)) {
  List *new_list = list_new();
  int x = 0, y = 0;
  int flist_size = list_get_num_elem(first);
  int slist_size = list_get_num_elem(second);
  void *felem, *selem;

  while(x < flist_size && y < slist_size) {
    felem = list_get_elem_at_index(first, x);
    selem = list_get_elem_at_index(second, y);

    if(compare(felem, selem)){
      list_add_tail(new_list, felem);
      x++;
    }else{
      list_add_tail(new_list, selem);
      y++;
    }
  }

  while(x < flist_size){
    felem = list_get_elem_at_index(first, x);
    list_add_tail(new_list, felem);
    x++;
  }

  while(y < slist_size){
    selem = list_get_elem_at_index(second, y);
    list_add_tail(new_list, selem);
    y++;
  }
  return new_list;
}
