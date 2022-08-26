#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int mat[51][51];
int visited[51][51];

void dfs(int y, int x, int n, int m)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (mat[ny][nx] == 0) continue;
		dfs(ny, nx, n, m);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		int m = 0, n = 0, k = 0;
		cin >> m >> n >> k;
		//vector<vector<int>> mat(n, vector<int>(m, 0));
		//vector<vector<int>> visited(n, vector<int>(m, 0));
		fill(&mat[0][0], &mat[0][0] + n * m, 0);
		fill(&visited[0][0], &visited[0][0] + n * m, 0);
		for (int j = 0; j < k; j++)
		{
			int x = 0, y = 0;
			cin >> x >> y;
			mat[y][x] = 1;
		}
		int ret = 0;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (visited[a][b]) continue;
				if (mat[a][b] == 0) continue;

				dfs(a, b, n, m);
				ret++;
			}
		}
		cout << ret << '\n';
	}
}