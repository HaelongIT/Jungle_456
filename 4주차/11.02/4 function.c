#include <stdio.h>

// #########����
// �Լ� ����
// void func(int num);

// ########��ȯ���� ���� �Լ�(�Ű����� ����)
// void function_without_return();
// ��ȯ���� ��� void

// #######��ȯ���� �ִ� �Լ�(�Ű����� ����)
// int function_with_return();
// ��ȯ���� �־ ��ȯ���� int

// ##########���ް��� ���� �Լ�(��ȯ���� ����)
// void function_without_params();

// ##########���ް��� �ִ� �Լ�(��ȯ���� ����)
// void function_with_params(int num1, int num2, int num3);

// ###########��ȯ���� ���ް��� �ִ� �Լ�
// int apple(int total, int ate);
// ��ü total ������ ate ���� �԰� ���� ���� ��ȯ

// ##############�Լ��� �̿��� ����
// int add(int num1, int num2);
// int sub(int num1, int num2);
// int mul(int num1, int num2);
// int div(int num1, int num2);

int main(void)
{
    // printf("Hello World\n");

    // function
    // ##########����

    // int num = 2;
    // printf("num �� %d �Դϴ�\n", num);
    // 2���

    // 2 + 3 ��?
    // num = num + 3;
    // num += 3;

    // printf("num �� %d �Դϴ�\n", num);
    // 5���

    // 5 - 1 ��?
    // num -= 1;
    // num = num - 1;

    // printf("num �� %d �Դϴ�\n", num);
    // 4���

    // 4 x 3 ��?
    // num *= 3;
    // printf("num �� %d �Դϴ�\n", num);
    // 12���

    // 12 / 6 ��?
    // num /= 6;
    // printf("num �� %d �Դϴ�\n", num);
    // 2���

    // ���ݱ��� ��Ģ���� �ϸ鼭 �Ź� printf();�� ����ϴµ�
    // �Ź� �ݺ��ؼ� ����ϴ°� ��ȿ�����̱� ������ �Լ��� �ʿ�

    // int num = 2;

    // printf("num �� %d �Դϴ�\n", num)
    // ��� printf()�� �Լ���(C��� �⺻ �����Լ�)

    // func(num);
    // func()�� ���� ���Ƿ� ���� �Լ���(����� ���� �Լ�)

    // num += 3;
    // func(num);

    // num -= 1;
    // func(num);

    // num *= 3;
    // func(num);

    // num /= 6;
    // func(num);

    // #######�Լ��� ����
    // �����Լ� �ϴ� ����

    // ########��ȯ���� ���� �Լ�

    // �Լ� ����
    // ��ȯ���� ���� �Լ�
    // function_without_return();

    // ###########��ȯ���� �ִ� �Լ�
    // int ret = function_with_return();
    // printf("%d\n", ret);
    // func(ret);

    // ##########���ް�(�Ű�����)�� ���� �Լ�
    // �Ű�����(�Ķ����, ���ް�, �μ� ��)
    // function_without_params();

    // ########���ް�(�Ű�����)�� �ִ� �Լ�
    // function_with_params(35, 27, 14);

    // ########��ȯ���� ���ް��� �ִ� �Լ�
    // �Ű�����(�Ķ����, ���ް�)�� �ް�, ��ȯ���� �����ִ� �Լ�
    // int ret = apple(5,2);
    // 5���� ��� �߿��� 2���� �Ծ����

    // printf("��� 5�� �߿� 2���� ������? %d ���� ���ƿ�\n", ret);
    // printf("��� %d �� �߿� %d ���� ������? %d ���� ���ƿ�\n", 10, 4, apple(10,4));

    // ##############�Լ��� �̿��� ����
    // ���� �Լ�
    // int num = 2;
    // num = add(num, 3);
    // func(num);

    // num = sub(num, 1);
    // func(num);

    // num = mul(num, 3);
    // func(num);

    // num = div(num, 6);
    // func(num);

    // ##################������Ʈ4
    // ������Ʈ4�� 4 function_project.c ���� �� ����

    return 0;
}

// ######����
// �Լ� ����
// void func(int num) {
//     printf("num �� %d �Դϴ�\n", num);
// }

// ###########�Լ��� ����

// ���ް�[�Ű�����] : ��(36)
// �Լ�[���� �˰���] : �� + 4
// ��ȯ�� : o(40)

// ��ȯ�� �Լ��̸�(������ ���ް�[�Ű�����]) {
//     return ��ȯ��;
// }

// int function(int ��) {
//     �� = �� + 4;
//     return o
// }
// function(36);

// void �Լ��̸�(int num1, int num2, char c, float f) {

// }
// �̷��� ��ȯ���� ������ void�� ��Ÿ���� ��
// �Ű������� ������ ���� ���� ����

// ###########��ȯ���� ���� �Լ�(�Ű����� ����)
// void function_without_return() {
//     printf("��ȯ���� ���� �Լ��Դϴ�\n");
// }

// ############��ȯ���� �ִ� �Լ�(�Ű����� ����)
// int function_with_return() {
//     printf("��ȯ���� �ִ� �Լ��Դϴ�\n");
//     return 10;
// }

// ##########���ް��� ���� �Լ�(��ȯ���� ����)
// void function_without_params() {
//     printf("���ް��� ���� �Լ��Դϴ�\n");
// }

// ############���ް��� �ִ� �Լ�(��ȯ���� ����)
// void function_with_params(int num1, int num2, int num3) {
//     printf("���ް��� �ִ� �Լ��̸�, ���޹��� ���� %d, %d, %d �Դϴ�\n"
//     , num1, num2, num3);
// }

// ################��ȯ���� ���ް��� �ִ� �Լ�
// int apple(int total, int ate) {
//     printf("���ް��� ��ȯ���� ��� �ִ� �Լ��Դϴ�\n");
//     return total - ate;
// }

// ##############�Լ��� �̿��� ����
// int add(int num1, int num2) {
//     return num1 + num2;
// }
// int sub(int num1, int num2) {
//     return num1 - num2;
// }
// int mul(int num1, int num2) {
//     return num1 * num2;
// }
// int div(int num1, int num2) {
//     return num1 / num2;
// }