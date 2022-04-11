#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;

	// k까지 도달하면 더 이상 구할 필요 없음
	int kCount = 0;

	// 1부터 n까지 나누면서 약수를 구함
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		// 나누어 떨어진다면 약수
		if (n % i == 0)
		{
			kCount++;

			if (kCount == k)
			{
				break;
			}
		}
	}

	// k번째 약수가 존재할 때만 출력
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