#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int number;
    char title[100];
};

void showBook(struct Book *p, int n)
{
    // n : 총 책의 갯수

    int i;

    for (i = 0; i < n; i++)
    {
        printf("번호 %d : %s\n", (p + i)->number, (p + i)->title);
    }
}

int main(void)
{
    // 구조체 동적 메모리 할당

    struct Book *p;
    p = (struct Book *)malloc(2 * sizeof(struct Book));
    // 구조체 변수 두개가 들어갈 크기의 메모리를 할당
    // (마치 배열처럼 두개가 연속으로 들어올 수 있게 공간을 할당함)

    if (p == NULL)
    {
        printf("동적 메모리 할당에 실패했습니다.\n");
        exit(1);
    }

    p->number = 1;
    strcpy(p->title, "C Programming");
    // strcpy(s2, s1) : s1의 문자열을 s2로 복사

    (p + 1)->number = 2;
    strcpy((p + 1)->title, "Data Structure");

    showBook(p, 2);
    free(p);

    return 0;
}