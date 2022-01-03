#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<int> scores(5);

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> scores[i];

		if (scores[i] < 40)
		{
			scores[i] = 40;
		}

		sum += scores[i];
	}

	cout << sum / 5;

	return 0;
}