#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char s[1000000];
	cin.getline(s, 1000001);

	// 단어 카운트
	int count = 0;
	
	// 첫 번째 단어가 나왔는지
	bool isFirst = false;

	// 단어를 읽는 중인지
	bool isWord = false;

	for (int i = 0; i < strlen(s); i++)
	{
		// 첫 번째 단어의 첫번째 글자 이후
		if (isFirst)
		{
			// 공백일 경우 단어의 끝
			if (s[i] == ' ')
			{
				isWord = false;
			}
			// 공백이 아닌 경우 단어의 시작 or 단어 중간
			else
			{
				// 공백 다음이므로 단어의 시작
				if (isWord == false)
				{
					isWord = true;
					count++;
				}
			}
		}
		// 첫 번째 단어의 첫번째 글자가 아직 안나옴
		else
		{
			// 공백이 아닌 알파벳일 경우
			// 첫번째 단어 시작
			if (s[i] != ' ')
			{
				isFirst = true;
				isWord = true;
				count++;
			}
		}
	}

	// 출력
	cout << count;

	return 0;
}