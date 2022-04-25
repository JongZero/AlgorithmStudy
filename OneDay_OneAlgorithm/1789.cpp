#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long s = 0;
	std::cin >> s;

	long long sum = 0;
	int num = 1;
	int resultCount = 0;
	while (true)
	{
		sum += num;
		resultCount++;

		if (sum > s)
		{
			resultCount--;
			break;
		}

		num++;
	}

	std::cout << resultCount;

	return 0;
}