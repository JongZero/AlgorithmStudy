#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001];	// dp���� k���� �� �� ��� �� �� �ִ� �ִ� ��ġ�̴�. ������ 1���� ���� �� �ִ�.

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--)		// �̷������� �迭�� �����ʺ��� ��ȸ�ϸ�, ���� ���°��� ������ �� �޴´�. ��, ���� 1������ ����Ѵ�.
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}