#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, h;
int ret = INF;
int visited[31][11];

bool check()
{
	for (int j = 1; j <= m; j++)
	{
		int s = j;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i][s]) s++;
			else if (visited[i][s - 1]) s--;
		}
		if (s != j)
		{
			return false;
		}
	}
	return true;
}

void func(int cnt, int s)
{
	if (cnt > 3 || cnt >= ret)
		return;

	if (check()) 
		ret = min(ret, cnt);

	for (int j = 1; j <= m; j++)
	{
		for (int i = s; i <= n; i++)
		{
			if (visited[i][j]) continue;
			if (visited[i][j - 1]) continue;
			if (visited[i][j + 1]) continue;
			visited[i][j] = 1;
			func(cnt + 1, i);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> m >> h >> n;
	for (int i = 1; i <= h; i++)
	{
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
	func(0, 1);
	if (ret == INF) cout << -1;
	else cout << ret;
}