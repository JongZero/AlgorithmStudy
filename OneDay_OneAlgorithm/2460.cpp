#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// ���� 10��
	const int Total = 10;

	// �ִ�
	int Max = 0;

	// ���� ��� ��
	int count = 0;
	for (int i = 0; i < Total; i++)
	{
		// ź���
		int in = 0;
		// �������
		int out = 0;

		// �Է�
		std::cin >> out >> in;

		// ������
		count -= out;
		// Ÿ��
		count += in;

		// �ִ밪�� ��
		if (count > Max)
		{
			Max = count;
		}
	}

	std::cout << Max;

	return 0;
}
