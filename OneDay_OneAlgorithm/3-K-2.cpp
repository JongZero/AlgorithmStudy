#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
int n, m, ret;
char a[1501][1501];
int visited[1501][1501];
int lVisited[1501][1501];
queue<pa> q, q2;
queue<pa> lQ, lQ2;
pa s;
bool isMeet = false;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
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
			if (a[i][j] == '.' || a[i][j] == 'L')
			{
				visited[i][j] = 1;
				q.push({ i, j });
			}
			if (a[i][j] == 'L')
			{
				s = { i, j };
			}
		}
	}
	lQ.push({ s.first, s.second });
	lVisited[s.first][s.second] = 1;
	while (true)
	{
		isMeet = false;
		while (lQ.size())
		{
			int y, x;
			tie(y, x) = lQ.front(); lQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (lVisited[ny][nx]) continue;
				lVisited[ny][nx] = 1;
				if (a[ny][nx] == '.')
				{
					lQ.push({ ny, nx });
				}
				if (a[ny][nx] == 'X')
				{
					lQ2.push({ ny, nx });
				}
				if (a[ny][nx] == 'L')
				{
					isMeet = true;
					break;
				}
			}
		}
		if (isMeet) break;
		lQ = lQ2;
		queue<pa> empty;
		lQ2 = empty;
		ret++;

		while (q.size())
		{
			int y, x;
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				if (a[ny][nx] == 'X')
				{
					q2.push({ ny, nx });
					a[ny][nx] = '.';
				}
				else if (a[ny][nx] == '.')
				{
					q.push({ ny, nx });
				}
			}
		}
		q = q2;
		q2 = empty;
	}
	cout << ret;
}