#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�´�.
	int m, n = 0;
	cin >> m >> n;

	vector<int> primeNumbers;	// �Ҽ� �迭

	if ((m >= 1 && n >= 1) && m <= n)
	{
		// �Ҽ����� �Ǻ�
		for (int i = m; i <= n; i++)
		{
			if (i <= 1)
				continue;

			// �Ҽ���� ����
			bool isPrime = true;

			for (int j = 2; j < i; j++)
			{
				// �Ҽ��� �ƴ� ������ �˻�
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
			// �Ҽ��� �հ� �ּ� �Ҽ��� ã�´�.
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