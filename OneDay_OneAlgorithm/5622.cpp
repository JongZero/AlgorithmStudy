#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ���̾� ���̺�
	string numbers[8] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

	// ���ڿ� �Է�
	string s;
	cin >> s;

	// �Է¹��� ���ڿ��� ���鼭
	// ���̾󿡼� �´� ���ڸ� ã�Ƴ���.
	// 2���� �����ϹǷ� numbers[0]�� 2�̴�.
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

			// ȿ���� ���� ã�Ҵٸ� break�� for���� Ż���Ų��.
			if (isEnd == true)
			{
				break;
			}
		}
	}
	
	cout << count;

	return 0;
}