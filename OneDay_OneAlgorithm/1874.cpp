#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// num을 1씩 증가시키면서 stack에 넣을 것이다.
	int num = 1;

	std::stack<int> _stack;
	std::vector<char> _vec;		// push, pop 저장

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
				// input까지 넣는다.
				_stack.push(num);
				_vec.push_back('+');
				num++;
			}
		}

		if (!_stack.empty())
		{
			int top = _stack.top();

			// 수열을 만들 수 없음
			if (input > top)
			{
				check = false;
				break;
			}
			else
			{
				for (int j = 0; j <= top - input; j++)
				{
					// 스택이 비었으면 break
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
		// 스택이 비었어도 체크
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
