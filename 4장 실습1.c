/*
4장 실습 1
회문이란 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다. 
예를 들어 "eye", "Madam, I'm Adam", "race car" 등이다.
여기서 구두점이나 스페이스, 대소문자 등은 무시하여야 한다.
스택을 이용하여 주어진 문자열이 회문인지 아닌지를 결정하는 프로그램을 작성하라
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
    return;
}

int is_full(StackType *s) {
    if (s->top == MAX_STACK_SIZE - 1) return 1;
    else return 0;
}

int is_empty(StackType *s) {
    if (s->top == -1) return 1;
    else return 0;
}

void push(StackType *s, element ch) {
    if (is_full(s)) {
        printf("스택 포화 에러\n");
        exit(1);
    }
    s->data[++s->top] = ch;
    return;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top--];
}

element peek(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}

void print_stack (StackType *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%c |", s->data[i]);
    }
    return;
}

char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    else return ch;
}

int check_palindrome(char *in) {
    StackType s;
    init_stack(&s);
    char clean[100];
    int index = 0;

    for (int i = 0; i < strlen(in); i++) {
        if ((in[i] >= 'a' && in[i] <= 'z')||(in[i] >= 'A' && in[i] <= 'Z')) {
            clean[index++] = to_lower(in[i]);
        }
    }

    for (int i = 0; i < index/2; i++) {
        push(&s, clean[i]);
    }

    print_stack(&s);

    int start = (index % 2 ==0) ? index/2 : index/2 +1;
    for (int j = start; j < index; j++) {
        if (pop(&s) != clean[j]) return 0;
    }

    if (!is_empty(&s)) return 0;
    return 1;
}

int main() {
    char *ch1 = "eye";
    char *ch2 = "Madam, I'm Adam";
    char *ch3 = "race car";

    if (check_palindrome(ch1)) printf("'%s'는 회문입니다.\n", ch1);
    else printf("'%s'는 회문이 아닙니다.\n", ch1);
    if (check_palindrome(ch2)) printf("'%s'는 회문입니다.\n", ch2);
    else printf("'%s'는 회문이 아닙니다.\n", ch2);
    if (check_palindrome(ch3)) printf("'%s'는 회문입니다.\n", ch3);
    else printf("'%s'는 회문이 아닙니다.\n", ch3);

    return 0;
}