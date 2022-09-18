#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int dp[2501][2501], dp2[2501];

int func(int n)
{
	if (n == s.size())
		return 0;
	int& d = dp2[n];
	if (d != INF) return d;
	for (int i = 1; n + i <= s.size(); i++)
	{
		if (dp[n][i]) d = min(d, func(n + i) + 1);
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
	{
		dp[i][1] = 1;
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 2; i + j <= s.size(); j++)
		{
			// i부터 i + j까지 팰린드롬인지?
			int size = j;
			dp[i][j] = 1;
			int w = i + j - 1;
			for (int k = i; k < i + size / 2; k++, w--)
			{
				if (s[k] != s[w])
				{
					dp[i][j] = 0;
					break;
				}
			}
			//if (dp[i][j] == 1)
			//	cout << i << ", " << j << "는 팰린드롬이다! \n";
		}
	}
	cout << func(0);
}