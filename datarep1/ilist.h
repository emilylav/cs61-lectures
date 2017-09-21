#include <stdlib.h>
#include <assert.h>

struct ielt {
    int i;
    struct ielt* next;
};
typedef struct ielt ielt;

struct ilist {
    ielt* head;
    ielt* tail;
};
typedef struct ilist ilist;

static inline ielt* ielt_new(int i) {
    ielt* x = (ielt*) malloc(sizeof(ielt));
    x->i = i;
    x->next = NULL;
    return x;
}

static inline void ilist_initialize(ilist* list) {
    list->head = list->tail = NULL;
}

static inline void ilist_push(ilist* list, ielt* x) {
    assert(x->next == NULL);
    if (list->tail) {
        list->tail->next = x;
    } else {
        list->head = x;
    }
    list->tail = x;
}

static inline void ilist_append(ilist* list1, ilist* list2) {
    if (list1->tail) {
        list1->tail->next = list2->head;
    } else {
        list1->head = list2->head;
    }
    if (list2->tail) {
        list1->tail = list2->tail;
    }
}

static inline void ilist_free(ilist* list) {
    while (list->head) {
        ielt* next = list->head->next;
        free(list->head);
        list->head = next;
    }
    list->tail = NULL;
}
