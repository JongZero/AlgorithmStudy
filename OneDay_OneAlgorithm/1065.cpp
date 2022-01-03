#include <iostream>
#include <string>
using namespace std;

/// 1065
// ����
// � ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�.
// ���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�.N�� �־����� ��, 
// 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� 1, 000���� �۰ų� ���� �ڿ��� N�� �־�����.
// 
// ���
// ù° �ٿ� 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����Ѵ�.

int main()
{
	int n = 0;

	cin >> n;

	int* numbers = new int[n];

	// �Ѽ��� ����
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		numbers[i] = i + 1;

		string str = to_string(numbers[i]);

		// �� �ڸ��� ����
		if (str.size() <= 2)
			count++;
		// �� �ڸ��� �̻�
		else
		{
			// �� �ڸ� ������ ����
			int prevSub = 0;
			int sub = 0;

			// ������������ �ƴ���
			bool isEqual = false;

			// �� �ڸ��� ����
			for (int j = 1; j < str.size(); j++)
			{
				int now = str[j] - '0';
				int prev = str[j - 1] - '0';
				
				sub = now - prev;

				if (j == 1)
				{
					prevSub = sub;
					continue;
				}
				// ���� ���̿� ��
				else
				{
					if (prevSub == sub)
					{
						isEqual = true;
						prevSub = sub;
					}
					// �ϳ��� ������ �ٸ��� ���������� �ƴϴ�.
					else
					{
						isEqual = false;
						break;
					}
				}
			}

			// ���������̶�� ī��Ʈ ����
			if (isEqual)
				count++;
		}
	}

	cout << count;

	delete[] numbers;
	numbers = nullptr;

	return 0;
}