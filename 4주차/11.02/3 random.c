#include <stdio.h>
// 표준 입출력 함수 헤더파일

#include <time.h>
#include <stdlib.h>
// 라이브러리를 사용하기 위해 헤더파일 가져오기

int main(void)
{
    // printf("Hello World\n");

    // srand(time(NULL));
    // '난수 초기화' 를 해야만 rand()를 쓸때
    // 진짜 랜덤으로 숫자가 뽑힌다

    // int num = rand() % 3;
    // 0~2 사이에서 하나를 랜덤으로 뽑아준다

    // int num2 = rand() % 3 + 1;
    // 1~3 사이에서 하나를 랜덤으로 뽑아줌

    // 난수 초기화 이전
    printf("난수 초기화 이전..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10);
    }
    printf("\n");
    // 여러번 실행해도 매번 10번 뽑히는 숫자의
    // 패턴이 바뀌지 않음

    // 난수 초기화 이후
    srand(time(NULL));

    printf("난수 초기화 이후..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    return 0;
}