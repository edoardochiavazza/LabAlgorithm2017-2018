#pragma once
#include "linked_list.h"

List *list_merge(List *first, List *second, int (*compare)(void *, void *));
