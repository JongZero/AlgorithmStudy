#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

typedef pair<int, int> pa;

pa s;
int r, c;
int visited[1001][1001];
int ret = 1987654321;

/*
void fireOne(int y, int x, vector<pa>& fireV)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (a[ny][nx] == '#') continue;
		visited[ny][nx] = 1;
		a[ny][nx] = 'F';
		fireV.push_back({ ny, nx });
	}
}

void fire(vector<pa>& fireV)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visited[i][j]) continue;
			if (a[i][j] == 'F')
				fireOne(i, j, fireV);
		}
	}
}

void fireBack(vector<pa>& fireV)
{
	for (pa p : fireV)
	{
		visited[p.first][p.second] = 0;
		a[p.first][p.second] = '.';
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt > ret)
		return;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			ret = min(ret, cnt);
			return;
		}
		if (a[ny][nx] == 'F' || a[ny][nx] == '#') continue;
		if (visited[ny][nx]) continue;
		vector<pa> fireV;
		visited[ny][nx] = 1;
		fire(fireV);
		dfs(ny, nx, cnt + 1);
		visited[ny][nx] = 0;
		fireBack(fireV);
	}
}
*/

bool isMoseri(int y, int x)
{
	if (y == 0 && x >= 0 && x < c) return true;
	if (y == r - 1 && x >= 0 && x < c) return true;
	if (x == 0 && y >= 0 && y < r) return true;
	if (x == c - 1 && y >= 0 && y < r) return true;
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	queue<pa> fireQ;

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string ss;
		cin >> ss;
		for (int j = 0; j < c; j++)
		{
			if (ss[j] == 'J')
			{
				s = { i, j };
			}
			if (ss[j] == 'F')
			{
				visited[i][j] = 10000000;
				fireQ.push({ i, j });
			}
			if (ss[j] == '#')
			{
				visited[i][j] = 20000000;
			}
		}
	}

	//visited[s.first][s.second] = 1;
	//dfs(s.first, s.second, 0);

	queue<pa> q;
	visited[s.first][s.second] = 1;
	q.push({ s.first, s.second });
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		int ori = visited[y][x];

		int fireSize = fireQ.size();
		for (int i = 0; i < fireSize; i++)
		{
			int fy, fx;
			tie(fy, fx) = fireQ.front();
			fireQ.pop();
			for (int j = 0; j < 4; j++)
			{
				int ny = fy + dy[j];
				int nx = fx + dx[j];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (visited[ny][nx] == 20000000) continue;
				if (visited[ny][nx] == 10000000) continue;
				visited[ny][nx] = 10000000;
				fireQ.push({ ny, nx });
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (visited[ny][nx]) continue;
			if (visited[ny][nx] == 10000000 || visited[ny][nx] == 20000000) continue;
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				// ≈ª√‚
				ret = min(ret, ori);
				break;
			}
			q.push({ ny, nx });
			visited[ny][nx] = ori + 1;
		}
	}

	if (ret == 1987654321) cout << "IMPOSSIBLE";
	else cout << ret;
}