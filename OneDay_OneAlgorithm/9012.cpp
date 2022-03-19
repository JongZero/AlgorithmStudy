#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		// ���� �ʱ�ȭ
		int stack[51] = { 0, };

		// Input �ޱ�
		std::string input;
		std::cin >> input;

		// ���ÿ� ���� �־���� �ε���
		int nowIndex = 0;

		// ������ ���� ������
		int stackSize = 0;

		for (int k = 0; k < input.size(); k++)
		{
			// '(' �� �� push�ϰ�, �ƴ� �� pop�ϸ� �����̶�� ������ ����� 0�� ����
			if (input[k] == '(')
			{
				stack[nowIndex] = 1;
				nowIndex++;
				stackSize++;
			}
			else
			{
				if (stackSize > 0)
				{
					stack[nowIndex - 1] = 0;
					nowIndex--;
				}

				stackSize--;

				// ������ ����� 0���� ���� ��� �� �������� �̹� �̻��ϴ�.
				if (stackSize < 0)
				{
					break;
				}
			}
		}

		// 0�̸� ����, 0�� �ƴϸ� ������
		if (stackSize == 0)
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}

	return 0;
}