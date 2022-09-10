#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001];	// dp에는 j무게 일 때 배낭에 넣은 물건들의 최대 가치(배낭에는 물건당 1개만 넣을 수 있다.)

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
		for (int j = k; j >= w; j--)	// 오른쪽에서부터 배열을 순회하면, 이전의 상태값에 영향을 받지 않게 된다.
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}