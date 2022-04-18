#include <iostream>
#include <map>

bool IsPrime(const int& num)
{
	bool isPrime = true;
	for (int i = 2; i < num; i++)
	{
		// ������������ �� �ִٸ� �Ҽ��� �ƴ�
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int m(0), n(0);
	std::cin >> m >> n;

	// �� ����
	int totalCount = n - m + 1;

	// �����佺�׳׽��� ü Ȱ���غ���
	std::map<int, bool> numMap;		// ����, �Ҽ�����

	// �ʱ�ȭ
	for (int i = m; i <= n; i++)
	{
		numMap[i] = true;
	}
	
	// �Ҽ��� ����� �Ҽ��� �ƴ�
	for (int i = m; i <= n; i++)
	{
		// �̹� �Ҽ��� �ƴ� �ɷ� �ǴܵǾ��ٸ� pass
		if (numMap[i] == false)
		{
			continue;
		}

		// �Ҽ����� üũ
		bool isPrime = false;
		for (int j = i; j <= n; j += i)
		{
			// ��¥ �Ҽ����� üũ
			if (numMap[j] == true)
			{
				isPrime = IsPrime(j);
			}

			// �Ҽ��� �ƴ϶��, �Ҽ��� �����
			if (isPrime == false)
			{
				numMap[j] = false;
			}
		}
	}

	int sum = 0;
	int min = 10001;
	for (int i = m; i <= n; i++)
	{
		// �Ҽ����
		if (i > 1 && numMap[i] == true)
		{
			// �ּ� üũ
			if (i < min)
			{
				min = i;
			}

			sum += i;
		}
	}

	if (sum <= 0)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << sum << '\n';
		std::cout << min;
	}

	return 0;
}