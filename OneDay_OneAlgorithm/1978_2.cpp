#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	std::vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> vec[i];
	}

	// �׳� ���鼭 ã��
	/*
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int now = vec[i];

		bool isPrime = true;
		for (int j = 2; j < now; j++)
		{
			if (now % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		// 1�� �ڱ� �ڽ� �̿ܿ� ������������ ���� ���� ��� �Ҽ�
		if (vec[i] != 1 && isPrime)
		{
			count++;
		}
	}

	std::cout << count;
	*/

	return 0;
}