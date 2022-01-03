#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	// 알파벳 아스키코드 테이블 (알파벳은 총 26개)
	int alphabets[26] = { 0, };

	for (int i = 0; i < 26; i++)
	{
		alphabets[i] = -1;
	}

	// 문자열을 돌면서 체크
	for (int i = 0; i < s.size(); i++)
	{
		int now = (int)s[i] - 97;

		if (alphabets[now] == -1)
		{
			alphabets[now] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabets[i] << " ";
	}

	return 0;
}