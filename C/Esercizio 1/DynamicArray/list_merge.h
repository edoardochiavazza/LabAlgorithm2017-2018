#pragma once
#include "list.h"

List *list_merge(List *first, List *second, int (*compare)(void *, void *));
