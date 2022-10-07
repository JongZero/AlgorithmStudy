#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, h;
int visited[31][11];
int ret = INF;

bool isGoal()
{
	for (int i = 1; i <= m; i++)
	{
		int s = i;
		for (int j = 1; j <= n; j++)
		{
			if (visited[j][s]) s++;
			else if (visited[j][s - 1]) s--;
		}
		if (s != i) return false;
	}
	return true;
}

void func(int x, int cnt)
{
	if (cnt > 3 || cnt >= ret)
		return;

	if (isGoal())
	{
		ret = min(ret, cnt);
		return;
	}

	for (int i = x; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[j][i]) continue;
			if (visited[j][i + 1]) continue;
			if (visited[j][i - 1]) continue;

			visited[j][i] = 1;
			func(i, cnt + 1);
			visited[j][i] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> m >> h >> n;
	for (int i = 0; i < h; i++)
	{
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
	func(1, 0);
	if (ret == INF) cout << -1;
	else cout << ret;
}