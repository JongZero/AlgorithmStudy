#include <iostream>
#include <string>
using namespace std;

int main()
{
	char alphabets_uppercase[26];		// �빮�� ���ĺ���
	int alphabets_count[26] = { 0, };	// ���ĺ��� �� �� ��������

	// �ҹ���, �빮�� ���ĺ� �迭 �ʱ�ȭ
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
		// �ҹ����� ���
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int order = s[i] - 'a';

			// �ҹ��� ī��Ʈ�� ������Ų��.
			alphabets_count[order]++;
		}
		// �빮���� ���
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int order = s[i] - 'A';

			// ī��Ʈ�� ������Ų��.
			alphabets_count[order]++;
		}
	}

	// ���� ���� ���� ���ĺ��� �����Ѵ�.
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

	// ���� ���� ���� ���ĺ��� ���� ������ �����Ѵ�.
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