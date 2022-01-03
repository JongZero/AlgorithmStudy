#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 다이얼 테이블
	string numbers[8] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

	// 문자열 입력
	string s;
	cin >> s;

	// 입력받은 문자열을 돌면서
	// 다이얼에서 맞는 문자를 찾아낸다.
	// 2부터 시작하므로 numbers[0]은 2이다.
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			bool isEnd = false;

			for (int k = 0; k < numbers[j].size(); k++)
			{
				if (numbers[j][k] == s[i])
				{
					count += (j + 3);
					isEnd = true;
					break;
				}
			}

			// 효율을 위해 찾았다면 break로 for문은 탈출시킨다.
			if (isEnd == true)
			{
				break;
			}
		}
	}
	
	cout << count;

	return 0;
}