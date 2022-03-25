#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;		// 교체!
							// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
							// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
	int size;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
	s->size = 0;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
		s->size++;
	}
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		s->size--;
		return s->data[(s->top)--];
	}
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

// 연습문제 14번
// 사이즈
int GetSize(StackType* s)
{
	return s->size;
}
// ===== 스택 코드의 끝 ===== 

int main(void)
{
	/*
	// 연습문제 11번
	StackType s;		// 괄호를 넣을 스택 (push만 한다. - 사이즈가 계속 증가되야함)
	StackType matchS;	// s의 사이즈를 넣을 스택 (push, pop을 한다.) - ( ) 매칭용
	init_stack(&s);
	init_stack(&matchS);

	const char* str = "((())(()))";		// 1 2 3 3 2 4 5 5 4 1
	//const char* str = "(((((()";		// 1 2 3 4 5 6 6 (책은 오타인듯)
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
	// 연습문제 12번
	StackType s;
	init_stack(&s);

	char input[256];
	scanf_s("%s", input, (unsigned int)sizeof(input));

	int len = strlen(input);
	
	char prev = ' ';
	int count = 0;
	int offset = 'a' - 'A';		// 'a'와 'A'의 아스키 코드상에서 차이
	for (int i = 0; i < len; i++)
	{
		// 알파벳 대문자, 소문자일 경우
		if (('A' <= input[i] && input[i] < 'Z')
			|| ('a' <= input[i] && input[i] < 'z'))
		{
			// 알파벳 대문자일 경우
			if (input[i] < 'a')
			{
				// 소문자로 바꿔줌
				input[i] += offset;
			}

			push(&s, input[i]);

			// 이전에 저장된 값과 비교해서
			// 다르다면 알파벳 + 카운트 출력
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
	// 연습문제 13번
	StackType s;
	init_stack(&s);

	char input[256];
	scanf_s("%s", input, (unsigned int)sizeof(input));

	int len = strlen(input);

	char prev = ' ';
	for (int i = 0; i < len; i++)
	{
		push(&s, input[i]);

		// 현재 스택의 맨 위 (가장 최근)이 이전과 다르다면
		// prev 갱신
		if (peek(&s) != prev)
		{
			prev = input[i];
			printf("%c", prev);
		}
	}
	*/

	
	// 연습문제 16번
	char input[256];

	fgets(input, sizeof(input), stdin);

	int len = strlen(input);
	input[len - 1] = '\0';		// fgets()로 입력받으면 한 줄 단위로 입력받을 수 있지만, 
								// 엔터키의 줄바꿈 문자가 문자열 끝에 들어간다. 제거해준다.
	len = strlen(input);		// 제거했으니, 길이도 다시 구한다.

	StackType s_original;		// 원본 스택 (pop안하고 스택의 원소 유지)
	init_stack(&s_original);

	StackType s_pop;			// pop 스택
	init_stack(&s_pop);

	char checkStr[256];
	int offset = 'a' - 'A';			// 대문자를 소문자로 변경하기 위해
	for (int i = 0; i < len; i++)
	{
		if (input[i] != ' '
			&& input[i] != '.'
			&& input[i] != '\''
			&& input[i] != ',')
		{
			// 대문자라면 소문자로 변경
			if (input[i] >= 'A'
				&& input[i] < 'Z')
				input[i] += offset;

			push(&s_original, input[i]);
			push(&s_pop, input[i]);
		}
	}

	// 체크용 스택 s_pop의 pop을 받아 저장,
	// 이 후 원본 스택인 s와 비교해 처음과 같은지를 검사
	StackType s_converted;
	init_stack(&s_converted);
	
	while (!is_empty(&s_pop))
	{
		push(&s_converted, pop(&s_pop));
	}

	// 같은지? 같다고 가정하고 검사
	bool isSame = true;

	// 원본과 변환된 체크용 스택을 서로 검사
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
		printf("회문입니다.");
	}
	else
	{
		printf("회문이 아닙니다.");
	}

	return 0;
}