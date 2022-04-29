#include <iostream>
#include <vector>

int n = 0;
typedef std::pair<int, int> indexPair;
std::vector<std::vector<long long>> inputVec;
std::vector<std::vector<long long>> visitedVec;
int resultCount = 0;

bool Check(int i, int j)
{
	if (i == n - 1 && j == n - 1)
	{
		return false;
	}
	else if (i > n - 1 || j > n - 1 || i < 0 || j < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Func(int i, int j)
{
	if (i == n - 1 && j == n - 1)
	{
		resultCount++;
		return;
	}
	else if (inputVec[i][j] > 0)
	{
		// �Ʒ��� �� ��,
		if (Check(i + inputVec[i][j], j))
		{
			Func(i + inputVec[i][j], j);
		}

		// ���������� �� ��
		if (Check(i, j + inputVec[i][j]))
		{
			Func(i, j + inputVec[i][j]);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;

	inputVec.resize(n);
	visitedVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		inputVec[i].resize(n);
		visitedVec[i].resize(n);

		for (int j = 0; j < n; j++)
		{
			std::cin >> inputVec[i][j];
		}
	}

	// ��ʹ� �ð��ʰ�
	//Func(0, 0);

	// 0,0�� 1�� �ʱ�ȭ
	visitedVec[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int jumpCount = inputVec[i][j];
			
			// �Ʒ�
			if (i != n - 1 && i + jumpCount < n)
			{
				visitedVec[i + jumpCount][j] += visitedVec[i][j];
			}
			
			// ������
			if (j != n - 1 && j + jumpCount < n)
			{
				visitedVec[i][j + jumpCount] += visitedVec[i][j];
			}
		}
	}
	
	std::cout << visitedVec[n - 1][n - 1];
	
	return 0;
}