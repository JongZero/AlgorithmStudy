#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, k;

int ret = 1e9;
int visited[MAX + 1];
queue<int> q;
int a[MAX + 1];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;


	visited[n] = 1;
	q.push(n);
	while (q.size())
	{
		int x = q.front();
		q.pop();

		if (x == k) break;

		for (int nx : {x - 1, x + 1, x * 2})
		{
			if (nx < 0 || nx > MAX) continue;

			if (!visited[nx])
			{
				visited[nx] = visited[x] + 1;
				a[nx] = x;
				q.push(nx);
			}
		}
	}
	ret = visited[k] - 1;
	cout << ret << '\n';

	vector<int> vv;
	for (int i = k; i != n; i = a[i])
	{
		vv.push_back(i);
	}
	vv.push_back(n);
	reverse(vv.begin(), vv.end());
	for (int ii : vv)
	{
		cout << ii << ' ';
	}
}