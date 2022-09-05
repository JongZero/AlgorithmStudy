#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int n, k, visited[MAX], prevv[MAX];
queue<int> q;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	q.push(n);
	visited[n] = 1;
	while (q.size())
	{
		int x = q.front(); q.pop();
		for (int nx : {x - 1, x + 1, x * 2})
		{
			if (nx < 0 || nx >= MAX) continue;
			if (visited[nx]) continue;
			visited[nx] = visited[x] + 1;
			prevv[nx] = x;
			q.push(nx);
		}
	}
	cout << visited[k] - 1 << '\n';
	vector<int> ret;
	for (int i = k; i != n; i = prevv[i])
	{
		ret.push_back(i);
	}
	ret.push_back(n);
	reverse(ret.begin(), ret.end());
	for (int ii : ret)
	{
		cout << ii << ' ';
	}
}