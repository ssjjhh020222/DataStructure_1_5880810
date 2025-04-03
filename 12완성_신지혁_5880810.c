#pragma warning(disable:4996)
#include <stdio.h>

int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int choice, n;

    while (1) {
    
        printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램이 종료되었습니다.\n");
            break;
        }

        printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
        scanf("%d", &n);

        if (n == 0) {
            printf("프로그램이 종료되었습니다.\n");
            break;
        }

        if (choice == 1) {
            printf("F(%d) = %d (재귀적 방법)\n", n, fibonacci_recursive(n));
        }
        else if (choice == 2) {
            printf("F(%d) = %d (순환적 방법)\n", n, fibonacci_iterative(n));
        }
        else {
            printf("잘못된 입력입니다. 1 또는 2를 입력하세요.\n");
        }
    }

    return 0;
}
