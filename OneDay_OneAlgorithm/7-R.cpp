#include <bits/stdc++.h>
using namespace std;

int n, m, a[2001], dp[2001][2001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][i] = 1;
	}
	for (int c = 1; c <= n; c++)
	{
		// È¦¼ö
		for (int i = 1; i <= 1000; i++)
		{
			int s = c - i;
			int e = c + i;
			if (s <= 0 || e > n) break;
			if (a[s] == a[e]) 
			{ 
				dp[s][e] = 1;
				cout << s << ", " << e << "´Â ÆÓ¸°µå·ÒÀÌ´Ù.\n";
			}
			else break;
		}
		// Â¦¼ö
		for (int i = 1; i <= 1000; i++)
		{
			int s = c;
			int e = s + i;

			int s2 = e + 1;
			int e2 = s2 + i;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';

		//if (dp[s][e] != -1)
		//{
		//	cout << dp[s][e];
		//	continue;
		//}
		//int cnt = e - s;
		//cnt = s + cnt / 2;
		//if (cnt % 2 == 0)
		//	cnt--;
		//bool isP = true;
		//int w = e;
		////cout << "cnt: " << cnt << '\n';
		//for (int q = s; q <= cnt; q++, w--)
		//{
		//	if (a[q] != a[w])
		//	{
		//		isP = false;
		//		break;
		//	}
		//}
		//if (isP) dp[s][e] = 1;
		//else dp[s][e] = 0;
		//cout << dp[s][e] << '\n';
	}
}