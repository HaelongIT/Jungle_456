#include <stdio.h>
#include <time.h>

int main(void) {
    // printf("Hello World\n");

    // #############������Ʈ5
    // ���� ���� ������ ���鼭 �߸���(����)�� ã�� ����

    // �� �ڵ�
    srand(time(NULL));
    
    printf("\n\n === �ƺ��� ��Ӹ� ���� === \n\n");

    int ans = rand() % 4;
    // printf("%d\n", ans);

    int cnt = rand() % 3+1;

    int bot[4] = {0, 0, 0, 0};

    bot[ans] = 1;

    for(int i = 0; i < 3; i++) {
        // printf("%d\n", bot[i]);
        for(int j = 0; j < cnt; j++) {
            printf("%d�� ��");
        }
        
    }

    // �����ڵ�
    // srand(time(NULL));
    // printf("\n\n === �ƺ��� ��Ӹ� ���� === \n\n");


    return 0;
}