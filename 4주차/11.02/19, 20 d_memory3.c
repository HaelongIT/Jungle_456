#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 동적 메모리로 정수 5개를 처리해보기

    int *pi, i;
    pi = (int *)malloc(5 * sizeof(int));
    // int형 5개가 들어갈 수 있는 메모리공간을 할당받아서 시작주소를 반환함

    if (pi == NULL)
    {
        printf("동적 메모리 할당에 실패했습니다.\n");
        exit(1);
    }

    pi[0] = 100;
    // pi(포인터변수)가 '(int *)malloc(5 * sizeof(int))'에게서 받은 시작주소가 pi[0]이자 *(pi + 0)
    // 배열의 인덱싱과 포인터를 이용한 주소 이동과 밀접한 관계가 있음

    pi[1] = 200;
    pi[2] = 300;
    pi[3] = 400;
    pi[4] = 500;

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(pi + i));
        // p[1] = *(pi + 1)
        // 배열도 동적 메모리 할당도 둘다 연속된 주소를 할당받기 때문에 비슷하게 사용가능
    }

    free(pi);

    return 0;
}