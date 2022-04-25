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

	// 배열의 인덱스를 벗어나면 안됨
	if (checkI < 0 || checkI >= n)
	{
		return;
	}
	if (checkJ < 0 || checkJ >= n)
	{
		return;
	}

	// 사탕의 색이 다른지 체크
	if (inputStrVec[checkI][checkJ] != inputStrVec[i][j])
	{
		// 다르다면 swap
		if (isSwap)
		{
			char temp = inputStrVec[checkI][checkJ];
			inputStrVec[checkI][checkJ] = inputStrVec[i][j];
			inputStrVec[i][j] = temp;
		}

		// swap 후 상, 하 / 좌, 우로 총 2번검사
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

		// 상, 하 먼저 체크
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

		// 상, 하 먼저 체크
		if (sameCandyCount > resultMax)
		{
			resultMax = sameCandyCount;
		}

		// 다시 원상복귀 swap
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

	// 한 번은 그냥 체크,
	// 한 번은 인접한 칸과 교환해가면서, 사탕을 체크한다.
	bool isSwap = false;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 상
				Check(i, j, eDir::Up, isSwap);
				// 하
				Check(i, j, eDir::Down, isSwap);
				// 좌
				Check(i, j, eDir::Left, isSwap);
				// 우
				Check(i, j, eDir::Right, isSwap);
			}
		}

		isSwap = true;
	}

	std::cout << resultMax;

	return 0;
}
