#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	while (cin >> n)
	{
		unsigned long long now = 1;
		unsigned long long temp = 10;
		
		int count = 1;
		while (now % n != 0)
		{
			now += temp;
			temp *= 10;
			now = now % n;
			count++;
		}
		cout << count << '\n';
	}
}