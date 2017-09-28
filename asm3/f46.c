//! -O1
struct ll {
    int x;
    struct ll* next;
};

int second_plus_third(struct ll* l) {
    return l->next->x + l->next->next->x;
}
