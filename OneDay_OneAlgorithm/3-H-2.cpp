#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int n, k;
int visited[MAX];
int prevv[MAX];
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
		int x = q.front();
		q.pop();

		if (x == k) break;

		for (int nx : {x - 1, x + 1, x * 2})
		{
			if (nx < 0 || nx >= MAX) continue;
			if (visited[nx]) continue;
			prevv[nx] = x;
			visited[nx] = visited[x] + 1;
			q.push(nx);
		}
	}
	cout << visited[k] - 1 << '\n';

	// prev[17] = 16
	// prev[16] = 8
	// prev[8] = 4
	// prev[4] = 5
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