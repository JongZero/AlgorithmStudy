#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51];
//int dp[51][51][51], prevv[51][51], counting[51][51];
int ret[51];
int dy[] = { 1, 0 };
int dx[] = { 0, 1 };

/*
bool check(int y, int x, int prevNum, int cnt, int q)
{
	// 가고자 하는 곳이 오락실이라면
	if (a[y][x])
	{
		// q개 초과로 오락실 방문하면 안됨
		if (cnt + 1 <= q)
		{
			// 넘버 체크... 이전에 갔던 곳보다 번호가 높아야 한다.
			if (prevNum < a[y][x])
			{
				// 번호가 높다면... 가능, 이전 오락실 체크해줌
				counting[y][x]++;
				prevv[y][x] = a[y][x];
				return true;
			}

			return false;
		}

		return false;
	}

	prevv[y][x] = prevNum;
	return true;
}
*/

int dfs(int y, int x, int cnt, int prevv)
{
	cout << y << ", " << x << '\n';
	if (y == n && x == m)
	{
		//cout << "cnt: " << cnt << '\n';
		//ret[cnt]++;
		//ret[cnt] %= 1000007;
		return 1;
	}
	if (y > n || x > m) return 0;
	if (a[y][x] && a[y][x] < prevv)
		return 0;
	if (dp[y][x][cnt])
	{
		cout << "이미있따\n";
		return dp[y][x][cnt];
	}
	int nextCnt = cnt;
	if (a[y][x] && a[y][x] > prevv)
	{
		nextCnt++;
		prevv = a[y][x];
	}
	for (int i = 0; i < 2; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		dp[y][x][cnt] += dfs(ny, nx, nextCnt, prevv);
	}
	cout << y << ", " << x << " cnt: " << cnt;
	cout << " dp: " << dp[y][x][cnt] << '\n';
	return dp[y][x][cnt];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++)
	{
		int b, c;
		cin >> b >> c;
		a[b][c] = i;
	}

	dfs(1, 1, 0, a[1][1]);
	for (int i = 0; i <= c; i++)
	{
		cout << dp[n][m][i] << ' ';
	}

	/*
	for (int q = 0; q <= c; q++)
	{
		dp[1][1][q] = 1;
		prevv[1][1] = a[1][1];
		counting[1][1] = (a[1][1] != 0);

		cout << "\n한 q 끝남! 현재 q: " << q << '\n';

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (check(i, j + 1, prevv[i][j], counting[i][j], q))
				{
					// 갈 수 있다면
					dp[i][j + 1][q] += dp[i][j][q];
				}
				if (check(i + 1, j, prevv[i][j], counting[i][j], q))
				{
					dp[i + 1][j][q] += dp[i][j][q];
				}

				cout << '\n';
				for (int a = 1; a <= n; a++)
				{
					for (int b = 1; b <= m; b++)
					{
						cout << dp[a][b][q] << ' ';
					}
					cout << ' ';
					for (int b = 1; b <= m; b++)
					{
						cout << prevv[a][b] << ' ';
					}
					cout << ' ';
					for (int b = 1; b <= m; b++)
					{
						cout << counting[a][b] << ' ';
					}
					cout << '\n';
				}
			}
		}
		memset(prevv, 0, sizeof(prevv));
		memset(counting, 0, sizeof(counting));
	}
	for (int i = 0; i <= c; i++)
	{
		cout << dp[n][m][i] << ' ';
	}
	*/


}