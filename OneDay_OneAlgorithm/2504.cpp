#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 올바른 괄호열
	// ( ) [ ]
	// (()[[]])
	// 틀린 괄호열
	// (())[][]
	// (()()[]

	std::string input;
	std::cin >> input;

	std::stack<char> _stack;
	std::stack<int> _addStack;

	int result = 1;
	bool isFail = false;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' || input[i] == '[')
		{
			// 새로운 괄호 집단을 만나면 이전 괄호 집단의 결과는 따로 저장, 나중에 더할 것임
			if (i > 0 && _stack.empty())
			{
				_addStack.push(result);
				result = 1;
			}

			_stack.push(input[i]);
		}
		// ')' ']'
		else
		{
			// 스택이 비어있으면 Fail
			if (_stack.empty())
			{
				isFail = true;
				break;
			}

			char top = _stack.top();

			if (top == )

		}


	}

	if (isFail)
	{
		std::cout << 0;
	}
	else
	{

	}

	return 0;
}