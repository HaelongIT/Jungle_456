#ifndef _RBTREE_H_
#define _RBTREE_H_
// 다른 파일에서 해당 헤더파일이 중복되는 것을 막기 위한 구조

#include <stddef.h>

typedef enum
{
    RBTREE_RED,
    RBTREE_BLACK
} color_t;
// 열거형을 이용해서 0과 1을 정의

typedef int key_t;
// int형의 별명을 key_t로 정의

typedef struct node_t
{
    color_t color;
    // color는 0 아니면 1
    key_t key;
    // key는 int형
    struct node_t *parent, *left, *right;
    // 구조체 내 구조체 포인터변수 선언 3가지
} node_t;

typedef struct
{
    node_t *root;
    // 구조체 내 포인터변수
    node_t *nil; // for sentinel
    // 구조체내 포인터변수
} rbtree;

rbtree *new_rbtree(void);
// 함수명 앞의 *는 포인터변수를 반환한다는 뜻(rbtree는 데이터형식을 의미) -> rbtree형식의 포인터변수를 반환한다
void delete_rbtree(rbtree *);
// 매개변수로 rbtree형의 포인터변수를 입력받음(매개변수명은 생략)

node_t *rbtree_insert(rbtree *, const key_t);
node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif // _RBTREE_H_
