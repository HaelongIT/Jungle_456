#include "rbtree.h"

/* 2️⃣ RB tree 구조체가 차지했던 메모리 반환 */

// 트리를 순회하면서 각 노드의 메모리를 반환하는 함수
void delete_rbtree(rbtree *t)
// rbtree의 모든 노드를 삭제하는 함수
{
    node_t *node = t->root;
    // node에 rb트리의 루트 주소 삽입

    if (node != t->nil)
        // t라는 rb트리가 비어있지 않은 경우

        traverse_and_delete_node(t, node);
    // 삭제할 rb트리와 루트노드 매개변수로 준다

    // nil 노드와 rbtree 구조체의 메모리를 반환

    free(t->nil);
    free(t);
}

// 각 노드와 그 자식 노드들의 메모리를 반환하는 함수
void traverse_and_delete_node(rbtree *t, node_t *node)
{
    if (node->left != t->nil)
        traverse_and_delete_node(t, node->left);
    if (node->right != t->nil)
        traverse_and_delete_node(t, node->right);

    // 현재 노드의 메모리를 반환
    free(node);
}