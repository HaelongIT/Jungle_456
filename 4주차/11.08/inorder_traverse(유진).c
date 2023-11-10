#include "rbtree.h"

// 주희씨 코드에서는 get_next_node에 후계자 찾기랑 중위순회가 섞여있었는데 유진님은 분리했음
void inorder_traverse(const rbtree *t, key_t *arr, node_t *node, int *count)
{
    if (node == NULL || node == t->nil)
        return;
    inorder_traverse(t, arr, node->left, count);
    arr[(*count)++] = node->key;
    // printf("key: %d, color: %s\n",node->key,(node->color==RBTREE_RED) ? "RED" : "BLACK");
    inorder_traverse(t, arr, node->right, count);
}