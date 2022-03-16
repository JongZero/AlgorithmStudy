#include <iostream>
#include <vector>

// 1. ó���� mCn �޺���̼� �������� �𸣰� Func�Լ��� �̿��� ����Լ��� Ǯ���� �õ�
// 2. �� �������δ� mCn ���Ĵ�� ���丮�� �Լ� ���� Ǫ�µ� ���� �ʹ��Ǵ�.
// 3. ����°�δ� ���丮���� �ٷ� ���ϴ°� �ƴ϶� 3! �̸� ���Ϳ� 3,2,1 �־���� ����ؼ� �и�/����
//	  �ϴ� ������� Ǯ������ ����!

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

		if (n == m)
		{
			std::cout << 1 << '\n';
			continue;
		}
		
		// ����
		std::vector<int> numeratorVec;
		for (int i = n + 1; i <= m; i++)
		{
			numeratorVec.emplace_back(i);
		}

		// �и�
		std::vector<int> denominatorVec;
		for (int i = 1; i <= m - n; i++)
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
				numeratorVec[nIndex] = numeratorVec[nIndex] / denominatorVec[dIndex];

				denominatorVec[dIndex] = 1;
			}

			dIndex++;

			if (dIndex >= denominatorVec.size())
			{
				dIndex = 0;
				nIndex++;

				if (nIndex >= numeratorVec.size())
				{
					check = false;
				}
			}
		}

		unsigned long long numerator = 1;
		for (int i = 0; i < numeratorVec.size(); i++)
		{
			numerator *= numeratorVec[i];
		}

		unsigned long long denominator = 1;
		for (int i = 0; i < denominatorVec.size(); i++)
		{
			denominator *= denominatorVec[i];
		}

		unsigned long long result = numerator / denominator;

		std::cout << result << '\n';
	}

	return 0;
};