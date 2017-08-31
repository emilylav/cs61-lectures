#include "ilist.h"

void qs(ilist* list) {
    if (!list->head) {
        return;
    }

    int pivot = list->head->i;

    ilist left;
    ilist_initialize(&left);
    for (ielt* x = list->head->next; x; x = x->next) {
        if (x->i < pivot) {
            ilist_push(&left, ielt_new(x->i));
        }
    }

    ilist right;
    ilist_initialize(&right);
    for (ielt* x = list->head->next; x; x = x->next) {
        if (x->i >= pivot) {
            ilist_push(&right, ielt_new(x->i));
        }
    }

    qs(&left);
    qs(&right);

    ilist_free(list);

    ilist_append(list, &left);
    ilist_push(list, ielt_new(pivot));
    ilist_append(list, &right);
}
