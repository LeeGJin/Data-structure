#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // 전역 변수로 선언된 스택의 최대 크기
typedef int element; // element라는 int형 선언

typedef struct {
	element stack[MAX_STACK_SIZE]; // 스택의 배열 선언
	int top; // 스택의 top 선언
} StackType;

void init_stack(StackType* s) //교수님 설명 : 구조체 안에서 초기화하는 것은 안된다. 구조체 안에 있는 것은 type이다. 굳이 함수를 안만들려면 main에서 초기화를 해야한다.
{
	s->top = -1; // top을 -1로 초기화
}

bool is_empty(StackType *s)
{
	return (s->top == -1);  // top이 -1이면 True 반환 아니면 false 반환
}

bool is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1)); // top이 MAX_STACK_SIZE - 1이면 True 반환 아니면 false 반환
}

void push(StackType *s, element item)
{
	if (is_full(s)) // 스택이 가득 찼을 때
	{
		printf("스택 포화 에러\n");
		return;
	}
	else
	{
		s->stack[++(s->top)] = item; // top을 증가시키고 item을 스택에 넣음
	}
}

element pop(StackType *s)
{
	if (is_empty(s)) // 스택이 비었을 때
	{
		printf("스택 공백 에러\n");
		return -1;
	}
	else
	{
		return s->stack[(s->top)--]; // 스택을 반환하고 top을 감소시킴
	}
}

element peek(StackType *s)
{
	if (is_empty(s)) // 스택이 비었을 때
	{
		printf("스택 공백 에러\n");
		return -1;
	}
	else
	{
		return s->stack[s->top]; // 스택을 반환
	}
}

int Check_matching(const char* str)
{
	StackType s;
	init_stack(&s);
	char ch, open_ch;

	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s))
				return 0;
			else
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return 0;
				break;
			}
		}
	}
	if (!is_empty(&s))
		return 0;
	return 1;
}

int eval(const char exp[])
{
	StackType s;
	init_stack(&s);
	int op1, op2, value;
	char ch;

	for (int i = 0; i < strlen(exp); i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';
			push(&s, value);
		}
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main()
{
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));


	const char *str = "{A[(i+1)) = 0;}";
	if (Check_matching(str) == 1)
		printf("괄호 매칭 성공\n");
	else 
		printf("괄호 매칭 실패\n");

	int result;
	result = eval("82/3-32*+");
	printf("연산 결과 = %d\n", result);


	return 0;
}
