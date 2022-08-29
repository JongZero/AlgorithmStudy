#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (cin >> n)
	{
		int now = 1;
		int cnt = 1;

		while (true)
		{
			if (now % n == 0)
			{
				cout << cnt << "\n";
				break;
			}
			else
			{
				now = now * 10 + 1;
				now = now % n;
				cnt++;
			}
		}
	}
}