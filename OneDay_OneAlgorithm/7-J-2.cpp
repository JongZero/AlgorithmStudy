#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001];	// dp���� j���� �� �� �賶�� ���� ���ǵ��� �ִ� ��ġ(�賶���� ���Ǵ� 1���� ���� �� �ִ�.)

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
		for (int j = k; j >= w; j--)	// �����ʿ������� �迭�� ��ȸ�ϸ�, ������ ���°��� ������ ���� �ʰ� �ȴ�.
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}