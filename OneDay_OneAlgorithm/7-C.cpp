#include <bits/stdc++.h>
using namespace std;
/*
typedef pair<int, int> pa;
int n, m, a[51][51], visited[51][51], ret = -1e9;
queue<pa> q;
bool isEnd = false;

int getHCount(int y, int x, int ny, int nx)
{
	int ret = 0;
	for (int i = y; i <= ny; i++)
	{
		for (int j = x; j <= nx; j++)
		{
			if (a[i][j] == 0) ret++;
		}
	}
	return ret;
}

void dfs(int y, int x, int depth)
{
	if (isEnd) return;
	ret = max(ret, depth);
	int c = a[y][x];
	for (pa p : { pa(y - c, x), pa(y, x + c), pa(y + c, x), pa(y, x - c) })
	{
		int ny, nx;
		tie(ny, nx) = p;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) { isEnd = true; break; }
		if (a[ny][nx] == 0) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, depth + 1);
		visited[ny][nx] = 0;
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
			char c;
			cin >> c;
			if (c != 'H') a[i][j] = c - '0';
		}
	}

	visited[0][0] = 1;
	dfs(0, 0, 1);

	//q.push({ 0, 0 });
	//while (q.size())
	//{
	//	int y, x;
	//	tie(y, x) = q.front(); q.pop();
	//	int c = a[y][x];
	//	int i = 0;
	//	for (pa p : { pa(y - c, x), pa(y, x + c), pa(y + c, x), pa(y, x - c) })
	//	{
	//		int ny, nx;
	//		tie(ny, nx) = p;
	//		//int hCount = getHCount(y, x, ny, nx);
	//		//if (i == 0) ny -= hCount;
	//		//if (i == 1) nx += hCount;
	//		//if (i == 2) ny += hCount;
	//		//if (i == 3) nx -= hCount;
	//		//i++;
	//		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
	//		if (visited[ny][nx]) { isEnd = true; break; }
	//		if (a[ny][nx] == 0) continue;
	//		//cout << ny << ", " << nx << '\n';
	//		visited[ny][nx] = visited[y][x] + 1;
	//		ret = visited[ny][nx];
	//		q.push({ ny, nx });
	//	}
	//	if (isEnd) break;
	//}
	if (isEnd) cout << -1;
	else
	{
		if (ret == 0) ret++;
		cout << ret;
	}
}
*/

#include <bits/stdc++.h>

using namespace std;
int t, a, d[54][54];
string s;
char b[54][54];
bool check[54][54];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
bool in(int aa, int bb) {
	return(1 <= aa && aa <= t && 1 <= bb && bb <= a);
}
int down(int y, int x) {
	if (!in(y, x) || b[y][x] == 'H') return 0;
	if (check[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}

	cout << '\n';
	cout << y << ", " << x << '\n';
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			cout << d[i][j];
		}
		cout << '\n';
	}

	int& ret = d[y][x];
	if (ret) return ret;

	cout << "ret: " << ret;
	cout << '\n';

	check[y][x] = 1;
	int value = (int)b[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		ret = max(ret, down(ny, nx) + 1);
	}
	check[y][x] = 0;

	cout << y << ", " << x << '\n';
	cout << "ret: " << ret;
	cout << '\n';
	return ret;
}
int main() {
	cin >> t >> a;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		for (int j = 1; j <= a; j++) {
			b[i][j] = s[j - 1];
		}
	}
	cout << down(1, 1) << "\n";
}
