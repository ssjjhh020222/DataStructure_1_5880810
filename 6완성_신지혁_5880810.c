/*
<의사코드>
START

// 에라토스테네스의 체 함수
FUNCTION findPrimes(N):
    IF N < 2:
        PRINT "소수가 없습니다."
        RETURN

    // 소수 여부를 저장하는 배열 만들기
    CREATE ARRAY is_prime[N+1] AND SET ALL VALUES TO TRUE
    SET is_prime[0] = FALSE
    SET is_prime[1] = FALSE  // 0과 1은 소수가 아님

    // 2부터 N까지 확인하며 소수 찾기
    FOR i FROM 2 TO sqrt(N):
        IF is_prime[i] IS TRUE:
            // i의 배수들을 전부 소수가 아니라고 표시
            FOR j FROM i * i TO N, STEP i:
                SET is_prime[j] = FALSE

    // 결과 출력
    PRINT "N 이하의 소수:"
    FOR i FROM 2 TO N:
        IF is_prime[i] IS TRUE:
            PRINT i

    // 사용한 메모리 정리
    FREE is_prime

END FUNCTION

MAIN:
    DECLARE INTEGER N
    PRINT "정수 N을 입력하세요: "
    READ N

    // 실행 시간 측정 시작
    START TIMER

    // 소수 찾기 함수 실행
    CALL findPrimes(N)

    // 실행 시간 측정 끝
    END TIMER
    CALCULATE TIME

    PRINT "실행 시간: ", elapsed_time, "초"

END
*/

#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void sieve_of_eratosthenes(int n) {
    if (n < 2) {
        printf("소수가 없습니다.\n");
        return;
    }

    bool* is_prime = (bool*)malloc((n + 1) * sizeof(bool));
    if (is_prime == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    // 배열 초기화
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 소수 출력
    printf("%d 이하의 소수: ", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime);
}

int main() {
    int n;
    printf("정수 n을 입력하세요: ");
    scanf("%d", &n);

    clock_t start_time = clock();  // 실행 시간 측정 시작

    sieve_of_eratosthenes(n);

    clock_t end_time = clock();  // 실행 시간 측정 종료
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("실행 시간: %.6f 초\n", elapsed_time);

    return 0;
}
