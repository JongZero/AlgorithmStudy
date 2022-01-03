#include <iostream>
#include <string>
using namespace std;

int main()
{
	char alphabets_uppercase[26];		// 대문자 알파벳들
	int alphabets_count[26] = { 0, };	// 알파벳이 몇 번 쓰였는지

	// 소문자, 대문자 알파벳 배열 초기화
	char a = 'a';
	char A = 'A';
	for (int i = 0; i < 26; i++)
	{
		alphabets_uppercase[i] = A + i;
	}
	
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		// 소문자일 경우
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int order = s[i] - 'a';

			// 소문자 카운트를 증가시킨다.
			alphabets_count[order]++;
		}
		// 대문자일 경우
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int order = s[i] - 'A';

			// 카운트를 증가시킨다.
			alphabets_count[order]++;
		}
	}

	// 가장 많이 쓰인 알파벳을 조사한다.
	int max = 0;
	int maxOrder = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabets_count[i] > max)
		{
			max = alphabets_count[i];
			maxOrder = i;
		}
	}

	// 가장 많이 사용된 알파벳이 여러 개인지 조사한다.
	bool isOnly = true;
	for (int i = 0; i < 26; i++)
	{
		if (i == maxOrder)
			continue;

		if (alphabets_count[i] == max)
			isOnly = false;
	}

	if (isOnly == false)
		cout << "?";
	else
		cout << alphabets_uppercase[maxOrder];

	return 0;
}