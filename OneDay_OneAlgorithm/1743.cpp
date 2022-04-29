#include <iostream>
#include <vector>
#include <map>

int n = 0;
int m = 0;

typedef std::pair<int, int> PairIndex;
std::vector<std::vector<int>> input;
std::vector<std::vector<bool>> visited;
std::map<PairIndex, std::vector<PairIndex>> nodeMap;

int tempResult = 0;
int resultMax = 0;

bool Connect(int i, int j, int myI, int myJ)
{
	// �迭�� �ε����� ��� ���
	if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
	{
		return false;
	}
	// �����Ⱑ �ƴ� ���
	else if (input[i][j] == 0)
	{
		return false;
	}
	else
	{
		nodeMap[PairIndex(i, j)].emplace_back(myI, myJ);
		return true;
	}
}

void Func(int i, int j)
{
	tempResult++;
	visited[i][j] = true;

	if (nodeMap.count(PairIndex(i, j)) > 0)
	{
		for (int k = 0; k < nodeMap[PairIndex(i, j)].size(); k++)
		{
			PairIndex now = nodeMap[PairIndex(i, j)][k];

			if (visited[now.first][now.second] == true)
				continue;

			Func(now.first, now.second);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k = 0;

	std::cin >> n >> m >> k;

	input.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		input[i].resize(m);
		visited[i].resize(m);
	}

	for (int i = 0; i < k; i++)
	{
		int indexI;
		int indexJ;

		std::cin >> indexI >> indexJ;

		indexI--;
		indexJ--;

		// �������� ��ġ
		input[indexI][indexJ] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// �����⸸ ����
			if (input[i][j] == 0)
				continue;

			int indexI = i;
			int indexJ = j;

			// �������� �ֺ� ģ���鿡�� ���� ���� ������
			Connect(indexI - 1, indexJ, indexI, indexJ);
			Connect(indexI + 1, indexJ, indexI, indexJ);
			Connect(indexI, indexJ - 1, indexI, indexJ);
			Connect(indexI, indexJ + 1, indexI, indexJ);
		}
	}
	
	int checkI = 0;
	int checkJ = 0;
	while (true)
	{
		// �湮�� �� ������ üũ
		bool isVisited = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// ������ �߿� �湮�� ���� �ִ���
				if (input[i][j] == 1 && visited[i][j] == false)
				{
					checkI = i;
					checkJ = j;
					isVisited = true;
					break;
				}
			}

			if (isVisited)
				break;
		}

		// �湮�� �� ���̻� ������ ��
		if (!isVisited)
		{
			break;
		}

		Func(checkI, checkJ);

		if (resultMax < tempResult)
			resultMax = tempResult;

		tempResult = 0;
	}

	std::cout << resultMax;

	return 0;
}
