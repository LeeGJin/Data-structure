/*
6장 실습 1
단순 연결 리스트가 정렬되지 않은 정수들의 리스트를 저장하고 있다.
리스트에서 최대값과 최소값을 찾는 프로그램을 작성하라.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    head = p;

    return head;
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode *removed;
    removed = head;
    head = removed->link;
    free(removed);

    return head;
}

void print_list(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        printf("%d ->", p->data);
        p = p->link;
    }
    printf("NULL\n");
    return;
}

void MinMaxfromList(ListNode *head) {
    ListNode *p = head;
    int min = p->data;
    int max = p->data;

    while (p != NULL) {
        if (p->data > max) max = p->data;
        else if (p->data < min) min = p->data;
        p = p->link;
    }

    printf("max : %d, min : %d\n", max, min);
    return;
}

int main() {
    ListNode *head = NULL;
    head = insert_first(head, 10);
    head = insert_first(head, 13);
    head = insert_first(head, 8);
    head = insert_first(head, 33);
    head = insert_first(head, 21);
    print_list(head);

    MinMaxfromList(head);

    return 0;
}