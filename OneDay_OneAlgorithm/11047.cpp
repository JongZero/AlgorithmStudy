#include <iostream>
#include <vector>
using namespace std;

int CalculateMaxCoin(vector<int>& coins, int k)
{
	int max = 0;
	int n = coins.size();

	for (int i = 0; i < n; i++)
	{
		// k보다 동전의 가치가 작으면서
		if (coins[i] <= k)
		{
			// 가장 큰 가치를 구한다.
			if (max < coins[i])
				max = coins[i];
		}
		// k보다 동전의 가치가 더 크다면 무의미하다.
		else
		{
			break;
		}
	}

	return max;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		coins[i] = a;
	}

	// 동전의 가치 중 k보다 작으면서 가장 큰 가치
	int max = 0;

	int totalCount = 0;
	while (true)
	{
		// k가 0이 될 때까지 카운트를 구하고 뺀다.
		if (k <= 0)
		{
			break;
		}

		// 동전의 가치 중 k보다 작으면서 가장 큰 가치 구하기
		max = CalculateMaxCoin(coins, k);
		
		if (max > 0)
		{
			int count = k / max;
			totalCount += count;

			k -= count * max;
		}
	}
	
	cout << totalCount;

	return 0;
}
