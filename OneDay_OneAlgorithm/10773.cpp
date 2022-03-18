#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k = 0;
	std::cin >> k;

	int* stack = new int[k];
	// �ʱ�ȭ
	for (int i = 0; i < k; i++)
	{
		stack[i] = 0;
	}

	// ���ڸ� �־�� �� �ε���
	int nowIndex = 0;

	for (int i = 0; i < k; i++)
	{
		int n = 0;
		std::cin >> n;

		// ���� �ֱٿ� �� ���� �����.
		if (n == 0)
		{
			stack[nowIndex - 1] = 0;
			nowIndex--;
		}
		// �ƴ� ��� �ִ´�.
		else
		{
			stack[nowIndex] = n;
			nowIndex++;
		}
	}

	// �� ���
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