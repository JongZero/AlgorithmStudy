#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;		// ��ü!
							// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
							// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
	int size;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
	s->size = 0;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
		s->size++;
	}
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		s->size--;
		return s->data[(s->top)--];
	}
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ������
int GetSize(StackType* s)
{
	return s->size;
}
// ===== ���� �ڵ��� �� ===== 

int main(void)
{
	/*
	// �������� 11��
	StackType s;		// ��ȣ�� ���� ���� (push�� �Ѵ�. - ����� ��� �����Ǿ���)
	StackType matchS;	// s�� ����� ���� ���� (push, pop�� �Ѵ�.) - ( ) ��Ī��
	init_stack(&s);
	init_stack(&matchS);

	const char* str = "((())(()))";		// 1 2 3 3 2 4 5 5 4 1
	//const char* str = "(((((()";		// 1 2 3 4 5 6 6 (å�� ��Ÿ�ε�)
	int len = strlen(str);
	int s_size = 0;
	int matchIndex = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			push(&s, str[i]);
			s_size = GetSize(&s);

			push(&matchS, s_size + '0');

			printf("%d ", s_size);
		}
		// ')'
		else
		{
			printf("%c ", pop(&matchS));
		}
	}
	*/

	// �������� 12��
	StackType s;
	init_stack(&s);

	char input[256];
	scanf_s("%s", input, (unsigned int)sizeof(input));

	int len = strlen(input);
	
	char now = ' ';
	for (int i = 0; i < len; i++)
	{
		
		push(&s, input[i]);
	}

	return 0;
}