#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // ���� �޸𸮸� �����ϰ� �Ҵ��Ͽ� ����غ��� ��ȯ�ϱ�

    int *pi;
    // Pointer Integer

    pi = (int *)malloc(sizeof(int));
    // malloc(sizeof(int)) : int���� ũ�⸸ŭ �޸� ������ �Ҵ��ض�(�׸��� �� �޸� ������ �����ּҸ� ��ȯ��)
    // sizeof(int) = 4
    // (int *) : malloc(sizeof(int))�� �⺻������ (void *)�� �⺻�ε� int������ �����͸� ����ȯ�Ѵ�

    if (pi == NULL)
    {
        printf("���� �޸� �Ҵ翡 �����߽��ϴ�. \n");

        exit(1);
        // ���α׷� ��ü�� �����Ѵ�
    }

    *pi = 100;
    // int�� ����ȯ �ؼ� int���� ��밡��

    printf("%d \n", *pi);

    // ���� �޸� ����� ���Ŀ��� ������ �ش� �޸𸮸� ��ȯ�ؾߵ�
    free(pi);
    // pi(�����ͺ���)�� ����Ű�� �ִ� �޸� �ּҿ� ���� �޸� �Ҵ��� �����

    return 0;
}