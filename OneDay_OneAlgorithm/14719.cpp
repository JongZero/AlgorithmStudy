#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int h(0), w(0);
	std::cin >> h >> w;

	std::vector<int> map(w);

	for (int i = 0; i < w; i++)
	{
		std::cin >> map[i];
	}

	/*
	int result = 0;
	int prev = 0;
	int leftMax = 0;
	int leftIndex = 0;
	// w���� ��ȸ�ϸ鼭, ���� üũ�Ѵ�.
	for (int i = 0; i < w;)
	{
		if (map[i] <= 0)
		{
			i++;
			continue;
		}

		// ������ ���� ���� ������
		int tempResultMax = 0;
		int j = i + 1;
		int prev = 0;
		int wallCount = 0;
		while (true)
		{
			// �� ���� ���� ���
			if (j >= w)
			{
				break;
			}

			// ���� ���� ���� ���� ������ ũ�� �ȵ�
			bool isEnd = false;
			if (map[i] <= map[j])
			{
				wallCount = map[i];
				isEnd = true;
			}
			else
			{
				wallCount = map[j];
			}

			// ���� ��Ϻ��� Ŭ ���, ������ ����
			if (prev < map[j])
			{
				// ���
				// ���� ���� ���̶� ġ��, �˻��ϰ� �ִ� ��� ~ �� ���� ���
				int tempResult = 0;
				for (int k = i + 1; k < j; k++)
				{
					int tempSub = wallCount - map[k];

					// �߰��� ������ ������ ���� ���� ���ִٸ�
					if (tempSub < 0)
					{
						isEnd = true;
						tempResult = 0;
						break;
					}

					tempResult += tempSub;
				}

				if (tempResultMax < tempResult)
					tempResultMax = tempResult;
			}

			if (isEnd)
				break;

			prev = map[j];
			j++;
		}

		result += tempResultMax;

		// ������ ����Ǿ��� ��� �� �������� �����ϸ��
		if (tempResultMax > 0)
		{
			//i = j;
			i++;
		}
		else
		{
			i++;
		}
	}
	*/

	int result = 0;
	// w���� ��ȸ�ϸ鼭, ���� üũ�Ѵ�.
	for (int i = 1; i < w - 1; i++)
	{
		// �ڽ��� ���� �߿� ���� ���� �� üũ
		int leftMax = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (map[j] > leftMax)
				leftMax = map[j];
		}

		// �ڽ��� ������ �߿� ���� ���� �� üũ
		int rightMax = 0;
		for (int j = i + 1; j < w; j++)
		{
			if (map[j] > rightMax)
				rightMax = map[j];
		}

		// �� ���� �� ���� �� üũ
		int wall = leftMax;
		if (leftMax > rightMax)
			wall = rightMax;

		// �ڽſ��� ä���� ���� ���� ����
		int sub = wall - map[i];
		if (sub > 0)
		{
			result += wall - map[i];
		}
	}

	std::cout << result;

	return 0;
}