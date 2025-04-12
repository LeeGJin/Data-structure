/*
6장 연결 리스트 1
단어들을 저장하고 있는 연결 리스트
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
}element;

typedef struct ListNode{
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
        printf("%s -> ", p->data.name);
        p = p->link;
    }
    printf("NULL\n");
}    

int main() {
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}