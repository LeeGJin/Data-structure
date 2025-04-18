/*
이중 연결리스트에서 사용자가 입력한 값을 지우는 함수 delete 작성
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *rlink;
    struct ListNode *llink;
}ListNode;

void init(ListNode *head) {
    head->rlink = head;
    head->llink = head;
}

void insert(ListNode *head, element data) {
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));

    temp->data = data;
    temp->rlink = head->rlink;
    temp->llink = head;
    head->rlink->llink = temp;
    head->rlink = temp;
}

void delete(ListNode *head, element data) {
    ListNode *p;
    for(p = head->rlink; p != head; p = p->rlink) {
        if (p->data == data) {
            p->llink->rlink = p->rlink;
            p->rlink->llink = p->llink;
            free(p);
            break;
        }
    }
}

void print_list(ListNode *head) {
    for(ListNode *p = head->rlink; p != head; p = p->rlink) {
        printf("->| %d |<-", p->data);
    }
    printf("\n");
}

int main() {
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    init(head);

    for (int i = 1; i < 6; i++) {
        insert(head, i);
        print_list(head);
    }
    int num;
    for (int i = 1; i < 6; i++) {
        printf("삭제할 값 입력 : ");
        scanf(" %d", &num);
        delete(head, num);
        print_list(head);
    }
    return 0;
}