#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	// 3킬로그램 봉지 개수와 5킬로그램 봉지 개수 배열
	// 이 중에 가장 적은 합을 찾을 것이다.
	vector<int> k3;
	vector<int> k5;

	// i -> 3킬로그램 봉지 개수, k -> 5킬로그램 봉지 개수
	// 1씩 증가시키면서 3 * i + 5 * k가 n이 되는 조합을 찾을 것이다.
	// n보다 더 큰 수가 나온다면 break로 탈출
	int i = 0;
	int k = 0;

	// i하나에, k를 다 조합시켜봄 ( i = 0, k = 0,1,2,3,4... // i = 1, k = 0,1,2,3,4...)
	while (true)
	{
		k = 0;
		while (true)
		{
			int now = 3 * i + 5 * k;

			if (now > n)
			{
				break;
			}

			if (now == n)
			{
				k3.push_back(i);
				k5.push_back(k);
			}

			k++;
		}

		if (3 * i > n)
		{
			break;
		}

		i++;
	}

	i = 0;
	k = 0;
	// k하나에, i를 다 조합시켜봄 ( k = 0, i = 0,1,2,3,4... // k = 1, i = 0,1,2,3,4...)
	while (true)
	{
		i = 0;
		while (true)
		{
			int now = 3 * i + 5 * k;

			if (now > n)
			{
				break;
			}

			if (now == n)
			{
				k3.push_back(i);
				k5.push_back(k);
			}

			i++;
		}

		if (3 * k > n)
		{
			break;
		}

		k++;
	}
	
	// 가장 적은 합이되는 i, k 조합을 찾는다.
	if (k3.size() > 0)
	{
		int sum = 100000;
		for (int i = 0; i < k3.size(); i++)
		{
			if (k3[i] + k5[i] < sum)
			{
				sum = k3[i] + k5[i];
			}
		}

		cout << sum;
	}
	else
	{
		cout << -1;
	}

	return 0;
}