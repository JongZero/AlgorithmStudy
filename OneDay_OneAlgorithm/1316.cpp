#include <iostream>
#include <string>
using namespace std;

/// 1316

int main()
{
	// �Է¹��� �ܾ��� ����
	int n;
	cin >> n;

	// �׷� �ܾ��� ����
	int count = n;

	for (int i = 0; i < n; i++)
	{
		// �ҹ��� ���ĺ� ���̺� �ʱ�ȭ
		string alphabets = "";
		for (int i = 'a'; i <= 'z'; i++)
		{
			alphabets += i;
		}

		string s;
		cin >> s;
		
		// �׷� �ܾ��ΰ�? �ϴ� �׷� �ܾ��� �����ϰ� �����Ѵ�.
		// (�׷� �ܾ �ƴ��� ���� ���̴�.)
		bool isGroup = true;

		// ���� ����
		char prev = ' ';

		// �Է� ���� �ܾ �׷� �ܾ����� �����Ѵ�.
		for (int j = 0; j < s.size(); j++)
		{
			// 1��° ���ʹ� ������ ����� ���ڿ� ���� ���ڸ� ���� ���Ӽ��� �����Ѵ�.
			if (j > 0)
			{
				// ���� ���ڰ� ������ ������ ���ڶ��
				if (alphabets[s[j] - 'a'] == 'X')
				{
					// ���� ���ڿ� ���� ���ڰ� ������ ����, ���ٸ� �������̹Ƿ� ���� ����
					// �ٸ��ٸ� �׷� �ܾ �ƴϴ�.
					if (prev != s[j])
					{
						isGroup = false;
						break;
					}
				}
			}

			// ���� ���ڸ� �����س���
			prev = s[j];

			// �ܾ�� �̹� �������Ƿ� X�� ǥ�� �Ѵ�.
			alphabets[s[j] - 'a'] = 'X';
		}

		// �׷� �ܾ �ƴ϶�� ī��Ʈ ���� �� bool���� �ʱ�ȭ
		if (isGroup == false)
		{
			count--;
			isGroup = true;
		}
	}

	cout << count;

	return 0;
}