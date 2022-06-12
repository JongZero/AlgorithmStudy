#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1000000;
int dp[1000001] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		int tempMinCount = 0;

		int temp2 = MAX;		// 2로 나눴을 경우
		if (i % 2 == 0)
		{
			temp2 = dp[i / 2];
		}
		
		int temp3 = MAX;		// 3으로 나눴을 경우
		if (i % 3 == 0)
		{
			temp3 = dp[i / 3];
		}

		int temp1 = dp[i - 1];	// 1로 나눴을 경우

		tempMinCount = temp1;
		if (temp2 < tempMinCount)
			tempMinCount = temp2;
		if (temp3 < tempMinCount)
			tempMinCount = temp3;
		
		dp[i] = tempMinCount + 1;
	}

	cout << dp[n];

	return 0;
}