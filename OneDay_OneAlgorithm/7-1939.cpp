#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
typedef long long ll;
int n, m;
ll ret;

int visited[10001];
vector<pa> v[10001];
pa f;
ll dp[10001];

ll func(int s, ll w)
{
	if (s == f.second)
	{
		//ret = max(ret, w);
		return w;
	}
	long long& d = dp[s];
	if (d != -1) return d;
	visited[s] = 1;
	for (pa& p : v[s])
	{
		if (visited[p.first]) continue;
		if (p.second < w) continue;
		d = max(d, func(p.first, w + (p.second - w)));
	}
	visited[s] = 0;
	return d;
}

bool bfs(int c)
{
	queue<int> q;
	q.push(f.first);
	visited[f.first] = 1;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		if (x == f.second) return true;
		for (pa& p : v[x])
		{
			if (visited[p.first]) continue;
			if (p.second < c) continue;
			visited[p.first] = 1;
			q.push(p.first);
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	int maxC = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
		maxC = max(maxC, c);
	}
	cin >> f.first >> f.second;

	int low = 1;
	int high = maxC;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (bfs(mid))
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << high;

	//cout << func(f.first, 0);
	//cout << ret;
}