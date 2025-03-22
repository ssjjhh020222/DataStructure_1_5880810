/*
<의사코드>
START

// 숫자 2개를 저장하는 구조체 만들기
DEFINE STRUCT Numbers:
    INTEGER num1
    INTEGER num2

// 더하기 함수
FUNCTION add(Numbers nums):
    RETURN nums.num1 + nums.num2

// 빼기 함수
FUNCTION subtract(Numbers nums):
    RETURN nums.num1 - nums.num2

// 곱하기 함수
FUNCTION multiply(Numbers nums):
    RETURN nums.num1 * nums.num2

// 나누기 함수 (0이면 오류 메시지 출력)
FUNCTION divide(Numbers nums):
    IF nums.num2 = 0:
        PRINT "0으로 나누기 불가능!"
        RETURN 0
    ELSE:
        RETURN nums.num1 / nums.num2

// 계산 수식 입력받아서 처리하는 함수
FUNCTION evaluateExpression(STRING expression):
    TRY TO CALCULATE expression
    IF FAIL:
        PRINT "잘못된 수식!"
        RETURN 0
    ELSE:
        RETURN RESULT

MAIN:
    // 숫자 저장할 변수 만들기
    DECLARE Numbers nums
    DECLARE STRING expression

    // 숫자 입력받기
    PRINT "첫 번째 숫자 입력: "
    READ nums.num1

    PRINT "두 번째 숫자 입력: "
    READ nums.num2

    // 실행 시간 측정 시작
    START TIMER

    // 사칙연산 결과 출력
    PRINT "더하기: ", add(nums)
    PRINT "빼기: ", subtract(nums)
    PRINT "곱하기: ", multiply(nums)
    PRINT "나누기: ", divide(nums)

    // 실행 시간 측정 끝
    END TIMER
    CALCULATE TIME

    // 사용자에게 수식 입력받고 계산
    PRINT "계산할 식 입력하세요 (예: 3 + 5 * 2 - 8 / 4): "
    READ expression
    PRINT "계산 결과: ", evaluateExpression(expression)

    // 실행 시간 출력
    PRINT "실행 시간: ", elapsed_time, "초"

END
*/

#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int num1;
    int num2;
} Numbers;

int add(Numbers nums) {
    return nums.num1 + nums.num2;
}

int subtract(Numbers nums) {
    return nums.num1 - nums.num2;
}

int multiply(Numbers nums) {
    return nums.num1 * nums.num2;
}

double divide(Numbers nums) {
    if (nums.num2 == 0) {
        printf("오류: 0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return (double)nums.num1 / nums.num2;
}

double evaluateExpression(char* expression) {
    double result = 0.0;
    if (sscanf(expression, "%lf", &result) != 1) {
        printf("잘못된 수식입니다.\n");
        return 0;
    }
    return result;
}

int main() {
    Numbers nums;
    char expression[100];

    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf("%d", &nums.num1);

    printf("두 번째 양의 정수를 입력하세요: ");
    scanf("%d", &nums.num2);

    clock_t start_time = clock(); // 실행 시간 측정 시작

    printf("덧셈: %d\n", add(nums));
    printf("뺄셈: %d\n", subtract(nums));
    printf("곱셈: %d\n", multiply(nums));
    printf("나눗셈: %.2lf\n", divide(nums));

    clock_t end_time = clock(); // 실행 시간 측정 종료
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
    scanf(" %[^\n]s", expression);

    printf("결과: %.6lf\n", evaluateExpression(expression));
    printf("실행 시간: %.6f 초\n", elapsed_time);

    return 0;
}
