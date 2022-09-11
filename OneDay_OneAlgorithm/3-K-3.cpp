#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
int n, m, ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char a[1501][1501];
int visited[1501][1501];
int lVisited[1501][1501];
pa l;
queue<pa> wQ, wQ2;
queue<pa> lQ, lQ2;
queue<pa> emptyQ;
bool isMeet = false;
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
			if (a[i][j] == 'L') l = { i, j };
			if (a[i][j] == '.' || a[i][j] == 'L')
			{
				visited[i][j] = 1;
				wQ.push({ i, j });
			}
		}
	}
	lQ.push({ l.first, l.second });
	lVisited[l.first][l.second] = 1;
	while (true)
	{
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
				else if (a[ny][nx] == 'X')
				{
					lQ2.push({ ny, nx });
				}
				else if (a[ny][nx] == 'L')
				{
					isMeet = true;
					break;
				}
			}
		}
		if (isMeet) break;
		lQ = lQ2;
		lQ2 = emptyQ;
		ret++;
		while (wQ.size())
		{
			int y, x;
			tie(y, x) = wQ.front(); wQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				if (a[ny][nx] == '.')
				{
					wQ.push({ ny, nx });
				}
				else if (a[ny][nx] == 'X')
				{
					a[ny][nx] = '.';
					wQ2.push({ ny, nx });
				}
			}
		}
		wQ = wQ2;
		wQ2 = emptyQ;
	}
	cout << ret;
}