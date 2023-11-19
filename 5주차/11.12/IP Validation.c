#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_valid_ip(const char *addr)
{

    // Your code here...
    // 숫자.숫자.숫자.숫자 로 들어오면 됨
    // 09 이런거는 안됨

    data_index = 3;

    for (int i = 0; i < strlen(addr); i++)
    {
        if (addr[i] == '.')
        {
            // printf("true\n");
            // return true;

            // i이전까지 짜르기
        }
    }
}

int main(void)
{
    is_valid_ip("123.45.67.89");
    is_valid_ip("123.456.78.90");
    return 0;
}