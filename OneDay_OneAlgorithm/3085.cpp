#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> inputStrVec;
int n = 0;
int resultMax = 1;

enum class eDir
{
	Up,
	Down,
	Left,
	Right
};

void Check(int i, int j, eDir eD, bool isSwap)
{
	int checkI = i;
	int checkJ = j;

	switch (eD)
	{
	case eDir::Up:
		checkI -= 1;
		break;
	case eDir::Down:
		checkI += 1;
		break;
	case eDir::Left:
		checkJ -= 1;
		break;
	case eDir::Right:
		checkJ += 1;
		break;
	}

	// �迭�� �ε����� ����� �ȵ�
	if (checkI < 0 || checkI >= n)
	{
		return;
	}
	if (checkJ < 0 || checkJ >= n)
	{
		return;
	}

	// ������ ���� �ٸ��� üũ
	if (inputStrVec[checkI][checkJ] != inputStrVec[i][j])
	{
		// �ٸ��ٸ� swap
		if (isSwap)
		{
			char temp = inputStrVec[checkI][checkJ];
			inputStrVec[checkI][checkJ] = inputStrVec[i][j];
			inputStrVec[i][j] = temp;
		}

		// swap �� ��, �� / ��, ��� �� 2���˻�
		int sameCandyCount = 1;
		for (int cI = i - 1; cI >= 0; cI--)
		{
			if (inputStrVec[cI][j] == inputStrVec[i][j])
			{
				sameCandyCount++;
			}
			else
			{
				break;
			}
		}
		for (int cI = i + 1; cI < n; cI++)
		{
			if (inputStrVec[cI][j] == inputStrVec[i][j])
			{
				sameCandyCount++;
			}
			else
			{
				break;
			}
		}

		// ��, �� ���� üũ
		if (sameCandyCount > resultMax)
		{
			resultMax = sameCandyCount;
		}

		sameCandyCount = 1;

		for (int cJ = j - 1; cJ >= 0; cJ--)
		{
			if (inputStrVec[i][cJ] == inputStrVec[i][j])
			{
				sameCandyCount++;
			}
			else
			{
				break;
			}
		}
		for (int cJ = j + 1; cJ < n; cJ++)
		{
			if (inputStrVec[i][cJ] == inputStrVec[i][j])
			{
				sameCandyCount++;
			}
			else
			{
				break;
			}
		}

		// ��, �� ���� üũ
		if (sameCandyCount > resultMax)
		{
			resultMax = sameCandyCount;
		}

		// �ٽ� ���󺹱� swap
		if (isSwap)
		{
			char temp = inputStrVec[checkI][checkJ];
			inputStrVec[checkI][checkJ] = inputStrVec[i][j];
			inputStrVec[i][j] = temp;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;

	inputStrVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputStrVec[i];
	}

	// �� ���� �׳� üũ,
	// �� ���� ������ ĭ�� ��ȯ�ذ��鼭, ������ üũ�Ѵ�.
	bool isSwap = false;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// ��
				Check(i, j, eDir::Up, isSwap);
				// ��
				Check(i, j, eDir::Down, isSwap);
				// ��
				Check(i, j, eDir::Left, isSwap);
				// ��
				Check(i, j, eDir::Right, isSwap);
			}
		}

		isSwap = true;
	}

	std::cout << resultMax;

	return 0;
}
