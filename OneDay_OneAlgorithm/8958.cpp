#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	int* stringCounts = new int[n];

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		int score = 0;
		int addScore = 0;
		int size = str.size();
		for (int j = 0; j < size; j++)
		{
			if (str[j] == 'O')
				addScore++;
			else
				addScore = 0;

			score += addScore;
		}

		stringCounts[i] = score;
	}

	for (int i = 0; i < n; i++)
	{
		cout << stringCounts[i] << "\n";
	}

	delete[] stringCounts;
	stringCounts = nullptr;

	return 0;
}