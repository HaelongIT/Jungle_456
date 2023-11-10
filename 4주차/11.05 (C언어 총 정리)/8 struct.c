#include <stdio.h>

struct GameInfo {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
    // 연관 업체 게임

    // '구조체'(GameInfo)를 '선언'할 때 '그 구조체'(GameInfo) 안에
    // '그 구조체'(GameInfo)를 '구조체내 변수'(friendGame)로 '생성'함
    // ('struct GameInfo'가 [자료형]이고, 'friendGame'이 [구조체 포인터변수명]임)
};

typedef struct GameInformation {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
} GAME_INFO;

typedef struct {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame;
} GAME_INFO2;

int main(void) {
    // printf("Hello World\n");

    // ##########구조체 기본
    
    // [게임 출시]
    // 이름 : 나도게임
    // 발매년도 : 2017년
    // 가격 : 50원
    // 제작사 : 나도회사

    char * name = "나도게임";
    int year = 2017;
    int price = 50;
    char * company = "나도회사";

    // [또다른 게임 출시]
    // 이름 : 너도게임
    // 발매년도 : 2017년
    // 가격 : 100원
    // 제작사 : 너도회사

    char * name2 = "너도게임";
    int year2 = 2017;
    int price2 = 100;
    char * company2 = "너도회사";
    // 세트로 사용되는 변수들이 하나로 통합적으로 관리되면 좋겠는데
    // 따로 변수로 관리되니 복잡함

    // ###############구조체 사용

    // 구조체 사용(개별로 초기화)
    struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";

    struct GameInfo gameInfo2;
    gameInfo2.name = "너도게임";
    gameInfo2.year = 2017;
    gameInfo2.price = 100;
    gameInfo2.company = "너도회사";

    // 구조체 출력
    printf("----- 게임 출시 정보 -----\n");
    printf("    게임명      : %s\n", gameInfo1.name);
    printf("    발매년도    : %d\n", gameInfo1.year);
    printf("    가격        : %d\n", gameInfo1.price);
    printf("    제작사      : %s\n", gameInfo1.company);

    printf("\n");

    printf("----- 또다른 게임 출시 정보 -----\n");
    printf("    게임명      : %s\n", gameInfo2.name);
    printf("    발매년도    : %d\n", gameInfo2.year);
    printf("    가격        : %d\n", gameInfo2.price);
    printf("    제작사      : %s\n", gameInfo2.company);

    printf("\n");

    // 구조체를 배열처럼 초기화(한번에 초기화)
    struct GameInfo gameInfo3 = {"배틀그라운드", 2019, 300, "크래프톤"};
    printf("----- 또다른 게임 출시 정보 -----\n");
    printf("    게임명      : %s\n", gameInfo3.name);
    printf("    발매년도    : %d\n", gameInfo3.year);
    printf("    가격        : %d\n", gameInfo3.price);
    printf("    제작사      : %s\n", gameInfo3.company);

    printf("\n");

    // #########구조체 배열
    
    // 구조체 배열
    struct GameInfo gameArray[2] = {
        {"배틀그라운드", 2019, 300, "크래프톤"},
        {"디아블로4", 2021, 400, "블리자드"}
    };
    // 기존 '구조체를 배열처럼 초기화'는 '1차원 배열'과 같고
    // '구조체 배열'은 '2차원 배열'과 같음

    printf("----- 내년 중요 게임 출시 목록 -----\n");
    printf("    게임명1      : %s\n", gameArray[0].name);
    printf("    게임명2      : %s\n", gameArray[1].name);

    printf("\n");
    
    // #########구조체 포인터

    // 구조체 포인터변수
    struct GameInfo * gamePtr;
    // 미션맨('구조체 포인터변수' : '구조체변수'를 '포인터변수'로 선언)
    
    // 구조체 포인터변수 초기화
    gamePtr = &gameInfo1;
    // '구조체 포인터변수'에는 '특정 구조체 일반변수'의 '주소값'을 저장함

    // 구조체 포인터변수 출력1
    printf("----- 미션맨의 게임 출시 정보1 -----\n");
    printf("    게임명      : %s\n", (*gamePtr).name);
    printf("    발매년도    : %d\n", (*gamePtr).year);
    printf("    가격        : %d\n", (*gamePtr).price);
    printf("    제작사      : %s\n", (*gamePtr).company);
    
    // '포인터변수'를 'int * ptr = &[일반변수];'로 생성했다면
    // 'ptr'은 '포인터변수'로 '특정한 일반변수의 주소값'을 가지고
    // '*ptr'은 '특정한 일반변수의 값'(value)에 접근 가능함

    printf("\n");

    // 구조체 포인터변수 출력2
    struct GameInfo * gamePtr2;
    gamePtr2 = &gameInfo2;

    printf("----- 미션맨의 게임 출시 정보2 -----\n");
    printf("    게임명      : %s\n", gamePtr2->name);
    printf("    발매년도    : %d\n", gamePtr2->year);
    printf("    가격        : %d\n", gamePtr2->price);
    printf("    제작사      : %s\n", gamePtr2->company);
    // '구조체 포인터변수'가 '특정한 구조체 일반변수'의 '값'(value)에 접근할 때
    // '[구조체 포인터변수명]->[구조체내 변수명]'을 사용함

    printf("\n");

    // ##########구조체 안의 구조체

    // 연관 업체 게임 소개
    gameInfo1.friendGame = &gameInfo3;
    // 앞에서 '생성'했던 '구조체변수'(gameInfo1)의 '구조체내 변수' 중
    // '구조체 포인터변수'(friendGame)가 있음
    // ('구조체 포인터변수'라서 특정 '구조체의 주소값'을 초기화함)

    printf("----- 연관 업체의 게임 출시 정보 -----\n");
    printf("    게임명      : %s\n", gameInfo1.friendGame->name);
    printf("    발매년도    : %d\n", gameInfo1.friendGame->year);
    printf("    가격        : %d\n", gameInfo1.friendGame->price);
    printf("    제작사      : %s\n", gameInfo1.friendGame->company);

    printf("\n");

    // ############ typedef

    // typedef
    // 자료형에 별명 지정

    int i = 1;
    // int : 정수형(자료형)
    // i : 정수형 변수

    typedef int js;
    // 'int'라는 '정수형(자료형)'의 이름을 'js'로 축약

    typedef float ss;
    // 'float'라는 '실수형(자료형)'의 이름을 'ss'로 축약

    js i_var = 3;
    // 'int i = 3;'과 같음
    // '[자료형] [변수명]'의 구조

    ss f_var = 3.23f;
    // 'float f = 3.23f;'와 같음

    printf("정수변수 : %d, 실수변수 : %.2f\n", i_var, f_var);

    printf("\n");

    // typedef을 이용해서 '구조체변수 생성'시 [자료형] 축약하기

    typedef struct GameInfo GI;
    // '구조체변수 생성'시 사용하는 'struct GameInfo'(자료형)을
    // 'GI'로 축약

    GI game1;
    // 'int i;'와 '[자료형] [변수명]'의 구조가 다를바가 없음

    game1.name = "한글 게임";
    game1.year = 2015;
    game1.price = 350;
    game1.company = "한국 회사";

    printf("----- 한글 게임 출시 정보1 -----\n");
    printf("    게임명      : %s\n", game1.name);
    printf("    발매년도    : %d\n", game1.year);
    printf("    가격        : %d\n", game1.price);
    printf("    제작사      : %s\n", game1.company);

    printf("\n");

    // typedef을 '구조체 선언'할 때 사용해서
    // '구조체변수 생성'시 [자료형] 축약하기

    GAME_INFO game2 = {"한글 게임2", 2017, 360, "한국 회사2"};
    // typedef을 '구조체 선언'시 사용해서 '자료형'으로 [별명] 지정
    // '배열처럼 한번에 초기화'도 가능함

    printf("----- 한글 게임 출시 정보2 -----\n");
    printf("    게임명      : %s\n", game2.name);
    printf("    발매년도    : %d\n", game2.year);
    printf("    가격        : %d\n", game2.price);
    printf("    제작사      : %s\n", game2.company);

    printf("\n");

    struct GameInformation game3;
    // typedef을 '구조체 선언'시 사용해서 '자료형'으로 [별명] 지정해도
    // '[별명]'과 'struct [구조체명]'은 둘다 사용 가능

    game3.name = "한글 게임3";
    game3.year = 2020;
    game3.price = 400;
    game3.company = "한국 회사3";

    printf("----- 한글 게임 출시 정보3 -----\n");
    printf("    게임명      : %s\n", game3.name);
    printf("    발매년도    : %d\n", game3.year);
    printf("    가격        : %d\n", game3.price);
    printf("    제작사      : %s\n", game3.company);

    printf("\n");

    GAME_INFO2 game4;
    // typedef을 '구조체 선언'시 사용해서 '자료형'으로 [별명] 지정하면
    // [구조체명]은 생략해도 됨([별명]으로 대체 가능해서)

    game4.name = "한글 게임4";
    game4.year = 2023;
    game4.price = 550;
    game4.company = "한국 회사4";

    printf("----- 한글 게임 출시 정보4 -----\n");
    printf("    게임명      : %s\n", game4.name);
    printf("    발매년도    : %d\n", game4.year);
    printf("    가격        : %d\n", game4.price);
    printf("    제작사      : %s\n", game4.company);

    return 0;
}