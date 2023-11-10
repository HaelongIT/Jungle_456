#include <stdio.h>

int main(void) {
    printf("Hello World\n");

    char str[256];
    scanf_s("%s", str, sizeof(str));
    printf("%s\n", str+1);
    // 배열로 문자열을 받은 경우에도 시작주소값으로 출력시킴

    return 0;
}