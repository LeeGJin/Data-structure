/*
이전에는 배열을 이용하여 스택을 구현한 것과 다르게 이번에는 연결리스트를 이용하여 스택을 구현한다.
연결리스트로 스택을 구현하면 이전에 배열을 이용하였을때 배열을 크기를 미리 지정하였던거와는 다르게 그럴 필요가 없다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element data;
    struct StackNode *link;
}StackNode;

typedef struct {
    StackNode *top;
}LinkStackType;

void init(LinkStackType *s) {
    s->top = NULL;
}

int is_full(LinkStackType *s) {
    //가득 차는 것은 hip 영역이 가득 차는것 
    //여기서는 무한하다고 가정
    return 0;
}

int is_empty(LinkStackType *s) {
    return (s->top == NULL);
}

void push(LinkStackType *s, element data) {
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));

    temp->data = data;
    temp->link = s->top;
    s->top = temp;
}

element pop(LinkStackType *s) {
    if (is_empty(s)) {
        printf("스택이 비어있습니다. \n");
        exit(1);
    }
    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->link;
    free(temp);
    return data;
}

void print_stack(LinkStackType *s) {
    for (StackNode *p = s->top; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("\n");
}

int main() {
    LinkStackType *s;
    init(s);
    for (int i = 0; i < 4; i++) {
        push(s, i+1);
        print_stack(s);
    }
    for (int i = 0; i < 4; i++) {
        pop(s);
        print_stack(s);
    }
    return 0;
}