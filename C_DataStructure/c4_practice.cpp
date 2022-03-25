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

// �������� 14��
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

	/*
	// �������� 12��
	StackType s;
	init_stack(&s);

	char input[256];
	scanf_s("%s", input, (unsigned int)sizeof(input));

	int len = strlen(input);
	
	char prev = ' ';
	int count = 0;
	int offset = 'a' - 'A';		// 'a'�� 'A'�� �ƽ�Ű �ڵ�󿡼� ����
	for (int i = 0; i < len; i++)
	{
		// ���ĺ� �빮��, �ҹ����� ���
		if (('A' <= input[i] && input[i] < 'Z')
			|| ('a' <= input[i] && input[i] < 'z'))
		{
			// ���ĺ� �빮���� ���
			if (input[i] < 'a')
			{
				// �ҹ��ڷ� �ٲ���
				input[i] += offset;
			}

			push(&s, input[i]);

			// ������ ����� ���� ���ؼ�
			// �ٸ��ٸ� ���ĺ� + ī��Ʈ ���
			if (i > 0 && prev != peek(&s))
			{
				printf("%c%d", prev, count);
				count = 0;
			}

			count++;
			prev = input[i];
		}
	}

	printf("%c%d", prev, count);
	*/

	/*
	// �������� 13��
	StackType s;
	init_stack(&s);

	char input[256];
	scanf_s("%s", input, (unsigned int)sizeof(input));

	int len = strlen(input);

	char prev = ' ';
	for (int i = 0; i < len; i++)
	{
		push(&s, input[i]);

		// ���� ������ �� �� (���� �ֱ�)�� ������ �ٸ��ٸ�
		// prev ����
		if (peek(&s) != prev)
		{
			prev = input[i];
			printf("%c", prev);
		}
	}
	*/

	
	// �������� 16��
	char input[256];

	fgets(input, sizeof(input), stdin);

	int len = strlen(input);
	input[len - 1] = '\0';		// fgets()�� �Է¹����� �� �� ������ �Է¹��� �� ������, 
								// ����Ű�� �ٹٲ� ���ڰ� ���ڿ� ���� ����. �������ش�.
	len = strlen(input);		// ����������, ���̵� �ٽ� ���Ѵ�.

	StackType s_original;		// ���� ���� (pop���ϰ� ������ ���� ����)
	init_stack(&s_original);

	StackType s_pop;			// pop ����
	init_stack(&s_pop);

	char checkStr[256];
	int offset = 'a' - 'A';			// �빮�ڸ� �ҹ��ڷ� �����ϱ� ����
	for (int i = 0; i < len; i++)
	{
		if (input[i] != ' '
			&& input[i] != '.'
			&& input[i] != '\''
			&& input[i] != ',')
		{
			// �빮�ڶ�� �ҹ��ڷ� ����
			if (input[i] >= 'A'
				&& input[i] < 'Z')
				input[i] += offset;

			push(&s_original, input[i]);
			push(&s_pop, input[i]);
		}
	}

	// üũ�� ���� s_pop�� pop�� �޾� ����,
	// �� �� ���� ������ s�� ���� ó���� �������� �˻�
	StackType s_converted;
	init_stack(&s_converted);
	
	while (!is_empty(&s_pop))
	{
		push(&s_converted, pop(&s_pop));
	}

	// ������? ���ٰ� �����ϰ� �˻�
	bool isSame = true;

	// ������ ��ȯ�� üũ�� ������ ���� �˻�
	for (int i = 0; i < s_original.size; i++)
	{
		char original = pop(&s_original);
		char converted = pop(&s_converted);

		if (original != converted)
		{
			isSame = false;
			break;
		}
	}

	if (isSame)
	{
		printf("ȸ���Դϴ�.");
	}
	else
	{
		printf("ȸ���� �ƴմϴ�.");
	}

	return 0;
}