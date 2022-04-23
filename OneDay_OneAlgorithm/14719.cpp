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
	// w별로 순회하면서, 벽을 체크한다.
	for (int i = 0; i < w;)
	{
		if (map[i] <= 0)
		{
			i++;
			continue;
		}

		// 오른쪽 벽을 만날 때까지
		int tempResultMax = 0;
		int j = i + 1;
		int prev = 0;
		int wallCount = 0;
		while (true)
		{
			// 끝 벽을 넘을 경우
			if (j >= w)
			{
				break;
			}

			// 현재 조사 중인 왼쪽 벽보다 크면 안됨
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

			// 이전 블록보다 클 경우, 빗물이 고임
			if (prev < map[j])
			{
				// 계산
				// 현재 왼쪽 벽이라 치고, 검사하고 있는 블록 ~ 내 이전 블록
				int tempResult = 0;
				for (int k = i + 1; k < j; k++)
				{
					int tempSub = wallCount - map[k];

					// 중간에 오른쪽 벽보다 높은 벽이 껴있다면
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

		// 빗물이 조사되었을 경우 그 다음부터 조사하면됨
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
	// w별로 순회하면서, 벽을 체크한다.
	for (int i = 1; i < w - 1; i++)
	{
		// 자신의 왼쪽 중에 가장 높은 벽 체크
		int leftMax = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (map[j] > leftMax)
				leftMax = map[j];
		}

		// 자신의 오른쪽 중에 가장 높은 벽 체크
		int rightMax = 0;
		for (int j = i + 1; j < w; j++)
		{
			if (map[j] > rightMax)
				rightMax = map[j];
		}

		// 그 벽들 중 낮은 것 체크
		int wall = leftMax;
		if (leftMax > rightMax)
			wall = rightMax;

		// 자신에게 채워질 물의 양을 구함
		int sub = wall - map[i];
		if (sub > 0)
		{
			result += wall - map[i];
		}
	}

	std::cout << result;

	return 0;
}