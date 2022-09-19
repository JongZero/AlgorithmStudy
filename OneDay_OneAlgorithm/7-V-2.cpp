#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

struct A
{
	int walkTime;
	int walkMoney;
	int rideTime;
	int rideMoney;
};

A a[101];
ll dp[101][100001];

ll func(int cnt, int timee)
{
	if (cnt > n) return 0;
	if (timee > k) return -1e9;
	long long& d = dp[cnt][timee];
	if (d != -1) return d;
	d = -1e9;
	d = max(d, func(cnt + 1, timee + a[cnt].walkTime) + a[cnt].walkMoney);
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