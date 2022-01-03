#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<char> chess_Even;	// Â¦¼ö Çà
	vector<char> chess_Odd;	// È¦¼ö Çà

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

	int count = 0;	// ÇÏ¾á Ä­ À§¿¡ ¸»ÀÌ ¸î °³ ÀÖ´ÂÁö

	// Â¦¼ö Çà (Èò,°Ë,Èò,°Ë...)
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			if (chess_Even[i] == 'F')
				count++;
		}
	}

	// È¦¼ö Çà (°Ë,Èò,°Ë,Èò...)
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