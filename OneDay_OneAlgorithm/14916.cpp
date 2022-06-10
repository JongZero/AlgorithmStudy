#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dpVec[100001] = { 0, };
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// 2원과 5원이 있음

	// 1 -> -1		
	// 2 -> 1		2
	// 3 -> -1		
	// 4 -> 2		2 2
	// 5 -> 1		5
	// 6 -> 3		2 2 2
	// 7 -> 2		2 5
	// 8 -> 4		2 2 2 2
	// 9 -> 3		2 2 5
	// 10 -> 2		5 5
	// 11 -> 4		2 2 2 5
	// 12 -> 3		2 5 5
	// 13 -> 5		2 2 2 2 5
	// 14 -> 4		2 2 5 5
	// 15 -> 3		5 5 5
	// 16 -> 5		2 2 2 5 5
	// 17 -> 4		2 5 5 5

	if (n == 1 || n == 3)
	{
		cout << -1;
		return 0;
	}

	dpVec[1] = 2;
	dpVec[2] = 1;
	dpVec[3] = 3;
	dpVec[4] = 2;
	dpVec[5] = 1;
	dpVec[6] = 3;
	dpVec[7] = 2;
	dpVec[8] = 4;
	dpVec[9] = 3;

	for (int i = 10; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			dpVec[i] = i / 5;
		}
		else
		{
			dpVec[i] = dpVec[i - 10] + 2;
		}
	}

	cout << dpVec[n];
	return 0;
}