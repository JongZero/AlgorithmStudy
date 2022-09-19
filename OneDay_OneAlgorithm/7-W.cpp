#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[100001], dp[100001][5][5];

int d1[] = { 0, 2, 1, 2, 1 };
int d2[] = { 0, 4, 3, 4, 3 };

int getScore(int from, int to)
{
	if (from == 0) return 2;
	if (from == to) return 1;
	if (from == d1[to] || from == d2[to])
	{
		return 3;
	}
	return 4;
}

int func(int idx, int x, int y)
{
	if (idx >= n) return 0;
	int& d = dp[idx][x][y];
	if (d != INF) return d;
	
	// 왼발을 이동한 경우
	d = min(d, func(idx + 1, a[idx], y) + getScore(x, a[idx]));

	// 오른발을 이동한 경우
	d = min(d, func(idx + 1, x, a[idx]) + getScore(y, a[idx]));

	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(&dp[0][0][0], &dp[0][0][0] + 100001 * 5 * 5, INF);
	while (true)
	{
		int t = 0;
		cin >> t;
		if (t == 0) break;

		a[n] = t;
		n++;
	}
	cout << func(0, 0, 0);
}