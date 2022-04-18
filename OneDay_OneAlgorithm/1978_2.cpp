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

	// 그냥 돌면서 찾기
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

		// 1과 자기 자신 이외에 나눠떨어지는 수가 없을 경우 소수
		if (vec[i] != 1 && isPrime)
		{
			count++;
		}
	}

	std::cout << count;
	*/

	return 0;
}