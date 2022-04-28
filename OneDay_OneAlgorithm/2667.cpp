#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int n = 0;

std::vector<std::string> inputVec;
std::vector<std::vector<bool>> visitedVec;
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> map;	// 배열의 인덱스 ,연결된 노드

std::vector<int> sumResultVec;
int sum = 0;

void Func(int i, int j)
{
	// 방문 표시
	if (visitedVec[i][j] == false)
	{
		visitedVec[i][j] = true;
		sum++;
	}

	// 연결된 곳이 있을경우
	if (map.count(std::pair<int, int>(i, j)) > 0)
	{
		// 연결된 곳을 방문
		for (int k = 0; k < map[std::pair<int, int>(i, j)].size(); k++)
		{
			const std::vector<std::pair<int, int>>& vec = map[std::pair<int, int>(i, j)];
			const std::pair<int, int> now = vec[k];

			// 집이 있고, 방문하지 않았을 경우에만
			if (inputVec[now.first][now.second] == '1' && visitedVec[now.first][now.second] == false)
			{
				Func(vec[k].first, vec[k].second);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;

	inputVec.resize(n);
	visitedVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];
		visitedVec[i].resize(n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 노드를 연결해준다.
			int up = i - 1;
			int down = i + 1;
			int left = j - 1;
			int right = j + 1;

			if (up >= 0 && inputVec[up][j] == '1')
			{
				map[std::pair<int, int>(i, j)].emplace_back(std::pair<int, int>(up, j));
			}
			if (down < n && inputVec[down][j] == '1')
			{
				map[std::pair<int, int>(i, j)].emplace_back(std::pair<int, int>(down, j));
			}
			if (left >= 0 && inputVec[i][left] == '1')
			{
				map[std::pair<int, int>(i, j)].emplace_back(std::pair<int, int>(i, left));
			}
			if (right < n && inputVec[i][right] == '1')
			{
				map[std::pair<int, int>(i, j)].emplace_back(std::pair<int, int>(i, right));
			}
		}
	}

	while (true)
	{
		int startI = 0;
		int startJ = 0;

		// 방문안한 곳이 있는가?
		bool isNotVisited = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (inputVec[i][j] == '1' && visitedVec[i][j] == false)
				{
					startI = i;
					startJ = j;
					isNotVisited = true;
					break;
				}
			}

			if (isNotVisited)
			{
				break;
			}
		}

		// 방문안한 곳이 없다면 탈출
		if (isNotVisited == false)
		{
			break;
		}
		
		Func(startI, startJ);

		sumResultVec.emplace_back(sum);
		sum = 0;
	}

	std::cout << sumResultVec.size() << '\n';

	// 오름차순으로 정렬
	sort(sumResultVec.begin(), sumResultVec.end());

	for (int i = 0; i < sumResultVec.size(); i++)
	{
		std::cout << sumResultVec[i] << '\n';
	}

	return 0;
}
