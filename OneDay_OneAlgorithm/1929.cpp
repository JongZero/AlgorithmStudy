#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	/// Mark1
	/// 1���� n���� �������� ���ϱ�
	/// �翬�� �ð��ʰ��� �����
	/// ������ Ǯ������ �����佺�׳׽��� ü�� Ȱ���غ���
	/*
	int m, n;
	cin >> m >> n;

	// m ~ n ���� �Ҽ��� ���Ѵ�.
	for (int i = m; i <= n; i++)
	{
		// 1 ���ϴ� �Ҽ��� �� �� ����.
		if (i <= 1)
		{
			continue;
		}
		
		bool isPrime = true;
		for (int j = 2; j < i; j++)
		{
			// ������������ ���� �ִٸ� �Ҽ��� �ƴ�
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		// �Ҽ���� ���
		if (isPrime == true)
		{
			cout << i << "\n";
		}
	}
	*/
	
	/// Mark2
	/// �����佺�׳׽��� ü
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int m, n;
	cin >> m >> n;

	int* eratosVec = new int[1000001];

	// �ϴ� ���ڸ� �迭�� �ִ´�.
	for (int i = 1; i <= n; i++)
	{
		eratosVec[i] = i;
	}
	
	for (int i = 2; i * i <= n; i++)
	{
		// �̹� �����佺�׳׽��� ü�� �ɷ��� ����� �˻������ʰ� �Ѿ��.
		if (eratosVec[i] == 1)
		{
			continue;
		}

		for (int j = i * i; j <= n; j += i)
		{
			eratosVec[j] = 1;
		}
	}

	// ����Ѵ�.
	for (int i = m; i <= n; i++)
	{
		if (eratosVec[i] > 1)
		{
			cout << eratosVec[i] << "\n";
		}
	}

	delete[] eratosVec;

	return 0;
}