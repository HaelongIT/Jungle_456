#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 동적 메모리를 이용해 2차원 배열 다루기

    int i, x, y;

    int **pptr = (int **)malloc(sizeof(int *) * 8);
    // 8개의 연속된 포인터변수를 만들었음
    // 각 포인터변수들이 어떤 주소를 가리키는지 아직 모름

    for (i = 0; i < 8; i++)
    {
        *(pptr + i) = (int *)malloc(sizeof(int) * 6);
        // 각 포인터변수들이 int형이 연속으로 6개만큼 들어갈 수 있는
        // 메모리 공간의 주소 시작점을 가리킴
    }
    // 8개의 연속된 포인터들이 각각 int형이 연속으로 6개만큼 들어가는 공간을 가리키면서
    // 총 48개의 공간이 생성(동적메모리를 이용한 2차원 배열 할당)

    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 6; x++)
        {
            *(*(pptr + y) + x) = 6 * y + x;
        }
    }
    // y는 8개의 연속된 포인터변수들의 인덱스 의미
    // x는 각 포인터변수들이 가리키는 'int형이 연속으로 6개만큼 들어가는 공간'을 의미

    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 6; x++)
        {
            printf("%3d", *(*(pptr + y) + x));
        }
        printf("\n");
    }

    for (y = 0; y < 8; y++)
    {
        free(*(pptr + y));
    }

    return 0;
}