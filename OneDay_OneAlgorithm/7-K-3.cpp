#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51][51];	// dp는 y,x에서 오락실을 cnt번 더 방문할 수 있을 때, 이전에 prevv번 오락실을 방문하고 온 상태에서 학원까지 가는 경우의 수이다.

int func(int y, int x, int cnt, int prevv)
{
	if (cnt < 0) return 0;
	if (y > n || x > m) return 0;
	if (y == n && x == m)
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prevv) return 1;	// 학원 위치에 오락실이 있을 수 있다.
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
		int b, c;
		cin >> b >> c;
		a[b][c] = i;
	}
	for (int i = 0; i <= c; i++)
	{
		cout << func(1, 1, i, 0) << ' ';
	}
}