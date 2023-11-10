#include <stdio.h>

int main(void)
{
    // printf("Hello World\n");

    // ###############쁠쁠

    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // printf("Hello World\n");
    // Hello World를 10번 출력하기

    // ++ 쁠쁠
    // int a = 10;
    // printf("a 는 %d\n", a);

    // a++;
    // printf("a에 ++하면 %d\n", a);
    // a++;
    // printf("a에 ++하면 %d\n", a);

    // int b = 20;
    // printf("b 는 %d\n", ++b);
    // ++b는 b = b + 1; 임(b+1을 선행적으로 함)

    // printf("b 는 %d\n", b++);
    // b++은 해당 문장에서는 b였다가 문장이 끝나고
    // 다음으로 넘어갈 때 b+1 해주는 것임(후행으로 함)

    // printf("b 는 %d\n", b);

    // int i = 1;
    // printf("Hello World %d\n", i++);    // i = 1
    // printf("Hello World %d\n", i++);    // i = 2
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);
    // printf("Hello World %d\n", i++);

    // ############### 반복문
    // for, while, do while

    // ############ for

    // for (선언; 조건; 증감)
    // for (int i = 1; i <= 10; i++) {
    //     printf("Hello World  %d\n", i);
    // }

    // ############## while

    // while (조건) {  }
    // int i = 1;
    // while (i <= 10) {
    //     printf("Hello World %d\n", i++);
    // i++;
    // }

    // ############ do while
    // do {  } while (조건);
    // int i = 1;
    // do {
    //     printf("Hello World! %d\n", i++);
    // } while (i <= 10);

    // #################2중 반복문 (구구단)
    // for (int i = 1; i <= 3; i++) {
    //     printf("첫 번째 반복문 : %d\n", i);

    //     for (int j = 1; j <= 5; j++) {
    //         printf("   두 번째 반복문 : %d\n", j);
    //     }
    // }

    // 구구단
    // 2 x 1 = 2
    // 2 x 2 = 4
    // ...
    // 9 x 9 = 81

    // for (int i = 2; i <= 9; i++) {
    //     printf("%d 단 시작합니다\n", i);
    //     for (int j = 1; j <= 9; j++) {
    //         printf("   %d x %d = %d\n", i, j, i*j);
    //     }
    // }

    // ##########이중 반복문 파헤치기
    /*
     *
     **
     ***
     ****
     *****
     */

    // for (int i = 1; i <= 5; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // #############이중 반복문(거꾸로 별)
    /*
     *
     **
     ***
     ****
     *****
     */

    /*
     @@@@*
     @@@**
     @@***
     @****
     *****
     */

    // 내가 만든것
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 4; j > i; j--) {
    //         printf(" ");
    //     }
    //     for (int k = 0; k <= i; k++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    // 정답코드
    // for (int i = 0; i < 5; i++) {
    //     for (int j = i; j < 5-1; j++) {
    //         printf("@");
    //     }
    //     for (int k = 0; k <= i; k++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // #################프로젝트2
    // 피라미드를 쌓아라 - 프로젝트

    // 내 코드
    /*
    @@@@*
    @@@***
    @@*****
    @*******
    *********
    */

    // int floor;

    // printf("몇 층으로 쌓아드릴까요 : ");
    // scanf_s("%d", &floor);

    // for (int i = 0; i < floor; i++) {
    //     for (int j = i; j < floor-1; j++) {
    //         printf(" ");
    //     }
    //     for (int k = 0; k <= i; k++) {
    //         printf("*");
    //     }
    //     for (int l = 0; l < i; l++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // 정답코드
    /*
    @@@@*
    @@@***
    @@*****
    @*******
    *********
    */

    int floor;
    printf("몇 층으로 쌓겠느냐?");
    scanf_s("%d", &floor);

    for (int i = 0; i < floor; i++)
    {
        for (int j = i; j < floor - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}