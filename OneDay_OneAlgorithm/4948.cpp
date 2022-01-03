#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int Min = 1;
	const int Max = 123456;

	int numbers[Max * 2 + 1] = { 0, };

	while (true)
	{
		int n = 0;
		cin >> n;

		// 0�� �ԷµǸ� ����
		if (n == 0)
		{
			break;
		}

		// �Ҽ��� ����
		int count = 0;

		// �����佺�׳׽��� ü Ȱ��
		// ���ڸ� �迭�� �־���´�.
		for (int i = 1; i <= 2 * n; i++)
		{
			numbers[i] = i;
		}

		for (int i = 2; i * i <= 2 * n; i++)
		{
			// �̹� �����佺�׳׽��� ü�� �ɷ��� ����� �˻������ʰ� �Ѿ��.
			if (numbers[i] == 1)
			{
				continue;
			}

			for (int j = i * i; j <= 2 * n; j += i)
			{
				numbers[j] = 1;
			}
		}

		// n����ũ�� 2n���� �۰ų� ���� �Ҽ��� ������ ���Ѵ�.
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (numbers[i] > 1)
			{
				count++;
			}
		}

		// ī��Ʈ ���
		std::cout << count << "\n";
	}

	return 0;
}