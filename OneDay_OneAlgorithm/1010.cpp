#include <iostream>
#include <vector>
#include <math.h>

unsigned long long factorial(const int n)
{
	unsigned long result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

void Func(int n, int m, std::vector<int> vec, int& count)
{
	// ���� Ȯ���ϰ� ������ ī����
	bool check = false;
	
	// ���� ó���� m-n�� �Ѿ ���
	if (vec.front() > m - n)
	{
		check = true;
	}

	// ���� �������� m�� �Ѿ ���
	if (vec.back() >= m)
	{
		check = true;
	}

	// �迭�� ������ �������� ū �� Ȯ��
	//if (check == false)
	//{
	//	int prevNum = vec.front();
	//	for (int i = 1; i < vec.size(); i++)
	//	{
	//		if (vec[i] <= prevNum)
	//		{
	//			check = true;
	//			break;
	//		}
	//	}
	//}
	
	// ��� ���� ���
	if (check == false)
	{
		count++;
	}
		
	// ��� �κ��� ������ų ���ΰ�?
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (vec[i] < m)
		{
			vec[i]++;
			Func(n, m, vec, count);
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n >> m;

		// ����
		std::vector<int> numeratorVec;
		//unsigned long long numerator = 1;
		for (int i = n + 1; i <= m; i++)
		{
			numeratorVec.emplace_back(i);
		}

		// �и�
		std::vector<int> denominatorVec;
		for (int i = 2; i <= m - n; i++)
		{
			denominatorVec.emplace_back(i);
		}

		bool check = true;
		int nIndex = 0;
		int dIndex = 0;
		while (check)
		{
			// ���� �������ٸ�
			if (numeratorVec[nIndex] % denominatorVec[dIndex] == 0)
			{
				
			}
		}

		int a = 0;

		//unsigned long long denominator = factorial(m - n);

		//unsigned long long result = numerator / denominator;

		//unsigned long long numerator = factorial(m);

		// �и�
		//unsigned long long denominator = factorial(m - n) * factorial(n);

		//unsigned long long result = numerator / denominator;
		//std::cout << result << '\n';

		//std::vector<int> vec(n);
		//
		//for (int j = 0; j < n; j++)
		//{
		//	vec[j] = j;
		//}
		//
		//int count = 0;
		//Func(n, m, vec, count);
		//
		//std::cout << count << '\n';
	}

	return 0;
};