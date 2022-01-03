#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int n = 10000;
	int* eratosArray = new int[10001];
	//vector<int> eratosArray(n);
	vector<int> primeNumbers;

	// �ϴ� ���ڸ� �迭�� �ִ´�.
	for (int i = 1; i <= n; i++)
	{
		eratosArray[i] = i;
	}

	for (int i = 2; i * i <= n; i++)
	{
		// �̹� �����佺�׳׽��� ü�� �ɷ��� ����� �˻������ʰ� �Ѿ��.
		if (eratosArray[i] == 1)
		{
			continue;
		}
		else
		{
			// �Ҽ��� �̸� ����
			primeNumbers.push_back(eratosArray[i]);
		}
		
		for (int j = i * i; j <= n; j += i)
		{
			eratosArray[j] = 1;
		}
	}

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;

		// ù ��° �Ҽ�
		vector<int> primeNum1s;
		// �� ��° �Ҽ�
		vector<int> primeNum2s;

		int primeNum1 = 0;
		int primeNum2 = 0;
		for (int j = 0; j < primeNumbers.size(); j++)
		{
			if (primeNumbers[j] >= n)
			{
				break;
			}
			else
			{
				primeNum1 = primeNumbers[j];

				for (int k = 0; k < primeNumbers.size(); k++)
				{
					if (primeNumbers[k] >= n)
					{
						break;
					}
					else
					{
						primeNum2 = primeNumbers[k];
					}

					if (primeNum1 + primeNum2 == n)
					{
						primeNum1s.push_back(primeNum1);
						primeNum2s.push_back(primeNum2);
					}
				}
			}
		}

		// 2�� �̻� ���� ��� ���� ���� ���� �� ���
		if (primeNum1s.size() > 1)
		{
			int min = 10000;
			int index = 0;
			for (int j = 0; j < primeNum1s.size(); j++)
			{
				int s = primeNum1s[j] - primeNum2s[j];

				if (s < 0)
					s *= -1;

				if (s < min)
				{
					min = s;
					index = j;
				}
			}

			if (primeNum1s[index] < primeNum2s[index])
			{
				cout << primeNum1s[index] << " " << primeNum2s[index] << "\n";
			}
			else
			{
				cout << primeNum2s[index] << " " << primeNum1s[index] << "\n";
			}
		}
		// 1�������� �װ��� ���
		else if (primeNum1s.size() > 0)
		{
			if (primeNum1s[0] < primeNum2s[0])
			{
				cout << primeNum1s[0] << " " << primeNum2s[0] << "\n";
			}
			else
			{
				cout << primeNum2s[0] << " " << primeNum1s[0] << "\n";
			}
		}
		else
		{
			cout << "���� : ������ ��Ƽ���� ����." << "\n";
		}
	}

	return 0;
}