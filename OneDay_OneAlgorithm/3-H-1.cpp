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
			visited[nx] = visited[x] + 1;
			q.push(nx);
			prevv[nx] = x;
		}
	}
	cout << visited[k] - 1 << '\n';
	vector<int> v;
	for (int i = k; i != n; i = prevv[i])
	{
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(), v.end());
	for (int ii : v)
		cout << ii << ' ';
}