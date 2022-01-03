#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<char> chess_Even;	// ¦�� ��
	vector<char> chess_Odd;	// Ȧ�� ��

	bool isEven = false;
	for (int i = 0; i < 8; i++)
	{
		string hangStr;
		cin >> hangStr;

		isEven ^= true;

		if (isEven)
		{
			for (int j = 0; j < hangStr.size(); j++)
			{
				chess_Even.push_back(hangStr[j]);
			}

		}
		else
		{
			for (int j = 0; j < hangStr.size(); j++)
			{
				chess_Odd.push_back(hangStr[j]);
			}
		}
	}

	int count = 0;	// �Ͼ� ĭ ���� ���� �� �� �ִ���

	// ¦�� �� (��,��,��,��...)
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			if (chess_Even[i] == 'F')
				count++;
		}
	}

	// Ȧ�� �� (��,��,��,��...)
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 1)
		{
			if (chess_Odd[i] == 'F')
				count++;
		}
	}

	cout << count;

	return 0;
}