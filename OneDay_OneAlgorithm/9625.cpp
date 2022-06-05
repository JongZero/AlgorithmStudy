#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k = 0;
	cin >> k;

	// A		1 0
	// B		0 1
	// BA		1 1
	// BAB		1 2
	// BABBA	2 3
	// BABBABAB	3 5
	// BABBABABBABBA	5 8

	int aNums[46] = { 0, };
	int bNums[46] = { 0, };

	aNums[0] = 1;
	bNums[1] = 1;

	for (int i = 2; i <= k; i++)
	{
		aNums[i] = aNums[i - 1] + aNums[i - 2];
		bNums[i] = bNums[i - 1] + bNums[i - 2];
	}

	cout << aNums[k] << ' ' << bNums[k];

	return 0;
}