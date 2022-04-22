#include <iostream>
#include <vector>

int n = 0;
std::vector<int> g_NumVec(11);			// 입력받은 숫자들
std::vector<int> g_OperatorCountVec(4);	// 입력받은 연산자 개수들
std::vector<int> g_CalcNumVec(11);		// 계산해야하는 연산자들

int g_Min = 1000000000;
int g_Max = -1000000000;


void Func(int count)
{
	if (count >= n - 1)
	{
		int result = g_NumVec.front();
		int numIndex = 1;

		// 계산한다.
		for (int i = 0; i < n; i++)
		{
			if (g_CalcNumVec[i] == 0)
				continue;

			switch (g_CalcNumVec[i])
			{
			case 1:
				result += g_NumVec[numIndex];
				break;
			case 2:
				result -= g_NumVec[numIndex];
				break;
			case 3:
				result *= g_NumVec[numIndex];
				break;
			case 4:
				result /= g_NumVec[numIndex];
				break;
			}

			numIndex++;
		}

		if (g_Min > result)
		{
			g_Min = result;
		}

		if (g_Max < result)
		{
			g_Max = result;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			// 연산자 개수가 0개라면 넘긴다.
			if (g_OperatorCountVec[i] == 0)
				continue;

			// 하나 사용하므로 개수 줄여주고,
			g_OperatorCountVec[i]--;
			g_CalcNumVec[count] = i + 1;	// 계산해야 할 연산자 벡터에 넣어준다.
			Func(count + 1);

			// 리셋
			g_OperatorCountVec[i]++;
			g_CalcNumVec[count] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> g_NumVec[i];
	}

	for (int j = 0; j < 4; j++)
	{
		std::cin >> g_OperatorCountVec[j];
	}

	Func(0);

	std::cout << g_Max << '\n' << g_Min;

	return 0;
}
