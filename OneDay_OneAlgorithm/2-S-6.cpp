#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10001];
vector<int> v[10001];

int func(int s)
{
	visited[s] = 1;
	int ret = 1;
	for (int ii : v[s])
	{
		if (visited[ii]) 
			continue;
		ret += func(ii);
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
		memset(visited, 0, sizeof(visited));
		int temp = func(i);
		if (nowMax < temp)
		{
			nowMax = temp;
			ret.clear();
			ret.push_back(i);
		}
		else if (nowMax == temp)
		{
			ret.push_back(i);
		}
	}
	for (int ii : ret)
		cout << ii << ' ';
}