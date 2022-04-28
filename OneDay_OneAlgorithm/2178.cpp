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
	// �迭�� �ε����� ��� ���
	if ((i > n - 1 || i < 0) || (j > m - 1 || j < 0))
	{
		return false;
	}
	// �̹� �湮�� ���
	else if (visitedVec[i][j] > 0)
	{
		return false;
	}
	// �� ����
	else
	{
		std::string str = inputVec[i];
		char c = str[j];
		return (c == '1');
	}
}

void Func(int i, int j, int count)
{
	// �� ���ϰ�� �׸� ����.
	if (count >= resultMin)
	{
		return;
	}

	// �������� ���
	if (i == n - 1 && j == m - 1)
	{
		// �ּ����� üũ
		if (resultMin > count)
			resultMin = count;
	}
	else
	{
		// ����� ���� ���� ���
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

			// ��, ��, ��, ��� ����
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

	// �ִܰŸ��� BFS��
	std::queue<indexPair> q;
	q.push(indexPair(0, 0));

	// �湮 ǥ��
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

		// ��, ��, ��, ��� ����
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

	// �������� �ϳ��� ġ�� ������ +1
	std::cout << visitedVec[n - 1][m - 1];

	return 0;
}
