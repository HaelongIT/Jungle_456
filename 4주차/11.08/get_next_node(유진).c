#include "rbtree.h"

// 키 값을 기준으로 다음 노드를 반환하는 함수
node_t *get_next_node(const rbtree *t, node_t *p)
{
    node_t *current = p->right;

    while (current->left != t->nil) // 왼쪽 자식이 없을 때까지 반복
        current = current->left;    // 왼쪽 끝으로 이동
    return current;
}