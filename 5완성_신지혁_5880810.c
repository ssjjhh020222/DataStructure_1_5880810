/*
ADT: PositiveIntegerCalculator
    연산: 덧셈(+), 뺄셈(-), 곱셈(*), 나눗셈(/)
    연산 대상: 양의 정수
    제약 조건:
        - 피연산자는 모두 양의 정수여야 함
        - 나눗셈 수행 시 0으로 나누는 경우는 허용하지 않음

함수 calculate(a, b, op):
    만약 a <= 0 또는 b <= 0이면
        오류 메시지 출력 및 종료
    만약 op == '+'이면
        반환 a + b  // 덧셈 수행
    만약 op == '-'이면
        반환 a - b  // 뺄셈 수행
    만약 op == '*'이면
        반환 a * b  // 곱셈 수행
    만약 op == '/'이면
        만약 b == 0이면
            오류 메시지 출력 및 종료
        반환 a / b  // 나눗셈 수행 (정수 나눗셈)
    반환 0  // 잘못된 연산자 입력 시
끝
*/

#pragma warning(disable:4996)
#include <stdio.h>

// ADT: PositiveIntegerCalculator
// 양의 정수만 다루는 사칙연산 함수
int calculate(int a, int b, char op) {
    if (a <= 0 || b <= 0) {
        printf("오류: 양의 정수만 입력 가능합니다.\n");
        return 0;
    }
    if (op == '+') return a + b; // 정수 덧셈 수행
    if (op == '-') return a - b; // 정수 뺄셈 수행
    if (op == '*') return a * b; // 정수 곱셈 수행
    if (op == '/') {
        if (b == 0) {
            printf("오류: 0으로 나눌 수 없습니다.\n");
            return 0;
        }
        return a / b; // 정수 나눗셈 수행
    }
    printf("오류: 지원되지 않는 연산자입니다.\n");
    return 0;
}

int main() {
    int a, b;
    char op;

    // 사용자에게 입력 받기
    printf("양의 정수와 연산자를 입력하세요 (예: 5 + 3): ");
    scanf("%d %c %d", &a, &op, &b);

    // 연산 및 결과 출력
    int result = calculate(a, b, op);
    printf("결과: %d\n", result);

    return 0;
}
