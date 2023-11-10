#include <stdio.h>

int main(void)
{

	// printf("Hello World\n");

	// ##################정수형 변수에 대한 예제
	//
	// 변수를 처음 선언할 때만 자료형을 써주면 됨
	/*int age = 12;
	printf("%d\n", age);*/

	// 변수는 값이 바뀔 수 있음
	/*age = 13;
	printf("%d\n", age);*/

	// 주석을 통해서 실행 안되게 할 수 있음
	// printf("1\n");
	// printf("2\n");	// 2는 범위에서 벗어나므로 주석 처리
	// printf("3\n");

	// #############실수형 변수에 대한 예제
	/*float f = 46.5f;
	printf("%f\n", f);*/

	// 소숫점을 결정하기
	// printf("%.2f\n", f);	// 소숫점 둘째자리까지로 변경

	/*double d = 4.428;
	printf("%lf\n", d);
	printf("%.2lf\n", d);*/

	// #####################상수
	// const int YEAR = 2000;  // 상수
	// printf("태어난 년도 : %d\n", YEAR);
	// YEAR = 2001;	// YEAR은 상수이기 때문에 변경 불가능

	// ####################printf
	// 연산
	// int add = 3 + 7;    //10
	// printf("3 + 7 = %d\n", add);
	// printf("%d + %d = %d\n", 3, 7, 3 + 7);
	// printf("%d + %d = %d\n", 30, 79, 30 + 79);
	// printf("%d x %d = %d\n", 30, 79, 30 * 79);

	// ########################scanf
	// 키보드 입력을 받아서 저장
	// int input;
	// printf("값을 입력하세요 : ");

	// scanf_s("%d", &input);
	// 입력받는다, 정수형을, input이라는 변수에
	// &input : input 변수의 주소에 값을 입력 받겠다

	// printf("입력값 : %d\n", input);

	// int one, two, three;
	// printf("3개의 정수를 입력하세요 : ");
	// scanf_s("%d %d %d", &one, &two, &three);
	// printf("첫번째 값 : %d\n", one);
	// printf("두번째 값 : %d\n", two);
	// printf("세번째 값 : %d\n", three);

	// 문자형을 입력받기
	// 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	// char c = 'A';
	// printf("%c\n", c);

	// 문자열

	// char str[256];
	// char c 같은 문자 하나를 저장할 수 있는 변수를
	// 256개를 쭉 이어서 배열로 만듦(배열 뒤에서 자세히)

	// scanf_s("%s", str, sizeof(str));
	// 문자열은 %s
	// 문자열로 받을 때에는 &를 이용해서 주소로 받을 필요 없음(정확히는 str로 주소를 보냄)
	// sizeof()를 이용해서 str[256]만큼만 받을 거라고 명시

	// printf("%s\n", str);

	// ################프로젝트1
	// 경찰관이 범죄자의 정보를 입수 (조서 작성)
	// 이름? 나이? 몸무게? 키? 범죄명?
	char name[256];
	int age;
	float weight;
	double height;
	char reason[256];

	printf("이름이 뭐냐 : ");
	scanf_s("%s", name, sizeof(name));
	printf("나이가 몇이냐 : ");
	scanf_s("%d", &age);
	printf("몸무게가 몇이냐 : ");
	scanf_s("%f", &weight);
	printf("키가 몇이냐 : ");
	scanf_s("%lf", &height);
	printf("범죄명이 뭐냐 : ");
	scanf_s("%s", reason, sizeof(reason));

	// 조서 내용 출력
	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf("범죄자의 이름은 %s 입니다\n", name);
	printf("나이는 %d살 이구요\n", age);
	printf("몸무게는 %.1fkg 이라네요\n", weight);
	printf("키는 %.2lf정도 된답니다\n", height);
	printf("자기 말로는 %s를 저질렀다네요\n", reason);

	return 0;
}