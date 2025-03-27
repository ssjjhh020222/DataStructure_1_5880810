#include <stdio.h>
#pragma warning (disable:4996)

/*
의사코드 (Pseudocode)
FUNCTION add_matrices()
    DECLARE matrix1[2][2], matrix2[2][2], sum[2][2]

    PRINT "첫 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ matrix1[i][j]

    PRINT "두 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ matrix2[i][j]

    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            sum[i][j] = matrix1[i][j] + matrix2[i][j]

    PRINT "행렬 덧셈 결과:"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            PRINT sum[i][j], " "
        PRINT NEWLINE
*/

int main() {
    int matrix1[2][2], matrix2[2][2], sum[2][2];

    // 첫 번째 2x2 행렬 입력 받기
    printf("첫 번째 2x2 행렬 입력:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // 두 번째 2x2 행렬 입력 받기
    printf("두 번째 2x2 행렬 입력:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 두 행렬의 합 계산
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 결과 출력
    printf("행렬 덧셈 결과:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
