#define _CRT_SECURE_NO_WARNINGS  // scanf 사용 시 경고 방지 (MSVC 환경에서 필요)

#include <stdio.h>  // 표준 입출력 라이브러리 포함

int main() {
    int num;  // 음수를 저장할 정수 변수 선언
    printf("음수를 입력하세요: ");  // 사용자에게 입력 요청
    scanf("%d", &num);  // 사용자로부터 정수 입력 받기

    unsigned int uNum = (unsigned int)num;  // num을 부호 없는 정수(unsigned int)로 변환

    printf("비트 표현: ");  // 비트 표현 출력 시작
    for (int i = 31; i >= 0; i--) {  // 32비트 정수의 각 비트를 출력하는 반복문
        printf("%d", (uNum >> i) & 1);  // i번째 비트를 추출하여 출력
    }
    printf("\n");  // 줄 바꿈

    return 0;  // 프로그램 종료
}
