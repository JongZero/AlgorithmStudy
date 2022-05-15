#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum eDir
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string input;
		cin >> input;

		// 시작 지점
		pair<int, int> nowPos(0, 0);

		// 최소
		pair<int, int> minPos(0, 0);
		// 최대
		pair<int, int> maxPos(0, 0);

		int dir = eDir::UP;
		for (int j = 0; j < input.size(); j++)
		{
			char c = input[j];
			
			if (c == 'F')
			{
				switch (dir)
				{
				case UP:
					nowPos.second++;
					break;
				case LEFT:
					nowPos.first--;
					break;
				case DOWN:
					nowPos.second--;
					break;
				case RIGHT:
					nowPos.first++;
					break;
				}

				// 최소, 최대 비교
				if (minPos.first > nowPos.first)
					minPos.first = nowPos.first;
				if (minPos.second > nowPos.second)
					minPos.second = nowPos.second;
				if (maxPos.first < nowPos.first)
					maxPos.first = nowPos.first;
				if (maxPos.second < nowPos.second)
					maxPos.second = nowPos.second;
			}
			else if (c == 'B')
			{
				switch (dir)
				{
				case UP:
					nowPos.second--;
					break;
				case LEFT:
					nowPos.first++;
					break;
				case DOWN:
					nowPos.second++;
					break;
				case RIGHT:
					nowPos.first--;
					break;
				}

				// 최소, 최대 비교
				if (minPos.first > nowPos.first)
					minPos.first = nowPos.first;
				if (minPos.second > nowPos.second)
					minPos.second = nowPos.second;
				if (maxPos.first < nowPos.first)
					maxPos.first = nowPos.first;
				if (maxPos.second < nowPos.second)
					maxPos.second = nowPos.second;
			}
			else if (c == 'L')
			{
				dir++;

				if (dir > eDir::RIGHT)
					dir = eDir::UP;
			}
			else if (c == 'R')
			{
				dir--;

				if (dir < eDir::UP)
					dir = eDir::RIGHT;
			}
		}

		// 최대 점 - 최소 점
		int width = maxPos.first - minPos.first;
		int height = maxPos.second - minPos.second;

		// 사각형의 넓이
		cout << width * height << '\n';
	}

	return 0;
}