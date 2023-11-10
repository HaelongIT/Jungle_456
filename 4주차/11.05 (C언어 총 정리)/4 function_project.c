#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNum(int level);

void showQuestion(int level, int num1, int num2);

void success();
void fail();

int main(void) {
// �Ű�����(���ް�)�� ����(void) main�̶�� �̸��� ���� �Լ��̰�
// ������(int) �ڷḦ ��ȯ������ ������

    // printf("Hello World\n");

    // #############������Ʈ4
    // ���� 5���� �ְ�, �� ������ ���� ����� ���� ��� ���� (��������)
    // ������ ���, Ʋ���� ����

    // �� �ڵ�

    // srand(time(NULL));
    // ���� �ʱ�ȭ

    // for (int i = 1; i <= 5; i++) {
    //     printf("%d ��° ���� ����\n", i);

    //     int ans;
    //     int num1 = rand() % 20*i + 1;
    //     int num2 = rand() % 20*i + 1;

    //     printf("%d x %d = ? : ", num1, num2);
    //     scanf_s("%d", &ans);
        
    //     if (ans == (num1*num2)) {
    //         if (i == 5) {
    //             printf("�����մϴ�. ��� ������ ������ϴ�. ����� ��й�ȣ ������!\n");
    //             break;
    //         }

    //         printf("�����̱�! ���� ������!\n\n");
    //     }
    //     else {
    //         printf("���зα�!\n");
    //         break;
    //     }
    // }

    // �����ڵ�
    // ���� 5���� �ְ�, �� ������ ���� ����� ���� ��� ���� (��������)
    // ������ ���, Ʋ���� ����
    // ������Ʈ ������ : 5���� Ǯ�ٰ� �߰��� Ʋ���� �����°� �ƴϰ�
    // �� 5���� ��ȸ���� ��� ������� ��� �˷���
    // �߰��� Ʋ���� �����ϰ� �Ϸ��� ���� ���ǹ����� break;�� ����ϸ� ��

    srand(time(NULL));

    int count = 0;
    // ���� ���� ����

    for (int i = 1; i <= 5; i++) {
        // ���� : x * y = ?
        int num1 = getRandomNum(i);
        int num2 = getRandomNum(i);
        // �Լ�1 : �������� ���ڸ� �̾��ִ� �Լ�(i�� �̿��ؼ� ����ϰ� ū ���ڸ� �̱�)

        // printf("%d x %d ?", num1, num2);
        showQuestion(i, num1, num2);
        // 'i��° ����'�� "%d x %d ?"�� ������ִ� �Լ�

        int answer = -1;
        scanf_s("%d", &answer);

        if(answer == -1) {
            printf("���α׷��� �����մϴ�\n");

            // break;
            // ��ü������ ������ '����� 5���� ��й�ȣ �� %d ���� �������ϴ�'�� ��µǸ� ���
            exit(0);
            // ���α׷� ��ü�� ������ ����('����� 5���� ��й�ȣ �� %d ���� �������ϴ�') ��µ� �� ������ �ڿ�������

            // �Է��ڰ� ���Ḧ ���Ѵٸ� -1�� �Է��ؼ� ���α׷� ����
        }
        else if(answer == num1 * num2) {
            // ������ ���

            success();

            count++;
            // �� ���� ������ ���� ���� ����
        }
        else {
            // ������ ���

            fail();
        }

    }

    printf("\n\n ����� 5���� ��й�ȣ �� %d ���� �������ϴ�\n", count);

    return 0;
}

int getRandomNum(int level) {
    return rand() % (level*20) + 1;
}

void showQuestion(int level, int num1, int num2) {
    // printf("%d ��° ���� : %d x %d ? \n", level, num1, num2);
    printf("\n\n\n############# %d ��° ��й�ȣ ################\n", level);
    printf("\n\t %d x %d ��? \n\n", num1, num2);
    printf("##############################################\n");
    printf("\n��й�ȣ�� �Է��ϼ��� (���� : -1) >> ");
}

void success() {
    printf("\n >> Good ! �����Դϴ� \n");
}
void fail() {
    
    printf("\n >> �� ! Ʋ�Ƚ��ϴ� \n");
}