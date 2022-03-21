#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	while (true)
	{
		std::string str;
		getline(std::cin, str);

		if (0 == str.compare("."))
		{
			break;
		}

		std::stack<char> _stack;
		bool _check = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '[' || str[i] == '(')
			{
				// 문자 사이에 괄호가 있는게 아니라면, 또는 '[', '(' 라면
				// 정상 처리
				_stack.push(str[i]);
			}
			else if (str[i] == ']')
			{
				// top과 형태가 맞아야함
				if (_stack.empty() || _stack.top() != '[')
				{
					_check = false;
					break;
				}

				_stack.pop();
			}
			else if (str[i] == ')')
			{
				// top과 형태가 맞아야함
				if (_stack.empty() || _stack.top() != '(')
				{
					_check = false;
					break;
				}

				_stack.pop();
			}
		}

		// 스택에 뭔가 남아있다면 괄호가 다 빠지지 않아 짝수가 맞지 않는 것
		if (!_stack.empty())
		{
			_check = false;
		}

		// 출력
		if (_check)
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}
	}

	return 0;
}