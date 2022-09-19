#include <bits/stdc++.h>
using namespace std;

double a, b, dp[19][19][19];

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

double func(int sA, int sB, int cnt)
{
	if (cnt >= 18)
	{
		if (isPrime(sA) || isPrime(sB))
			return 1.0;
		return 0.0;
	}
	double& d = dp[sA][sB][cnt];
	if (d > -0.5) return d;
	d = 0.0;
	d += func(sA + 1, sB + 1, cnt + 1) * a * b;
	d += func(sA + 1, sB, cnt + 1) * a * (1 - b);
	d += func(sA, sB + 1, cnt + 1) * (1 - a) * b;
	d += func(sA, sB, cnt + 1) * (1 - a) * (1 - b);
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	a /= 100;
	b /= 100;
	cout << func(0, 0, 0);
}