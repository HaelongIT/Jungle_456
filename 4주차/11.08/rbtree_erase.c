#include "rbtree.h"

/* 6️⃣ node 삭제 */

// 노드를 삭제하는 함수
int rbtree_erase(rbtree *t, node_t *delete)
{
    node_t *remove; // 트리에서 없어질 노드
    node_t *remove_parent, *replace_node;
    int is_remove_black, is_remove_left;

    // Step 1) delete 삭제 후 대체할 replace_node 찾기
    // Step 1-1) delete 노드의 자식이 둘인 경우: delete의 키를 후계자 노드의 키값으로 대체, 노드의 색은 delete의 색 유지
    if (delete->left != t->nil && delete->right != t->nil)
    {
        remove = get_next_node(t, delete); // 후계자 노드 (오른쪽 서브트리에서 가장 작은 노드)
        replace_node = remove->right;      // 대체할 노드: 지워질 노드인 후계자는 항상 왼쪽 자식이 없기 때문에, 자식이 있다면 오른쪽 자식 하나뿐임
        delete->key = remove->key;         // delete의 키를 후계자 노드의 키값으로 대체 (색은 변경 X)
    }
    else
    { // Step 1-2) delete 노드의 자식이 없거나 하나인 경우: delete 노드를 자식으로 대체, 노드의 색도 대체되는 노드의 색으로 변경
        remove = delete;
        // 대체할 노드: 자식이 있으면 자식노드로, 없으면 nil 노드로 대체
        replace_node = (remove->right != t->nil) ? remove->right : remove->left;
    }
    remove_parent = remove->parent;

    // Step 2) remove 노드 제거하기
    /* [CASE D1]: remove 노드가 루트인 경우 */
    if (remove == t->root)
    {
        t->root = replace_node;        // 대체할 노드를 트리의 루트로 지정
        t->root->color = RBTREE_BLACK; // 루트 노드는 항상 BLACK
        free(remove);
        return 0; // 불균형 복구 함수 호출 불필요 (제거 전 트리에 노드가 하나 혹은 두개이므로 불균형이 발생하지 않음)
    }

    // Step 2-1) 'remove의 부모'와 'remove의 자식' 이어주기
    is_remove_black = remove->color; // remove 노드 제거 전에 지워진 노드의 색 저장
    is_remove_left = remove_parent->left == remove;

    // Step 2-1-1) 자식 연결
    if (is_remove_left) // remove가 왼쪽 자식이었을 경우: remove 부모의 왼쪽에 이어주기
        remove_parent->left = replace_node;
    else // remove가 오른쪽 자식이었을 경우: remove 부모의 오른쪽에 이어주기
        remove_parent->right = replace_node;

    // Step 2-1-2) 부모도 연결 (양방향 연결)
    replace_node->parent = remove_parent;
    free(remove);

    /* [CASE D2~D6]: remove 노드가 검정 노드인 경우 */
    // Step 3) 불균형 복구 함수 호출
    if (is_remove_black)
        rbtree_erase_fixup(t, remove_parent, is_remove_left);
    return 0;
}

// 노드 삭제 후 불균형을 복구하는 함수
// `parent`: extra_black이 부여된 노드의 부모
// `is_left`: extra_black이 부여된 노드가 왼쪽 자식인지 여부
void rbtree_erase_fixup(rbtree *t, node_t *parent, int is_left)
{
    // 삭제 후 대체한 노드가 RED (Red & Black): BLACK으로 변경
    node_t *extra_black = is_left ? parent->left : parent->right;
    if (extra_black->color == RBTREE_RED)
    {
        extra_black->color = RBTREE_BLACK;
        return;
    }

    node_t *sibling = is_left ? parent->right : parent->left;
    node_t *sibling_left = sibling->left;
    node_t *sibling_right = sibling->right;

    if (sibling->color == RBTREE_RED)
    { // [CASE D3] 형제가 RED
        if (is_left)
            left_rotate(t, sibling);
        else
            right_rotate(t, sibling);
        exchange_color(sibling, parent);
        rbtree_erase_fixup(t, parent, is_left);
        return;
    }

    node_t *near = is_left ? sibling_left : sibling_right;    // 형제의 자식 중 extra_black으로부터 가까운 노드
    node_t *distant = is_left ? sibling_right : sibling_left; // 형제의 자식 중 extra_black으로부터 먼 노드

    if (is_left && near->color == RBTREE_RED && distant->color == RBTREE_BLACK)
    { // [CASE D4] 형제가 BLACK, 형제의 가까운 자식이 RED, 형제의 더 먼 자식이 BLACK
        right_rotate(t, near);
        exchange_color(sibling, near);
        rbtree_erase_fixup(t, parent, is_left);
        return;
    }

    if (is_left && distant->color == RBTREE_RED)
    { // [CASE D5] 형제가 BLACK, 형제의 더 먼 자식이 RED
        left_rotate(t, sibling);
        exchange_color(sibling, parent);
        distant->color = RBTREE_BLACK;
        return;
    }

    if (near->color == RBTREE_RED && distant->color == RBTREE_BLACK)
    { // [CASE D4] 형제가 BLACK, 형제의 가까운 자식이 RED, 형제의 더 먼 자식이 BLACK
        left_rotate(t, near);
        exchange_color(sibling, near);
        rbtree_erase_fixup(t, parent, is_left);
        return;
    }

    if (distant->color == RBTREE_RED)
    { // [CASE D5] 형제가 BLACK, 형제의 더 먼 자식이 RED
        right_rotate(t, sibling);
        exchange_color(sibling, parent);
        distant->color = RBTREE_BLACK;
        return;
    }

    // [CASE D2] 형제가 BLACK, 형제의 자식이 둘 다 BLACK
    sibling->color = RBTREE_RED;

    if (parent != t->root)
        rbtree_erase_fixup(t, parent->parent, parent->parent->left == parent);
}