#include <bits/stdc++.h>
using namespace std;

int t, w, dp[1001][2][31];	// dp�� O��, O������, O������Ƚ���� ���¿��� �ִ�� ���� �� �ִ� �ڵΰ���
int a[1001];

int func(int ti, int tree, int cnt)
{
	if (ti >= t) return 0;
	if (cnt < 0) return 0;
	if (dp[ti][tree][cnt]) return dp[ti][tree][cnt];
	dp[ti][tree][cnt] = max(
		func(ti + 1, tree, cnt), 
		func(ti + 1, (tree + 1) % 2, cnt - 1)) + (a[ti] - 1 == tree);
	return dp[ti][tree][cnt];
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