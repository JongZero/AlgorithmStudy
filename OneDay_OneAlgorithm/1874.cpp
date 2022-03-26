#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// num�� 1�� ������Ű�鼭 stack�� ���� ���̴�.
	int num = 1;

	std::stack<int> _stack;
	std::vector<char> _vec;		// push, pop ����

	bool check = true;
	for (int i = 0; i < n; i++)
	{
		int input = 0;
		std::cin >> input;

		if (input >= num)
		{
			int loopCount = input - num;
			for (int j = 0; j <= loopCount; j++)
			{
				// input���� �ִ´�.
				_stack.push(num);
				_vec.push_back('+');
				num++;
			}
		}

		if (!_stack.empty())
		{
			int top = _stack.top();

			// ������ ���� �� ����
			if (input > top)
			{
				check = false;
				break;
			}
			else
			{
				for (int j = 0; j <= top - input; j++)
				{
					// ������ ������� break
					if (!_stack.empty())
					{
						_stack.pop();
						_vec.push_back('-');
					}
					else
					{
						break;
					}
				}
			}
		}
		// ������ ���� üũ
		else
		{
			check = false;
			break;
		}
	}

	if (check)
	{
		for (int i = 0; i < _vec.size(); i++)
		{
			std::cout << _vec[i] << '\n';
		}
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}
