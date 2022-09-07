#include <bits/stdc++.h>
using namespace std;

/*
int n, a[17][17], visited[17][17], ret;

enum eType
{
	GARO,
	SERO,
	DAEGAK,
	TCOUNT,
};

int dy[3][3] = { {0, 1, 0}, {1, 1, 0}, {0, 1, 1} };
int dx[3][3] = { {1, 1, 0}, {0, 1, 0}, {1, 1, 0} };

bool check(int y, int x, int i)
{
	if (visited[y][x] == 1 || a[y][x] == 1) return false;
	if (y < 0 || y >= n || x < 0 || x >= n) return false;
	// 다음에 대각선으로 갈 경우
	if (i == 1)
	{
		if (visited[y - 1][x] == 1 || visited[y][x - 1] == 1 || a[y - 1][x] == 1 || a[y][x - 1] == 1) return false;
	}
	return true;
}

void checkVisited(int y, int x, int i, int h)
{
	visited[y][x] = h;
	if (i == 1)
	{
		visited[y - 1][x] = h;
		visited[y][x - 1] = h;
	}
}

eType getType(int i, eType t)
{
	switch (t)
	{
	case GARO:
	{
		if (i == 0) return GARO;
		else return DAEGAK;
	}
	break;
	case SERO:
	{
		if (i == 0) return SERO;
		else return DAEGAK;
	}
	break;
	case DAEGAK:
	{
		if (i == 0) return GARO;
		else if (i == 1) return DAEGAK;
		else return SERO;
	}
	break;
	}
}

void func(int y, int x, eType t)
{
	//cout << "y, x : " << y << ", " << x << '\n';
	if (y == n - 1 && x == n - 1)
	{
		ret++;
	}
	int c = 2;
	if (t == DAEGAK) c = 3;
	for (int i = 0; i < c; i++)
	{
		int ny = y + dy[t][i];
		int nx = x + dx[t][i];
		//cout << "ny, nx : " << ny << ", " << nx << '\n';
		if (check(ny, nx, i) == false) continue;
		//cout << "check 통과 \n";
		checkVisited(ny, nx, i, 1);
		func(ny, nx, getType(i, t));
		checkVisited(ny, nx, i, 0);
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
	visited[0][0] = 1;
	visited[0][1] = 1;
	func(0, 1, GARO);
	cout << ret;
}
*/

#include <bits/stdc++.h>
using namespace std;
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int n, a[24][24], dp[24][24][3];
bool check(int y, int x, int d) {
	if (d == 0 || d == 2) {
		if (!a[y][x]) return true;
	}
	else if (d == 1) {
		if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
	}
	return false;
}
int main() {
	fastIO();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0];

			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2];

			if (check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	int ret = dp[n][n][0];
	ret += dp[n][n][1]; ret += dp[n][n][2];
	cout << ret << "\n";

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dp[i][j][0] + dp[i][j][1] + dp[i][j][2] << ' ';
		}
		cout << '\n';
	}
	return 0;
}