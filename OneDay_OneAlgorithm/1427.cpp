#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string s;
	cin >> s;

	vector<int> numbers(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		// char to int
		numbers[i] = s[i] - '0';
	}

	for (int i = 0; i < numbers.size() - 1;)
	{
		if (numbers[i] < numbers[i + 1])
		{
			int temp = numbers[i + 1];
			numbers[i + 1] = numbers[i];
			numbers[i] = temp;
			
			i = 0;
		}
		else
		{
			i++;
		}
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i];
	}

	return 0;
}