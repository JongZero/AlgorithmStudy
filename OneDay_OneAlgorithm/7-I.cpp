#include <bits/stdc++.h>
using namespace std;

int dp[10004], ret, n, m;
int c[5004], p[5004];

int func(int money, int k, int nowC)
{
	//cout << "money: " << money << " Ä®·Î¸®: " << k << '\n';
	if (money > m)
	{
		return 0;
	}
	ret = max(ret, k);
	if (dp[money])
	{
		//cout << "ÀÌ¹ÌÀÖ´Ù!!!!!!!!!\n";
		//cout << "money: " << money << " Ä®·Î¸®: " << k << '\n';
		//cout << dp[money] << '\n';
		return dp[money];
	}
	dp[money] = k;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = max(temp, func(money + p[i], k + c[i], c[i]));
	}
	if (temp != 0)
		dp[money] = temp - nowC;
	//cout << "money: " << money << " Ä®·Î¸®: " << k << '\n';
	//cout << dp[money] << '\n';
	return dp[money];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		float d;
		cin >> n >> d;
		m = d * 100;
		if (n == 0 && m == 0) break;

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++)
		{
			float b;
			cin >> c[i] >> b;
			p[i] = b * 100;
		}
		func(0, 0, 0);
		//cout << func(m, 0) << '\n';
		cout << ret << '\n';
		ret = 0;
	}
}