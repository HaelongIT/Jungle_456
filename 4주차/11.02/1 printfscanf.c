#include <stdio.h>

int main(void)
{

	// printf("Hello World\n");

	// ##################������ ������ ���� ����
	//
	// ������ ó�� ������ ���� �ڷ����� ���ָ� ��
	/*int age = 12;
	printf("%d\n", age);*/

	// ������ ���� �ٲ� �� ����
	/*age = 13;
	printf("%d\n", age);*/

	// �ּ��� ���ؼ� ���� �ȵǰ� �� �� ����
	// printf("1\n");
	// printf("2\n");	// 2�� �������� ����Ƿ� �ּ� ó��
	// printf("3\n");

	// #############�Ǽ��� ������ ���� ����
	/*float f = 46.5f;
	printf("%f\n", f);*/

	// �Ҽ����� �����ϱ�
	// printf("%.2f\n", f);	// �Ҽ��� ��°�ڸ������� ����

	/*double d = 4.428;
	printf("%lf\n", d);
	printf("%.2lf\n", d);*/

	// #####################���
	// const int YEAR = 2000;  // ���
	// printf("�¾ �⵵ : %d\n", YEAR);
	// YEAR = 2001;	// YEAR�� ����̱� ������ ���� �Ұ���

	// ####################printf
	// ����
	// int add = 3 + 7;    //10
	// printf("3 + 7 = %d\n", add);
	// printf("%d + %d = %d\n", 3, 7, 3 + 7);
	// printf("%d + %d = %d\n", 30, 79, 30 + 79);
	// printf("%d x %d = %d\n", 30, 79, 30 * 79);

	// ########################scanf
	// Ű���� �Է��� �޾Ƽ� ����
	// int input;
	// printf("���� �Է��ϼ��� : ");

	// scanf_s("%d", &input);
	// �Է¹޴´�, ��������, input�̶�� ������
	// &input : input ������ �ּҿ� ���� �Է� �ްڴ�

	// printf("�Է°� : %d\n", input);

	// int one, two, three;
	// printf("3���� ������ �Է��ϼ��� : ");
	// scanf_s("%d %d %d", &one, &two, &three);
	// printf("ù��° �� : %d\n", one);
	// printf("�ι�° �� : %d\n", two);
	// printf("����° �� : %d\n", three);

	// �������� �Է¹ޱ�
	// ����(�� ����), ���ڿ�(�� ���� �̻��� ���� ����)
	// char c = 'A';
	// printf("%c\n", c);

	// ���ڿ�

	// char str[256];
	// char c ���� ���� �ϳ��� ������ �� �ִ� ������
	// 256���� �� �̾ �迭�� ����(�迭 �ڿ��� �ڼ���)

	// scanf_s("%s", str, sizeof(str));
	// ���ڿ��� %s
	// ���ڿ��� ���� ������ &�� �̿��ؼ� �ּҷ� ���� �ʿ� ����(��Ȯ���� str�� �ּҸ� ����)
	// sizeof()�� �̿��ؼ� str[256]��ŭ�� ���� �Ŷ�� ���

	// printf("%s\n", str);

	// ################������Ʈ1
	// �������� �������� ������ �Լ� (���� �ۼ�)
	// �̸�? ����? ������? Ű? ���˸�?
	char name[256];
	int age;
	float weight;
	double height;
	char reason[256];

	printf("�̸��� ���� : ");
	scanf_s("%s", name, sizeof(name));
	printf("���̰� ���̳� : ");
	scanf_s("%d", &age);
	printf("�����԰� ���̳� : ");
	scanf_s("%f", &weight);
	printf("Ű�� ���̳� : ");
	scanf_s("%lf", &height);
	printf("���˸��� ���� : ");
	scanf_s("%s", reason, sizeof(reason));

	// ���� ���� ���
	printf("\n\n--- ������ ���� ---\n\n");
	printf("�������� �̸��� %s �Դϴ�\n", name);
	printf("���̴� %d�� �̱���\n", age);
	printf("�����Դ� %.1fkg �̶�׿�\n", weight);
	printf("Ű�� %.2lf���� �ȴ�ϴ�\n", height);
	printf("�ڱ� ���δ� %s�� �������ٳ׿�\n", reason);

	return 0;
}