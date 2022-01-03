#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> numbers;	// 숫자 배열
	int count = 0;			// 소수가 몇개인지

	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;

		if (a > 1)
		{
			numbers.push_back(a);
		}
	}

	// 소수인지 판별
	for (int i = 0; i < numbers.size(); i++)
	{
		// 소수라고 가정
		bool isPrime = true;

		for (int j = 2; j < numbers[i]; j++)
		{
			// 소수가 아닌 조건을 검사
			if (numbers[i] % j == 0)
			{
				isPrime = false;
			}
		}

		if (isPrime == true)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}