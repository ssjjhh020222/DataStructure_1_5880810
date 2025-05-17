#pragma once

typedef int elementType;

typedef struct ListNode {
    elementType data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList(void);
void destroyLinkedList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, elementType item);
void insertLastNode(linkedList_h* L, elementType item);
void insertMiddleNode(linkedList_h* L, elementType target, elementType item);
void printList(linkedList_h* L);
void printHeadTail(linkedList_h* L);
