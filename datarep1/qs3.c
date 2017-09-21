#include "ilist.h"

void qs(ilist* list) {
    if (!list->head) {
        return;
    }

    int pivot = list->head->i;

    ilist left, right;
    ilist_initialize(&left);
    ilist_initialize(&right);
    ielt* x = list->head->next;
    while (x) {
        ielt* next = x->next;
        x->next = NULL;
        if (x->i < pivot) {
            ilist_push(&left, x);
        } else {
            ilist_push(&right, x);
        }
        x = next;
    }

    qs(&left);
    qs(&right);

    ielt* middle = list->head;
    middle->next = NULL;
    ilist_push(&left, middle);
    ilist_append(&left, &right);
    *list = left;
}
