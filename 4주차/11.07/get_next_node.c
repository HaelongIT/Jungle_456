#include "rbtree.h"

// 키 값을 기준으로 다음 노드를 반환하는 함수
node_t *get_next_node(const rbtree *t, node_t *p)
{
    node_t *current = p->right;

    // 여기서부터는 솔직히 잘 이해가 안감(알고보니 rbtree_to_array 부분에서도 쓰이는데 그걸 위한 부분인듯)
    // (함수가 한가지 역할로만 쓰는게 아니고 아예 다른 역할 2가지를 부여 받아서 이질적인 2가지 역할을 모두한다)
    if (current == t->nil) // 오른쪽 자식이 없으면
    // p의 오른쪽으로 내려갔는데 nil이면
    {
        current = p;
        // 다시 p로 올라감
        while (1)
        {
            if (current->parent->right == current) // current(p)가 오른쪽 자식인 경우
                current = current->parent;         // 부모 노드로 이동 후 이어서 탐색
            else
                return current->parent; // current가 왼쪽 자식인 경우 부모 리턴
        }
    }
    // 여기까지는 이해가 잘 안감

    while (current->left != t->nil) // 왼쪽 자식이 없을 때까지 반복
        current = current->left;    // 왼쪽 끝으로 이동
    return current;
}