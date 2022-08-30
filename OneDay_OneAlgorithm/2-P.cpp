#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m;
int ori[9][9];
int a[9][9];
int visited[9][9];
vector<pa> v;
int ret;
int wallCount, virCount;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	virCount++;
	visited[y][x] = 1;
	a[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx]) continue;
		dfs(ny, nx);
	}
}

vector<int> now;
void combi(int size, int r, int start)
{
	if (now.size() == r)
	{
		virCount = 0;
		memset(visited, 0, sizeof(visited));
		memcpy(a, ori, sizeof(ori));

		// 벽을 세움 (0 -> 1)
		for (int i = 0; i < r; i++)
		{
			pa p = v[now[i]];
			a[p.first][p.second] = 1;
		}

		// 바이러스를 퍼뜨림
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != 2) continue;
				if (visited[i][j]) continue;
				dfs(i, j);
			}
		}

		// 안전 영역의 크기를 구함
		int cnt = n * m - (virCount + wallCount + 3);

		// 최대인지?
		ret = max(ret, cnt);
		return;
	}
	for (int i = start + 1; i < size; i++)
	{
		now.push_back(i);
		combi(size, r, i);
		now.pop_back();
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
			int input = 0;
			cin >> input;
			ori[i][j] = input;
			if (input == 0) v.push_back({ i, j });
			if (input == 1) wallCount++;
		}
	}
	combi(v.size(), 3, -1);
	cout << ret;
}