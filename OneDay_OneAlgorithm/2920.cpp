#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int numArr[8];

	bool isAscending = true;
	bool isDescending = true;

	int des = 8;
	for (int i = 0; i < 8; i++)
	{
		cin >> numArr[i];

		if (numArr[i] != i + 1)
		{
			isAscending = false;
		}

		if (numArr[i] != des)
		{
			isDescending = false;
		}

		des--;
	}

	if (isAscending)
	{
		cout << "ascending";
	}
	else if (isDescending)
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}

	return 0;
}