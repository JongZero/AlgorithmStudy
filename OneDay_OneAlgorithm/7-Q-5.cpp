#include <bits/stdc++.h>
using namespace std;

double a, b, dp[19][19][19];

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0) return false;
	}
	return true;
}

double func(int aa, int bb, int idx)
{
	if (idx == 18)
	{
		if (isPrime(aa) || isPrime(bb))
			return 1.0;
		return 0.0;
	}
	double& d = dp[aa][bb][idx];
	if (d >= -0.5) return d;
	d = 0.0;
	d += func(aa + 1, bb + 1, idx + 1) * a * b;
	d += func(aa + 1, bb, idx + 1) * a * (1 - b);
	d += func(aa, bb + 1, idx + 1) * (1 - a) * b;
	d += func(aa, bb, idx + 1) * (1 - a) * (1 - b);
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	a /= 100;
	b /= 100;

	cout << func(0, 0, 0);
}