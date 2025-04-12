/*
4장 스택의 응용 : 후위 표기식의 계산
수식을 왼쪽에서 오른쪽으로 스캔
    - 피연산자이면 스택에 저장
    - 연산자이면
        - 필요한 수만큼의 피연산자를 스택에서 꺼내 연산자를 실행
        - 연산의 결과를 다시 스택에 저장
ex)
82/3-32*+  <-> (8/2)-3 + 3*2 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//전역 변수
#define MAX_STACK_SIZE 100

typedef char element;

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

int eval(char exp[]) {
    int op1, op2, value;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);

    for (int i = 0; i < len; i++) {
        ch = exp[i];
        if ((ch != '+')&&(ch != '-')&&(ch != '*')&&(ch != '/')) {
            push(&s, ch-'0');
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main() {
    
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d 입니다.\n", result);
    return 0;
}