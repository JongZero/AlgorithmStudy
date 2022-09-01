#include <bits/stdc++.h>
using namespace std;

int n, m, j;
int l = 1, r, ret;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m >> j;
	for (int i = 0; i < j; i++)
	{
		int nex;
		cin >> nex;

		r = l + m - 1;
		if (l <= nex && nex <= r) continue;
		if (nex < l)
		{
			ret += (l - nex);
			l -= (l - nex);
		}
		else
		{
			ret += (nex - r);
			l += (nex - r);
		}
	}
	cout << ret;
}