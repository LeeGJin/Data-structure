/*
6장 연결 리스트 1
리스트의 항목들을 노드(node)라고 하는 곳에 분산하여 저장 
노드는 데이터 필드와 링크 필드로 구성 
- 데이터 필드 : 리스트의 원소, 즉 데이터 값을 저장하는 장소
- 링크 필드 : 다른 노드의 주소값을 저장하는 장소 (포인터)

장점 
    - 삽입, 삭제가 보다 용이하다   (배열로 만든 리스트 보다.)
    - 연속된 메모리 공간이 필요없다. (hip 영역에 저장)
    - 크기 제한이 없다.

단점 
    - 코드가 복잡하다.

헤드 포인터 : 데이터 값은 안들어있고 첫번째 노드를 가르킨다
마지막 노드의 링크 필드는 NULL로 설정한다.


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

int main() {
    ListNode *head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }    

    return 0;
}