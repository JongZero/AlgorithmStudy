#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;

	// k���� �����ϸ� �� �̻� ���� �ʿ� ����
	int kCount = 0;

	// 1���� n���� �����鼭 ����� ����
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		// ������ �������ٸ� ���
		if (n % i == 0)
		{
			kCount++;

			if (kCount == k)
			{
				break;
			}
		}
	}

	// k��° ����� ������ ���� ���
	if (kCount == k)
	{
		std::cout << i;
	}
	else
	{
		std::cout << 0;
	}

	return 0;
}