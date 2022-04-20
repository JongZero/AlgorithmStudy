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
	// nowVec의 사이즈 (n * 2 - 1)까지 도달하면 계산완료
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
	std::vector<int> inputOperatorVec(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> inputOperatorVec[i];
	}

	// Operator들을 하나하나 저장
	// 얘의 순서를 바꿔가면서 최소, 최대 검사 할 것임
	std::vector<eOperator> operatorVec;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < inputOperatorVec[i]; j++)
		{
			operatorVec.emplace_back(eOperator(i));
		}
	}

	int max = -1000000000;
	int min = 1000000000;	// 최대 값을 넣는다.

	// 최대는 n * 2 - 1까지 진행
	const int MaxCount = n * 2 - 1;	// 최대 숫자 + 연산자 개수
	do 
	{
		int numIndex = 0;
		int opeIndex = 0;
		int result = 0;			// 계산 결과
		eOperator eOpe = Add;	// 현재 연산자

		for (int i = 0; i < MaxCount; i++)
		{
			// 숫자
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

		// 계산결과 비교 후 저장
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
