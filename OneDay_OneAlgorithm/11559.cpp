#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int Height = 12;
const int Width = 6;

vector<string> InputVec;
vector<vector<bool>> IsVisited;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.first < p2.first;
}

bool Check(int i, int j, char c)
{
	if (i < 0 || j < 0 || i >= Height || j >= Width)
		return false;
	else if (IsVisited[i][j] == true)
		return false;
	else if (InputVec[i][j] != c)
		return false;
	else
		return true;
}

void Func(int i, int j, int& tempCount, vector<pair<int, int>>& tempVec)
{
	IsVisited[i][j] = true;
	tempCount++;
	tempVec.emplace_back(make_pair(i, j));

	// ��, ��, ��, �� Ž��
	char c = InputVec[i][j];
	if (Check(i - 1, j, c))
		Func(i - 1, j, tempCount, tempVec);
	if (Check(i + 1, j, c))
		Func(i + 1, j, tempCount, tempVec);
	if (Check(i, j - 1, c))
		Func(i, j - 1, tempCount, tempVec);
	if (Check(i, j + 1, c))
		Func(i, j + 1, tempCount, tempVec);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	InputVec.resize(Height);
	IsVisited.resize(Height);
	for (int i = 0; i < Height; i++)
	{
		IsVisited[i].resize(Width);
		cin >> InputVec[i];
	}

	int result = 0;
	while (true)
	{
		// Ž���� ������ ��ġ
		int startX = 0;
		int startY = Height - 1;

		// Ž���� ���� �ִ��� (�� ���� �ִ���?)
		bool isExist = false;

		// �ؿ������� �˻�
		for (int i = Height - 1; i >= 0; i--)
		{
			for (int j = 0; j < Width; j++)
			{
				// Ž���� ���� �ִٸ�
				if (InputVec[i][j] != '.' && IsVisited[i][j] == false)
				{
					startY = i;
					startX = j;
					isExist = true;
					break;
				}
			}

			if (isExist)
				break;
		}

		if (!isExist)
			break;

		//cout << startY << ' ' << startX << '\n';

		int tempCount = 0;
		vector<pair<int, int>> tempVec;
		Func(startY, startX, tempCount, tempVec);

		// 4�� �̻� ���̸� ����
		if (tempCount >= 4)
		{
			sort(tempVec.begin(), tempVec.end(), compare);

			for (int k = 0; k < tempVec.size(); k++)
			{
				int i = tempVec[k].first;
				int j = tempVec[k].second;

				InputVec[i][j] = '.';
				
				// ������ ��ĭ�� ����
				int eraseCount = 0;
				for (int h = i; h >= 1; h--)
				{
					if (InputVec[h - 1][j] == '.')
						eraseCount++;
					
					if (eraseCount > 1)
						break;

					InputVec[h][j] = InputVec[h - 1][j];
				}
			}

			// �湮 ǥ�� �ʱ�ȭ
			for (int h = 0; h < Height; h++)
			{
				for (int w = 0; w < Width; w++)
					IsVisited[h][w] = false;
			}

			result++;	// ���� Ƚ��
		}
	}

	cout << result;

	return 0;
}
