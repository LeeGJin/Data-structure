/*
이중 연결 리스트에서 사용자가 입력한 값이 들어있는지 확인하는 search 함수 작성성
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *llink;
    struct ListNode *rlink;
}ListNode;

void init(ListNode *head) {
    head->llink = head;
    head->rlink = head;
}

void insert(ListNode *head, element data) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));

    p->data = data;
    p->rlink = head->rlink;
    p->llink = head;

    head->rlink->llink = p;
    head->rlink = p;
}

void delete(ListNode *head, ListNode *removed) {
    if (head == removed) return;

    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;

    free(removed);
}

void print_list(ListNode *head) {
    if (head == NULL) return;

    for (ListNode *p = head->rlink; p != head; p = p->rlink) {
        printf("->| %d |<-", p->data);
    }
    printf("\n");
}

int search(ListNode *head, element data) {
    for(ListNode *p = head->rlink; p != head; p = p->rlink) {
        if (p->data == data) {
            return 1;
        }
    }
    return NULL;
}

int main() {
    int count;
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    init(head);
    insert(head, 1); insert(head, 2);
    insert(head, 3); insert(head, 4);
    print_list(head);

    element data;
    printf("탐색할 값 : ");
    scanf("%d", &data);

    if (search(head, data) != NULL) {
        printf("값이 리스트 안에 있습니다. \n");
    }
    else {
        printf("값이 리스트 안에 없습니다. \n");
    }
    return 0;
}