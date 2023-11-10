#include <stdio.h>

int main(void)
{
    // printf("Hello World!\n");

    // #############다차원 배열 기본

    // 다차원 배열 Multidimensional Array
    // int i;
    // □ : '일반변수'를 선언시 '메모리 공간(주소)'을 하나만큼 차지함

    // int arr[5];
    // □□□□□ : arr[5] 선언해서 메모리 공간 5개만큼 차지함
    // 5개짜리 '1차원 배열'이 1개 있음(1차원 배열)
    // 공간이 5개

    // 배열 : 연속된 (데이터를 저장할 수 있는 메모리) 공간
    // □□□...□□□□□□□ : '배열'을 선언시 '메모리 공간(주소)'를 연속적으로 여러개만큼 차지함

    // 다차원 배열
    // int arr2[2][5];
    // □□□□□
    // □□□□□
    // 5개짜리 '1차원 배열'이 2개 있음(2차원 배열)
    // 공간이 10개

    // int arr3[4][2];
    // □□
    // □□
    // □□
    // □□
    // 2개짜리 '1차원 배열'이 4개 있음(2차원 배열)
    // 공간이 8개

    // int arr4[3][3][3];
    // □□□
    // □□□
    // □□□

    // □□□
    // □□□
    // □□□

    // □□□
    // □□□
    // □□□
    // 3개짜리 '1차원 배열'이 3개가 있는 '2차원배열'이 3개 있음(3차원 배열)
    // 공간이 27개

    // #########다차원 배열 접근
    // int arr[5];
    // □□□□□

    // [0][1][2][3][4]

    // int arr2[2][5];
    // □□□□□
    // □□□□□

    // [0,0][0,1][0,2][0,3][0,4]
    // [1,0][1,1][1,2][1,3][1,4]
    // -> ex) arr2[0][0]
    // -> ex) arr2[1][4]

    // int arr3[4][2];
    // □□
    // □□
    // □□
    // □□

    // [0,0][0,1]
    // [1,0][1,1]
    // [2,0][2,1]
    // [3,0][3,1]
    // -> ex) arr3[0][1]
    // -> ex) arr3[3][2]

    // int arr4[3][3][3];
    // □□□
    // □□□
    // □□□

    // □□□
    // □□□
    // □□□

    // □□□
    // □□□
    // □□□

    // [0,0,0][0,0,1][0,0,2]
    // [0,1,0][0,1,1][0,1,2]
    // [0,2,0][0,2,1][0,2,2]

    // [1,0,0][1,0,1][1,0,2]
    // [1,1,0][1,1,1][1,1,2]
    // [1,2,0][1,2,1][1,2,2]

    // [2,0,0][2,0,1][2,0,2]
    // [2,1,0][2,1,1][2,1,2]
    // [2,2,0][2,2,1][2,2,2]

    // ##########다차원 배열 선언

    // 1차원 배열 선언
    // int arr[5] = {1,2,3,4,5};

    // 2차원 배열 선언
    // int arr2[2][5] = {
    //     {1,2,3,4,5},
    //     {1,2,3,4,5}
    // };

    // int arr3[4][2] = {
    //     {1,2},
    //     {1,2},
    //     {1,2},
    //     {1,2}
    // };

    // 3차원 배열 선언
    // int arr4[3][3][3] = {
    //     {
    //         {1,2,3},
    //         {1,2,3},
    //         {1,2,3}
    //     },
    //     {
    //         {1,2,3},
    //         {1,2,3},
    //         {1,2,3}
    //     },
    //     {
    //         {1,2,3},
    //         {1,2,3},
    //         {1,2,3}
    //     }
    // };

    // #############다차원 배열 사용
    // 다차원 배열에 접근하기

    // 2차원 배열에 접근
    int arr3[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("2차원배열 (%d, %d)의 값 : %d\n", i, j, arr3[i][j]);
        }
        printf("\n");
    }

    // 3차원 배열에 접근
    int arr4[3][3][3] = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},
        {{11, 12, 13},
         {14, 15, 16},
         {17, 18, 19}},
        {{21, 22, 23},
         {24, 25, 26},
         {27, 28, 29}}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("3차원배열 (%d, %d, %d)의 값 : %d\n", i, j, k, arr4[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // #############프로젝트7
    // 7 m_array_project.c 에서 진행함

    return 0;
}