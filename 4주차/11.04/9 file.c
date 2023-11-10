#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 10000
// 상수 MAX를 10000으로 정의함

int main(void)
{
    // #####################파일 쓰기 fputs

    // 파일 입출력
    // 파일에 어떤 데이터를 저장하고,
    // 파일에 저장된 데이터를 불러오기

    // fputs, fgets 쌍 -> 문자열 저장

    char line[MAX];
    // char line[10000]; 과 같음

    // 파일에 쓰기

    // FILE *file = fopen("C:\\Users\\손용재\\Desktop\\개발자\\정글\\4주차\\11.04\\test1.txt", "wb");
    // FILE : 구조체의 별명임(typedef)
    // file : 구조체 FILE의 포인터변수

    // fopen() : 성공적으로 파일이 열리면 '파일 포인터' 반환
    // 실패하면 NULL이 반환

    // 파일 포인터 : 파일을 조작하기 위한 핸들 또는 파일에 대한 정보를 가리키는 포인터

    // r(읽기 전용), w(쓰기 전용), a(이어쓰기 전용)
    // t(텍스트 데이터), b(바이너리 데이터)

    // if (file == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    //     // 프로그램 종료하기
    // }

    // fputs("I will write this using fputs\n", file);
    // fputs("Please make sure it is written well\n", file);
    // fputs()에서 파일포인터를 이용해서 파일에 텍스트 내용을 작성한다

    // 파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면?
    // 데이터 손실 발생 가능 !
    // 그래서 항상 파일을 닫아주는 습관을 들여주세요
    // fclose(file);
    // 파일을 저장하고 닫는다

    // ############파일 읽기 fgets

    // 파일 읽기

    // FILE *file = fopen("C:\\Users\\손용재\\Desktop\\개발자\\정글\\4주차\\11.04\\test1.txt", "rb");
    // // fopen을 '읽기 전용'(rb)으로 열기

    // if (file == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // while (fgets(line, MAX, file) != NULL)
    // {
    //     printf("%s", line);
    // }
    // fgets : '저장될 곳, 사이즈, 파일포인터'를 매개변수로 주면 '저장될 곳'에 텍스트 내용을 반환한다

    // ###########또다른 파일 쓰기 fprintf

    // fprintf, fscanf 쌍 -> 정형화된 포맷에 대해서 파일을 읽고 쓸 때 사용
    // (printf, scanf 쌍과 비슷한 모양새 : 정형화된 포맷에 대해서 파일을 읽고 쓸 때 사용)
    // printf("%d %d %s ...")
    // scanf("%d %d", &num1, ...)

    int num[6] = {0,
                  0,
                  0,
                  0,
                  0,
                  0};
    // 로또 추첨번호

    int bonus = 0;
    // 보너스 번호

    char str1[MAX];
    char str2[MAX];

    // 파일에 쓰기
    // FILE *file = fopen("C:\\Users\\손용재\\Desktop\\개발자\\정글\\4주차\\11.04\\test2.txt", "wb");

    // if (file == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // // 로또 추첨 번호 저장
    // fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
    // fprintf(file, "%s %d\n", "보너스번호", 7);

    // fclose(file);

    // #############또다른 파일 읽기 fscanf

    // 파일 읽기

    FILE *file = fopen("C:\\Users\\손용재\\Desktop\\개발자\\정글\\4주차\\11.04\\test2.txt", "rb");

    if (file == NULL)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

    fscanf(file, "%s %d", str2, &bonus);
    printf("%s %d\n", str2, bonus);

    fclose(file);

    return 0;
}