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

	// 수의 개수
	int n = 0;
	std::cin >> n;

	// 수열
	std::vector<int> inputNumVec(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputNumVec[i];
	}

	// (+)(-)(x)(/)의 개수
	std::vector<int> operatorVec(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> operatorVec[i];
	}

	int max = 0;
	int min = 1000000000;	// 최대 값을 넣는다.

	// 최대는 n - 1까지 진행
	std::vector<int> nowVec;	// 현재 진행 중인 벡터 (숫자와 연산자가 담길 것임)
	Func(inputNumVec, operatorVec, min, max, 0, 0, 0, n, nowVec);

	std::cout << max << '\n' << min;

	return 0;
}

void Func(const std::vector<int>& inputNumVec, const std::vector<int>& operatorVec, int& min, int& max, int totalCount, int numCount, int opeCount, int n, std::vector<int>& nowVec)
{
	// n * 2 - 1까지 도달하면 계산완료
	if (totalCount == n * 2 - 1)
	{
		int result = 0;
		eOperator _eOperator = Add;

		// nowVec
		for (int i = 0; i < n * 2 - 1; i++)
		{
			// 나눠떨어지면 숫자
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
					// 음수일 경우 양수로 바꾼 뒤 몫을 취하고
					if (result < 0)
					{
						result *= -1;
						isMinus = true;
					}

					result /= nowVec[i];

					// 음수일 경우 몫을 다시 음수로 바꾼다.
					if (isMinus)
					{
						result *= -1;
					}
					break;
				}
			}
			// 연산자
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

		// 계산이 끝나면 최소, 최대 비교한다.
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
		// 숫자 차례
		if (totalCount % 2 == 0)
		{
			nowVec[numCount] = inputNumVec[numCount];
			numCount++;
		}
		// 연산자 차례
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