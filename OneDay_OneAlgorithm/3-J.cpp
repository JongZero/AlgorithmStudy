#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

pa j, c;
int n, m;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

char a[301][301];
int visited[301][301];

int ret;
bool isEnd = false;
vector<pa> v;
void dfs(int y, int x)
{
	//cout << y << ", " << x << '\n';
	visited[y][x] = 1;
	if (y == c.first && x == c.second) isEnd = true;
	if (isEnd) return;
	if (a[y][x] == '1') { v.push_back({ y, x }); return; }
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
	cin >> j.first >> j.second >> c.first >> c.second;
	j.first--; j.second--; c.first--; c.second--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	// dfs
	/* 
	while (true)
	{
		ret++;
		dfs(j.first, j.second);
		if (isEnd) break;
		memset(visited, 0, sizeof(visited));
		for (pa p : v)
		{
			a[p.first][p.second] = 0;
		}
		v.clear();
	}
	cout << ret;
	 */

	// bfs
	queue<pa> q;
	q.push({ j.first, j.second });
	visited[j.first][j.second] = 1;
	int cnt = 0;
	while (true)
	{
		cnt++;
		queue<pa> q2;
		while (q.size())
		{
			int y, x;
			tie(y, x) = q.front();
			q.pop();

			if (y == c.first && x == c.second)
				break;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if (a[ny][nx] == '0')
				{
					q.push({ ny, nx });
				}
				else
				{
					a[ny][nx] = '0';
					q2.push({ ny, nx });
				}
			}
		}
		q = q2;
		if (a[c.first][c.second] == '0') break;
	}
	cout << visited[c.first][c.second];
}