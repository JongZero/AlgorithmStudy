#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long go(long long n, long long p)
{
	if (p == 1) return n % c;

	long long temp = go(n, p / 2);
	temp = (temp * temp) % c;

	if (p % 2 == 1)
	{
		temp = (temp * n) % c;
	}
	return temp;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b >> c;

	// 시간 초과
	/*
	long long ret = a;
	for (long long i = 0; i < b; i++)
	{
		ret *= a;
		ret = ret % c;
	}
	cout << ret;
	*/

	long long ret = go(a, b);
	cout << ret;
}