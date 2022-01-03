#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// M이상 N이하의 자연수 중 소수인 것을 모두 찾는다.
	int m, n = 0;
	cin >> m >> n;

	vector<int> primeNumbers;	// 소수 배열

	if ((m >= 1 && n >= 1) && m <= n)
	{
		// 소수인지 판별
		for (int i = m; i <= n; i++)
		{
			if (i <= 1)
				continue;

			// 소수라고 가정
			bool isPrime = true;

			for (int j = 2; j < i; j++)
			{
				// 소수가 아닌 조건을 검사
				if (i % j == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime == true)
			{
				primeNumbers.push_back(i);
			}
		}

		if (primeNumbers.size() > 0)
		{
			// 소수의 합과 최소 소수를 찾는다.
			int minPrimeNum = 100000;
			int sum = 0;
			for (int i = 0; i < primeNumbers.size(); i++)
			{
				if (minPrimeNum > primeNumbers[i])
				{
					minPrimeNum = primeNumbers[i];
				}

				sum += primeNumbers[i];
			}

			cout << sum << "\n" << minPrimeNum;
		}
		else
		{
			cout << -1;
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}