#include <stdio.h>

int main(void)
{
    // printf("Hello World\n");

    // ###############�ܻ�

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
    // Hello World�� 10�� ����ϱ�

    // ++ �ܻ�
    // int a = 10;
    // printf("a �� %d\n", a);

    // a++;
    // printf("a�� ++�ϸ� %d\n", a);
    // a++;
    // printf("a�� ++�ϸ� %d\n", a);

    // int b = 20;
    // printf("b �� %d\n", ++b);
    // ++b�� b = b + 1; ��(b+1�� ���������� ��)

    // printf("b �� %d\n", b++);
    // b++�� �ش� ���忡���� b���ٰ� ������ ������
    // �������� �Ѿ �� b+1 ���ִ� ����(�������� ��)

    // printf("b �� %d\n", b);

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

    // ############### �ݺ���
    // for, while, do while

    // ############ for

    // for (����; ����; ����)
    // for (int i = 1; i <= 10; i++) {
    //     printf("Hello World  %d\n", i);
    // }

    // ############## while

    // while (����) {  }
    // int i = 1;
    // while (i <= 10) {
    //     printf("Hello World %d\n", i++);
    // i++;
    // }

    // ############ do while
    // do {  } while (����);
    // int i = 1;
    // do {
    //     printf("Hello World! %d\n", i++);
    // } while (i <= 10);

    // #################2�� �ݺ��� (������)
    // for (int i = 1; i <= 3; i++) {
    //     printf("ù ��° �ݺ��� : %d\n", i);

    //     for (int j = 1; j <= 5; j++) {
    //         printf("   �� ��° �ݺ��� : %d\n", j);
    //     }
    // }

    // ������
    // 2 x 1 = 2
    // 2 x 2 = 4
    // ...
    // 9 x 9 = 81

    // for (int i = 2; i <= 9; i++) {
    //     printf("%d �� �����մϴ�\n", i);
    //     for (int j = 1; j <= 9; j++) {
    //         printf("   %d x %d = %d\n", i, j, i*j);
    //     }
    // }

    // ##########���� �ݺ��� ����ġ��
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

    // #############���� �ݺ���(�Ųٷ� ��)
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

    // ���� �����
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

    // �����ڵ�
    // for (int i = 0; i < 5; i++) {
    //     for (int j = i; j < 5-1; j++) {
    //         printf("@");
    //     }
    //     for (int k = 0; k <= i; k++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // #################������Ʈ2
    // �Ƕ�̵带 �׾ƶ� - ������Ʈ

    // �� �ڵ�
    /*
    @@@@*
    @@@***
    @@*****
    @*******
    *********
    */

    // int floor;

    // printf("�� ������ �׾Ƶ帱��� : ");
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

    // �����ڵ�
    /*
    @@@@*
    @@@***
    @@*****
    @*******
    *********
    */

    int floor;
    printf("�� ������ �װڴ���?");
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