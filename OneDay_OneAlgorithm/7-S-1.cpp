#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
string a;
int n, dp[2501][2501], dp2[2501];

int func(int idx)
{
	if (idx == n) return 0;
	int& d = dp2[idx];
	if (d != INF) return d;
	for (int i = 1; idx + i <= n; i++)
	{
		if (dp[idx][i]) d = min(d, func(idx + i) + 1);
	}
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	fill(dp2, dp2 + 2501, INF);

	cin >> a;
	n = a.size();

	for (int i = 0; i < n; i++)
		dp[i][1] = 1;

	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cout << i << ", " << 2 << "�� �Ӹ�����̴�!\n";
			dp[i][2] = 1;
		}
	}
	for (int _size = 3; _size <= n; _size++) {
		for (int j = 0; j + _size <= n; j++) {
			if (a[j] == a[j + _size - 1] && dp[j + 1][_size - 2])
			{
				cout << j << ", " << _size << "�� �Ӹ�����̴�!\n";
				dp[j][_size] = 1;
			}
		}
	}

	cout << func(0);
}