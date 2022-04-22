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

		// 3이 input이라면 0 ~ 3까지 wall 이다.
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

	// w별로 순회하면서, 벽을 체크한다.
	for (int i = 0; i < w; i++)
	{
		
	}

	return 0;
}