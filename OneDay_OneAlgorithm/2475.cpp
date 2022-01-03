#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int numbers[5];

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> numbers[i];

		sum += numbers[i] * numbers[i];
	}

	int checkNum = sum % 10;
	cout << checkNum;

	return 0;
}