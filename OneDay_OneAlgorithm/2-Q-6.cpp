#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m, a[101][101], visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int retTime, retCount;

vector<pa> cVec;
void dfs(int y, int x)
{
	visited[y][x] = 1;
	if (a[y][x] == 1) { cVec.push_back({ y, x }); return; }
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

		if (cVec.size() == 0) break;
		retTime++;
		retCount = cVec.size();
		for (pa p : cVec)
		{
			a[p.first][p.second] = 0;
		}
		cVec.clear();
		memset(visited, 0, sizeof(visited));
	}
	cout << retTime << '\n' << retCount;
}