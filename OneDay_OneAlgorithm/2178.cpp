#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

std::vector<std::string> inputVec;
std::vector<std::vector<int>> visitedVec;

std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> nodeMap;

int resultMin = 10000;

int n = 0;
int m = 0;

bool CheckWall(int i, int j)
{
	// 배열의 인덱스를 벗어난 경우
	if ((i > n - 1 || i < 0) || (j > m - 1 || j < 0))
	{
		return false;
	}
	// 이미 방문한 경우
	else if (visitedVec[i][j] > 0)
	{
		return false;
	}
	// 벽 인지
	else
	{
		std::string str = inputVec[i];
		char c = str[j];
		return (c == '1');
	}
}

void Func(int i, int j, int count)
{
	// 뻘 짓일경우 그만 돈다.
	if (count >= resultMin)
	{
		return;
	}

	// 도착했을 경우
	if (i == n - 1 && j == m - 1)
	{
		// 최소인지 체크
		if (resultMin > count)
			resultMin = count;
	}
	else
	{
		// 연결된 곳이 있을 경우
		if (nodeMap.count(std::pair<int, int>(i, j)) > 0)
		{
			const std::vector<std::pair<int, int>>& vec = nodeMap[std::pair<int, int>(i, j)];

			for (auto& it : vec)
			{
				if (visitedVec[it.first][it.second] == true)
					continue;

				visitedVec[it.first][it.second] = true;
				Func(it.first, it.second, count + 1);
				visitedVec[it.first][it.second] = false;
			}
		}
	}
}

typedef std::pair<int, int> indexPair;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m;

	inputVec.resize(n);
	visitedVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		visitedVec[i].resize(m);
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::pair<int, int> nowIndex = std::pair<int, int>(i, j);

			// 상, 하, 좌, 우로 연결
			if (CheckWall(i - 1, j))
			{
				nodeMap[nowIndex].emplace_back(std::pair<int, int>(i - 1, j));
			}
			if (CheckWall(i + 1, j))
			{
				nodeMap[nowIndex].emplace_back(std::pair<int, int>(i + 1, j));
			}
			if (CheckWall(i, j - 1))
			{
				nodeMap[nowIndex].emplace_back(std::pair<int, int>(i, j - 1));
			}
			if (CheckWall(i, j + 1))
			{
				nodeMap[nowIndex].emplace_back(std::pair<int, int>(i, j + 1));
			}
		}
	}
	*/

	//Func(0, 0, 1);

	// 최단거리는 BFS로
	std::queue<indexPair> q;
	q.push(indexPair(0, 0));

	// 방문 표시
	visitedVec[0][0] = 1;

	indexPair now(0, 0);

	int count = 0;
	while (!q.empty())
	{
		indexPair front = q.front();
		q.pop();

		count++;

		int i = front.first;
		int j = front.second;

		if (i == n - 1 && j == m - 1)
		{
			if (count < resultMin)
				resultMin = count;
		}

		// 상, 하, 좌, 우로 연결
		if (CheckWall(i + 1, j))
		{
			visitedVec[i + 1][j] = visitedVec[i][j] + 1;
			q.push(indexPair(i + 1, j));
		}
		if (CheckWall(i, j + 1))
		{
			visitedVec[i][j + 1] = visitedVec[i][j] + 1;
			q.push(indexPair(i, j + 1));
		}
		if (CheckWall(i, j - 1))
		{
			visitedVec[i][j - 1] = visitedVec[i][j] + 1;
			q.push(indexPair(i, j - 1));
		}
		if (CheckWall(i - 1, j))
		{
			visitedVec[i - 1][j] = visitedVec[i][j] + 1;
			q.push(indexPair(i - 1, j));
		}
	}

	// 마지막도 하나로 치기 때문에 +1
	std::cout << visitedVec[n - 1][m - 1];

	return 0;
}
