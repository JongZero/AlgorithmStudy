#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m = 0;
	cin >> n >> m;
	
	// true -> 흰색(W)
	// false -> 검정(B)

	bool** board = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		board[i] = new bool[m];
		
		string input;
		cin >> input;

		for (int j = 0; j < m; j++)
		{
			if (input[j] == 'W')
			{
				board[i][j] = true;
			}
			else
			{
				board[i][j] = false;
			}
		}
	}

	int nStart = 0;
	int mStart = 0;
	int checkCountMin = 50 * 50;
	int checkCount = 0;
	while (true)
	{
		// 가장 맨위 맨 왼쪽을 체크
		bool startWB = board[nStart][mStart];
		
		for (int k = 0; k < 2; k++)
		{
			// 맨위 맨 왼쪽을 한 번 바꿔서 체크해봄
			if (k == 1)
				startWB = !startWB;

			bool evenRowEvenColumn = startWB;	// 짝수 행의 짝수 열
			bool evenRowOddColumn = !startWB;	// 짝수 행의 홀수 열

			bool oddRowEvenColumn = !startWB;	// 홀수 행의 짝수 열
			bool oddRowOddColumn = startWB;		// 홀수 행의 홀수 열

			// 가로 8 X 세로 8 만큼을 체크
			for (int i = nStart; i < nStart + 8; i++)
			{
				for (int j = mStart; j < mStart + 8; j++)
				{
					// 짝수 행
					if (i % 2 == 0)
					{
						// 짝수 열
						if (j % 2 == 0)
						{
							if (board[i][j] != evenRowEvenColumn)
							{
								checkCount++;
							}
						}
						// 홀수 열
						else
						{
							if (board[i][j] != evenRowOddColumn)
							{
								checkCount++;
							}
						}
					}
					// 홀수 행
					else
					{
						// 짝수 열
						if (j % 2 == 0)
						{
							if (board[i][j] != oddRowEvenColumn)
							{
								checkCount++;
							}
						}
						// 홀수 열
						else
						{
							if (board[i][j] != oddRowOddColumn)
							{
								checkCount++;
							}
						}
					}
				}
			}

			// 최소 카운트 체크
			if (checkCount < checkCountMin)
				checkCountMin = checkCount;

			checkCount = 0;
		}
		
		mStart++;

		if (m - mStart < 8)
		{
			mStart = 0;
			nStart++;

			// 체스판의 최소 크기가 안될 경우
			if (n - nStart < 8)
			{
				break;
			}
		}
	}
	
	cout << checkCountMin;

	for (int i = 0; i < n; i++)
	{
		delete[] board[i];
	}
	delete board;

	return 0;
}