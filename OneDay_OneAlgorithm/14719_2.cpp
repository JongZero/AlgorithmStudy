#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int h = 0;
	int w = 0;
	std::cin >> h >> w;

	std::vector<int> heightVec(w);	// height들이 들어있는 벡터

	for (int i = 0; i < w; i++)
	{
		std::cin >> heightVec[i];
	}

	int result = 0;
	
	
	for (int i = 1; i < w - 1; i++)
	{
		// 자신의 왼쪽 중 가장 높은 벽 체크
		int leftMax = 0;
		for (int j = i; j >= 0; j--)
		{
			if (leftMax < heightVec[j])
			{
				leftMax = heightVec[j];
			}
		}

		// 자신의 오른쪽 중 가장 높은 벽 체크
		int rightMax = 0;
		for (int j = i; j < w; j++)
		{
			if (rightMax < heightVec[j])
			{
				rightMax = heightVec[j];
			}
		}

		// 더 작은 벽으로 빼야함
		int sub = leftMax;
		if (leftMax > rightMax)
		{
			sub = rightMax;
		}

		result += sub - heightVec[i];
	}

	std::cout << result;

	return 0;
}