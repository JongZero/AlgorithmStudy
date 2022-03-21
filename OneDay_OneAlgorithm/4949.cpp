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
				// ���� ���̿� ��ȣ�� �ִ°� �ƴ϶��, �Ǵ� '[', '(' ���
				// ���� ó��
				_stack.push(str[i]);
			}
			else if (str[i] == ']')
			{
				// top�� ���°� �¾ƾ���
				if (_stack.empty() || _stack.top() != '[')
				{
					_check = false;
					break;
				}

				_stack.pop();
			}
			else if (str[i] == ')')
			{
				// top�� ���°� �¾ƾ���
				if (_stack.empty() || _stack.top() != '(')
				{
					_check = false;
					break;
				}

				_stack.pop();
			}
		}

		// ���ÿ� ���� �����ִٸ� ��ȣ�� �� ������ �ʾ� ¦���� ���� �ʴ� ��
		if (!_stack.empty())
		{
			_check = false;
		}

		// ���
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