#include <stdio.h>

int main()
{
    // printf("Hello World \n");
    // printf("안녕 세상\n");

    // ######################## scanf
    int input;
    printf("값을 입력하세요 : ");

    scanf("%d", &input);
    // input으로 받으면 call by value라서 제대로 바뀌지가 않는다

    printf("%d\n", input);

    int one, two, three;

    printf("3개의 정수를 입력하시오 : ");
    scanf("%d %d %d", &one, &two, &three);
    printf("입력받은 정수 3개는 %d %d %d 입니다\n", one, two, three);

    // 문자형을 입력받기(한 글자)
    char c;
    printf("한글자만 입력하시오 : ");

    getchar();
    // 입력 버퍼 비우기

    scanf("%c", &c);
    printf("%c\n", c);

    // 문자열을 입력받기(여러 글자)
    char str[256];
    printf("문자열을 입력하시오 : ");
    scanf("%s", str);
    // str : str[256]의 시작 주소값

    printf("%s\n", str);
    // 시작 주소값부터 NULL 종료를 만날 때 까지 출력된다

    return 0;
}