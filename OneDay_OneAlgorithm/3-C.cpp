#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int ret;
int n, l, r;
int a[51][51];
int visited[51][51];

int dy[] = { -1 ,0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, vector<pa>& list, int& sum)
{
	sum += a[y][x];
	visited[y][x] = 1;
	list.push_back({ y, x });
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		int c = abs(a[ny][nx] - a[y][x]);
		if (l <= c && c <= r)
		{
			dfs(ny, nx, list, sum);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	while (true)
	{
		bool isEnd = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j]) continue;
				vector<pa> list;
				int sum = 0;
				dfs(i, j, list, sum);
				for (pa p : list)
				{
					int y, x;
					tie(y, x) = p;
					a[y][x] = sum / list.size();
				}
				if (list.size() != 1 || list.back().first != i || list.back().second != j)
				{
					isEnd = false;
				}
			}
		}

		if (isEnd) break;

		ret++;
		memset(visited, 0, sizeof(visited));
	}
	cout << ret;
}