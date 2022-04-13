#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int InputMax = 100;
	const int ArrayMax = 9;
	std::vector<int> _array(ArrayMax);

	int sum = 0;
	for (int i = 0; i < ArrayMax; i++)
	{
		std::cin >> _array[i];
		sum += _array[i];
	}

	for (int j = 0; j < ArrayMax - 1; j++)
	{
		for (int k = j + 1; k < ArrayMax; k++)
		{
			if (sum - _array[j] - _array[k] == 100)
			{
				_array[j] = 0;
				_array[k] = 0;
				break;
			}
		}

		if (_array[j] == 0)
		{
			break;
		}
	}

	std::sort(_array.begin(), _array.end());

	for (int i = 0; i < ArrayMax; i++)
	{
		if (_array[i] == 0)
			continue;

		std::cout << _array[i] << '\n';
	}

	return 0;
}