#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n;
//int visited[MAX + 1];
int prevv[MAX + 1];
//queue<int> q;
int dp[MAX + 1], ret;

int func(int x, int prev)
{
	//cout << x << '\n';
	if (x <= 0) return MAX;
	if (x == 1) return 0;
	if (dp[x]) return dp[x];
	//prevv[x] = prev;
	//cout << "prev[" << x << "] = " << prev << '\n';
	int n1(MAX), n2(MAX), n3(MAX);
	if (x % 3 == 0) n1 = func(x / 3, x);
	if (x % 2 == 0) n2 = func(x / 2, x);
	n3 = func(x - 1, x);
	dp[x] = min(min(n1, n2), n3);
	if (dp[x] == n1) prevv[x / 3] = x;
	else if (dp[x] == n2) prevv[x / 2] = x;
	else prevv[x - 1] = x;
	dp[x]++;
	return dp[x];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> n;
	
	cout << func(n, 0) << '\n';
	vector<int> ret;
	for (int i = 1; i != n; i = prevv[i])
	{
		ret.push_back(i);
	}
	ret.push_back(n);
	reverse(ret.begin(), ret.end());
	for (int ii : ret)
		cout << ii << ' ';

	/*
	q.push(n);
	visited[n] = 1;
	while (q.size())
	{
		int x = q.front(); q.pop();
		if (x == 1) break;
		for (int i = 0; i < 3; i++)
		{
			int nx = 0;
			if (i == 0)
			{
				if (x % 3 == 0) nx = x / 3;
				else continue;
			}
			else if (i == 1)
			{
				if (x % 2 == 0) nx = x / 2;
				else continue;
			}
			else nx = x - 1;
			if (nx <= 0 || nx > MAX) continue;
			if (visited[nx]) continue;
			visited[nx] = visited[x] + 1;
			prevv[nx] = x;
			//cout << "prev[" << nx << "]" << " = " << x << '\n';
			q.push(nx);
		}
	}
	cout << visited[1] - 1 << '\n';
	vector<int> ret;
	for (int i = 1; i != n; i = prevv[i])
	{
		ret.push_back(i);
	}
	ret.push_back(n);
	reverse(ret.begin(), ret.end());
	for (int ii : ret)
		cout << ii << ' ';
	*/
}