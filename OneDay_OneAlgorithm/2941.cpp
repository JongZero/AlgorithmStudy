#include <iostream>
using namespace std;

int main()
{
	// 두 글자로 이루어진 크로아티아 알파벳
	string croatiaAlphabets[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	
	// 세 글자로 이루어진 크로아티아 알파벳
	string croatiaAlphabetsD = "dz=";

	string s;
	cin >> s;

	// 입력받은 문자열의 길이
	int size = s.size();

	// 문자열이 3글자 이상일 때
	if (size >= 3)
	{
		// 세 글자 크로아티아 알파벳이 있는지 조사한다. (0 ~ size - 2)
		for (int i = 0; i < size - 2; i++)
		{
			string now = "";
			now += s[i];
			now += s[i + 1];
			now += s[i + 2];

			// 현재 조사 중인 세 글자가 크로아티아 알파벳 세 글자라면
			if (now == croatiaAlphabetsD)
			{
				// 구분을 위해 대문자 D로 치환한다.
				s[i] = 'D';
				s[i + 1] = 'D';
				s[i + 2] = 'D';
			}
		}
	}

	// 문자열이 2글자 이상일 때
	if (size >= 2)
	{
		// 두 글자 크로아티아 알파벳이 있는지 조사한다.
		for (int i = 0; i < 7; i++)
		{
			// 입력받은 스트링 두 글자씩 조사(맨 앞부터 맨 뒤에서 하나 앞까지) (0 ~ size - 1)
			for (int k = 0; k < size - 1; k++)
			{
				// 조사 할 두 글자
				string now = "";
				now += s[k];
				now += s[k + 1];

				// 현재 조사 중인 두 글자가 크로아티아 알파벳 두 글자라면
				if (now == croatiaAlphabets[i])
				{
					// 구분을 위해 대문자 C(roatia)로 치환한다.
					// 추후에 대문자 C의 개수를 구하고 2로 나눌 것이다.
					s[k] = 'C';
					s[k + 1] = 'C';
				}
			}
		}
	}
	
	// 개수 구하기
	int c = 0;	// 두 글자 크로아티아 알파벳 수
	int d = 0;	// 세 글자 크로아티아 알파벳 수
	int a = 0;	// 그냥 알파벳 수
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'C')
		{
			c++;
		}
		else if (s[i] == 'D')
		{
			d++;
		}
		else
		{
			a++;
		}
	}

	int count = a + (c / 2) + (d / 3);

	cout << count;
	return 0;
}