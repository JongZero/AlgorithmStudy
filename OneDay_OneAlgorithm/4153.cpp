#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	while (true)
	{
		int nums[3];

		cin >> nums[0] >> nums[1] >> nums[2];

		if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
		{
			break;
		}

		int max = 0;
		int maxIndex = 0;
		for (int i = 0; i < 3; i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
			}
		}

		int a = 0;
		int b = 0;
		for (int i = 0; i < 3; i++)
		{
			if (max != nums[i])
			{
				if (a == 0)
				{
					a = nums[i];
				}
				else
				{
					b = nums[i];
				}
			}
		}

		if (pow(a, 2) + pow(b, 2) == pow(max, 2))
		{
			cout << "right" << "\n";
		}
		else
		{
			cout << "wrong" << "\n";
		}
	}

	return 0;
}