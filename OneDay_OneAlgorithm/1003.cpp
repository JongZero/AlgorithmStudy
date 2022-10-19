#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

pa dp[41];

pa fibonacci(int n, pa p)
{
	if (n == 0)
	{
		p.first++;
		return p;
	}
	else if (n == 1)
	{
		p.second++;
		return p;
	}
	else
	{
		if (dp[n].first != 0 || dp[n].second != 0)
			return dp[n];

		pa p1 = fibonacci(n - 1, p);
		pa p2 = fibonacci(n - 2, p);
		dp[n] = pa(p1.first + p2.first, p1.second + p2.second);
		return dp[n];
	}
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		pa p = fibonacci(t, pa(0, 0));
		cout << p.first << ' ' << p.second << '\n';
	}
}