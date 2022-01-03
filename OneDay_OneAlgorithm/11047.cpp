#include <iostream>
#include <vector>
using namespace std;

int CalculateMaxCoin(vector<int>& coins, int k)
{
	int max = 0;
	int n = coins.size();

	for (int i = 0; i < n; i++)
	{
		// k���� ������ ��ġ�� �����鼭
		if (coins[i] <= k)
		{
			// ���� ū ��ġ�� ���Ѵ�.
			if (max < coins[i])
				max = coins[i];
		}
		// k���� ������ ��ġ�� �� ũ�ٸ� ���ǹ��ϴ�.
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

	// ������ ��ġ �� k���� �����鼭 ���� ū ��ġ
	int max = 0;

	int totalCount = 0;
	while (true)
	{
		// k�� 0�� �� ������ ī��Ʈ�� ���ϰ� ����.
		if (k <= 0)
		{
			break;
		}

		// ������ ��ġ �� k���� �����鼭 ���� ū ��ġ ���ϱ�
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
