#include <bits/stdc++.h>
using namespace std;

int t, w, a[1001];
int dp[1001][2][31];

int func(int nowTime, int nowTree, int cnt)
{
	//cout << "nowTime : " << nowTime << " nowTree : " << nowTree << " cnt : " << cnt << '\n';
	if (nowTime >= t) return 0;
	if (cnt < 0) return 0;
	if (dp[nowTime][nowTree][cnt]) return dp[nowTime][nowTree][cnt];
	dp[nowTime][nowTree][cnt] = max(
		func(nowTime + 1, nowTree, cnt),
		func(nowTime + 1, (nowTree + 1) % 2, cnt - 1));
	if (nowTree + 1 == a[nowTime]) dp[nowTime][nowTree][cnt] += 1;
	//cout << "nowTime : " << nowTime << " nowTree : " << nowTree << " cnt : " << cnt << " == dp : " << dp[nowTime][nowTree][cnt] << '\n';
	return dp[nowTime][nowTree][cnt];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}
	int f1 = func(0, 0, w);
	int f2 = func(0, 1, w - 1);
	cout << max(f1, f2);
}