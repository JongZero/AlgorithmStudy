#include <bits/stdc++.h>
using namespace std;

const int MAX = 18;
int a, b, primeCount, aPer, bPer, dp[19][19], totalCount;

int getFloor(int n)
{
	if (n % 10 >= 5)
		return (n / 10 + 1);
	else
		return (n / 10);
}

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (i % n == 0) return false;
	}
	return true;
}

void func(int t1, int t2, int cnt)
{
	if (dp[t1][t2]) return;
	dp[t1][t2] = 1;

	if (cnt == MAX)
	{
		cout << t1 << ", " << t2 << " cnt : " << cnt << '\n';

		totalCount++;
		if (isPrime(t1))
		{
			primeCount++;
			return;
		}
		if (isPrime(t2))
		{
			primeCount++;
		}
		return;
	}

	int n = rand();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b;

	aPer = getFloor(a);
	bPer = getFloor(b);
	//cout << aPer << " , " << bPer;

	func(0, 0, 0);
	double ret = (double)primeCount / (double)totalCount;
	cout << ret;
}