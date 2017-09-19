#include "gc61.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/resource.h>

typedef struct node {
    unsigned width;
    unsigned height;
    unsigned round;
    struct node* child[];
} node;

static node* tree_build(unsigned width, unsigned height, unsigned round) {
    if (height == 0)
        return NULL;
    else {
        node* n = (node*) m61_malloc(sizeof(node) + width * sizeof(node*));
        n->width = width;
        n->height = height;
        n->round = round;
        for (unsigned i = 0; i < width; ++i) {
            n->child[i] = tree_build(width, height - 1, round);
        }
        return n;
    }
}

static void tree_free(node* n, unsigned round) {
    if (n) {
        assert(n->round == round);
        for (unsigned i = 0; i < n->width; ++i) {
            assert(!n->child[i] || n->child[i]->height == n->height - 1);
            tree_free(n->child[i], round);
        }
        // m61_free(n);
    }
}

static void test(unsigned width, unsigned height, unsigned nrounds) {
    node* t0 = tree_build(width, height, -1);

    for (unsigned i = 0; i < nrounds; ++i) {
        if (i % 10 == 9 && i != 0) {
            fprintf(stderr, "Round %u/%u\n", i + 1, nrounds);
        }
        node* t = tree_build(width, height, i);
        tree_free(t, i);
    }

    m61_print_allocations(stdout);
    tree_free(t0, -1);
}

int main(int argc, char** argv) {
    stack_bottom = (char*) &argc;
    unsigned width = 16;
    unsigned height = 4;
    unsigned nrounds = 30;

    struct rlimit rlim;
    getrlimit(RLIMIT_AS, &rlim);
    rlim.rlim_cur = 10000000;
    setrlimit(RLIMIT_AS, &rlim);

    int opt;
    while ((opt = getopt(argc, argv, "w:h:n:")) != -1) {
        switch (opt) {
        case 'w':
            width = strtoul(optarg, NULL, 0);
            break;
        case 'h':
            height = strtoul(optarg, NULL, 0);
            break;
        case 'n':
            nrounds = strtoul(optarg, NULL, 0);
            break;
        default:
            fprintf(stderr, "Usage: ./testgc [-w WIDTH] [-h HEIGHT] [-n NROUNDS]\n");
            exit(1);
        }
    }

    test(width, height, nrounds);
}
