#include "rbtree.h"

/* 4️⃣ 탐색 3 - 최대값을 가진 node 탐색 */

// key가 최대값에 해당하는 노드를 반환하는 함수
node_t *rbtree_max(const rbtree *t)
{
    node_t *current = t->root;
    while (current->right != t->nil)
        current = current->right;
    return current;
}