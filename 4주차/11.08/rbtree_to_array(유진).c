#include "rbtree.h"

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
{
    // TODO: implement to_array
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    node = t->root;
    int c = 0;
    int *count = &c;
    inorder_traverse(t, arr, node, count);

    return 0;
}