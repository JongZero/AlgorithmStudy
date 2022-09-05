#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int MAX = 1e9;
int n, m;
char a[1001][1001];
int visited[1001][1001], fireVisited[1001][1001];
int ret = MAX;
queue<pa> q;
pa s;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//memset(fireVisited, MAX, sizeof(fireVisited));
	fill(&fireVisited[0][0], &fireVisited[0][0] + 1001 * 1001, MAX);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'F')
			{
				q.push({ i, j });
				fireVisited[i][j] = 1;
			}
			else if (a[i][j] == 'J') s = { i, j };
		}
	}
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (fireVisited[ny][nx] != MAX) continue;
			if (a[ny][nx] == '#') continue;
			fireVisited[ny][nx] = fireVisited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	q.push({ s.first, s.second });
	visited[s.first][s.second] = 1;
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();
 		if (y == 0 || x == 0 || y == n - 1 || x == m - 1)
		{
			ret = visited[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[ny][nx] == '#' || a[ny][nx] == 'F') continue;
			if (visited[ny][nx]) continue;
			if (visited[y][x] + 1 >= fireVisited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (ret == MAX) cout << "IMPOSSIBLE";
	else cout << ret;
}