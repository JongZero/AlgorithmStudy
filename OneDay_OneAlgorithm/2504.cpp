#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// �ùٸ� ��ȣ��
	// ( ) [ ]
	// (()[[]])
	// Ʋ�� ��ȣ��
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
			// ���ο� ��ȣ ������ ������ ���� ��ȣ ������ ����� ���� ����, ���߿� ���� ����
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
			// ������ ��������� Fail
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