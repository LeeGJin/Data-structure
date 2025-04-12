/*
4장 스택의 응용 : 괄호 검사
괄호의 종류 : 대괄호 ('[', ']'), 중괄호 ('{', '}'), 소괄호 ('(', ')')
조건
1. 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
2. 같은 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
3. 괄호 사이에는 포함 관계만 존재한다.

잘못된 괄호 사용의 예
(a(b)
a(b)c)
a{b(c[d]e}f)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//전역 변수
#define MAX_STACK_SIZE 500

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

int check_matching(char *in) {
    StackType s; //스택을 이용해 비교
    init_stack(&s);
    char ch, open_ch; //괄호 비교 변수
    int n = strlen(in); //입력 받은 문자열의 길이 

    for (int i = 0; i < n; i++) {
        ch = in[i];
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            push(&s, ch);
            break;
        case ')':
        case '}':
        case ']':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')')||(open_ch == '{' && ch != '}')||(open_ch == '[' && ch != ']')) return 0;
            }
            break;
        }
    }
    if (is_empty(&s) == 0) return 0;
    return 1; 
}

int main() {
    char *p1 = "{A[(i+1)]=0;}";
    if (check_matching(p1) == 1) printf("%s 괄호검사성공\n", p1);
    else printf("%s 괄호검사실패\n", p1);

    char *p2 = "{A[(i+1]=0;}";
    if (check_matching(p2) == 1) printf("%s 괄호검사성공\n", p2);
    else printf("%s 괄호검사실패\n", p2);

    char *p3 = "{A[(i+1]=0);}";
    if (check_matching(p3) == 1) printf("%s 괄호검사성공\n", p3);
    else printf("%s 괄호검사실패\n", p3);
    
    return 0;
}