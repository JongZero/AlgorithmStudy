#include <iostream>
using namespace std;

int main()
{
	// �� ���ڷ� �̷���� ũ�ξ�Ƽ�� ���ĺ�
	string croatiaAlphabets[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	
	// �� ���ڷ� �̷���� ũ�ξ�Ƽ�� ���ĺ�
	string croatiaAlphabetsD = "dz=";

	string s;
	cin >> s;

	// �Է¹��� ���ڿ��� ����
	int size = s.size();

	// ���ڿ��� 3���� �̻��� ��
	if (size >= 3)
	{
		// �� ���� ũ�ξ�Ƽ�� ���ĺ��� �ִ��� �����Ѵ�. (0 ~ size - 2)
		for (int i = 0; i < size - 2; i++)
		{
			string now = "";
			now += s[i];
			now += s[i + 1];
			now += s[i + 2];

			// ���� ���� ���� �� ���ڰ� ũ�ξ�Ƽ�� ���ĺ� �� ���ڶ��
			if (now == croatiaAlphabetsD)
			{
				// ������ ���� �빮�� D�� ġȯ�Ѵ�.
				s[i] = 'D';
				s[i + 1] = 'D';
				s[i + 2] = 'D';
			}
		}
	}

	// ���ڿ��� 2���� �̻��� ��
	if (size >= 2)
	{
		// �� ���� ũ�ξ�Ƽ�� ���ĺ��� �ִ��� �����Ѵ�.
		for (int i = 0; i < 7; i++)
		{
			// �Է¹��� ��Ʈ�� �� ���ھ� ����(�� �պ��� �� �ڿ��� �ϳ� �ձ���) (0 ~ size - 1)
			for (int k = 0; k < size - 1; k++)
			{
				// ���� �� �� ����
				string now = "";
				now += s[k];
				now += s[k + 1];

				// ���� ���� ���� �� ���ڰ� ũ�ξ�Ƽ�� ���ĺ� �� ���ڶ��
				if (now == croatiaAlphabets[i])
				{
					// ������ ���� �빮�� C(roatia)�� ġȯ�Ѵ�.
					// ���Ŀ� �빮�� C�� ������ ���ϰ� 2�� ���� ���̴�.
					s[k] = 'C';
					s[k + 1] = 'C';
				}
			}
		}
	}
	
	// ���� ���ϱ�
	int c = 0;	// �� ���� ũ�ξ�Ƽ�� ���ĺ� ��
	int d = 0;	// �� ���� ũ�ξ�Ƽ�� ���ĺ� ��
	int a = 0;	// �׳� ���ĺ� ��
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