#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;

	// input
	std::vector<int> inputVec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];
	}

	// dp
	std::vector<int> dpVec(k + 1);

	// k가 10이라면, 1원부터 10원까지 경우의 수를 누적시켜주면됨
	// 0원도 경우의 수 1개로 친다.
	dpVec[0] = 1;
	for (int j = 0; j < n; j++)
	{
		for (int i = inputVec[j]; i < k + 1; i++)
		{
			dpVec[i] += dpVec[i - inputVec[j]];
		}
	}

	std::cout << dpVec[k];

	return 0;
}