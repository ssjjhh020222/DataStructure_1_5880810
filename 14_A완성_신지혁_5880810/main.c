#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

void inputMatrix(listType* list) {
    int r, c, v;
    elementType item;

    printf("행렬을 입력하십시오? (-1 입력 시 행렬의 입력이 종료됨)\n");
    while (1) {
        scanf("%d", &r);
        if (r == -1) break;
        scanf("%d %d", &c, &v);
        item.row = r;
        item.col = c;
        item.val = v;
        ordered_insertItem(list, item);
    }
}

void addMatrix(listType* a, listType* b, listType* result) {
    int i = 0, j = 0;
    elementType item;

    while (i <= a->last && j <= b->last) {
        int cmp = compare_item(a->array[i], b->array[j]);
        if (cmp == 0) {
            item = a->array[i];
            item.val += b->array[j].val;
            if (item.val != 0) {
                ordered_insertItem(result, item);
            }
            i++; j++;
        }
        else if (cmp < 0) {
            ordered_insertItem(result, a->array[i++]);
        }
        else {
            ordered_insertItem(result, b->array[j++]);
        }
    }

    while (i <= a->last) ordered_insertItem(result, a->array[i++]);
    while (j <= b->last) ordered_insertItem(result, b->array[j++]);
}

int main() {
    int size;
    printf("리스트의 최대 크기를 입력하세요: ");
    scanf("%d", &size);

    listType* a = createList(size);
    listType* b = createList(size);
    listType* result = createList(size * 2); // 결과는 더 커질 수 있음

    inputMatrix(a);
    inputMatrix(b);

    addMatrix(a, b, result);

    printf("두 행렬의 합\n");
    printList(result);

    // 메모리 해제
    free(a->array); free(a);
    free(b->array); free(b);
    free(result->array); free(result);

    return 0;
}
