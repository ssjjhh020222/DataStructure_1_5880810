#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

typedef struct {
    int coef; // 계수
    int expo; // 차수
} elementType;

#define NULL_ITEM (elementType){0, 0}

typedef struct ListType {
    int size;
    int last;
    int move;
    elementType* array;
} listType;

listType* createList(int size);
elementType readItem(listType* list, int index);
elementType deleteItem(listType* list, int index);
int insertItem(listType* list, int index, elementType item);
int printList(listType* list);
int initList(listType* list);
int ordered_insertItem(listType* list, elementType item);
int destroyList(listType* list);

#endif
