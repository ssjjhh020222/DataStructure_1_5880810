#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

listType* createList(int size) {
    listType* lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
}

int destroyList(listType* list) {
    free(list->array);
    free(list);
    return 1;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in readItem\n", index);
        return NULL_ITEM;
    }
    return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
    return (item2.expo - item1.expo); // 내림차순
}

int ordered_insertItem(listType* list, elementType item) {
    int i, j;
    for (i = 0; i <= list->last; i++) {
        if (compare_item(list->array[i], item) > 0) break;
    }
    for (j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }
    list->array[i] = item;
    list->last++;
    return 1;
}

int insertItem(listType* list, int index, elementType item) {
    if (index < 0 || index >(list->last + 1)) return -1;
    if (index >= list->size) return -1;
    for (int i = list->last + 1; i > index; i--) {
        list->array[i] = list->array[i - 1];
        list->move++;
    }
    list->array[index] = item;
    list->last++;
    return 1;
}

elementType deleteItem(listType* list, int index) {
    elementType r = list->array[index];
    if (index < 0 || index > list->last) return NULL_ITEM;
    for (int i = index; i < list->last; i++) {
        list->array[i] = list->array[i + 1];
        list->move++;
    }
    list->last--;
    return r;
}

int printList(listType* list) {
    printf("List: size = %d, last = %d, move = %d\n", list->size, list->last, list->move);
    printf("Items: P(x) = ");
    for (int i = 0; i <= list->last; i++) {
        elementType e = list->array[i];
        if (e.coef == 0) continue;

        if (i > 0 && e.coef > 0) printf("+");

        if (e.expo == 0) printf("%d", e.coef);
        else if (e.expo == 1) {
            if (e.coef == 1) printf("x");
            else if (e.coef == -1) printf("-x");
            else printf("%dx", e.coef);
        }
        else {
            if (e.coef == 1) printf("x^%d", e.expo);
            else if (e.coef == -1) printf("-x^%d", e.expo);
            else printf("%dx^%d", e.coef, e.expo);
        }
    }
    printf("\n");
    return 1;
}

int initList(listType* list) {
    list->last = -1;
    list->move = 0;
    return 1;
}
