#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51][51];	// dp는 y,x에서 cnt번 남은 횟수에서 prev를 바로 이전에 방문하고 온 상황을 저장해놓는다.

int func(int y, int x, int cnt, int prevv)
{
	if (y > n || x > m) return 0;
	if (y == n && x == m)
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prevv) return 1;	// 마지막 도착 지점이 오락실일 수 있음
		return 0;
	}
	if (dp[y][x][cnt][prevv] != -1) return dp[y][x][cnt][prevv];
	dp[y][x][cnt][prevv] = 0;
	if (a[y][x] == 0)
		dp[y][x][cnt][prevv] = (func(y, x + 1, cnt, prevv) + func(y + 1, x, cnt, prevv)) % 1000007;
	else if (a[y][x] > prevv)
		dp[y][x][cnt][prevv] = (func(y, x + 1, cnt - 1, a[y][x]) + func(y + 1, x, cnt - 1, a[y][x])) % 1000007;
	return dp[y][x][cnt][prevv];
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