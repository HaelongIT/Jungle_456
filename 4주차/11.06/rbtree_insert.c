#include "rbtree.h"

/* 3️⃣ key 추가 */

// 노드를 삽입하고 불균형을 복구하는 함수
node_t *rbtree_insert(rbtree *t, const key_t key)
// rbtree를 포인터로 받는 이유는 call by value 때문임
{
    // 새 노드 생성
    node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
    new_node->key = key;
    new_node->color = RBTREE_RED;              // 항상 레드로 추가
    new_node->left = new_node->right = t->nil; // 추가한 노드의 자식들을 nil 노드로 설정

    // 새 노드를 삽입할 위치 탐색
    node_t *current = t->root;
    while (current != t->nil)
    {
        if (key < current->key)
        {
            if (current->left == t->nil)
            {
                current->left = new_node; // 새 노드를 왼쪽 자식으로 추가
                break;
            }
            current = current->left;
        }
        else
        {
            if (current->right == t->nil)
            {
                current->right = new_node; // 새 노드를 오른쪽 자식으로 추가
                break;
            }
            current = current->right;
        }
    }

    new_node->parent = current; // 새 노드의 부모 지정

    // root가 nil이면(트리가 비어있으면) 새 노드를 트리의 루트로 지정
    if (current == t->nil)
        t->root = new_node;

    // 불균형 복구
    rbtree_insert_fixup(t, new_node);

    return new_node;
    // 삽입한 노드의 포인터를 반환해서 나중에
    // 해당 노드를 참조할 수 있게 하기 위해서
}

// 노드 삽입 후 불균형을 복구하는 함수
void rbtree_insert_fixup(rbtree *t, node_t *node)
{
    node_t *parent = node->parent;
    node_t *grand_parent = parent->parent;
    node_t *uncle;
    int is_left = node == parent->left; // 현재 노드가 왼쪽 자식인지 여부
    int is_parent_is_left;              // 부모가 왼쪽 자식인지 여부

    // 추가된 노드가 root 노드인 경우: 색만 변경
    if (node == t->root)
    {
        node->color = RBTREE_BLACK;
        return;
    }

    // 부모가 BLACK인 경우: 변경 없음
    if (parent->color == RBTREE_BLACK)
        return;

    is_parent_is_left = grand_parent->left == parent;
    uncle = (is_parent_is_left) ? grand_parent->right : grand_parent->left;
    // is_parent_is_left 가 True면 grand_parent->right, False면 grand_parent->left

    // [CASE 1]: 부모와 부모의 형제가 모두 RED인 경우
    if (uncle->color == RBTREE_RED)
    {
        parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        grand_parent->color = RBTREE_RED;
        rbtree_insert_fixup(t, grand_parent);
        return;
    }

    if (is_parent_is_left)
    {
        if (is_left)
        // [CASE 2]: 부모의 형제가 BLACK & 부모가 왼쪽 자식 & 현재 노드가 왼쪽 자식인 경우
        {
            right_rotate(t, parent);
            exchange_color(parent, parent->right);
            return;
        }

        // [CASE 3]: 부모의 형제가 BLACK & 부모가 왼쪽 자식 & 현재 노드가 오른쪽 자식인 경우
        left_rotate(t, node);
        right_rotate(t, node);
        exchange_color(node, node->right);
        return;
    }

    if (is_left)
    {
        // [CASE 3]: 부모의 형제가 BLACK & 부모가 오른쪽 자식 & 현재 노드가 왼쪽 자식인 경우
        right_rotate(t, node);
        left_rotate(t, node);
        exchange_color(node, node->left);
        return;
    }

    // [CASE 2]: 부모의 형제가 BLACK & 부모가 오른쪽 자식 & 현재 노드가 오른쪽 자식인 경우
    left_rotate(t, parent);
    exchange_color(parent, parent->left);
}