#include <stdio.h>
#include <stdlib.h>
#include "Linked List.h"
#pragma warning (disable:4996)

int main() {
    linkedList_h* mylist = createLinkedList();
    int menu, value, target;

    while (1) {
        printf("\n====== Linked_List Menu ======\n");
        printf("1) insertFirst (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle (특정 값 뒤에 삽입)\n");
        printf("7) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu ▶ ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFirstNode(mylist, value);
            printList(mylist);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertLastNode(mylist, value);
            printList(mylist);
            break;
        case 3:
            printf("Insert after which value? ");
            scanf("%d", &target);
            printf("Value to insert: ");
            scanf("%d", &value);
            insertMiddleNode(mylist, target, value);
            printList(mylist);
            break;
        case 7:
            printHeadTail(mylist);
            break;
        case 0:
            destroyLinkedList(mylist);
            printf("Program Stopped.\n");
            return 0;
        default:
            printf("Invalid menu.\n");
        }
    }

    return 0;
}
