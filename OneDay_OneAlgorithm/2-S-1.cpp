#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> c[10001];
int visited[10001];

int dfs(int n)
{
	visited[n] = 1;
	int ret = 1;
	for (int ii : c[n])
	{
		if (visited[ii]) continue;
		ret += dfs(ii);
	}
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		c[b].push_back(a);
	}
	vector<int> ret;
	int nowMax = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = dfs(i);
		if (temp > nowMax)
		{
			nowMax = temp;
			ret.clear();
			ret.push_back(i);
		}
		else if (temp == nowMax)
		{
			ret.push_back(i);
		}
		memset(visited, 0, sizeof(visited));
	}
	for (int ii : ret)
	{
		cout << ii << ' ';
	}
}