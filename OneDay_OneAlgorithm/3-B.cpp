#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n, m;
char a[51][51];
int visited[51][51];
int nowMax = 0;
vector<pa> land;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
			if (a[i][j] == 'L') land.push_back({ i, j });
		}
	}
	for (auto p : land)
	{
		int sy, sx;
		tie(sy, sx) = p;

		queue<pa> q;
		q.push(p);
		visited[sy][sx] = 1;
		
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
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'W') continue;
				visited[ny][nx] = visited[y][x] + 1;
				if (visited[ny][nx] > nowMax)
				{
					nowMax = visited[ny][nx];
				}
				q.push({ ny, nx });
			}
		}

		memset(visited, 0, sizeof(visited));
	}
	cout << nowMax - 1;
}