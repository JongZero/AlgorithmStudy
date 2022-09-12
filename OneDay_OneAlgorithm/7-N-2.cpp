#include <bits/stdc++.h>
using namespace std;
const int n = 10;
const int INF = 987654321;
int a[11][11], ret = INF;
int cnt[6];

bool isAttach(int y, int x, int k)
{
	if (y + k > n || x + k > n) return false;
	for (int i = y; i < y + k; i++)
	{
		for (int j = x; j < x + k; j++)
		{
			if (a[i][j] == 0)
				return false;
		}
	}
	return true;
}

void update(int y, int x, int k, int t)
{
	for (int i = y; i < y + k; i++)
	{
		for (int j = x; j < x + k; j++)
		{
			a[i][j] = t;
		}
	}
}

void func(int y, int x)
{
	//cout << y << ", " << x << '\n';
	if (x == n)
	{
		func(y + 1, 0);
		return;
	}
	if (y == n)
	{
		int temp = 0;
		for (int i = 1; i <= 5; i++)
			temp += cnt[i];
		ret = min(ret, temp);
		return;
	}
	if (a[y][x] == 0)
	{
		func(y, x + 1);
		return;
	}
	for (int i = 5; i >= 1; i--)
	{
		if (cnt[i] >= 5) continue;
		if (isAttach(y, x, i))
		{
			cnt[i]++;
			update(y, x, i, 0);
			func(y, x + i);
			cnt[i]--;
			update(y, x, i, 1);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	func(0, 0);
	if (ret == INF) cout << -1;
	else cout << ret;
}