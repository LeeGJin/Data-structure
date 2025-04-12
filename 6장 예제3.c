/*
6장 연결 리스트 1
2개의 리스트를 합하는 함수수
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

ListNode* concat_list(ListNode *head1, ListNode *head2) {
    
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode *p;
        p = head1;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

int main() {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *combined_head = NULL;

    for (int i = 1; i < 4; i++) {
        head1 = insert_first(head1, i*10);
    }
    print_list(head1);
    for (int i = 4; i < 6; i++) {
        head2 = insert_first(head2, i*10);
    }    
    print_list(head2);

    combined_head = concat_list(head1, head2);
    print_list(combined_head);

    return 0;
}