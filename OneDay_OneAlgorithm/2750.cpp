#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& numbers)
{
	int size = numbers.size();
	for (int i = 0; i < size - 1; i++)
	{
		// 작은 숫자를 계속 왼쪽으로 옮긴다.
		if (numbers[i] > numbers[i + 1])
		{
			int temp = 0;
			temp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = temp;
			Sort(numbers);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	Sort(numbers);

	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << "\n";
	}

	return 0;
}