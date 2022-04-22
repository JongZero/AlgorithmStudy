#include <iostream>
#include <vector>

int n = 0;
std::vector<int> g_NumVec(11);			// �Է¹��� ���ڵ�
std::vector<int> g_OperatorCountVec(4);	// �Է¹��� ������ ������
std::vector<int> g_CalcNumVec(11);		// ����ؾ��ϴ� �����ڵ�

int g_Min = 1000000000;
int g_Max = -1000000000;


void Func(int count)
{
	if (count >= n - 1)
	{
		int result = g_NumVec.front();
		int numIndex = 1;

		// ����Ѵ�.
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
			// ������ ������ 0����� �ѱ��.
			if (g_OperatorCountVec[i] == 0)
				continue;

			// �ϳ� ����ϹǷ� ���� �ٿ��ְ�,
			g_OperatorCountVec[i]--;
			g_CalcNumVec[count] = i + 1;	// ����ؾ� �� ������ ���Ϳ� �־��ش�.
			Func(count + 1);

			// ����
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
