#include <bits/stdc++.h>
using namespace std;

int n, m, k, mat[101][101], visited[101][101], temp;
vector<int> ret;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	temp++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (mat[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m >> k;
	while (k--)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		for (int i = sy; i < ey; i++)
		{
			for (int j = sx; j < ex; j++)
			{
				mat[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			if (mat[i][j]) continue;
			dfs(i, j);
			ret.push_back(temp);
			temp = 0;
		}
	}
	sort(ret.begin(), ret.end(), less<int>());
	cout << ret.size() << '\n';
	for (int it : ret)
		cout << it << ' ';
}