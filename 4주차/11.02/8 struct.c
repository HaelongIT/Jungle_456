#include <stdio.h>

struct GameInfo {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
    // ���� ��ü ����

    // '����ü'(GameInfo)�� '����'�� �� '�� ����ü'(GameInfo) �ȿ�
    // '�� ����ü'(GameInfo)�� '����ü�� ����'(friendGame)�� '����'��
    // ('struct GameInfo'�� [�ڷ���]�̰�, 'friendGame'�� [����ü �����ͺ�����]��)
};

typedef struct GameInformation {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
} GAME_INFO;

typedef struct {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
} GAME_INFO2;

int main(void) {
    // printf("Hello World\n");

    // ##########����ü �⺻
    
    // [���� ���]
    // �̸� : ��������
    // �߸ų⵵ : 2017��
    // ���� : 50��
    // ���ۻ� : ����ȸ��

    char * name = "��������";
    int year = 2017;
    int price = 50;
    char * company = "����ȸ��";

    // [�Ǵٸ� ���� ���]
    // �̸� : �ʵ�����
    // �߸ų⵵ : 2017��
    // ���� : 100��
    // ���ۻ� : �ʵ�ȸ��

    char * name2 = "�ʵ�����";
    int year2 = 2017;
    int price2 = 100;
    char * company2 = "�ʵ�ȸ��";
    // ��Ʈ�� ���Ǵ� �������� �ϳ��� ���������� �����Ǹ� ���ڴµ�
    // ���� ������ �����Ǵ� ������

    // ###############����ü ���

    // ����ü ���(������ �ʱ�ȭ)
    struct GameInfo gameInfo1;
    gameInfo1.name = "��������";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "����ȸ��";

    struct GameInfo gameInfo2;
    gameInfo2.name = "�ʵ�����";
    gameInfo2.year = 2017;
    gameInfo2.price = 100;
    gameInfo2.company = "�ʵ�ȸ��";

    // ����ü ���
    printf("----- ���� ��� ���� -----\n");
    printf("    ���Ӹ�      : %s\n", gameInfo1.name);
    printf("    �߸ų⵵    : %d\n", gameInfo1.year);
    printf("    ����        : %d\n", gameInfo1.price);
    printf("    ���ۻ�      : %s\n", gameInfo1.company);

    printf("\n");

    printf("----- �Ǵٸ� ���� ��� ���� -----\n");
    printf("    ���Ӹ�      : %s\n", gameInfo2.name);
    printf("    �߸ų⵵    : %d\n", gameInfo2.year);
    printf("    ����        : %d\n", gameInfo2.price);
    printf("    ���ۻ�      : %s\n", gameInfo2.company);

    printf("\n");

    // ����ü�� �迭ó�� �ʱ�ȭ(�ѹ��� �ʱ�ȭ)
    struct GameInfo gameInfo3 = {"��Ʋ�׶���", 2019, 300, "ũ������"};
    printf("----- �Ǵٸ� ���� ��� ���� -----\n");
    printf("    ���Ӹ�      : %s\n", gameInfo3.name);
    printf("    �߸ų⵵    : %d\n", gameInfo3.year);
    printf("    ����        : %d\n", gameInfo3.price);
    printf("    ���ۻ�      : %s\n", gameInfo3.company);

    printf("\n");

    // #########����ü �迭
    
    // ����ü �迭
    struct GameInfo gameArray[2] = {
        {"��Ʋ�׶���", 2019, 300, "ũ������"},
        {"��ƺ��4", 2021, 400, "���ڵ�"}
    };
    // ���� '����ü�� �迭ó�� �ʱ�ȭ'�� '1���� �迭'�� ����
    // '����ü �迭'�� '2���� �迭'�� ����

    printf("----- ���� �߿� ���� ��� ��� -----\n");
    printf("    ���Ӹ�1      : %s\n", gameArray[0].name);
    printf("    ���Ӹ�2      : %s\n", gameArray[1].name);

    printf("\n");
    
    // #########����ü ������

    // ����ü �����ͺ���
    struct GameInfo * gamePtr;
    // �̼Ǹ�('����ü �����ͺ���' : '����ü����'�� '�����ͺ���'�� ����)
    
    // ����ü �����ͺ��� �ʱ�ȭ
    gamePtr = &gameInfo1;
    // '����ü �����ͺ���'���� 'Ư�� ����ü �Ϲݺ���'�� '�ּҰ�'�� ������

    // ����ü �����ͺ��� ���1
    printf("----- �̼Ǹ��� ���� ��� ����1 -----\n");
    printf("    ���Ӹ�      : %s\n", (*gamePtr).name);
    printf("    �߸ų⵵    : %d\n", (*gamePtr).year);
    printf("    ����        : %d\n", (*gamePtr).price);
    printf("    ���ۻ�      : %s\n", (*gamePtr).company);
    
    // '�����ͺ���'�� 'int * ptr = &[�Ϲݺ���];'�� �����ߴٸ�
    // 'ptr'�� '�����ͺ���'�� 'Ư���� �Ϲݺ����� �ּҰ�'�� ������
    // '*ptr'�� 'Ư���� �Ϲݺ����� ��'(value)�� ���� ������

    printf("\n");

    // ����ü �����ͺ��� ���2
    struct GameInfo * gamePtr2;
    gamePtr2 = &gameInfo2;

    printf("----- �̼Ǹ��� ���� ��� ����2 -----\n");
    printf("    ���Ӹ�      : %s\n", gamePtr2->name);
    printf("    �߸ų⵵    : %d\n", gamePtr2->year);
    printf("    ����        : %d\n", gamePtr2->price);
    printf("    ���ۻ�      : %s\n", gamePtr2->company);
    // '����ü �����ͺ���'�� 'Ư���� ����ü �Ϲݺ���'�� '��'(value)�� ������ ��
    // '[����ü �����ͺ�����]->[����ü�� ������]'�� �����

    printf("\n");

    // ##########����ü ���� ����ü

    // ���� ��ü ���� �Ұ�
    gameInfo1.friendGame = &gameInfo3;
    // �տ��� '����'�ߴ� '����ü����'(gameInfo1)�� '����ü�� ����' ��
    // '����ü �����ͺ���'(friendGame)�� ����
    // ('����ü �����ͺ���'�� Ư�� '����ü�� �ּҰ�'�� �ʱ�ȭ��)

    printf("----- ���� ��ü�� ���� ��� ���� -----\n");
    printf("    ���Ӹ�      : %s\n", gameInfo1.friendGame->name);
    printf("    �߸ų⵵    : %d\n", gameInfo1.friendGame->year);
    printf("    ����        : %d\n", gameInfo1.friendGame->price);
    printf("    ���ۻ�      : %s\n", gameInfo1.friendGame->company);

    printf("\n");

    // ############ typedef

    // typedef
    // �ڷ����� ���� ����

    int i = 1;
    // int : ������(�ڷ���)
    // i : ������ ����

    typedef int js;
    // 'int'��� '������(�ڷ���)'�� �̸��� 'js'�� ���

    typedef float ss;
    // 'float'��� '�Ǽ���(�ڷ���)'�� �̸��� 'ss'�� ���

    js i_var = 3;
    // 'int i = 3;'�� ����
    // '[�ڷ���] [������]'�� ����

    ss f_var = 3.23f;
    // 'float f = 3.23f;'�� ����

    printf("�������� : %d, �Ǽ����� : %.2f\n", i_var, f_var);

    printf("\n");

    // typedef�� �̿��ؼ� '����ü���� ����'�� [�ڷ���] ����ϱ�

    typedef struct GameInfo GI;
    // '����ü���� ����'�� ����ϴ� 'struct GameInfo'(�ڷ���)��
    // 'GI'�� ���

    GI game1;
    // 'int i;'�� '[�ڷ���] [������]'�� ������ �ٸ��ٰ� ����

    game1.name = "�ѱ� ����";
    game1.year = 2015;
    game1.price = 350;
    game1.company = "�ѱ� ȸ��";

    printf("----- �ѱ� ���� ��� ����1 -----\n");
    printf("    ���Ӹ�      : %s\n", game1.name);
    printf("    �߸ų⵵    : %d\n", game1.year);
    printf("    ����        : %d\n", game1.price);
    printf("    ���ۻ�      : %s\n", game1.company);

    printf("\n");

    // typedef�� '����ü ����'�� �� ����ؼ�
    // '����ü���� ����'�� [�ڷ���] ����ϱ�

    GAME_INFO game2 = {"�ѱ� ����2", 2017, 360, "�ѱ� ȸ��2"};
    // typedef�� '����ü ����'�� ����ؼ� '�ڷ���'���� [����] ����
    // '�迭ó�� �ѹ��� �ʱ�ȭ'�� ������

    printf("----- �ѱ� ���� ��� ����2 -----\n");
    printf("    ���Ӹ�      : %s\n", game2.name);
    printf("    �߸ų⵵    : %d\n", game2.year);
    printf("    ����        : %d\n", game2.price);
    printf("    ���ۻ�      : %s\n", game2.company);

    printf("\n");

    struct GameInformation game3;
    // typedef�� '����ü ����'�� ����ؼ� '�ڷ���'���� [����] �����ص�
    // '[����]'�� 'struct [����ü��]'�� �Ѵ� ��� ����

    game3.name = "�ѱ� ����3";
    game3.year = 2020;
    game3.price = 400;
    game3.company = "�ѱ� ȸ��3";

    printf("----- �ѱ� ���� ��� ����3 -----\n");
    printf("    ���Ӹ�      : %s\n", game3.name);
    printf("    �߸ų⵵    : %d\n", game3.year);
    printf("    ����        : %d\n", game3.price);
    printf("    ���ۻ�      : %s\n", game3.company);

    printf("\n");

    GAME_INFO2 game4;
    // typedef�� '����ü ����'�� ����ؼ� '�ڷ���'���� [����] �����ϸ�
    // [����ü��]�� �����ص� ��([����]���� ��ü �����ؼ�)

    game4.name = "�ѱ� ����4";
    game4.year = 2023;
    game4.price = 550;
    game4.company = "�ѱ� ȸ��4";

    printf("----- �ѱ� ���� ��� ����4 -----\n");
    printf("    ���Ӹ�      : %s\n", game4.name);
    printf("    �߸ų⵵    : %d\n", game4.year);
    printf("    ����        : %d\n", game4.price);
    printf("    ���ۻ�      : %s\n", game4.company);

    return 0;
}