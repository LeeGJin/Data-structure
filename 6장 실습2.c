/*
6장 실습 2
단순 연결 리스트에서 특정한 데이터 값을 갖는 노드를 삭제하는 함수를 작성하라
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
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
    return;
}

ListNode* delete_node(ListNode *head, int value) {
    ListNode *p = head;
    ListNode *temp = head->link;

    if (p->data == value) {
        head = p->link;
        free(p);
        return head;
    }
    while (temp != NULL) {
        if (temp->data == value) {
            p->link = temp->link;
            free(temp);
            return head;
        }
        p = p->link;
        temp = temp->link;
    }
    return head;
}

int main() {
    ListNode *head = NULL;
    int value;
    head = insert_first(head, 10);
    head = insert_first(head, 13);
    head = insert_first(head, 8);
    head = insert_first(head, 33);
    head = insert_first(head, 21);
    print_list(head);

    printf("삭제할 값을 하시오 : ");
    scanf("%d", &value);

    head = delete_node(head, value);
    print_list(head);

    return 0;
}