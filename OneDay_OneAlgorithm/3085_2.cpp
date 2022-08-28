#include <bits/stdc++.h>
using namespace std;

int ret;
int n;
char a[51][51];
char temp[51][51];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void check()
{
	// 가로먼저 체크
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		char c = temp[i][0];
		for (int j = 1; j < n; j++)
		{
			if (c == temp[i][j])
			{
				count++;
			}
			else
			{
				c = temp[i][j];
				count = 1;
			}

			if (count > ret)
				ret = count;
		}
	}

	// 세로 체크
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		char c = temp[0][i];
		for (int j = 1; j < n; j++)
		{
			if (c == temp[j][i])
			{
				count++;
			}
			else
			{
				c = temp[j][i];
				count = 1;
			}

			if (count > ret)
				ret = count;
		}
	}
}

void func(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

		temp[y][x] = a[ny][nx];
		temp[ny][nx] = a[y][x];
		check();
		memcpy(temp, a, sizeof(a));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	// 안바꾸고 한번 체크
	memcpy(temp, a, sizeof(a));
	check();
	memcpy(temp, a, sizeof(a));

	// 바꾸고, 체크하고
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			func(i, j);
		}
	}
	cout << ret << '\n';
	return 0;
}