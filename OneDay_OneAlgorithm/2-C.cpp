#include <bits/stdc++.h>
using namespace std;

int n, mat[104][104], visited[104][104], ret;
map<int, int> mp;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };

void dfs(int y, int x, int k)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (mat[ny][nx] <= k) continue;
		dfs(ny, nx, k);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	ret = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int in;
			cin >> in;
			mat[i][j] = in;
			mp[in]++;
		}
	}
	for (auto it : mp)
	{
		int k = it.first;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] <= k) continue;
				if (visited[i][j]) continue;
				dfs(i, j, k);
				cnt++;
			}
		}
		if (cnt > ret)
			ret = cnt;

		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
	}
	cout << ret;
}