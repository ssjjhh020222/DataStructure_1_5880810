#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main() {
    int* matrix1, * matrix2, * result;
    int i, rows = 2, cols = 2;

  
    matrix1 = (int*)malloc(rows * cols * sizeof(int));
    matrix2 = (int*)malloc(rows * cols * sizeof(int));
    result = (int*)malloc(rows * cols * sizeof(int));

    if (matrix1 == NULL || matrix2 == NULL || result == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 첫 번째 행렬 입력
    printf("첫 번째 2x2 행렬 입력:\n");
    for (i = 0; i < rows * cols; i++) {
        scanf("%d", matrix1 + i);
    }

    // 두 번째 행렬 입력
    printf("두 번째 2x2 행렬 입력:\n");
    for (i = 0; i < rows * cols; i++) {
        scanf("%d", matrix2 + i);
    }

    // 행렬 덧셈
    for (i = 0; i < rows * cols; i++) {
        *(result + i) = *(matrix1 + i) + *(matrix2 + i);
    }

    // 결과 출력
    printf("행렬 덧셈 결과:\n");
    for (i = 0; i < rows * cols; i++) {
        printf("%d ", *(result + i));
        if ((i + 1) % cols == 0) {
            printf("\n");
        }
    }

    // 동적 메모리 해제
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
