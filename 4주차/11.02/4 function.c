#include <stdio.h>

// #########계산기
// 함수 선언
// void func(int num);

// ########반환값이 없는 함수(매개변수 없는)
// void function_without_return();
// 반환값이 없어서 void

// #######반환값이 있는 함수(매개변수 없는)
// int function_with_return();
// 반환값이 있어서 반환형은 int

// ##########전달값이 없는 함수(반환값이 없는)
// void function_without_params();

// ##########전달값이 있는 함수(반환값이 없는)
// void function_with_params(int num1, int num2, int num3);

// ###########반환값과 전달값이 있는 함수
// int apple(int total, int ate);
// 전체 total 개에서 ate 개를 먹고 남은 수를 반환

// ##############함수를 이용한 계산기
// int add(int num1, int num2);
// int sub(int num1, int num2);
// int mul(int num1, int num2);
// int div(int num1, int num2);

int main(void)
{
    // printf("Hello World\n");

    // function
    // ##########계산기

    // int num = 2;
    // printf("num 은 %d 입니다\n", num);
    // 2출력

    // 2 + 3 은?
    // num = num + 3;
    // num += 3;

    // printf("num 은 %d 입니다\n", num);
    // 5출력

    // 5 - 1 은?
    // num -= 1;
    // num = num - 1;

    // printf("num 은 %d 입니다\n", num);
    // 4출력

    // 4 x 3 은?
    // num *= 3;
    // printf("num 은 %d 입니다\n", num);
    // 12출력

    // 12 / 6 은?
    // num /= 6;
    // printf("num 은 %d 입니다\n", num);
    // 2출력

    // 지금까지 사칙연산 하면서 매번 printf();를 사용하는데
    // 매번 반복해서 사용하는게 비효율적이기 때문에 함수가 필요

    // int num = 2;

    // printf("num 은 %d 입니다\n", num)
    // 사실 printf()도 함수임(C언어 기본 내장함수)

    // func(num);
    // func()은 내가 임의로 만든 함수임(사용자 정의 함수)

    // num += 3;
    // func(num);

    // num -= 1;
    // func(num);

    // num *= 3;
    // func(num);

    // num /= 6;
    // func(num);

    // #######함수의 형태
    // 메인함수 하단 참고

    // ########반환값이 없는 함수

    // 함수 종류
    // 반환값이 없는 함수
    // function_without_return();

    // ###########반환값이 있는 함수
    // int ret = function_with_return();
    // printf("%d\n", ret);
    // func(ret);

    // ##########전달값(매개변수)이 없는 함수
    // 매개변수(파라미터, 전달값, 인수 등)
    // function_without_params();

    // ########전달값(매개변수)이 있는 함수
    // function_with_params(35, 27, 14);

    // ########반환값과 전달값이 있는 함수
    // 매개변수(파라미터, 전달값)도 받고, 반환값도 보내주는 함수
    // int ret = apple(5,2);
    // 5개의 사과 중에서 2개를 먹었어요

    // printf("사과 5개 중에 2개를 먹으면? %d 개가 남아요\n", ret);
    // printf("사과 %d 개 중에 %d 개를 먹으면? %d 개가 남아요\n", 10, 4, apple(10,4));

    // ##############함수를 이용한 계산기
    // 계산기 함수
    // int num = 2;
    // num = add(num, 3);
    // func(num);

    // num = sub(num, 1);
    // func(num);

    // num = mul(num, 3);
    // func(num);

    // num = div(num, 6);
    // func(num);

    // ##################프로젝트4
    // 프로젝트4는 4 function_project.c 에서 할 것임

    return 0;
}

// ######계산기
// 함수 정의
// void func(int num) {
//     printf("num 은 %d 입니다\n", num);
// }

// ###########함수의 형태

// 전달값[매개변수] : ㅁ(36)
// 함수[내부 알고리즘] : ㅁ + 4
// 반환값 : o(40)

// 반환형 함수이름(전달형 전달값[매개변수]) {
//     return 반환값;
// }

// int function(int ㅁ) {
//     ㅇ = ㅁ + 4;
//     return o
// }
// function(36);

// void 함수이름(int num1, int num2, char c, float f) {

// }
// 이렇게 반환형이 없으면 void로 나타내면 됨
// 매개변수는 여러개 받을 수도 있음

// ###########반환값이 없는 함수(매개변수 없는)
// void function_without_return() {
//     printf("반환값이 없는 함수입니다\n");
// }

// ############반환값이 있는 함수(매개변수 없는)
// int function_with_return() {
//     printf("반환값이 있는 함수입니다\n");
//     return 10;
// }

// ##########전달값이 없는 함수(반환값이 없는)
// void function_without_params() {
//     printf("전달값이 없는 함수입니다\n");
// }

// ############전달값이 있는 함수(반환값이 없는)
// void function_with_params(int num1, int num2, int num3) {
//     printf("전달값이 있는 함수이며, 전달받은 값은 %d, %d, %d 입니다\n"
//     , num1, num2, num3);
// }

// ################반환값과 전달값이 있는 함수
// int apple(int total, int ate) {
//     printf("전달값과 반환값이 모두 있는 함수입니다\n");
//     return total - ate;
// }

// ##############함수를 이용한 계산기
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