/*
6장 연결 리스트 1
특정한 값을 탐색하는 함수
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
    p->link = head;
    head = p;

    return head;
}

ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;

    removed = head;
    head = removed->link;
    free(removed);

    return head;
}

void print_list(ListNode *head) {
    /*
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
    */
    
    ListNode *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}    

ListNode* search_list(ListNode *head, element x) {
    
    ListNode *p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;
}

int main() {
    ListNode *head = NULL;

    for (int i = 1; i < 4; i++) {
        head = insert_first(head, i*10);
        print_list(head);
    }

    if(search_list(head, 30) != NULL) {
        printf("리스트에서 30을 찾았습니다. \n");
    }
    else {
        printf("리스트에서 30을 찾지 못했습니다. \n");
    }

    return 0;
}