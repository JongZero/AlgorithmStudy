#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> indexPair;

// table ([5][3] �迭���� �����ִ� �κ��� �ε����� ���)
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

	// ������ ����
	int garo = n / 5;

	string firstLine = input.substr(0, garo);

	// ù��° ���� ���θ� üũ
	for (int j = 0; j < garo; j++)
	{
		if (firstLine[j] == '#')
		{
			// 1���� ���� üũ
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

				// �´� ���ڸ� üũ
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