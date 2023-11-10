#include <stdio.h>

int main()
{
    // printf("Hello World \n");
    // printf("안녕 세상\n");

    // #############실수형 변수에 대한 예제
    float f = 46.5f;
    // float는 실수형 숫자 뒤에 명시적으로 f를 붙여줘야 함
    printf("%.2f\n", f);

    double d = 4.429;
    printf("%.3lf\n", d);

    return 0;
}