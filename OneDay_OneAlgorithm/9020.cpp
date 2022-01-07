#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int Max = 10000;
	int eratosArray[Max + 1] = { 0, };

	// 일단 숫자를 배열에 넣는다.
	for (int i = 1; i <= Max; i++)
	{
		eratosArray[i] = i;
	}

	for (int i = 2; i * i <= Max; i++)
	{
		// 이미 에라토스테네스의 체로 걸러진 수라면 검사하지않고 넘어간다.
		if (eratosArray[i] == 1)
		{
			continue;
		}

		for (int j = i * i; j <= Max; j += i)
		{
			eratosArray[j] = 1;
		}
	}

	//vector<int> primeNumbers;
	//for (int i = 2; i <= Max; i++)
	//{
	//	if (eratosArray[i] > 1)
	//	{
	//		primeNumbers.push_back(eratosArray[i]);
	//	}
	//}

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;

		// 첫 번째 소수
		int primeNum1s[Max + 1] = { 0, };
		// 두 번째 소수
		int primeNum2s[Max + 1] = { 0, };
		int primeIndex = 0;

		int primeNum1 = 0;
		int primeNum2 = 0;
		for (int j = 2; j <= n; j++)
		{
			// 소수가 아니라면 넘어감
			if (eratosArray[j] == 1)
				continue;
			
			primeNum1 = eratosArray[j];
			primeNum2 = n - primeNum1;

			// n은 두 소수의 합이므로 n - primeNum1도 소수여야 한다.
			if (eratosArray[primeNum2] > 1)
			{
				primeNum1s[primeIndex] = primeNum1;
				primeNum2s[primeIndex] = primeNum2;

				primeIndex++;
			}
		}

		// 2개 이상 있을 경우 가장 차가 작은 것 출력
		if (primeIndex > 1)
		{
			/*
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
			*/

			int index = primeIndex;
			if (index % 2 == 0)
				index /= 2;
			else
			{
				int index1 = (index + 1) / 2;
				int index2 = (index - 1) / 2;

				int s1 = primeNum1s[index1] - primeNum2s[index1];
				if (s1 < 0)
					s1 *= -1;

				int s2 = primeNum1s[index2] - primeNum2s[index2];
				if (s2 < 0)
					s2 *= -1;

				if (s1 < s2)
				{
					index = index1;
				}
				else
				{
					index = index2;
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
		// 1개있으면 그것을 출력
		else if (primeIndex > 0)
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
			cout << "오류 : 골드바흐 파티션이 없다." << "\n";
		}
	}

	return 0;
}