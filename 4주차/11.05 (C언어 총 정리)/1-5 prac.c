#include <stdio.h>

int main()
{
    // printf("Hello World \n");
    // printf("�ȳ� ����\n");

    // ######################## scanf
    int input;
    printf("���� �Է��ϼ��� : ");

    scanf("%d", &input);
    // input���� ������ call by value�� ����� �ٲ����� �ʴ´�

    printf("%d\n", input);

    int one, two, three;

    printf("3���� ������ �Է��Ͻÿ� : ");
    scanf("%d %d %d", &one, &two, &three);
    printf("�Է¹��� ���� 3���� %d %d %d �Դϴ�\n", one, two, three);

    // �������� �Է¹ޱ�(�� ����)
    char c;
    printf("�ѱ��ڸ� �Է��Ͻÿ� : ");

    getchar();
    // �Է� ���� ����

    scanf("%c", &c);
    printf("%c\n", c);

    // ���ڿ��� �Է¹ޱ�(���� ����)
    char str[256];
    printf("���ڿ��� �Է��Ͻÿ� : ");
    scanf("%s", str);
    // str : str[256]�� ���� �ּҰ�

    printf("%s\n", str);
    // ���� �ּҰ����� NULL ���Ḧ ���� �� ���� ��µȴ�

    return 0;
}