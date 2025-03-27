#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996) // Visual Studio에서 scanf 보안 경고를 비활성화

/*
의사코드 (Pseudocode)
FUNCTION sort_numbers()
DECLARE N
PRINT "정수의 개수를 입력하세요:"
READ N

DECLARE array[N]

PRINT N, "개의 정수를 입력하세요:"
FOR i FROM 0 TO N - 1 DO
READ array[i]

SORT array IN ASCENDING ORDER

PRINT "오름차순으로 정렬된 정수들:"
FOR i FROM 0 TO N - 1 DO
PRINT array[i], " "
PRINT NEWLINE
*/

// qsort에서 사용할 비교 함수 (오름차순 정렬)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;

    // 사용자로부터 정수 개수 입력받기
    printf("정수의 개수를 입력하세요: ");
    scanf("%d", &N);

    // 동적 메모리 할당
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) { // 메모리 할당 실패 시 오류 메시지 출력 후 종료
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 정수 입력받기
    printf("%d개의 정수를 입력하세요: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // qsort를 사용하여 배열을 오름차순 정렬
    qsort(arr, N, sizeof(int), compare);

    // 정렬된 배열 출력
    printf("오름차순으로 정렬된 정수들:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 할당된 메모리 해제
    free(arr);

    return 0;
}
