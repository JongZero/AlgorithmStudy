#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	// ���ĺ� �ƽ�Ű�ڵ� ���̺� (���ĺ��� �� 26��)
	int alphabets[26] = { 0, };

	for (int i = 0; i < 26; i++)
	{
		alphabets[i] = -1;
	}

	// ���ڿ��� ���鼭 üũ
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