#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
int maxRet;
vector<int> retV;
//unordered_map<int, vector<int>> mp;
vector<int> v[10001];
int visited[10001];

int func(int a)
{
	visited[a] = 1;
	int ret = 1;
	for (int t : v[a])
	{
		if (visited[t]) continue;
		ret += func(t);
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
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == 0) continue;
		int ret = 0;
		ret = func(i);
		if (maxRet < ret)
		{
			maxRet = ret;
			retV.clear();
			retV.push_back(i);
		}
		else if (maxRet == ret)
			retV.push_back(i);
		memset(visited, 0, sizeof(visited));
	}
	for (int ii : retV)
	{
		cout << ii << ' ';
	}
}