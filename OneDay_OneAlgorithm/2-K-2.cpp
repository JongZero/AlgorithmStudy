#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;

		int ret2 = 0;
		for (int i = 2; i <= n; i *= 2)
		{
			ret2 += n / i;
		}
		int ret5 = 0;
		for (int i = 5; i <= n; i *= 5)
		{
			ret5 += n / i;
		}
		cout << min(ret2, ret5) << '\n';
	}
}