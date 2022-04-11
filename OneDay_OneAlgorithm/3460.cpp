#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		std::cin >> n;

		int index = 0;
		while (true)
		{
			// 2�� ���� �������� ����
			int remainder = n % 2;

			// 1�� ��ġ ���
			if (remainder == 1)
			{
				std::cout << index << ' ';
			}

			// index ����, 2�� ������
			index++;
			n /= 2;

			// �� �̻� ���� �� ������ ��
			if (n < 1)
			{
				break;
			}
		}
	}

	return 0;
}