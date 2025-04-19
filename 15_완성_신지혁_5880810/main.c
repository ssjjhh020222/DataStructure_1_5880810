#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "linearList.h"

int main() {
    ListType list;
    int menu;
    char name[100], phone[15];

    initList(&list);

    while (1) {
        printf("===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);
        getchar(); // 버퍼 비우기

        switch (menu) {
        case 1:
            printf("이름을 입력하세요: ");
            scanf(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("전화번호를 입력하세요: ");
            scanf(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = '\0';

            addContact(&list, name, phone);
            break;

        case 2:
            printf("이름을 입력하세요: ");
            scanf(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            if (deleteContact(&list, name)) {
                printf("삭제되었습니다.\n");
            }
            else {
                printf("연락처를 찾을 수 없습니다.\n");
            }
            break;

        case 3:
            printf("이름을 입력하세요: ");
            scanf(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            int index = searchContact(&list, name);
            if (index != -1) {
                printf("이름: %s, 전화번호: %s\n", list.contacts[index].name, list.contacts[index].phone);
            }
            else {
                printf("연락처를 찾을 수 없습니다.\n");
            }
            break;

        case 4:
            printAllContacts(&list);
            break;

        case 0:
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }

    return 0;
}
