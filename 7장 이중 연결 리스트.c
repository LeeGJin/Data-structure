/*
이중 연결 리스트 
Node에 right link, left link 두가지가 존재한다. 각각 양방향에 있는 node를 가르키고 있기 때문에
기존에 한 방향으로만 데이터를 관리했던거와는 다르게 양 방향 모두 이동하여 관리 가능하다.asm
여기에서는 처음에 헤드가 양방향 모두 자신을 가르키게 초기화를 해줘야 한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode
{
    element data;
    struct DListNode *Llink;
    struct DListNode *Rlink;   
}DListNode;

void init(DListNode *phead) {
    phead->Llink = phead;
    phead->Rlink = phead;
}

void Dinsert(DListNode *before, element data) {
    DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;

    newNode->Llink = before;
    newNode->Rlink = before->Rlink;

    before->Rlink->Llink = newNode;
    before->Rlink = newNode;
}

void Ddelete(DListNode *head, DListNode *removed) {
    if (head == removed) return;

    removed->Llink->Rlink = removed->Rlink;
    removed->Rlink->Llink = removed->Llink;

    free(removed);
}

void print_dlist(DListNode *phead) {
    DListNode *p;
    for (p = phead->Rlink; p != phead; p = p->Rlink) {
        printf("<-| |%d| |->" , p->data);
    }
    printf("\n");
}

int main() {
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("추가단계\n");
    for (int i = 0; i < 5; i++) {
        Dinsert(head, i);
        print_dlist(head);
    }
    printf("삭제단계\n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        Ddelete(head, head->Rlink);
    }
    free(head);
    return 0;
}
