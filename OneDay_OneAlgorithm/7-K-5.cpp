#include <bits/stdc++.h>
using namespace std;

int n, m, c, dp[51][51][51][51], a[51][51];

int func(int y, int x, int cnt, int prevv)
{
	if (y > n || x > m) return 0;
	if (cnt < 0) return 0;
	if (y == n && x == m)
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prevv) return 1;
		return 0;
	}
	int& d = dp[y][x][cnt][prevv];
	if (d != -1) return d;
	d = 0;
	if (a[y][x] == 0) d = func(y + 1, x, cnt, prevv) + func(y, x + 1, cnt, prevv);
	else if (a[y][x] > prevv) d = func(y + 1, x, cnt - 1, a[y][x]) + func(y, x + 1, cnt - 1, a[y][x]);
	d %= 1000007;
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++)
	{
		int q, w;
		cin >> q >> w;
		a[q][w] = i;
	}
	for (int i = 0; i <= c; i++)
	{
		cout << func(1, 1, i, 0) << ' ';
	}
}