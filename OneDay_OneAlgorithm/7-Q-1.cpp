#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

const int MAX = 18;
double a, b, dp[19][19][19];

double func(int da, int db, int cnt)
{
	if (cnt == MAX)
	{
		if (isPrime(da) || isPrime(db)) return 1.0;
		return 0.0;
	}
	double& d = dp[da][db][cnt];
	if (d > -0.5) return d;
	d = 0.0;
	d += func(da, db, cnt + 1) * (1.0 - a) * (1.0 - b);
	d += func(da + 1, db, cnt + 1) * a * (1.0 - b);
	d += func(da, db + 1, cnt + 1) * (1.0 - a) * b;
	d += func(da + 1, db + 1, cnt + 1) * a * b;
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	scanf("%lf %lf", &a, &b);
	a /= 100; b /= 100;
	printf("%.6lf", func(0, 0, 0));
}