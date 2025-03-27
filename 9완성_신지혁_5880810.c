#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

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

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // 오름차순 정렬
}

int main() {
    int N;


    printf("정수의 개수를 입력하세요: ");
    scanf("%d", &N);

 
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    
    printf("%d개의 정수를 입력하세요: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    
    qsort(arr, N, sizeof(int), compare);

    
    printf("오름차순으로 정렬된 정수들:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    free(arr);

    return 0;
}
