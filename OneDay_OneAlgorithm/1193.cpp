#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;

	// x�� �� ��° �밢�� �迭�� �����ִ��� �˾Ƴ���
	int count = 1;

	// ���۹�°
	int startNum = 1;

	// ���� ��°���� ����
	int range = 0;

	while (true)
	{
		// ���۹�° ~ ���۹�° + �� �迭�� ���� �ȿ� ���Ѵٸ� Ż��
		if (startNum <= x && x <= startNum + range)
		{
			break;
		}
		else
		{
			range = count;
			startNum = startNum + range;

			count++;
		}
	}

	// �밢�� ���� �迭���� ���� �� ��°����
	int countInArray = x - startNum;

	// �ε���
	int i = 0;

	// �и�
	int mo = 0;

	// ����
	int ja = 0;

	// ù ��°�� ���
	if (count == 1)
	{
		mo = 1;
		ja = 1;
	}
	// ¦����°�� ���Ѵٸ�
	// ���� ���ں��� -> ū ���ڷ� (1 / count ~ count)
	else if (count % 2 == 0)
	{
		// �и�
		mo = count;

		// ����
		ja = 1;

		// 1��°���͸� ���ϸ�ȴ�.
		if (countInArray > 0)
		{
			// �밢�� ���� �迭���� ���� �ִ� �ε������� ���Ѵ�.
			for (int i = 0; i < countInArray; i++)
			{
				// ���ڴ� ���ϰ�
				ja++;

				// �и�� ����.
				mo--;
			}
		}
	}
	// Ȧ����°�� ���Ѵٸ�
	// ū ���ں��� -> ���� ���ڷ� (count ~ 1 / count)
	else
	{
		// �и�
		mo = 1;

		// ����
		ja = count;

		// 1��°���͸� ���ϸ�ȴ�.
		if (countInArray > 0)
		{
			for (int i = 0; i < countInArray; i++)
			{
				// ���ڴ� ����
				ja--;

				// �и�� ���Ѵ�.
				mo++;
			}
		}
	}

	// ���
	cout << ja << "/" << mo;

	return 0;
}