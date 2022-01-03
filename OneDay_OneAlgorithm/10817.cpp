#include <iostream>
using namespace std;

int main()
{
	int numbers[3];
	cin >> numbers[0] >> numbers[1] >> numbers[2];

	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] == max)
		{
			numbers[i] = -1;
			break;
		}
	}

	int middle = 0;
	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] == -1)
			continue;

		if (numbers[i] > middle)
		{
			middle = numbers[i];
		}
	}

	cout << middle;
}