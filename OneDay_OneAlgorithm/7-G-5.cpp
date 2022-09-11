#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];	// dp���� n���� ��ġ�� �������� k���� �ǰ� �ϴ� �ּ� ������ ������ ��� ����
const int INF = 987654321;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, INF);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);		// t�� 3�� ��, 3���� ���� �� �ִ� �ּ� ������ 0���� ���� �� �ִ� �ּ� ���� + 1�̴�.
													// ���������� 6���� ���� �� �ִ� �ּ� ������ 3���� ���� �� �ִ� �ּ� ���� + 1(3��¥�� ���� 2��)�̴�.
													// �׷��� +1 �� ���� ������ �ּҴ� �ƴ� �� �ִ�. ���� �ּ� �񱳸� ����� �Ѵ�.
		}
	}
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}