#include "rbtree.h"

void left_rotation(rbtree *t, node_t *x)
{
    node_t *y = x->right;
    // y에 x의 오른쪽 노드 주소 초기화(x의 오른쪽이 y임)

    x->right = y->left; // x 오른쪽 자식에 y->left 달아
    // x의 오른쪽에 y의 왼쪽 주소값 담기(y의 왼쪽 자식은 x의 오른쪽 자식이 된다)

    if (y->left != t->nil)
    // y의 left가 nil이 아니라면
    {
        y->left->parent = x;
        // y의 왼쪽 노드의 부모는 x이다
    }
    y->parent = x->parent;
    // y의 부모는 x의 부모와 같다

    if (x->parent == t->nil)
    {                // x가 루트 노드이면 (루트 노드의 부모는 t->nil)
        t->root = y; // 이제 y가 루트 노드가 되어야 함
    }
    else if (x == x->parent->left)
    { // x가 왼쪽 자식 노드이면
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y; // x가 오른쪽 자식 노드
    }
    y->left = x;
    x->parent = y;
}

// right_rotation은 위에서 left를 right으로 바꾸기만 하면 끝