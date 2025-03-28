#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // ���� ������ ����� ������ �ִ� ũ��
typedef int element; // element��� int�� ����

typedef struct {
	element stack[MAX_STACK_SIZE]; // ������ �迭 ����
	int top; // ������ top ����
} StackType;

void init_stack(StackType* s) //������ ���� : ����ü �ȿ��� �ʱ�ȭ�ϴ� ���� �ȵȴ�. ����ü �ȿ� �ִ� ���� type�̴�. ���� �Լ��� �ȸ������ main���� �ʱ�ȭ�� �ؾ��Ѵ�.
{
	s->top = -1; // top�� -1�� �ʱ�ȭ
}

bool is_empty(StackType *s)
{
	return (s->top == -1);  // top�� -1�̸� True ��ȯ �ƴϸ� false ��ȯ
}

bool is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1)); // top�� MAX_STACK_SIZE - 1�̸� True ��ȯ �ƴϸ� false ��ȯ
}

void push(StackType *s, element item)
{
	if (is_full(s)) // ������ ���� á�� ��
	{
		printf("���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->stack[++(s->top)] = item; // top�� ������Ű�� item�� ���ÿ� ����
	}
}

element pop(StackType *s)
{
	if (is_empty(s)) // ������ ����� ��
	{
		printf("���� ���� ����\n");
		return -1;
	}
	else
	{
		return s->stack[(s->top)--]; // ������ ��ȯ�ϰ� top�� ���ҽ�Ŵ
	}
}

element peek(StackType *s)
{
	if (is_empty(s)) // ������ ����� ��
	{
		printf("���� ���� ����\n");
		return -1;
	}
	else
	{
		return s->stack[s->top]; // ������ ��ȯ
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
		printf("��ȣ ��Ī ����\n");
	else 
		printf("��ȣ ��Ī ����\n");

	int result;
	result = eval("82/3-32*+");
	printf("���� ��� = %d\n", result);


	return 0;
}