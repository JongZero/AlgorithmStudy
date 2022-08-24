#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ondo;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	ondo.resize(n);

	int max = -100 * 100000 - 10;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ondo[i];

		sum += ondo[i];

		count++;
		if (count > k)
		{
			count = k;
			sum -= ondo[i - k];
		}

		if (count >= k)
		{
			if (sum > max)
				max = sum;
		}
	}

	cout << max;
}