#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    // printf("Hello World\n");

    // ########### if else
    // if (����) { ... } else { ... }

    // ������ ź�ٰ� ����
    // �л�/�Ϲ������� ���� (�Ϲ��� : 20�� �̻�)
    // int age = 15;
    // int age = 25;

    // if (age >= 20) {
    //     printf("�Ϲ��� �Դϴ�\n");
    // }
    // else {
    //     printf("�л��Դϴ�\n");
    // }

    // �ʵ��л�(8-13)/���л�(14-16)/����л�(17-19)���� ������?
    // if / else if / else
    // int age = 25;
    // if (age >= 8 && age <= 13) {
    //     printf("�ʵ��л��Դϴ�\n");
    // }
    // else if (age >= 14 && age <= 16) {
    //     printf("���л��Դϴ�\n");
    // }
    // else if (age >= 17 && age <= 19) {
    //     printf("����л��Դϴ�\n");
    // }
    // else {
    //     printf("�л��� �ƴѰ�����\n");
    // }

    // ########## break / continue
    // 1������ 30������ �ִ� �ݿ��� 1������ 5������
    // ���� ��ǥ�� �մϴ�.
    // for (int i = 1; i <=30; i++) {
    //     if (i >= 6) {
    //         printf("������ �л��� ���� ������\n");
    //         break;
    //     }
    //     printf("%d �� �л��� ���� ��ǥ �غ� �ϼ���\n", i);
    // }

    // 1������ 30������ �ִ� �ݿ��� 7�� �л��� ���ļ� �Ἦ
    // 7���� �����ϰ� 6������ 10������ ���� ��ǥ�� �ϼ���

    // �� �ڵ�
    // for (int st = 1; st <= 30; st++) {
    //     if (st >= 6 && st <= 10) {
    //         if (st == 7) {
    //             continue;
    //         }
    //         printf("%d ���� ��ǥ\n", st);
    //     }
    // }

    // ���� �ڵ�
    // for (int i = 1; i <=30; i++) {
    //     if (i >= 6 && i <= 10) {
    //         if (i == 7) {
    //             printf("%d �� �л��� �Ἦ�Դϴ�\n", i);
    //             continue;
    //         }
    //         printf("%d �� �л��� ���� ��ǥ �غ� �ϼ���\n", i);
    //     }
    // }

    // ############ and(&&) / or(||)
    // int a = 10;
    // int b = 11;
    // int c = 13;
    // int d = 13;
    // if (a == b && c == d) {
    //     printf("a �� b �� ����, (���ÿ�) c �� d �� �����ϴ�\n");
    // }
    // else if (a == b || c == d) {
    //     printf("a �� b, Ȥ�� (���� �ϳ���) c �� d �� ���� �����ϴ�\n");
    // }
    // else {
    //     printf("���� ���� �ٸ��׿�\n");
    // }

    // ##############����
    // 3 random.c ���� ���� ������

    // ############# switch case

    // ����(0) / ����(1) / ��(2)

    // srand(time(NULL));
    // ���� �ʱ�ȭ

    // int i = rand() % 3;
    // 0~2 ������ ���� �������� ��ȯ

    // if (i == 0) {
    //     printf("����\n");
    // }
    // else if (i == 1) {
    //     printf("����\n");
    // }
    // else if (i == 2) {
    //     printf("��\n");
    // }
    // else {
    //     printf("�����\n");
    // }

    // switch�� �̿��ؼ��� ����,����, ��
    // ������
    // srand(time(NULL));

    // int i = rand() % 3;

    // int i = 0;
    // �� case�� break;�� ������ �ش�Ǵ� case ������
    // ������ case���� ���������� �����

    // switch (i) {

    //     case 0:
    //         printf("����\n");
    //         break;
    //     case 1:
    //         printf("����\n");
    //         break;
    //     case 2: printf("��\n"); break;
    //     default: printf("�����\n"); break;
    // }

    // �ʵ��л�(8-13)/���л�(14-16)/����л�(17-19)����
    // ������? (switch case�� �غ���)

    // srand(time(NULL));

    // int age = rand() % 30;
    // printf("%d ��\n", age);

    // switch (age) {
    //     case 1: printf("������ �Ƶ�\n"); break;
    //     case 2: printf("������ �Ƶ�\n"); break;
    //     case 3: printf("������ �Ƶ�\n"); break;
    //     case 4: printf("������ �Ƶ�\n"); break;
    //     case 5: printf("������ �Ƶ�\n"); break;
    //     case 6: printf("������ �Ƶ�\n"); break;
    //     case 7: printf("������ �Ƶ�\n"); break;
    //     case 8:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 9:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 10:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 11:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 12:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 13:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 14: printf("���л��Դϴ�\n"); break;
    //     case 15: printf("���л��Դϴ�\n"); break;
    //     case 16: printf("���л��Դϴ�\n"); break;
    //     case 17: printf("����л��Դϴ�\n"); break;
    //     case 18: printf("����л��Դϴ�\n"); break;
    //     case 19: printf("����л��Դϴ�\n"); break;
    //     default:
    //         printf("�л��� �ƴѰ�����\n");
    //         break;
    // }

    // break;�� �̿��ؼ� case�� ���� �����
    // srand(time(NULL));

    // int age = rand() % 30;
    // printf("%d ��\n", age);

    // switch (age) {
    //     case 1:
    //     case 2:
    //     case 3:
    //     case 4:
    //     case 5:
    //     case 6:
    //     case 7: printf("������ �Ƶ�\n"); break;
    //     case 8:
    //     case 9:
    //     case 10:
    //     case 11:
    //     case 12:
    //     case 13:
    //         printf("�ʵ��л��Դϴ�\n");
    //         break;
    //     case 14:
    //     case 15:
    //     case 16: printf("���л��Դϴ�\n"); break;
    //     case 17:
    //     case 18:
    //     case 19: printf("����л��Դϴ�\n"); break;
    //     default:
    //         printf("�л��� �ƴѰ�����\n");
    //         break;
    // }

    // ############������Ʈ3
    // Up and Down

    // �� �ڵ�
    // srand(time(NULL));
    // int ai_num = rand() % 100 + 1;
    // printf("%d\n", ai_num);

    // ��ȸ�� 10������ �����ؼ� �����
    // for (int i = 0; i < 10; i++) {

    //     int my_num;
    //     printf("���ڸ� ���纸�ÿ�(1~100) : ");
    //     scanf_s("%d", &my_num);
    //     // printf("%d\n", my_num);

    //     if (my_num == ai_num) {
    //         printf("�����Դϴ�\n");
    //         break;
    //     }
    //     else if (my_num > ai_num) {
    //         printf("Down\n");
    //     }
    //     else if (my_num < ai_num) {
    //         printf("Up\n");
    //     }
    //     else {
    //         printf("������Ȳ\n");
    //     }
    // }

    // �����ڵ�

    srand(time(NULL));
    int num = rand() % 100 + 1;
    // �����ʱ�ȭ �ϰ� 1~100 ������ ������ ��ȯ

    printf("��ǻ�Ͱ� ���� ���� : %d\n", num);

    int answer = 0;
    // ���� ������ ����

    int chance = 5;
    // ��ȸ�� 5��

    while (chance > 0)
    {
        // ���ѷ������� Ż������(break;) ���� ����Ÿ�
        // while (1) {...}���� �ص� ��

        // 1 : ��, 0 : ����

        printf("���� ��ȸ %d ��\n", chance--);
        // ���� ��ȸ�� ����ϰ� ���Ŀ� -1�� �ϱ�

        printf("���ڸ� ���������� (1~100) : ");
        scanf_s("%d", &answer);

        if (answer > num)
        {
            printf("DOWN ��\n\n");
        }
        else if (answer < num)
        {
            printf("UP ��\n\n");
        }
        else if (answer == num)
        {
            printf("�����Դϴ�!! \n");
            printf("�����մϴ�. ��ȸ�� %d�� ����� ����\n\n", chance);
            break;
            // ������ ��쿡�� ��ü loop���� Ż����
        }
        else
        {
            printf("�� �� ���� ������ �߻��߾��\n\n");
        }

        if (chance == 0)
        {
            printf("��� ��ȸ�� �� ����ϼ̳׿�. �ƽ��� �����߽��ϴ�\n");
            break;
        }
        // while�� ������ 0���� Ŭ ���� ��� �ʿ�� ���� �κ�
        // ���ѷ������� Ż���Ҽ� �ִ� �κ��̱� ������ while��
        // ������ 1�� �ص���
    }

    return 0;
}