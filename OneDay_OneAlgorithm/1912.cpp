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

	int max = -1000;
	int prev = 0;
	int prevMax = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		prev = prev + input;

		if (prev < input)
			prev = input;

		if (prev > max)
			max = prev;
	}

	cout << max;

	return 0;
}