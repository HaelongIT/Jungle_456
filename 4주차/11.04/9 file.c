#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 10000
// ��� MAX�� 10000���� ������

int main(void)
{
    // #####################���� ���� fputs

    // ���� �����
    // ���Ͽ� � �����͸� �����ϰ�,
    // ���Ͽ� ����� �����͸� �ҷ�����

    // fputs, fgets �� -> ���ڿ� ����

    char line[MAX];
    // char line[10000]; �� ����

    // ���Ͽ� ����

    // FILE *file = fopen("C:\\Users\\�տ���\\Desktop\\������\\����\\4����\\11.04\\test1.txt", "wb");
    // FILE : ����ü�� ������(typedef)
    // file : ����ü FILE�� �����ͺ���

    // fopen() : ���������� ������ ������ '���� ������' ��ȯ
    // �����ϸ� NULL�� ��ȯ

    // ���� ������ : ������ �����ϱ� ���� �ڵ� �Ǵ� ���Ͽ� ���� ������ ����Ű�� ������

    // r(�б� ����), w(���� ����), a(�̾�� ����)
    // t(�ؽ�Ʈ ������), b(���̳ʸ� ������)

    // if (file == NULL)
    // {
    //     printf("���� ���� ����\n");
    //     return 1;
    //     // ���α׷� �����ϱ�
    // }

    // fputs("I will write this using fputs\n", file);
    // fputs("Please make sure it is written well\n", file);
    // fputs()���� ���������͸� �̿��ؼ� ���Ͽ� �ؽ�Ʈ ������ �ۼ��Ѵ�

    // ������ ���� ���� ���� ���� ���¿��� � ���α׷��� ������ �����?
    // ������ �ս� �߻� ���� !
    // �׷��� �׻� ������ �ݾ��ִ� ������ �鿩�ּ���
    // fclose(file);
    // ������ �����ϰ� �ݴ´�

    // ############���� �б� fgets

    // ���� �б�

    // FILE *file = fopen("C:\\Users\\�տ���\\Desktop\\������\\����\\4����\\11.04\\test1.txt", "rb");
    // // fopen�� '�б� ����'(rb)���� ����

    // if (file == NULL)
    // {
    //     printf("���� ���� ����\n");
    //     return 1;
    // }

    // while (fgets(line, MAX, file) != NULL)
    // {
    //     printf("%s", line);
    // }
    // fgets : '����� ��, ������, ����������'�� �Ű������� �ָ� '����� ��'�� �ؽ�Ʈ ������ ��ȯ�Ѵ�

    // ###########�Ǵٸ� ���� ���� fprintf

    // fprintf, fscanf �� -> ����ȭ�� ���˿� ���ؼ� ������ �а� �� �� ���
    // (printf, scanf �ְ� ����� ���� : ����ȭ�� ���˿� ���ؼ� ������ �а� �� �� ���)
    // printf("%d %d %s ...")
    // scanf("%d %d", &num1, ...)

    int num[6] = {0,
                  0,
                  0,
                  0,
                  0,
                  0};
    // �ζ� ��÷��ȣ

    int bonus = 0;
    // ���ʽ� ��ȣ

    char str1[MAX];
    char str2[MAX];

    // ���Ͽ� ����
    // FILE *file = fopen("C:\\Users\\�տ���\\Desktop\\������\\����\\4����\\11.04\\test2.txt", "wb");

    // if (file == NULL)
    // {
    //     printf("���� ���� ����\n");
    //     return 1;
    // }

    // // �ζ� ��÷ ��ȣ ����
    // fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1, 2, 3, 4, 5, 6);
    // fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);

    // fclose(file);

    // #############�Ǵٸ� ���� �б� fscanf

    // ���� �б�

    FILE *file = fopen("C:\\Users\\�տ���\\Desktop\\������\\����\\4����\\11.04\\test2.txt", "rb");

    if (file == NULL)
    {
        printf("���� ���� ����\n");
        return 1;
    }

    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

    fscanf(file, "%s %d", str2, &bonus);
    printf("%s %d\n", str2, bonus);

    fclose(file);

    return 0;
}