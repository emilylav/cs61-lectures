#include "ilist.h"

void qs(ilist* list) {
    if (!list->head) {
        return;
    }

    int pivot = list->head->i;

    ilist left, right;
    ilist_initialize(&left);
    ilist_initialize(&right);
    for (ielt* x = list->head->next; x; x = x->next) {
        if (x->i < pivot) {
            ilist_push(&left, ielt_new(x->i));
        } else {
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
