#include <stdio.h>
#include <time.h>

int main(void) {
    // printf("Hello World\n");

    // #############프로젝트5
    // 여러 물약 조합을 보면서 발모제(랜덤)를 찾는 게임

    // 내 코드
    srand(time(NULL));
    
    printf("\n\n === 아빠는 대머리 게임 === \n\n");

    int ans = rand() % 4;
    // printf("%d\n", ans);

    int cnt = rand() % 3+1;

    int bot[4] = {0, 0, 0, 0};

    bot[ans] = 1;

    for(int i = 0; i < 3; i++) {
        // printf("%d\n", bot[i]);
        for(int j = 0; j < cnt; j++) {
            printf("%d번 약");
        }
        
    }

    // 정답코드
    // srand(time(NULL));
    // printf("\n\n === 아빠는 대머리 게임 === \n\n");


    return 0;
}