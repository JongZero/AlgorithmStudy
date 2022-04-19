#include <iostream>
#include <vector>

enum eOperator
{
	Add,
	Sub,
	multi,
	Devision,
};

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
	std::vector<int> operatorVec(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> operatorVec[i];
	}

	int max = 0;
	int min = 1000000000;	// �ִ� ���� �ִ´�.

	// �ִ�� n - 1���� ����
	std::vector<int> nowVec;	// ���� ���� ���� ���� (���ڿ� �����ڰ� ��� ����)
	Func(inputNumVec, operatorVec, min, max, 0, 0, 0, n, nowVec);

	std::cout << max << '\n' << min;

	return 0;
}

void Func(const std::vector<int>& inputNumVec, const std::vector<int>& operatorVec, int& min, int& max, int totalCount, int numCount, int opeCount, int n, std::vector<int>& nowVec)
{
	// n * 2 - 1���� �����ϸ� ���Ϸ�
	if (totalCount == n * 2 - 1)
	{
		int result = 0;
		eOperator _eOperator = Add;

		// nowVec
		for (int i = 0; i < n * 2 - 1; i++)
		{
			// ������������ ����
			if (i % 2 == 0)
			{
				switch (nowVec[i])
				{
				case Add:
					result += nowVec[i];
					break;
				case Sub:
					result -= nowVec[i];
					break;
				case multi:
					result *= nowVec[i];
					break;
				case Devision:
					bool isMinus = false;
					// ������ ��� ����� �ٲ� �� ���� ���ϰ�
					if (result < 0)
					{
						result *= -1;
						isMinus = true;
					}

					result /= nowVec[i];

					// ������ ��� ���� �ٽ� ������ �ٲ۴�.
					if (isMinus)
					{
						result *= -1;
					}
					break;
				}
			}
			// ������
			else
			{
				switch (nowVec[i])
				{
				case Add:
					_eOperator = Add;
					break;
				case Sub:
					_eOperator = Sub;
					break;
				case multi:
					_eOperator = multi;
					break;
				case Devision:
					_eOperator = Devision;
					break;
				}
			}
		}

		// ����� ������ �ּ�, �ִ� ���Ѵ�.
		if (result < min)
		{
			min = result;
		}

		if (result > max)
		{
			max = result;
		}
	}
	else
	{
		// ���� ����
		if (totalCount % 2 == 0)
		{
			nowVec[numCount] = inputNumVec[numCount];
			numCount++;
		}
		// ������ ����
		else
		{
			nowVec[opeCount] = operatorVec[opeCount];
			opeCount++;
		}

		totalCount++;
		Func(inputNumVec, operatorVec, min, max, totalCount, numCount, opeCount, n, nowVec);

		

		if (opeCount + 2)
		{

		}
	}
}