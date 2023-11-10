#include "rbtree.h"

/* 4️⃣ 탐색 1 - key 탐색 */

// key에 해당하는 노드를 반환하는 함수
node_t *rbtree_find(const rbtree *t, const key_t key)
// const로 상수임을 나타내면 함수에서 내가 실수로 매개변수를 변경하는 실수를 줄일 수 있음
// 또한 읽는 사람에게도 해당 매개변수는 읽기전용으로만 쓰임을 알려줘서 가독성 측면에서도 좋음
{
  node_t *current = t->root;
  while (current != t->nil)
  {
    if (key == current->key)
      return current;
    else
      current = (key < current->key) ? current->left : current->right;
  }
  return NULL; // 해당 key값을 가진 노드가 없을 경우 NULL 반환
}