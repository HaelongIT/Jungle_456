#include "rbtree.h"

// 새 트리를 생성하는 함수
rbtree *new_rbtree(void)
{
    // tree 구조체 동적 할당
    rbtree *t = (rbtree *)calloc(1, sizeof(rbtree));
    // rbtree가 들어갈 공간을 만들어서 포인터로 저장

    // nil 노드 생성 및 초기화
    node_t *nil = (node_t *)calloc(1, sizeof(node_t));
    // rbtree 내에 있던 변수 nil을 초기화

    nil->color = RBTREE_BLACK; // nil 노드는 항상 BLACK

    // tree의 nil과 root를 nil 노드로 설정 (tree가 빈 경우 root는 nil노드여야 한다.)
    t->nil = t->root = nil;

    return t;
}

// tree 구조체 동적 할당
// nil 노드 생성 및 초기화
//