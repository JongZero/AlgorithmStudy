#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

const int INF = 1987654321;

int n, m, ret = INF;
char a[1001][1001];
int visited[1001][1001];
int fireVisited[1001][1001];

queue<pa> q;
pa s;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//memset(fireVisited, INF, sizeof(fireVisited)); -1, 0, 1�� ����
	fill(&fireVisited[0][0], &fireVisited[0][0] + 1001 * 1001, INF);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'J') s = { i, j };
			if (a[i][j] == 'F')
			{
				fireVisited[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (fireVisited[ny][nx] != INF) continue;
			if (a[ny][nx] == '#') continue;
			q.push({ ny, nx });
			fireVisited[ny][nx] = fireVisited[y][x] + 1;
		}
	}
	q.push({s.first, s.second});
	visited[s.first][s.second] = 1;
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

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
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == '#' || a[ny][nx] == 'F') continue;
			if (visited[y][x] + 1 >= fireVisited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (ret == INF) cout << "IMPOSSIBLE";
	else cout << ret;
}