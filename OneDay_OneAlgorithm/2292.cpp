#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	const int max = 1000000000;

	/// Mark 1 �޸� �ʰ�
	/*
	int* numbers = new int[n];

	// 1 ���� �ʱ�ȭ
	numbers[0] = 1;

	// 2 ���� ��Ģ�� ����
	// 6 -> 12 -> 18

	// 1������� i���� �� ���� ���� ��������
	int howMany = 2;

	// ���� ����
	int range = 6;

	// ���� ���� ī��Ʈ
	int nowCount = 0;

	for (int i = 1; i < n; i++)
	{
		if (nowCount >= range)
		{
			// ī��Ʈ �ʱ�ȭ
			nowCount = 0;

			// ���� ���� ���� (6��)
			range += 6;

			// �� �Ѱ��� �� ��������
			howMany++;

		}

		numbers[i] = howMany;

		nowCount++;
	}

	cout << numbers[n - 1];

	delete[] numbers;
	numbers = nullptr;
	*/

	/// Mark2
	// max���� ���鼭 �ڽ��� ��� ���ߴ��� ã��
	// (�迭�� �̸� �־���� ���� �ƴ϶�)
	if (n == 1)
	{
		cout << 1;
	}
	else
	{
		// ���� ����
		int startNum = 2;
		// ���� ����
		int range = 6;
		// �� ĭ �����ϴ���
		int howMany = 2;
		
		while (true)
		{
			if (startNum <= n && n < startNum + range)
			{
				n = howMany;
				break;
			}
			else
			{
				// �� ������ �������� ���� ����
				startNum = startNum + range;

				// ������ 6�� ����
				range += 6;

				// �� ĭ ���ߵǴ����� 1�� ����
				howMany++;
			}
		}

		cout << n;
	}

	return 0;
}