#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int MaxNumber = 10001;

	int t = 0;
	cin >> t;

	int countArray[MaxNumber] = { 0, };
	
	// input
	for (int i = 0; i < t; i++)
	{
		int n1 = 0;
		cin >> n1;

		countArray[n1]++;
	}

	for (int i = 1; i < MaxNumber; i++)
	{
		if (countArray == 0)
			continue;

		for (int j = 0; j < countArray[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}