#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m;
int a[101][101];
int visited[101][101];

int retTime, retCount;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<pa> v;
vector<pa> removeCheeseList;

bool isOutline(int y, int x)
{
	if (y == 0 && 0 <= x && x < m) return true;
	if (y == n - 1 && 0 <= x && x < m) return true;
	if (x == 0 && 0 <= y && y < n) return true;
	if (x == m - 1 && 0 <= y && y < n) return true;
	return false;
}

bool isInCheese(int y, int x)
{
	if (isOutline(y, x)) return false;
	visited[y][x] = 1;
	bool isIn = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (a[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		isIn = isInCheese(ny, nx);
		if (isIn == false) return false;
	}
	return true;
}

void checkNextCheese(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[ny][nx] == 2) continue;
		if (a[ny][nx] == 1)
		{
			removeCheeseList.push_back({ ny, nx });
			a[ny][nx] = 2; 
			continue;
		}
		if (visited[ny][nx]) continue;
		checkNextCheese(ny, nx);
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
			cin >> a[i][j];
		}
	}
	// 치즈 안에 있지 않은지를 먼저 체크
		// 가장 모서리 부분과 닿지 못하면 치즈 안에 있는것.
	// 치즈 안에 있지 않다면, 접하는 치즈를 모두 2로 체크
	// 시간을 증가시키고, 2는 0으로 변경(녹아 없어짐)
	// 모두 없어질 때까지 위 과정 반복
		// 모두 없어진다는 것은 0밖에 남지 않았을 때임.

	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j]) continue;
				bool isIn = isInCheese(i, j);
				memset(visited, 0, sizeof(visited));
				if (isIn == false)	// 치즈들 안에 없다면
				{
					v.push_back({ i, j });
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < v.size(); i++)
		{
			int y, x;
			tie(y, x) = v[i];
			if (visited[y][x]) continue;
			checkNextCheese(y, x);
		}
		v.clear();
		retTime++;
		retCount = removeCheeseList.size();
		for (int i = 0; i < removeCheeseList.size(); i++)
		{
			int y, x;
			tie(y, x) = removeCheeseList[i];
			a[y][x] = 0;
		}
		removeCheeseList.clear();
		bool isAllRemove = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j])
				{
					isAllRemove = false;
					break;
				}
			}
			if (isAllRemove == false)
				break;
		}
		if (isAllRemove)
			break;
	}
	cout << retTime << '\n';
	cout << retCount;
}