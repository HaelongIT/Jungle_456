#include <stdio.h>
// ǥ�� ����� �Լ� �������

#include <time.h>
#include <stdlib.h>
// ���̺귯���� ����ϱ� ���� ������� ��������

int main(void)
{
    // printf("Hello World\n");

    // srand(time(NULL));
    // '���� �ʱ�ȭ' �� �ؾ߸� rand()�� ����
    // ��¥ �������� ���ڰ� ������

    // int num = rand() % 3;
    // 0~2 ���̿��� �ϳ��� �������� �̾��ش�

    // int num2 = rand() % 3 + 1;
    // 1~3 ���̿��� �ϳ��� �������� �̾���

    // ���� �ʱ�ȭ ����
    printf("���� �ʱ�ȭ ����..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10);
    }
    printf("\n");
    // ������ �����ص� �Ź� 10�� ������ ������
    // ������ �ٲ��� ����

    // ���� �ʱ�ȭ ����
    srand(time(NULL));

    printf("���� �ʱ�ȭ ����..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    return 0;
}