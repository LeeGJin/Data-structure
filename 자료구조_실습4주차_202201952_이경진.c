#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
    return;
}

int is_full(StackType* s) {
    return (s->top == MAX_STACK_SIZE -1);
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

void enqueue(StackType* s, int item) {
    if (is_full(s)) {
        printf("포화 에러\n");
        exit(1);
    }
    s->stack[++(s->top)] = item;
    return;
}

int pop(StackType* s) {
    return (s->stack[s->top--]);
}

int dequeue(StackType* s_in, StackType* s_out) {
    if (!is_empty(s_out)) {
        return pop(s_out);
    }
    else if (is_empty(s_out) && (!is_empty(s_in))) {
        for (int i = s_in->top; i >= 0; i--) {
            enqueue(s_out, s_in->stack[i]);
        }
        for (int j = s_in->top; j >= 0; j--) {
            pop(s_in);
        }
        return pop(s_out);
    }
    else {
        printf("공백 에러\n");
        exit(1);
    }
}

void print_queue(StackType* s_in, StackType* s_out) {
    printf("stack_in : ");
    if (!is_empty(s_in)) {
        for (int i = 0; i < s_in->top+1; i++) {
            printf("| %d ", s_in->stack[i]);
        }
    }
    printf("\nstack_out : ");
    if (!is_empty(s_out)) {
        for (int i = 0; i < s_out->top+1; i++) {
            printf("| %d ", s_out->stack[i]);
        }
    }
    printf("\n\n");
    return;
}

int main() {
    StackType stack_in;
    StackType stack_out;
    init_stack(&stack_in);
    init_stack(&stack_out);
    
    enqueue(&stack_in, 10);
    print_queue(&stack_in, &stack_out);
    enqueue(&stack_in, 20);
    print_queue(&stack_in, &stack_out);
    enqueue(&stack_in, 30);
    print_queue(&stack_in, &stack_out);
    printf("반환값 : %d\n", dequeue(&stack_in, &stack_out));
    print_queue(&stack_in, &stack_out);
    printf("반환값 : %d\n", dequeue(&stack_in, &stack_out));
    print_queue(&stack_in, &stack_out);
    enqueue(&stack_in, 40);
    print_queue(&stack_in, &stack_out);
    printf("반환값 : %d\n", dequeue(&stack_in, &stack_out));
    print_queue(&stack_in, &stack_out);
    printf("반환값 : %d\n", dequeue(&stack_in, &stack_out));
    print_queue(&stack_in, &stack_out);

    return 0;
}