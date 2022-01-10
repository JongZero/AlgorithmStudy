#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m = 0;
	cin >> n >> m;
	
	// true -> ���(W)
	// false -> ����(B)

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
		// ���� ���� �� ������ üũ
		bool startWB = board[nStart][mStart];
		
		for (int k = 0; k < 2; k++)
		{
			// ���� �� ������ �� �� �ٲ㼭 üũ�غ�
			if (k == 1)
				startWB = !startWB;

			bool evenRowEvenColumn = startWB;	// ¦�� ���� ¦�� ��
			bool evenRowOddColumn = !startWB;	// ¦�� ���� Ȧ�� ��

			bool oddRowEvenColumn = !startWB;	// Ȧ�� ���� ¦�� ��
			bool oddRowOddColumn = startWB;		// Ȧ�� ���� Ȧ�� ��

			// ���� 8 X ���� 8 ��ŭ�� üũ
			for (int i = nStart; i < nStart + 8; i++)
			{
				for (int j = mStart; j < mStart + 8; j++)
				{
					// ¦�� ��
					if (i % 2 == 0)
					{
						// ¦�� ��
						if (j % 2 == 0)
						{
							if (board[i][j] != evenRowEvenColumn)
							{
								checkCount++;
							}
						}
						// Ȧ�� ��
						else
						{
							if (board[i][j] != evenRowOddColumn)
							{
								checkCount++;
							}
						}
					}
					// Ȧ�� ��
					else
					{
						// ¦�� ��
						if (j % 2 == 0)
						{
							if (board[i][j] != oddRowEvenColumn)
							{
								checkCount++;
							}
						}
						// Ȧ�� ��
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

			// �ּ� ī��Ʈ üũ
			if (checkCount < checkCountMin)
				checkCountMin = checkCount;

			checkCount = 0;
		}
		
		mStart++;

		if (m - mStart < 8)
		{
			mStart = 0;
			nStart++;

			// ü������ �ּ� ũ�Ⱑ �ȵ� ���
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