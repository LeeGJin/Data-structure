/*
이중 연결리스트를 이용하여 재생프로그램 만들기 
앞으로 가기를 누르면 다음 노래 강조 뒤로 가기를 누르면 이전 노래 강조
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct DListNode
{
    element data[50];
    struct DListNode *Llink;
    struct DListNode *Rlink;   
}DListNode;

void init(DListNode *phead) {
    phead->Llink = phead;
    phead->Rlink = phead;
}

void Dinsert(DListNode *before, element *data) {
    DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
    strcpy(newNode->data, data);

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

void print_dlist(DListNode *phead, DListNode *nowsong) {
    DListNode *p;
    for (p = phead->Rlink; p != phead; p = p->Rlink) {
        if (p == nowsong)  // ✅ 포인터 자체를 비교!
            printf("<-| #%s# |->", p->data);
        else
            printf("<-|  %s  |->", p->data);
    }
    printf("\n");
}

int main() {
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    Dinsert(head, "Fernando");
    Dinsert(head, "Dancing Queen");
    Dinsert(head, "Mamamia");

    DListNode *nowsong = head->Rlink;

    print_dlist(head, nowsong);

    char ch;
    while (ch != 'q') {
        printf("명령어를 입력하시오 (<, >, q) : ");
        scanf(" %c", &ch);

        if (ch == '>') {
            if (nowsong->Rlink == head) {
                nowsong = head;
            }
            nowsong = nowsong->Rlink;
            print_dlist(head, nowsong);
        }
        else if (ch == '<') {
            if (nowsong->Llink == head) {
                nowsong = head;
            }
            nowsong = nowsong->Llink;
            print_dlist(head, nowsong);
        }
    }

    free(head);
    return 0;
}
