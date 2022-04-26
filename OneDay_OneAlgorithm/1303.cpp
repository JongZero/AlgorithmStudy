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

	// 아군, 적군 체크
	if (inputVec[i][j] == 'W')
	{
		whiteSum++;
	}
	else
	{
		blueSum++;
	}

	// 연결된 노드가 존재할 경우
	if (map.count(arrayIndex(i, j)) > 0)
	{
		for (int k = 0; k < map[arrayIndex(i, j)].size(); k++)
		{
			arrayIndex temp = map[arrayIndex(i, j)][k];

			// 아직 방문하지 않았을 경우
			if (visitedVec[temp.first][temp.second] == false)
			{
				// 방문한다.
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
		// 방금 입력받은 i행의 노드들과
		// 연결되어있는 노드들을 넣어줌
		for (int j = 0; j < n; j++)
		{
			// 상, 하, 좌, 우로 체크해서 넣어준다
			int up = i - 1;
			int down = i + 1;
			int left = j - 1;
			int right = j + 1;

			// 인덱스는 벗어나면 안됨
			// 아군이여야함 (W - W, B - B)
			// 노드들을 연결시켜줌
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
				// 아직 방문하지 않은 곳이 있다면, 방문해야함
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

		// 모두 방문했다면 끝!
		if (!isNotVisited)
			break;

		Func(startI, startJ);

		// 제곱의 위력을 낼 수 있다고함
		whiteResult += whiteSum * whiteSum;
		blueResult += blueSum * blueSum;

		whiteSum = 0;
		blueSum = 0;
	}
	
	std::cout << whiteResult << ' ' << blueResult;

	return 0;
}
