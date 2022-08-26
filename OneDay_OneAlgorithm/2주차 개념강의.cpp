// 2주차. 그래프 이론, DFS, BFS, 트리순회

#include <bits/stdc++.h>
using namespace std;

int n, m;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int ret = 0;

void DFS2(vector<vector<int>>& v, vector<vector<bool>>& b, int y, int x)
{
	b[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;

		if (b[ny][nx] == true) continue;
		if (v[ny][nx] == 0) continue;

		DFS2(v, b, ny, nx);
	}
}

int main2()
{
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<bool>> b(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int in = 0;
			cin >> in;
			v[i][j] = in;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == true) continue;
			if (v[i][j] == 0) continue;

			DFS2(v, b, i, j);
			ret++;
		}
	}

	cout << ret << '\n';
	return 0;
}

int sx, sy;
int ex, ey;
int mp[104][104];
int visited[104][104];
typedef pair<int, int> pa;

int main3()
{
	cin >> n >> m;
	cin >> sy >> sx;
	cin >> ey >> ex;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];
	}

	queue<pa> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = 1;
	while (q.size())
	{
		pa ne = q.front();
		for (int i = 0; i < 4; i++)
		{
			int ny, nx;
			tie(ny, nx) = ne;
			ny += dy[i];
			nx += dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] > 0) continue;
			if (mp[ny][nx] == 0) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[ne.first][ne.second] + 1;
		}
		q.pop();
	}
	cout << visited[ey][ex] << "\n";
	return 0;
}

vector<int> adj[1004];
int visited2[1004];

void postOrder(int here)
{
	for (int i : adj[here])
	{
		if (visited2[i]) continue;
		postOrder(i);
	}
	visited2[here] = 1;
	cout << here << " ";
}
void preOrder(int here)
{
	visited2[here] = 1;
	cout << here << " ";
	for (int i : adj[here])
	{
		if (visited2[i]) continue;
		preOrder(i);
	}
}
void inOrder(int here)
{
	if (adj[here].size() > 0 && visited2[adj[here][0]] == 0)
		inOrder(adj[here][0]);
	visited2[here] = 1;
	cout << here << " ";
	if (adj[here].size() > 1 && visited2[adj[here][1]] == 0)
		inOrder(adj[here][1]);
}
int main()
{
	//	    1
	//	 2     3
	// 4   5

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	int root = 1;
	cout << "\n 트리순회 : postOrder \n";
	postOrder(root); memset(visited2, 0, sizeof(visited2));
	cout << "\n 트리순회 : preOrder \n";
	preOrder(root); memset(visited2, 0, sizeof(visited2));
	cout << "\n 트리순회 : inOrder \n";
	inOrder(root); memset(visited2, 0, sizeof(visited2));
	return 0;
}