#include <iostream>
#include <map>
#include <vector>

std::map<int, std::vector<int>> nodeMap;
std::vector<bool> isVisited;
std::vector<bool> checkVec;
int result = 0;

void Func(int i)
{
	isVisited[i] = true;
	result++;

	if (nodeMap.count(i) > 0)
	{
		// 연결된 곳이 있으면
		for (int k = 0; k < nodeMap[i].size(); k++)
		{
			if (isVisited[nodeMap[i][k]] == true)
				continue;

			Func(nodeMap[i][k]);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;
	
	isVisited.resize(n);
	checkVec.resize(n);

	for (int i = 0; i < k; i++)
	{
		int s = 0;
		int e = 0;
		std::cin >> s >> e;

		s--;
		e--;

		// 서로 연결 시켜줌
		nodeMap[s].emplace_back(e);
		nodeMap[e].emplace_back(s);
	}

	Func(0);

	// 1은 빼야함
	std::cout << result - 1;

	return 0;
}
