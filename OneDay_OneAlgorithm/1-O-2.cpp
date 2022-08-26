#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	while (cin >> n)
	{
		int now = 1;
		int count = 1;	// ÀÚ¸®¼ö
		while (true)
		{
			if (now % n == 0)
			{
				cout << count << '\n';
				break;
			}
			else
			{
				now = now * 10 + 1;
				now = now % n;
				count++;
			}
		}
	}
}