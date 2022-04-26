#include <iostream>
#include <string>
#include <vector>
#include <map>

int n = 0;
int m = 0;

std::vector<std::string> inputVec;
std::vector<std::vector<bool>> visitedVec;

typedef std::pair<int, int> arrayIndex;
std::map<arrayIndex, std::vector<arrayIndex>> map;

int whiteSum = 0;
int blueSum = 0;

int whiteResult = 0;
int blueResult = 0;

void Func(int i, int j)
{
	visitedVec[i][j] = true;

	// �Ʊ�, ���� üũ
	if (inputVec[i][j] == 'W')
	{
		whiteSum++;
	}
	else
	{
		blueSum++;
	}

	// ����� ��尡 ������ ���
	if (map.count(arrayIndex(i, j)) > 0)
	{
		for (int k = 0; k < map[arrayIndex(i, j)].size(); k++)
		{
			arrayIndex temp = map[arrayIndex(i, j)][k];

			// ���� �湮���� �ʾ��� ���
			if (visitedVec[temp.first][temp.second] == false)
			{
				// �湮�Ѵ�.
				Func(temp.first, temp.second);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m;

	inputVec.resize(m);
	visitedVec.resize(m);

	for (int i = 0; i < m; i++)
	{
		std::string input;
		std::cin >> input;

		inputVec[i] = input;

		visitedVec[i].resize(n);
	}

	for (int i = 0; i < m; i++)
	{
		// ��� �Է¹��� i���� �����
		// ����Ǿ��ִ� ������ �־���
		for (int j = 0; j < n; j++)
		{
			// ��, ��, ��, ��� üũ�ؼ� �־��ش�
			int up = i - 1;
			int down = i + 1;
			int left = j - 1;
			int right = j + 1;

			// �ε����� ����� �ȵ�
			// �Ʊ��̿����� (W - W, B - B)
			// ������ ���������
			if (up >= 0 && inputVec[up][j] == inputVec[i][j])
			{
				map[arrayIndex(i, j)].emplace_back(arrayIndex(up, j));
			}
			if (down < m && inputVec[down][j] == inputVec[i][j])
			{
				map[arrayIndex(i, j)].emplace_back(arrayIndex(down, j));
			}
			if (left >= 0 && inputVec[i][left] == inputVec[i][j])
			{
				map[arrayIndex(i, j)].emplace_back(arrayIndex(i, left));
			}
			if (right < n && inputVec[i][right] == inputVec[i][j])
			{
				map[arrayIndex(i, j)].emplace_back(arrayIndex(i, right));
			}
		}
	}

	while (true)
	{
		int startI = 0;
		int startJ = 0;
		bool isNotVisited = false;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// ���� �湮���� ���� ���� �ִٸ�, �湮�ؾ���
				if (visitedVec[i][j] == false)
				{
					startI = i;
					startJ = j;
					isNotVisited = true;
					break;
				}
			}

			if (isNotVisited)
				break;
		}

		// ��� �湮�ߴٸ� ��!
		if (!isNotVisited)
			break;

		Func(startI, startJ);

		// ������ ������ �� �� �ִٰ���
		whiteResult += whiteSum * whiteSum;
		blueResult += blueSum * blueSum;

		whiteSum = 0;
		blueSum = 0;
	}
	
	std::cout << whiteResult << ' ' << blueResult;

	return 0;
}
