#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int h(0), w(0);
	std::cin >> h >> w;

	/*
	std::vector<std::vector<int>> map(w);

	for (int i = 0; i < w; i++)
	{
		map[i].resize(h);

		int wall = 0;
		std::cin >> wall;

		// 3�� input�̶�� 0 ~ 3���� wall �̴�.
		for (int j = 0; j < wall; j++)
		{
			map[i][j] = 1;
		}
	}
	*/

	std::vector<int> map(w);

	for (int i = 0; i < w; i++)
	{
		std::cin >> map[i];
	}

	// w���� ��ȸ�ϸ鼭, ���� üũ�Ѵ�.
	for (int i = 0; i < w; i++)
	{
		
	}

	return 0;
}