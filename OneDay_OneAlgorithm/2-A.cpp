#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[104][104];
int visited[104][104];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

typedef pair<int, int> pa;

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
			mp[i][j] = s[j] - '0';
		}
	}
	int sy = 0, sx = 0;
	queue<pa> q;
	q.push({ sy, sx });
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
			if (mp[ny][nx] == 0) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	cout << visited[n - 1][m - 1] << '\n';
}