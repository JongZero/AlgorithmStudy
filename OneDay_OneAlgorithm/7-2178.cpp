#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
int n, m, a[101][101], visited[101][101];
queue<pa> q;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j+1] = s[j] - '0';
		}
	}
	q.push({ 1,1 });
	visited[1][1] = 1;
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		if (y == n && x == m) break;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cout << visited[n][m];
}