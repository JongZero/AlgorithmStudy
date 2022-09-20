#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001][101];

struct A
{
	int walkTime;
	int walkMoney;
	int rideTime;
	int rideMoney;
};

A a[101];

int func(int timee, int cnt)
{
	if (cnt > n) return 0;
	if (timee > k) return -1e9;
	int& d = dp[timee][cnt];
	if (d != -1) return d;
	d = -1e9;
	d = max(d, func(timee + a[cnt].walkTime, cnt + 1) + a[cnt].walkMoney);
	d = max(d, func(timee + a[cnt].rideTime, cnt + 1) + a[cnt].rideMoney);
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