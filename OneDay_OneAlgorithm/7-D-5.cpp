#include <bits/stdc++.h>
using namespace std;

int t, w, a[1001], dp[1001][2][31];	// dp에는 t초에서 0,1번 나무에 있을 때 남은 움직일 수 있는 횟수인 상태에서의 최대로 받을 수 있는 자두 개수

int func(int ti, int tree, int cnt)
{
	if (ti >= t) return 0;
	if (cnt < 0) return 0;
	int& d = dp[ti][tree][cnt];
	if (d != -1) return d;
	d = 0;
	d = max(func(ti + 1, tree, cnt), func(ti + 1, (tree + 1) % 2, cnt - 1)) + (a[ti] - 1 == tree);
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}
	cout << max(func(0, 0, w), func(0, 1, w - 1));
}