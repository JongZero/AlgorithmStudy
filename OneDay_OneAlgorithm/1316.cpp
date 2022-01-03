#include <iostream>
#include <string>
using namespace std;

/// 1316

int main()
{
	// 입력받을 단어의 개수
	int n;
	cin >> n;

	// 그룹 단어의 개수
	int count = n;

	for (int i = 0; i < n; i++)
	{
		// 소문자 알파벳 테이블 초기화
		string alphabets = "";
		for (int i = 'a'; i <= 'z'; i++)
		{
			alphabets += i;
		}

		string s;
		cin >> s;
		
		// 그룹 단어인가? 일단 그룹 단어라고 가정하고 조사한다.
		// (그룹 단어가 아님을 밝힐 것이다.)
		bool isGroup = true;

		// 이전 글자
		char prev = ' ';

		// 입력 받은 단어가 그룹 단어인지 조사한다.
		for (int j = 0; j < s.size(); j++)
		{
			// 1번째 부터는 이전에 저장된 글자와 현재 글자를 비교해 연속성을 조사한다.
			if (j > 0)
			{
				// 현재 글자가 이전에 쓰였던 글자라면
				if (alphabets[s[j] - 'a'] == 'X')
				{
					// 이전 글자와 현재 글자가 같은지 조사, 같다면 연속적이므로 문제 없음
					// 다르다면 그룹 단어가 아니다.
					if (prev != s[j])
					{
						isGroup = false;
						break;
					}
				}
			}

			// 현재 글자를 저장해놓고
			prev = s[j];

			// 단어에서 이미 쓰였으므로 X로 표시 한다.
			alphabets[s[j] - 'a'] = 'X';
		}

		// 그룹 단어가 아니라면 카운트 감소 및 bool변수 초기화
		if (isGroup == false)
		{
			count--;
			isGroup = true;
		}
	}

	cout << count;

	return 0;
}