#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int numbers[3] = { 0, };
	int maxNum = 0;
	int equalCount = 0;
	int equalNum = 0;
	for (int i = 0; i < 3; i++)
	{
		std::cin >> numbers[i];

		if (numbers[i] > maxNum)
		{
			maxNum = numbers[i];
		}

		if (i == 0)
			continue;

		if (numbers[i] == numbers[i - 1])
		{
			equalCount++;
			equalNum = numbers[i];
		}
	}

	if (numbers[0] == numbers[2])
	{
		equalCount++;
		equalNum = numbers[0];
	}

	int prize = 0;
	if (equalCount >= 2)
	{
		prize = 10000 + equalNum * 1000;
	}
	else if (equalCount >= 1)
	{
		prize = 1000 + equalNum * 100;
	}
	else
	{
		prize = maxNum * 100;
	}

	std::cout << prize;

	return 0;
}