#include <bits/stdc++.h>
using namespace std;

int t, w, dp[1001][2][31], a[1001];	// dp���� ���� ��, ���� ��ġ�� ���� ��ȣ, �� �� �� ������ �� �ִ����� ���¿��� ���� ���� ���� �� �ִ� ����.

int func(int ttt, int tree, int cnt)
{
	if (cnt < 0) return 0;
	if (ttt >= t) return 0;
	if (dp[ttt][tree][cnt]) return dp[ttt][tree][cnt];
	dp[ttt][tree][cnt] = max(func(ttt + 1, tree, cnt), func(ttt + 1, (tree + 1) % 2, cnt - 1)) + ((a[ttt] - 1) == tree);
	return dp[ttt][tree][cnt];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}
	cout << max(func(0, 0, w), func(0, 1, w - 1));
}