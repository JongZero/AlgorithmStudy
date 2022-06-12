#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int input = 0;
		cin >> input;

		long long nums[101] = { 0, };

		nums[1] = 1;
		nums[2] = 1;
		nums[3] = 1;
		nums[4] = 2;
		nums[5] = 2;

		for (int j = 6; j <= input; j++)
		{
			nums[j] = nums[j - 2] + nums[j - 3];
		}

		cout << nums[input] << '\n';
	}

	return 0;
}