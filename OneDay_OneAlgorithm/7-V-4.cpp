#include <bits/stdc++.h>
using namespace std;

int n, k;

struct A
{
	int walkTime, walkMoney, rideTime, rideMoney;
};
A a[101];
int dp[101][100001];

int func(int cnt, int timee)
{
	cout << cnt << ", " << timee << '\n';
	if (timee > k) return -1e9;
	if (cnt > n) return 0;
	int& d = dp[cnt][timee];
	if (d != -1)
	{
		cout << "이전에 한번 갔었음\n";
		return d;
	}
	d= -1e9;
	d = func(cnt + 1, timee + a[cnt].walkTime) + a[cnt].walkMoney;
	d = max(d, func(cnt + 1, timee + a[cnt].rideTime) + a[cnt].rideMoney);
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].walkTime >> a[i].walkMoney >> a[i].rideTime >> a[i].rideMoney;
	}
	cout << func(0, 0);
}