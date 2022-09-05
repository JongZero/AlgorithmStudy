#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
int n, ret = 1e9;
int a[11][11], visited[11][11];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool isFlower(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
		if (visited[ny][nx]) return false;
	}
	return true;
}

void checkVisited(int y, int x, int z, int& p)
{
	visited[y][x] = z;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = z;
		if (z == 1)
			p += a[ny][nx];
		else
			p -= a[ny][nx];
	}
}

vector<pa> now;
void func(int now, int cnt)
{
	if (now > ret) return;
	if (cnt >= 3)
	{
		//cout << "꽃 3개를 피웠다. 현재 비용 : " << now << '\n';
		ret = min(ret, now);
		//cout << "현재 최소 비용 : " << ret << '\n';
		return;
	}
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (visited[i][j]) continue;
			if (isFlower(i, j) == false) continue;
			now += a[i][j];
			checkVisited(i, j, 1, now);
			//cout << i << ", " << j << " 에 꽃을 피운다! 현재 비용 : " << now << '\n';
			func(now, cnt + 1);
			now -= a[i][j];
			checkVisited(i, j, 0, now);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	func(0, 0);
	cout << ret;
}