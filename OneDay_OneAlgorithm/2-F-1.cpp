#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret;
int l = 1, r, apple;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	cin >> j;
	m--;
	for (int i = 0; i < j; i++)
	{
		cin >> apple;
		r = l + m;
		if (apple >= l && apple <= r) continue;
		else
		{
			if (apple < l)
			{
				ret += (l - apple);
				l -= (l - apple);
			}
			else
			{
				ret += (apple - r);
				l += (apple - r);
			}
		}
	}
	cout << ret << "\n";
}