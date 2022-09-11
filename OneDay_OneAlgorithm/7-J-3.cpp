#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001];	// dp에는 k무게 일 때 들고 갈 수 있는 최대 가치이다. 물건은 1번만 담을 수 있다.

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
		for (int j = k; j >= w; j--)		// 이런식으로 배열의 오른쪽부터 순회하면, 이전 상태값에 영향을 안 받는다. 즉, 물건 1개만을 고려한다.
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}