#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    // printf("Hello World\n");

    // ########### if else
    // if (조건) { ... } else { ... }

    // 버스를 탄다고 가정
    // 학생/일반인으로 구분 (일반인 : 20세 이상)
    // int age = 15;
    // int age = 25;

    // if (age >= 20) {
    //     printf("일반인 입니다\n");
    // }
    // else {
    //     printf("학생입니다\n");
    // }

    // 초등학생(8-13)/중학생(14-16)/고등학생(17-19)으로 나누면?
    // if / else if / else
    // int age = 25;
    // if (age >= 8 && age <= 13) {
    //     printf("초등학생입니다\n");
    // }
    // else if (age >= 14 && age <= 16) {
    //     printf("중학생입니다\n");
    // }
    // else if (age >= 17 && age <= 19) {
    //     printf("고등학생입니다\n");
    // }
    // else {
    //     printf("학생이 아닌가봐요\n");
    // }

    // ########## break / continue
    // 1번부터 30번까지 있는 반에서 1번에서 5번까지
    // 조별 발표를 합니다.
    // for (int i = 1; i <=30; i++) {
    //     if (i >= 6) {
    //         printf("나머지 학생은 집에 가세요\n");
    //         break;
    //     }
    //     printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
    // }

    // 1번부터 30번까지 있는 반에서 7번 학생은 아파서 결석
    // 7번을 제외하고 6번부터 10번까지 조별 발표를 하세요

    // 내 코드
    // for (int st = 1; st <= 30; st++) {
    //     if (st >= 6 && st <= 10) {
    //         if (st == 7) {
    //             continue;
    //         }
    //         printf("%d 번의 발표\n", st);
    //     }
    // }

    // 정답 코드
    // for (int i = 1; i <=30; i++) {
    //     if (i >= 6 && i <= 10) {
    //         if (i == 7) {
    //             printf("%d 번 학생은 결석입니다\n", i);
    //             continue;
    //         }
    //         printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
    //     }
    // }

    // ############ and(&&) / or(||)
    // int a = 10;
    // int b = 11;
    // int c = 13;
    // int d = 13;
    // if (a == b && c == d) {
    //     printf("a 와 b 는 같고, (동시에) c 와 d 도 같습니다\n");
    // }
    // else if (a == b || c == d) {
    //     printf("a 와 b, 혹은 (둘중 하나라도) c 와 d 의 값이 같습니다\n");
    // }
    // else {
    //     printf("값이 서로 다르네요\n");
    // }

    // ##############랜덤
    // 3 random.c 에서 따로 공부함

    // ############# switch case

    // 가위(0) / 바위(1) / 보(2)

    // srand(time(NULL));
    // 난수 초기화

    // int i = rand() % 3;
    // 0~2 사이의 숫자 랜덤으로 반환

    // if (i == 0) {
    //     printf("가위\n");
    // }
    // else if (i == 1) {
    //     printf("바위\n");
    // }
    // else if (i == 2) {
    //     printf("보\n");
    // }
    // else {
    //     printf("몰라요\n");
    // }

    // switch를 이용해서도 가위,바위, 보
    // 가능함
    // srand(time(NULL));

    // int i = rand() % 3;

    // int i = 0;
    // 각 case에 break;가 없으면 해당되는 case 이후의
    // 나머지 case들은 무지성으로 실행됨

    // switch (i) {

    //     case 0:
    //         printf("가위\n");
    //         break;
    //     case 1:
    //         printf("바위\n");
    //         break;
    //     case 2: printf("보\n"); break;
    //     default: printf("몰라요\n"); break;
    // }

    // 초등학생(8-13)/중학생(14-16)/고등학생(17-19)으로
    // 나누면? (switch case로 해보기)

    // srand(time(NULL));

    // int age = rand() % 30;
    // printf("%d 살\n", age);

    // switch (age) {
    //     case 1: printf("미취학 아동\n"); break;
    //     case 2: printf("미취학 아동\n"); break;
    //     case 3: printf("미취학 아동\n"); break;
    //     case 4: printf("미취학 아동\n"); break;
    //     case 5: printf("미취학 아동\n"); break;
    //     case 6: printf("미취학 아동\n"); break;
    //     case 7: printf("미취학 아동\n"); break;
    //     case 8:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 9:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 10:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 11:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 12:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 13:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 14: printf("중학생입니다\n"); break;
    //     case 15: printf("중학생입니다\n"); break;
    //     case 16: printf("중학생입니다\n"); break;
    //     case 17: printf("고등학생입니다\n"); break;
    //     case 18: printf("고등학생입니다\n"); break;
    //     case 19: printf("고등학생입니다\n"); break;
    //     default:
    //         printf("학생이 아닌가봐요\n");
    //         break;
    // }

    // break;를 이용해서 case의 조건 만들기
    // srand(time(NULL));

    // int age = rand() % 30;
    // printf("%d 살\n", age);

    // switch (age) {
    //     case 1:
    //     case 2:
    //     case 3:
    //     case 4:
    //     case 5:
    //     case 6:
    //     case 7: printf("미취학 아동\n"); break;
    //     case 8:
    //     case 9:
    //     case 10:
    //     case 11:
    //     case 12:
    //     case 13:
    //         printf("초등학생입니다\n");
    //         break;
    //     case 14:
    //     case 15:
    //     case 16: printf("중학생입니다\n"); break;
    //     case 17:
    //     case 18:
    //     case 19: printf("고등학생입니다\n"); break;
    //     default:
    //         printf("학생이 아닌가봐요\n");
    //         break;
    // }

    // ############프로젝트3
    // Up and Down

    // 내 코드
    // srand(time(NULL));
    // int ai_num = rand() % 100 + 1;
    // printf("%d\n", ai_num);

    // 기회를 10번으로 제한해서 줘야함
    // for (int i = 0; i < 10; i++) {

    //     int my_num;
    //     printf("숫자를 맞춰보시오(1~100) : ");
    //     scanf_s("%d", &my_num);
    //     // printf("%d\n", my_num);

    //     if (my_num == ai_num) {
    //         printf("정답입니다\n");
    //         break;
    //     }
    //     else if (my_num > ai_num) {
    //         printf("Down\n");
    //     }
    //     else if (my_num < ai_num) {
    //         printf("Up\n");
    //     }
    //     else {
    //         printf("오류상황\n");
    //     }
    // }

    // 정답코드

    srand(time(NULL));
    int num = rand() % 100 + 1;
    // 난수초기화 하고 1~100 사이의 랜덤수 반환

    printf("컴퓨터가 뽑은 숫자 : %d\n", num);

    int answer = 0;
    // 정답 저장할 변수

    int chance = 5;
    // 기회는 5번

    while (chance > 0)
    {
        // 무한루프에서 탈출조건(break;) 따로 만들거면
        // while (1) {...}으로 해도 됨

        // 1 : 참, 0 : 거짓

        printf("남은 기회 %d 번\n", chance--);
        // 남은 기회를 출력하고 이후에 -1씩 하기

        printf("숫자를 맞혀보세요 (1~100) : ");
        scanf_s("%d", &answer);

        if (answer > num)
        {
            printf("DOWN ↓\n\n");
        }
        else if (answer < num)
        {
            printf("UP ↑\n\n");
        }
        else if (answer == num)
        {
            printf("정답입니다!! \n");
            printf("축하합니다. 기회를 %d번 남기고 성공\n\n", chance);
            break;
            // 정답일 경우에는 전체 loop에서 탈출함
        }
        else
        {
            printf("알 수 없는 오류가 발생했어요\n\n");
        }

        if (chance == 0)
        {
            printf("모든 기회를 다 사용하셨네요. 아쉽게 실패했습니다\n");
            break;
        }
        // while의 조건이 0보다 클 경우라 사실 필요는 없는 부분
        // 무한루프에서 탈출할수 있는 부분이기 때문에 while의
        // 조건을 1로 해도됨
    }

    return 0;
}