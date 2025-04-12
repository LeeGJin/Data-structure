/*
5장 실습 1
2개의 Stack을 이용해 Queue처럼 작동하는 자료구조를 구현
- 입력 스택 (stack_in) : 데이터를 집어넣을 때 사용하는 스택
- 출력 스택 (stack_out) : 데이터를 꺼낼 때 사용하는 스택

기본 아이디어 
-enqueue(x) -> stack_in.push(x)
-dequeue() ->
    - 만약 stack_out이 비어있지 않으면, stack_out.pop()
    - 만약 stack_out이 비어있고, stack_in에 데이터가 있으면 :
        stack_in의 모든 원소를 stack_out으로 옮긴 뒤, stack_out.pop()
    - 둘 다 비어있으면 -> 큐가 비어있음
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
    return;
}

int is_full(StackType *s) {
    return s->top == MAX_STACK_SIZE -1;
}

int is_empty(StackType *s) {
    return s->top == -1;
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("스택 포화 에러\n");
        exit(1);
    }
    else {
        s->data[++s->top] = item;
    }
    return;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top--];
    }
}

void enqueue(StackType *stack_in, element num) {
    push(stack_in, num);
    return;
}

element dequeue(StackType *stack_in, StackType *stack_out) {
    if (!is_empty(stack_out)) return pop(stack_out);
    else if (!is_empty(stack_in) && is_empty(stack_out)) {
        while (!is_empty(stack_in))
        {
            push(stack_out, pop(stack_in));
        }
        
        return pop(stack_out);
    }
    else exit(1);
}

void print_queue(StackType *stack_in, StackType *stack_out) {
    printf("| stack_in : [");
    for (int i = 0; i <= stack_in->top; i++) {
        printf("%d,", stack_in->data[i]);
    }
    printf("] | stack_out : [");
    for (int i = 0; i <= stack_out->top; i++) {
        printf("%d,", stack_out->data[i]);
    }
    printf("]\n");
    return;
}

int main() {
    StackType *stack_in;
    StackType *stack_out;
    init_stack(stack_in);
    init_stack(stack_out);
    int value;

    enqueue(stack_in, 10);
    printf("반환값 : -  ");
    print_queue(stack_in, stack_out);
    enqueue(stack_in, 20);
    printf("반환값 : -  ");
    print_queue(stack_in, stack_out);
    enqueue(stack_in, 30);
    printf("반환값 : -  ");
    print_queue(stack_in, stack_out);
    printf("반환값 : %d ", dequeue(stack_in, stack_out));
    print_queue(stack_in, stack_out);
    printf("반환값 : %d ", dequeue(stack_in, stack_out));
    print_queue(stack_in, stack_out);
    enqueue(stack_in, 40);
    printf("반환값 : -  ");
    print_queue(stack_in, stack_out);
    printf("반환값 : %d ", dequeue(stack_in, stack_out));
    print_queue(stack_in, stack_out);
    printf("반환값 : %d ", dequeue(stack_in, stack_out));
    print_queue(stack_in, stack_out);

    return 0;
}
