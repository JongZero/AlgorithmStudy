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
		// 10 -> 2 * 5 -> 2와 5의 갯수를 구한다.
		// 10!의 2의 개수
		//		1 2 3 4 5 6 7 8 9 10
		//	2	  1   1   1   1   1
		//	4		  1       1
		//  8                 1
		// -> 5 + 2 + 1 = 8
		int ret2 = 0;
		int ret5 = 0;
		for (int i = 2; i <= n; i *= 2)
		{
			ret2 += n / i;
		}
		for (int i = 5; i <= n; i *= 5)
		{
			ret5 += n / i;
		}
		int ret = min(ret2, ret5);
		cout << ret << '\n';
	}
}