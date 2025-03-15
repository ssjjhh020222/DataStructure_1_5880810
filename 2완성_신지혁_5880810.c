#include <stdio.h>

// 이진수 출력을 위한 함수
void print_binary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // 해당 비트를 오른쪽으로 이동시키고 1과 AND 연산
    }
}

int main() {
    float num; // 사용자 입력을 저장할 실수형 변수
    printf("실수를 입력하세요: ");
    scanf_s("%f", &num); // 실수 입력 받기

    // float 값을 unsigned int 형으로 해석하기 위한 포인터
    unsigned int* binary_rep = (unsigned int*)&num;

    // IEEE 754 표준에 따라 비트 분리
    unsigned int sign = (*binary_rep >> 31) & 1;      // 최상위 비트 (31번째 비트) → 부호
    unsigned int exponent = (*binary_rep >> 23) & 0xFF; // 23~30번째 비트 → 지수 (8비트)
    unsigned int mantissa = *binary_rep & 0x7FFFFF;   // 하위 23비트 → 가수

    // 부호 출력 (0: 양수, 1: 음수)
    printf("부호 (1비트) : %u\n", sign);

    // 지수 출력 (8비트)
    printf("지수 (8비트) : ");
    print_binary(exponent, 8);
    printf("\n");

    // 가수 출력 (23비트)
    printf("가수 (23비트) : ");
    print_binary(mantissa, 23);
    printf("\n");

    return 0;
}
