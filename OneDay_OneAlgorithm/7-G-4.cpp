#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];	//dp���� �ּҰ��� ��� ����, n�� ��ġ�� ���� ����... 1���� �� 1~k���� ���� �� �ִ� �ּ�, 3���� �� 1~k���� ���� �� �ִ� �ּ�

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, 987654321);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);
		}
	}
	if (dp[k] == 987654321) cout << -1;
	else cout << dp[k];
}