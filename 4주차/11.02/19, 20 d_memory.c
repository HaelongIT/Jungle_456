#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 동적 메모리를 간단하게 할당하여 사용해보고 반환하기

    int *pi;
    // Pointer Integer

    pi = (int *)malloc(sizeof(int));
    // malloc(sizeof(int)) : int형의 크기만큼 메모리 공간을 할당해라(그리고 그 메모리 공간의 시작주소를 반환함)
    // sizeof(int) = 4
    // (int *) : malloc(sizeof(int))는 기본적으로 (void *)이 기본인데 int형으로 포인터를 형변환한다

    if (pi == NULL)
    {
        printf("동적 메모리 할당에 실패했습니다. \n");

        exit(1);
        // 프로그램 자체를 종료한다
    }

    *pi = 100;
    // int로 형변환 해서 int형만 사용가능

    printf("%d \n", *pi);

    // 동적 메모리 사용한 이후에는 무조건 해당 메모리를 반환해야됨
    free(pi);
    // pi(포인터변수)가 가리키고 있던 메모리 주소에 동적 메모리 할당을 취소함

    return 0;
}