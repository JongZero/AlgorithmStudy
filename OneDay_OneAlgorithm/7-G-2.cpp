#include <bits/stdc++.h>
using namespace std;

int t, k, dp[10001];	// dp���� �ּڰ��� ��� ����, ������ ������ ��ġ�� ����
						// ex) k = 10, n = 1,3,5
							// �Ʒ����� �߿��� ���� k�� 0�� �� �ּҰ� 0���� ���´ٴ� ���̴�.
							// n�� 1�� �� �ּҰ�
							// k		0	1	2	3	4	5	6	7	8	9	10
							// �ּҰ�		0	1	2	3	4	5	6	7	8	9	10
							
							// n�� 3�� �� �ּҰ�(*�� ���ŵ� �ּҰ�)
							// k		0	1	2	3	4	5	6	7	8	9	10
							// �ּҰ�		0	1	2	1*	4	5	2*	7	8	3*	10

							// n�� 5�� �� �ּҰ�
							// k		0	1	2	3	4	5	6	7	8	9	10
							// �ּҰ�		0	1	2	1	4	1*	2	7	8	3	2*

							// ���� ��ȭ���� dp[i] = dp[i - n] + 1�� ���� �� �ְ�, �Ź� �ּҰ��� �������ش�.
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, 1000000000);
	dp[0] = 0;
	cin >> t >> k;
	for (int q = 0; q < t; q++)
	{
		int n;
		cin >> n;
		for (int i = n; i <= k; i++)
		{
			dp[i] = min(dp[i], dp[i - n] + 1);
		}
	}
	if (dp[k] == 1000000000) cout << -1;
	else cout << dp[k];
}