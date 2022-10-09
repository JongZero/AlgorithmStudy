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

//	- 문자열 비교의 경우 커스텀 비교 함수가 아니라면, 아스키 코드를 기반으로 비교한다.
//	ex) “123” < “20” → 123이 더 큰 숫자지만, 가장 앞자리부터 아스키 코드 값으로 비교하기 때문에 1 < 2가 되어서 20을 더 큰 숫자로 판정함.
//		- 분, 초가 있을 때는 하나의 단위로 통일해서 쓰는 것이 편함.
//		ex) 1분 30초 = 90초, 2분 30초 = 150초 → 2분 30초(150초) - 1분 30초(90초) = 1분(60)초
//		- 어림 잡아 1000만번 이하로 계산될 수 있으면 무식하게 풀어도 괜찮다. (문제마다 다르긴 함)
//		- 처음 문제 접했을 때 일단, 무식하게 생각 → 범위 계산
//		ex) 8 * 8 2차원 배열, 3개의 조합을 찾는 경우 : 64C3 = 36600
//		1억, 1000만 이하인 경우는 무식하게 해도 괜찮다.
//		- 위의 경우에서 1억, 1000만이 넘어가는 경우에는 효율적인 방법 생각.
//		- 트리는 루트 노드부터 탐색하는 것이 좋다. (그래프는 어디서부터 탐색하던 상관없다.)
//		- 트리에서 erase 한다는 것 → 1. 진짜 지운다.   2. 더 이상 탐색하지 않는다.