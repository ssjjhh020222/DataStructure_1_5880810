#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "linearList.h"

void initList(ListType* list) {
    list->size = 0;
}

void addContact(ListType* list, const char* name, const char* phone) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }
    strcpy(list->contacts[list->size].name, name);
    strcpy(list->contacts[list->size].phone, phone);
    list->size++;
    printf("연락처가 추가되었습니다.\n");
}

int searchContact(ListType* list, const char* name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int deleteContact(ListType* list, const char* name) {
    int index = searchContact(list, name);
    if (index == -1) {
        return 0; // 삭제 실패
    }
    for (int i = index; i < list->size - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->size--;
    return 1; // 삭제 성공
}

void printAllContacts(ListType* list) {
    printf("===== 전체 연락처 =====\n");
    for (int i = 0; i < list->size; i++) {
        printf("[%d] 이름: %s, 전화번호: %s\n", i + 1,
            list->contacts[i].name, list->contacts[i].phone);
    }
}
