#include "rbtree.h"

/* 4️⃣ 탐색 2 - 최소값을 가진 node 탐색 */

// key가 최소값에 해당하는 노드를 반환하는 함수
node_t *rbtree_min(const rbtree *t)
{
    node_t *current = t->root;
    while (current->left != t->nil)
        current = current->left;
    return current;
}