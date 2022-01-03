#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int sum = 0;
	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		int in, out;
		cin >> out >> in;

		sum += (in - out);

		if (sum > max)
		{
			max = sum;
		}
	}

	cout << max;

	return 0;
}