#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int dp[2501][2501], dp2[2501];

int func(int idx)
{
	if (idx == s.size()) return 0;
	int& d = dp2[idx];
	if (d != INF) return d;
	for (int i = 1; i <= s.size(); i++)
	{
		if (dp[idx][i]) d = min(d, func(idx + i) + 1);
	}
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp2, dp2 + 2501, INF);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		dp[i][1] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 2; i + j <= s.size(); j++)
		{
			dp[i][j] = 1;
			int w = i + j - 1;
			for (int k = i; k < i + j / 2; k++, w--)
			{
				if (s[k] != s[w])
				{
					dp[i][j] = 0;
					break;
				}
			}
		}
	}
	cout << func(0);
}