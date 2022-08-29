#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		int cnt = 0;
		int now = n - 1;
		int last = n;
		while (last % 10 == 0)
		{
			cnt++;
			last /= 10;
		}
		if (last >= 10)
		{
			string s = to_string(last);
			last = s.back() - '0';
		}
		for (int i = 0; i < n - 1; i++)
		{
			last *= now;
		}
		cout << cnt << '\n';
	}
}