/*
4장 스택 
스택은 후입선출 (LIFO : Last In First Out) 방식이다.
스택을 구현하기 위해서는 
1. 구조체로 스택 선언하기
    - 스택 안에는 top이라는 데이터 위치를 가르키는 인덱스 값이 있다.
    - 스택 관련 함수는 이 top을 이용해 구현
2. 필요한 함수
    - init_stack(stack) : 스택의 top을 -1로 초기화
    - is_full(stack) : 스택이 가득 찼는지 확인
    - is_empty(stack) : 스택이 비어있는지 확인
    - push(stack, data) : 스택에 값을 넣는다. 이때 top을 1만큼 증가시켜 최근 넣은 데이터 값을 가르키게 한다.
    - pop() : 스택에서 값을 빼는 함수 
    - peek() : 값을 스택에서 빼지 않고 가장 위에 있는 값이 무엇인지 반환

*/

#include <stdio.h>
#include <stdlib.h>

//전역 변수
#define MAX_STACK_SIZE 5

typedef int element;

//스택 구조체 선언
typedef struct StackType {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
    return;
}

int is_full(StackType *s) {
    if (s->top == MAX_STACK_SIZE-1) return 1;
    else return 0;
}

int is_empty(StackType *s) {
    if (s->top == -1) return 1;
    else return 0;
}

void push(StackType *s, element data) {
    if (is_full(s)) {
        printf("스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = data;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top--];
}

element peek(StackType *s) {
    if (is_full(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

void print_stack(StackType *s) {
    if (is_empty(s)) {
        printf("스택이 비었습니다.\n");
        return;
    }
    else {
        printf("--------------------------\n");
        for(int i = 0; i <= s->top; i++) {
            printf("| %d ", s->data[i]);
        }
        printf("\n------------------------\n");
    }
    return;
}

int main() {
    StackType *stack;
    init_stack(stack);

    for(int i = 0; i < MAX_STACK_SIZE; i++) {
        push(stack, (i+1)*10);
    }
    print_stack(stack);

    printf("pop : %d\n", pop(stack));
    print_stack(stack);
    printf("pop : %d\n", pop(stack));
    print_stack(stack);
    
    printf("peek : %d\n", peek(stack));
    print_stack(stack);
    
    return 0;
}