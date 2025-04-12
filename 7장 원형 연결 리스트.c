/*
7장 리스트
원형 연결 리스트 : 마지막 노드 링크가 첫 번째 노드를 가르키는 리스트
한 노드에서 다른 모든 노드로의 접근이 가능

보통 헤드포인터가 마지막 노드를 가르키게끔 구성
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    if (head == NULL) {
        head = p;
        head->link = head;
    }
    else {
        p->link = head->link;
        head->link = p;
    }

    return head;
}

ListNode* insert_last(ListNode *head, int value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    if (head == NULL) {
        head = p;
        head->link = head;
    }
    else {
        p->link = head->link;
        head->link = p;
        head = p;
    }

    return head;
}

ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;

    removed = head->link;
    head->link = removed->link;
    free(removed);

    return head;
}

void print_list(ListNode *head) {
    if (head == NULL) return;
    ListNode *p = head->link;
    do{
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head->link);
    
    printf("NULL\n");
}    

int main() {
    ListNode *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);

    return 0;
}