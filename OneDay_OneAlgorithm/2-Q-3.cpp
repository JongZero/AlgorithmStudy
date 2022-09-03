#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m, ret, retCount;
int a[101][101];
int visited[101][101];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<pa> cList;
void dfs(int y, int x)
{
	visited[y][x] = 1;
	if (a[y][x] == 1)
	{
		cList.push_back({ y, x });
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	while (true)
	{
		dfs(0, 0);

		if (cList.size() == 0)
			break;

		ret++;
		retCount = cList.size();
		for (pa p : cList)
		{
			a[p.first][p.second] = 0;
		}
		cList.clear();
		memset(visited, 0, sizeof(visited));
	}
	cout << ret << '\n' << retCount;
}