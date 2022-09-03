#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m;

int dy[] = { -1 ,0 ,1, 0 };
int dx[] = { 0, 1, 0, -1 };

char a[1501][1501];
int visited[1501][1501];
int lVisited[1501][1501];

vector<pa> lList;
vector<pa> wList;

void isMeet(int y, int x, bool& is)
{
	if (is) return;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx] == 'X') continue;
		if (ny == lList[1].first && nx == lList[1].second) is = true;
		isMeet(ny, nx, is);
	}
}

void dfs(int y, int x, int cnt)
{
	visited[y][x] = 1;
	if (a[y][x] == 'X')
	{
		if (cnt != 1)
			wList.push_back({ y, x });

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx, cnt + 1);
	}
}

queue<pa> q;
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
			if (a[i][j] == 'L') lList.push_back({ i, j });
			if (a[i][j] == '.' || a[i][j] == 'L')
			{
				visited[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
	
	queue<pa> lQ;
	queue<pa> lQ2;
	int cnt = 0;
	lQ.push({ lList[0].first, lList[0].second });
	lVisited[lList[0].first][lList[0].second] = 1;
	while (true)
	{
		while (lQ.size())
		{
			int y, x;
			tie(y, x) = lQ.front(); lQ.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (lVisited[ny][nx]) continue;
				lVisited[ny][nx] = lVisited[y][x] + 1;
				if (a[ny][nx] == 'X')
				{
					lQ2.push({ ny, nx });
					continue;
				}
				lQ.push({ ny, nx });
			}
			if (lVisited[lList[1].first][lList[1].second] != 0) break;
		}
		if (lVisited[lList[1].first][lList[1].second] != 0) break;
		lQ = lQ2;
		queue<pa> empty;
		lQ2 = empty;


		queue<pa> q2;
		while (q.size())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				int y, x;
				tie(y, x) = q.front(); q.pop();

				for (int j = 0; j < 4; j++)
				{
					int ny = y + dy[j];
					int nx = x + dx[j];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (visited[ny][nx]) continue;
					visited[ny][nx] = visited[y][x] + 1;
					if (a[ny][nx] == '.' || a[ny][nx] == 'L')
					{
						q.push({ ny, nx });
					}
					else
					{
						a[ny][nx] = '.';
						q2.push({ ny, nx });
					}
				}
			}
		}
		q = q2;
		cnt++;

		
	}

	cout << cnt;

	/*
	int cnt = 0;
	while (true)
	{
		bool is = false;
		isMeet(lList[0].first, lList[0].second, is);
		if (is == true) break;

		cnt++;
		memset(visited, 0, sizeof(visited));

		int tempCnt = 0;
		dfs(lList[0].first, lList[0].second, 0);
		tempCnt = wList.size();
		for (pa p : wList)
		{
			a[p.first][p.second] = '.';
		}
		wList.clear();
		memset(visited, 0, sizeof(visited));

		dfs(lList[1].first, lList[1].second, 0);
		tempCnt = wList.size();
		for (pa p : wList)
		{
			a[p.first][p.second] = '.';
		}
		wList.clear();
		memset(visited, 0, sizeof(visited));

		if (tempCnt == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (a[i][j] == '.' && visited[i][j] == 0)
						dfs(i, j, 1);
				}
			}
			for (pa p : wList)
			{
				a[p.first][p.second] = '.';
			}
			wList.clear();
			memset(visited, 0, sizeof(visited));
		}
	}
	cout << cnt;
	*/


}