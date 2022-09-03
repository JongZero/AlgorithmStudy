#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[10001];
int visited[10001];

int hack(int s)
{
	visited[s] = 1;
	int ret = 1;
	for (int ii : v[s])
	{
		if (visited[ii]) continue;
		ret += hack(ii);
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
		v[b].push_back(a);
	}
	int nowMax = 0;
	vector<int> ret;
	for (int i = 1; i <= n; i++)
	{
		int temp = hack(i);
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