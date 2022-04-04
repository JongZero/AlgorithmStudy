#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		// ������ ����
		int n = 0;
		// �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue���� �� ��°�� ���� �ִ���
		int m = 0;
		std::cin >> n >> m;

		// ���� ť, ���� ���� ���� �ڴ� �߿䵵
		std::queue<std::pair<int, int>> q;

		// n�� ������ �߿䵵 ���ʴ�� �־�����.
		for (int j = 0; j < n; j++)
		{
			// �߿䵵
			int inputPoint = 0;
			std::cin >> inputPoint;
			
			// ���� ������ �߿䵵�� ť�� �ִ´�.
			q.push(std::pair<int, int>(j, inputPoint));
		}

		// ��� ����
		int index = 0;
		while (true)
		{
			// ���� �����ŭ ��ȸ�ϸ鼭, �߿䵵�� �ڽź��� �� ū���� �ϳ��� �ִ��� üũ�Ѵ�.
			bool isExist = false;
			int checkNum = q.front().second;
			int qSize = q.size();
			for (int j = 0; j < qSize; j++)
			{
				std::pair<int, int> front = q.front();

				if (checkNum < front.second)
				{
					isExist = true;
				}

				// ���� �� �ڿ� �ִ´�.
				// (�ٸ� �͵鵵 üũ�ؾ� �Ǳ� ����)
				q.pop();
				q.push(front);
			}

			// �߿䵵�� �ڽź��� �� ū���� �ϳ��� �ִٸ�
			std::pair<int, int> front = q.front();
			if (isExist)
			{
				// ���� ������ ���� �ڿ� ���ġ�Ѵ�.
				q.push(front);
				q.pop();
			}
			// ���ٸ�
			else
			{
				// ��� ���� ����
				index++;

				// �μ��Ѵ�.
				q.pop();

				// ���� ã���� �ϴ� �������
				// ���� ��� ������ ����Ѵ�.
				if (m == front.first)
				{
					std::cout << index << '\n';
					break;
				}
			}
		}
	}

	return 0;
}