#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char s[1000000];
	cin.getline(s, 1000001);

	// �ܾ� ī��Ʈ
	int count = 0;
	
	// ù ��° �ܾ ���Դ���
	bool isFirst = false;

	// �ܾ �д� ������
	bool isWord = false;

	for (int i = 0; i < strlen(s); i++)
	{
		// ù ��° �ܾ��� ù��° ���� ����
		if (isFirst)
		{
			// ������ ��� �ܾ��� ��
			if (s[i] == ' ')
			{
				isWord = false;
			}
			// ������ �ƴ� ��� �ܾ��� ���� or �ܾ� �߰�
			else
			{
				// ���� �����̹Ƿ� �ܾ��� ����
				if (isWord == false)
				{
					isWord = true;
					count++;
				}
			}
		}
		// ù ��° �ܾ��� ù��° ���ڰ� ���� �ȳ���
		else
		{
			// ������ �ƴ� ���ĺ��� ���
			// ù��° �ܾ� ����
			if (s[i] != ' ')
			{
				isFirst = true;
				isWord = true;
				count++;
			}
		}
	}

	// ���
	cout << count;

	return 0;
}