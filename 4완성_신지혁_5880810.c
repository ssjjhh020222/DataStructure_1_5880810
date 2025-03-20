/* 
 함수 is_prime(num):
    만약 num < 2이면
        반환 0  // 2 미만의 수는 소수가 아님
    끝
    i를 2부터 num의 제곱근까지 반복:
        만약 num이 i로 나누어 떨어지면
            반환 0  // 소수가 아님
        끝
    끝
    반환 1  // 소수임
끝
*/

#include <stdio.h>
#pragma warning(disable:4996) 

// 소수를 판별하는 함수
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;

    // 사용자에게 정수 입력 받기
    printf("정수를 입력하세요: ");
    scanf("%d", &N);

    printf("%d 이하의 소수: ", N);

    // 2부터 N까지의 수 중 소수 찾기
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
