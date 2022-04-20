#include <iostream>
#include <vector>
#include <algorithm>

enum eOperator
{
	Add,
	Sub,
	multi,
	Devision,
};

void Func(const std::vector<int>& inputNumVec)
{
	// nowVec�� ������ (n * 2 - 1)���� �����ϸ� ���Ϸ�
	if (true)
	{

	}
	else
	{

	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// ���� ����
	int n = 0;
	std::cin >> n;

	// ����
	std::vector<int> inputNumVec(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputNumVec[i];
	}

	// (+)(-)(x)(/)�� ����
	std::vector<int> inputOperatorVec(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> inputOperatorVec[i];
	}

	// Operator���� �ϳ��ϳ� ����
	// ���� ������ �ٲ㰡�鼭 �ּ�, �ִ� �˻� �� ����
	std::vector<eOperator> operatorVec;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < inputOperatorVec[i]; j++)
		{
			operatorVec.emplace_back(eOperator(i));
		}
	}

	int max = -1000000000;
	int min = 1000000000;	// �ִ� ���� �ִ´�.

	// �ִ�� n * 2 - 1���� ����
	const int MaxCount = n * 2 - 1;	// �ִ� ���� + ������ ����
	do 
	{
		int numIndex = 0;
		int opeIndex = 0;
		int result = 0;			// ��� ���
		eOperator eOpe = Add;	// ���� ������

		for (int i = 0; i < MaxCount; i++)
		{
			// ����
			if (i % 2 == 0)
			{
				int nowNum = inputNumVec[numIndex];

				switch (eOpe)
				{
				case Add:
					result += nowNum;
					break;
				case Sub:
					result -= nowNum;
					break;
				case multi:
					result *= nowNum;
					break;
				case Devision:
					bool isMinus = false;
					if (result < 0)
					{
						result *= -1;
						isMinus = true;
					}

					result /= nowNum;

					if (isMinus)
					{
						result *= -1;
					}
					break;
				}

				numIndex++;
			}
			else
			{
				eOpe = operatorVec[opeIndex];
				opeIndex++;
			}
		}

		// ����� �� �� ����
		if (result < min)
		{
			min = result;
		}

		if (result > max)
		{
			max = result;
		}
	} while (std::next_permutation(operatorVec.begin(), operatorVec.end()));

	std::cout << max << '\n' << min;

	return 0;
}
