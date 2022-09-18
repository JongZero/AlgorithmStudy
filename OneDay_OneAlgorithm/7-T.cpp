#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, a[101];
ll dp[21][101];

int plusF(int a, int b)
{
	return a + b;
}
int minusF(int a, int b)
{
	return a - b;
}

ll func(int ret, int idx)
{
	if (ret < 0 || ret > 20) return 0;
	if (idx == n - 1)
	{
		if (ret == a[n])
			return 1;
		return 0;
	}
	ll& d = dp[ret][idx];
	if (d != -1) return d;
	d = func(plusF(ret, a[idx + 1]), idx + 1) + func(minusF(ret, a[idx + 1]), idx + 1);
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << func(a[1], 1);
}