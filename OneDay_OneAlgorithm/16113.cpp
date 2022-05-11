#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> indexPair;

// table ([5][3] 배열에서 빠져있는 부분을 인덱스로 기록)
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
vector<string> table =		{	{"####.##.##.####"},
								{"###############"},
								{"###..#####..###"},
								{"###..####..####"},
								{"#.##.####..#..#"},
								{"####..###..####"},
								{"####..####.####"},
								{"###..#..#..#..#"},
								{"####.#####.####"},
								{"####.####..####"} };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	string input;
	cin >> input;

	vector<int> resultVec;

	// 가로의 길이
	int garo = n / 5;

	string firstLine = input.substr(0, garo);

	// 첫번째 줄의 가로를 체크
	for (int j = 0; j < garo; j++)
	{
		if (firstLine[j] == '#')
		{
			// 1인지 먼저 체크
			if (j + 1 < garo && firstLine[j + 1] == '.')
			{
				resultVec.push_back(1);
				j += 1;
			}
			else if (j == garo - 1)
			{
				resultVec.push_back(1);
				j += 1;
			}
			else
			{
				int tempStartIndex = 0;
				string tempLine = firstLine;
				string check;
				for (int k = 0; k < 5; k++)
				{
					for (int i = j; i < j + 3; i++)
					{
						check += tempLine[i];
					}

					tempStartIndex += garo;
					tempLine = input.substr(tempStartIndex, garo);
				}

				// 맞는 숫자를 체크
				for (int p = 0; p < 10; p++)
				{
					if (table[p] == check)
					{
						resultVec.push_back(p);
						break;
					}
				}

				j += 3;
			}
		}
	}

	for (int i = 0; i < resultVec.size(); i++)
	{
		cout << resultVec[i];
	}

	return 0;
}