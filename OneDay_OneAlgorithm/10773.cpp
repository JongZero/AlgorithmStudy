#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k = 0;
	std::cin >> k;

	int* stack = new int[k];
	// 초기화
	for (int i = 0; i < k; i++)
	{
		stack[i] = 0;
	}

	// 숫자를 넣어야 할 인덱스
	int nowIndex = 0;

	for (int i = 0; i < k; i++)
	{
		int n = 0;
		std::cin >> n;

		// 가장 최근에 쓴 수를 지운다.
		if (n == 0)
		{
			stack[nowIndex - 1] = 0;
			nowIndex--;
		}
		// 아닐 경우 넣는다.
		else
		{
			stack[nowIndex] = n;
			nowIndex++;
		}
	}

	// 합 출력
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += stack[i];
	}

	std::cout << sum;

	delete[] stack;
	stack = nullptr;

	return 0;
}