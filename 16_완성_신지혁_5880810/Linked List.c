#include <stdio.h>
#include <stdlib.h>
#include "Linked List.h"

linkedList_h* createLinkedList(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void destroyLinkedList(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
    free(L);
}

void insertFirstNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = L->head;
    L->head = newNode;
}

void insertLastNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    listNode* temp = L->head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void insertMiddleNode(linkedList_h* L, elementType target, elementType item) {
    listNode* current = L->head;

    while (current != NULL && current->data != target) {
        current = current->link;
    }

    if (current == NULL) {
        printf("Target value not found.\n");
        return;
    }

    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = current->link;
    current->link = newNode;
}

void printList(linkedList_h* L) {
    listNode* temp = L->head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("[%d] ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void printHeadTail(linkedList_h* L) {
    if (L->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    listNode* temp = L->head;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    printf("Head: %d, Tail: %d\n", L->head->data, temp->data);
}
