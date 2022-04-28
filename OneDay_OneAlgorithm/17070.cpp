#include <iostream>
#include <vector>
using namespace std;

// 현재 상태
enum class eNowState
{
	Garo,
	Sero,
	Daegak,
};

int n = 0;
const int Max = 16 + 1;
int house[Max][Max];
int resultCount = 0;

bool CheckWall(int i, int j)
{
	// 인덱스를 벗어날 경우
	if (i > n - 1 || j > n - 1)
	{
		return false;
	}
	else
	{
		return (house[i][j] == 0);
	}
}

void Func(eNowState nowState, int i, int j)
{
	// 끝 지점에 도착한 경우
	if (i == n - 1 && j == n - 1)
	{
		resultCount++;
	}
	else
	{
		switch (nowState)
		{
			// 가로일 경우 가로로 한 번, 대각선 한 번
		case eNowState::Garo:
			if (CheckWall(i, j + 1))
			{
				Func(eNowState::Garo, i, j + 1);

				if (CheckWall(i + 1, j) && CheckWall(i + 1, j + 1))
				{
					Func(eNowState::Daegak, i + 1, j + 1);
				}
			}
			break;
		case eNowState::Sero:
			if (CheckWall(i + 1, j))
			{
				Func(eNowState::Sero, i + 1, j);

				if (CheckWall(i, j + 1) && CheckWall(i + 1, j + 1))
				{
					Func(eNowState::Daegak, i + 1, j + 1);
				}
			}
			break;
		case eNowState::Daegak:
			if (CheckWall(i, j + 1))
			{
				Func(eNowState::Garo, i, j + 1);

				if (CheckWall(i + 1, j) && CheckWall(i + 1, j + 1))
				{
					Func(eNowState::Daegak, i + 1, j + 1);
				}
			}
			if (CheckWall(i + 1, j))
			{
				Func(eNowState::Sero, i + 1, j);
			}
			break;
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
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;

			house[i][j] = input;
		}
	}

	// 첫 모양 가로로 정해져있음
	eNowState nowState = eNowState::Garo;

	// 파이프의 시작 위치 정해져있음
	Func(nowState, 0, 1);

	std::cout << resultCount;

	return 0;
}
