#include "rbtree.h"

/* 5️⃣ array로 변환 */

// `t`를 inorder로 `n`번 순회한 결과를 `arr`에 담는 함수
int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
// size_t는 부호 없는 정수 자료형임
{
    node_t *current = rbtree_min(t);
    arr[0] = current->key;
    for (int i = 1; i < n; i++)
    {
        if (current == t->nil)
            break;                           // 노드가 끝까지 탐색된 경우 loop 탈출
        current = get_next_node(t, current); // 다음 노드로 이동
        if (current == t->nil)
            break;             // 노드가 끝까지 탐색된 경우 loop 탈출
        arr[i] = current->key; // 현재 노드의 key 값을 배열에 저장
    }
    return 0;
}