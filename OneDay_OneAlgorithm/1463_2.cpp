#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> dpVec(n + 1);

	// n까지 누적
	for (int i = 1; i < n; i++)
	{
		int nextNum = i + 1;

		// 최소를 검사
		int min = dpVec[i];

		if (nextNum % 2 == 0)
		{
			min = Min(min, dpVec[nextNum / 2]);
		}
		if (nextNum % 3 == 0)
		{
			min = Min(min, dpVec[nextNum / 3]);
		}

		dpVec[nextNum] = min + 1;
	}

	cout << dpVec[n];

	return 0;
}