#include <iostream>
#include <stack>
#include <string>
#include <stack>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string input;
	std::cin >> input;

	stack<char> _stack;

	int result = 0;
	int tempResult = 1;
	char prev = ' ';
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			tempResult *= 2;
			_stack.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (_stack.empty())
			{
				result = -1;
				break;
			}

			char top = _stack.top();
			if (top != '(')
			{
				result = -1;
				break;
			}
			else if (prev == '(')
			{
				result += tempResult;
			}

			tempResult /= 2;
			_stack.pop();
		}
		else if (input[i] == '[')
		{
			tempResult *= 3;
			_stack.push(input[i]);
		}
		else if (input[i] == ']')
		{
			if (_stack.empty())
			{
				result = -1;
				break;
			}

			char top = _stack.top();
			if (top != '[')
			{
				result = -1;
				break;
			}
			else if (prev == '[')
			{
				result += tempResult;
			}

			tempResult /= 3;
			_stack.pop();
		}
		else
		{
			result = -1;
			break;
		}

		prev = input[i];
	}

	// 스택이 다 비어있어야함 (그래야 짝이 맞는 것)
	if (!_stack.empty() || result == -1)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << result;
	}

	return 0;
}