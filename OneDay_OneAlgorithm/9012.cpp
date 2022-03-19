#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		// 스택 초기화
		int stack[51] = { 0, };

		// Input 받기
		std::string input;
		std::cin >> input;

		// 스택에 현재 넣어야할 인덱스
		int nowIndex = 0;

		// 스택의 현재 사이즈
		int stackSize = 0;

		for (int k = 0; k < input.size(); k++)
		{
			// '(' 일 때 push하고, 아닐 때 pop하면 정상이라면 스택의 사이즈가 0일 것임
			if (input[k] == '(')
			{
				stack[nowIndex] = 1;
				nowIndex++;
				stackSize++;
			}
			else
			{
				if (stackSize > 0)
				{
					stack[nowIndex - 1] = 0;
					nowIndex--;
				}

				stackSize--;

				// 스택의 사이즈가 0보다 작을 경우 그 시점에서 이미 이상하다.
				if (stackSize < 0)
				{
					break;
				}
			}
		}

		// 0이면 정상, 0이 아니면 비정상
		if (stackSize == 0)
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}

	return 0;
}