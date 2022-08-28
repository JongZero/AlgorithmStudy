#include <bits/stdc++.h>
using namespace std;

int n;
int a[68][68];

int dy[] = { 0, 0, 1, 1 };
int dx[] = { 0, 1, 0, 1 };

string ret;

bool dfs(int num, int y, int x, int k, vector<vector<int>>& mini, vector<vector<int>>& visited)
{
	visited[y][x] = true;

	bool isSame = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= k || nx < 0 || nx >= k) continue;
		if (visited[ny][nx]) continue;
		if (mini[ny][nx] != num) return false;

		isSame = dfs(num, ny, nx, k, mini, visited);
		if (isSame == false) return false;
	}
	return isSame;
}

void fillMini(vector<vector<int>>& mini, int ky, int kx, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			mini[i][j] = a[i + ky][j + kx];
		}
	}
}

void quad(int k, int sy, int sx)
{
	if (k == 0) return;

	int ky[] = { 0, 0, k, k };
	int kx[] = { 0, k, 0, k };

	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> mini(k, vector<int>(k, 0));
		fillMini(mini, sy + ky[i], sx + kx[i], k);
		vector<vector<int>> visited(k, vector<int>(k, 0));

		int num = mini[0][0];
		bool isSame = dfs(num, 0, 0, k, mini, visited);

		if (isSame)
		{
			ret += to_string(num);
		}
		else
		{
			ret += "(";
			quad(k / 2, sy + ky[i], sx + kx[i]);
			ret += ")";
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
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j] - '0';
		}
	}
	if (n == 1)
	{
		ret += to_string(a[0][0]);
	}
	else
	{
		ret += "(";
		quad(n / 2, 0, 0);
		ret += ")";
	}

	if (ret.size() == 6)
	{
		if (ret.find("1111") != string::npos
			|| ret.find("0000") != string::npos)
		{
			//ret = ret.substr(1, 4);
		}
	}
	cout << ret;
}