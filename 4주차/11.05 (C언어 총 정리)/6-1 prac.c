#include <stdio.h>

int main(void)
{
    // printf("Hello World \n");
    // printf("안녕 세상\n");

    // ##########친구들의 주소

    // 포인터

    int Cs = 1;
    int Yh = 2;
    int Ms = 3;

    printf("%d %d\n", Cs, &Cs);

    // ############미션맨(포인터)의 등장

    int *XMan;

    XMan = &Cs;

    printf("%d %d\n", XMan, *XMan);

    // 미션맨의 두 번째 미션 : 각 암호에 3을 곱해라

    *XMan = *XMan * 3;

    printf("%d %d\n", XMan, *XMan);

    // ############스파이(또다른 포인터)의 등장

    int *Spy = XMan;
    // XMan : Cs의 주소값(&Cs)

    printf("%d %d\n", Spy, *Spy);

    *Spy = *Spy - 2;

    printf("%d %d\n", Spy, *Spy);

    // '일반변수'를 출력해서 실제로 '특정변수의 값(value)'이 변경이 됐는지 확인하기
    printf("%d %d\n", Cs, &Cs);

    // 참고로.. 포인터변수의 메모리 주소는 '&포인터변수'로 확인 가능
    // 포인터변수는 다른 일반변수의 메모리 주소값을 저장
    // 포인터변수의 메모리 주소값도 따로 있음
    printf("%d %d\n", XMan, &XMan);
    printf("%d %d\n", Spy, &Spy);

    // #############배열과 포인터의 관계
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    // ptr(포인터변수)에 arr(배열의 시작주소값)을 초기화
    // arr == (arr + 0) == &arr[0] : 배열 arr의 첫번째 주소값(arr[0]의 주소값)

    for (int i = 0; i < 3; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("ptr[%d] : %d\n", i, ptr[i]);
    }
    // '포인터변수'는 '포인터변수[i]'를 이용해서 '포인터변수'에 저장된
    // '특정변수의 주소값'에서 i만큼 거리가 있는 '값'(value)에 접근이 가능함
    // (cf. '포인터변수'는 '*포인터변수'로 '특정변수의 값'(value)에 접근이 가능함)

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    // '포인터변수[i]'를 이용해서 '포인터변수'에 저장된
    // '특정변수의 주소값에서 i만큼 거리가 있는 값'(value)에 접근하면
    // 실제 '배열의 값'(value)이 변경되는 것을 출력으로 확인 가능

    for (int i = 0; i < 3; i++)
    {
        // printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
        printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i));
    }

    for (int i = 0; i < 3; i++)
    {
        // printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
        printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i));
    }
    // *(arr + i) == arr[i]
    // 둘은 서로 똑같은 표현임

    // arr이 결국 '특정 주소값[arr 배열의 첫번째 값의 주소]'을 의미하기 때문에
    // '*(arr + i)'은 '*(특정 주소값+i)'라서 특정 주소값에서 i만큼 떨어진 주소값을 가지는
    // 변수의 값(value)을 의미함
    // 'arr[i]'는 해당 배열(arr)에서 i번째에 해당되는 값(value)을 의미함
    // 결과적으로 '*(arr + i)'과 'arr[i]'은 같은 의미임

    // arr == &arr[0] : arr 배열의 첫번째 값의 주소
    printf("arr 자체의 값 : %d\n", arr);
    printf("arr[0]의 주소 : %d\n", &arr[0]);

    printf("arr 자체의 값(주소값)의 실제 값(value) : %d\n", *arr);
    // *arr == *(arr + 0)

    printf("arr[0] 주소(&arr[0])의 실제 값 : %d\n", *&arr[0]);

    printf("arr[0] 주소의 실제 값 : %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
    printf("arr[0] 주소의 실제 값 : %d\n", arr[0]);

    return 0;
}