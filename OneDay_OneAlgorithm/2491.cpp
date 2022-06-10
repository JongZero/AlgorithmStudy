#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	int prev = 0;
	int maxUpCount = 1;
	int maxDownCount = 1;
	int upCount = 1;
	int downCount = 1;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (i > 0)
		{
			if (prev <= input)
			{
				upCount++;
			}
			else
			{
				upCount = 1;
			}
			
			if (prev >= input)
			{
				downCount++;
			}
			else
			{
				downCount = 1;
			}

			if (upCount > maxUpCount)
				maxUpCount = upCount;

			if (downCount > maxDownCount)
				maxDownCount = downCount;
		}

		prev = input;
	}

	int result = maxUpCount;
	if (maxUpCount < maxDownCount)
		result = maxDownCount;

	cout << result;

	return 0;
}