#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51][51]; //dp는 y,x에서 오락실을 몇개 방문했는지, 이전에 몇번 오락실을 방문하고왔는지를 저장해놓음. 그 상태에서 n,m을 방문하는 경우의 수이다.
											// 세번째는 좀 더 정확하게 말해서, 몇 번더 오락실에 방문할 수 있는지 카운트이다.
int func(int y, int x, int cnt, int prevv)
{
	//cout << y << ", " << x << '\n';
	if (cnt < 0) return 0;
	if (y > n || x > m) return 0;
	if (y == n && x == m)	// 학원에 도착한 경우
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prevv) return 1;	// 학원이 오락실일 수도 있다. 그렇다면 그 경우에는 cnt가 1이어야 함.
		return 0;
	}
	if (dp[y][x][cnt][prevv] != -1) return dp[y][x][cnt][prevv];
	dp[y][x][cnt][prevv] = 0;
	if (a[y][x] == 0) dp[y][x][cnt][prevv] = (func(y + 1, x, cnt, prevv) + func(y, x + 1, cnt, prevv)) % 1000007;
	else if (a[y][x] > prevv) dp[y][x][cnt][prevv] = (func(y + 1, x, cnt - 1, a[y][x]) + func(y, x + 1, cnt - 1, a[y][x])) % 1000007;

	//cout << y << ", " << x << '\n';
	//cout << " dp: " << dp[y][x][cnt][prevv] << '\n';

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
		//cout << "=============\n";
		cout << func(1, 1, i, 0) << ' ';
	}
}