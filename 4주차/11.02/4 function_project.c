#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNum(int level);

void showQuestion(int level, int num1, int num2);

void success();
void fail();

int main(void) {
// 매개변수(전달값)이 없는(void) main이라는 이름을 가진 함수이고
// 정수형(int) 자료를 반환값으로 가진다

    // printf("Hello World\n");

    // #############프로젝트4
    // 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤출제)
    // 맞히면 통과, 틀리면 실패

    // 내 코드

    // srand(time(NULL));
    // 난수 초기화

    // for (int i = 1; i <= 5; i++) {
    //     printf("%d 번째 문제 시작\n", i);

    //     int ans;
    //     int num1 = rand() % 20*i + 1;
    //     int num2 = rand() % 20*i + 1;

    //     printf("%d x %d = ? : ", num1, num2);
    //     scanf_s("%d", &ans);
        
    //     if (ans == (num1*num2)) {
    //         if (i == 5) {
    //             printf("축하합니다. 모든 문제를 맞췄습니다. 당신은 비밀번호 마스터!\n");
    //             break;
    //         }

    //         printf("정답이군! 다음 문제로!\n\n");
    //     }
    //     else {
    //         printf("실패로군!\n");
    //         break;
    //     }
    // }

    // 정답코드
    // 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤출제)
    // 맞히면 통과, 틀리면 실패
    // 프로젝트 변경점 : 5문제 풀다가 중간에 틀리면 끝나는게 아니고
    // 총 5번의 기회에서 몇번 맞췄는지 세어서 알려줌
    // 중간에 틀리면 종료하게 하려면 실패 조건문에서 break;를 사용하면 됨

    srand(time(NULL));

    int count = 0;
    // 맞힌 문제 갯수

    for (int i = 1; i <= 5; i++) {
        // 수식 : x * y = ?
        int num1 = getRandomNum(i);
        int num2 = getRandomNum(i);
        // 함수1 : 랜덤으로 숫자를 뽑아주는 함수(i를 이용해서 비례하게 큰 숫자를 뽑기)

        // printf("%d x %d ?", num1, num2);
        showQuestion(i, num1, num2);
        // 'i번째 문제'와 "%d x %d ?"를 출력해주는 함수

        int answer = -1;
        scanf_s("%d", &answer);

        if(answer == -1) {
            printf("프로그램을 종료합니다\n");

            // break;
            // 전체루프를 끝내고 '당신은 5개의 비밀번호 중 %d 개를 맞혔습니다'가 출력되면 어색
            exit(0);
            // 프로그램 자체를 끝내면 문장('당신은 5개의 비밀번호 중 %d 개를 맞혔습니다') 출력될 게 없으니 자연스러움

            // 입력자가 종료를 원한다면 -1을 입력해서 프로그램 종료
        }
        else if(answer == num1 * num2) {
            // 성공일 경우

            success();

            count++;
            // 총 맞춘 문제의 갯수 세는 변수
        }
        else {
            // 실패한 경우

            fail();
        }

    }

    printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맞혔습니다\n", count);

    return 0;
}

int getRandomNum(int level) {
    return rand() % (level*20) + 1;
}

void showQuestion(int level, int num1, int num2) {
    // printf("%d 번째 문제 : %d x %d ? \n", level, num1, num2);
    printf("\n\n\n############# %d 번째 비밀번호 ################\n", level);
    printf("\n\t %d x %d 는? \n\n", num1, num2);
    printf("##############################################\n");
    printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}

void success() {
    printf("\n >> Good ! 정답입니다 \n");
}
void fail() {
    
    printf("\n >> 땡 ! 틀렸습니다 \n");
}