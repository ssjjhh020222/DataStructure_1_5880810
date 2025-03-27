#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    int score;
    struct Student* next;
} Student;

// 학생 정보 입력 함수
Student* insertStudent(Student* head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("메모리 할당 실패\n");
        return head;
    }

    printf("학생의 정보를 입력하세요 (이름 학번 점수): ");
    scanf("%s %d %d", newStudent->name, &newStudent->id, &newStudent->score);
    newStudent->next = head;
    return newStudent;
}

// 학생 정보 검색 함수
void searchStudent(Student* head, int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("%s %d %d\n", temp->name, temp->id, temp->score);
            return;
        }
        temp = temp->next;
    }
    printf("해당 학번의 학생이 없습니다.\n");
}

// 동적 메모리 해제 함수
void freeStudents(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Student* head = NULL;
    int num, id;

    printf("몇 명의 학생 정보를 입력하시나요? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        head = insertStudent(head);
    }

    while (1) {
        printf("학번을 입력하세요 (0이면 종료): ");
        scanf("%d", &id);
        if (id == 0) break;
        searchStudent(head, id);
    }

    freeStudents(head); // 메모리 해제
    return 0;
}
