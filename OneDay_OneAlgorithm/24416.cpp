#include <iostream>
#include <vector>
#include <string>

using namespace std;

int recursiveCount = 1;
int dpCount = 0;

int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
	{
		recursiveCount++;
		return fib(fib(n - 1) + fib(n - 2));
	}
}

int dp[41];

int fibDP(int n)
{
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dpCount++;
	}
	return dp[n];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	fib(n);
	fibDP(n);

	cout << recursiveCount << ' ' << dpCount;

	return 0;
}