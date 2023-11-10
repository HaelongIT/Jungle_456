#include "rbtree.h"

// 오른쪽으로 회전하는 함수
void right_rotate(rbtree *t, node_t *node)

// 기준 노드는 부모 자리로 대체되는 노드
{
    node_t *parent = node->parent;
    node_t *grand_parent = parent->parent;
    node_t *node_right = node->right;
    // 참조를 잃어버리지 않기 위해서 따로 포인터로 node의 right를 저장함
    // (회전하는 도중에 node의 right는 연결이 끊기기 때문에 참조하려면 반드시 따로 저장이 필요함)

    // 부모가 루트인 경우: 현재 노드를 루트로 지정 (노드를 삭제한 경우만 해당)
    if (parent == t->root)
        t->root = node;
    else
    { // 1-1) 노드의 부모를 grand_parent로 변경
        if (grand_parent->left == parent)
            grand_parent->left = node;
        else
            grand_parent->right = node;
    }
    node->parent = grand_parent; // 1-2) 노드를 grand_parent의 자식으로 변경 (양방향 연결)
    parent->parent = node;       // 2-1) parent의 부모를 노드로 변경
    node->right = parent;        // 2-2) parent를 노드의 자식으로 변경 (양방향 연결)
    node_right->parent = parent; // 3-1) 노드의 자식의 부모를 parent로 변경
    parent->left = node_right;   // 3-2) 노드의 자식을 부모의 자식으로 변경 (양방향 연결)
}

// 왼쪽으로 회전하는 함수
void left_rotate(rbtree *t, node_t *node)
{
    node_t *parent = node->parent;
    node_t *grand_parent = parent->parent;
    node_t *node_left = node->left;

    // 부모가 루트인 경우: 현재 노드를 루트로 지정 (노드를 삭제한 경우만 해당)
    if (parent == t->root)
        t->root = node;
    else
    { // 1-1) 노드의 부모를 grand_parent로 변경
        if (grand_parent->left == parent)
            grand_parent->left = node;
        else
            grand_parent->right = node;
    }
    node->parent = grand_parent; // 1-2) 노드를 grand_parent의 자식으로 변경 (양방향 연결)
    parent->parent = node;       // 2-1) parent의 부모를 노드로 변경
    node->left = parent;         // 2-2) parent를 노드의 자식으로 변경 (양방향 연결)
    parent->right = node_left;   // 3-1) 노드의 자식의 부모를 parent로 변경
    node_left->parent = parent;  // 3-2) 노드의 자식을 부모의 자식으로 변경 (양방향 연결)
}