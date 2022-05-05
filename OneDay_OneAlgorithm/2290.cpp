#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
vector<bool> top = { true, false, true, true, false, true, true, true, true, true };
vector<bool> middle = { false, false, true, true, true, true, true, false, true, true };
vector<bool> down = { true, false, true, true, false, true, true, false, true, true };

vector<bool> leftTop = { true, false, false, false, true, true, true, false, true, true };
vector<bool> rightTop = { true, true, true, true, true, false, false, true, true, true };
vector<bool> leftDown = { true, false, true, false, false, false, true, false, true, false };
vector<bool> rightDown = { true, true, false, true, true, true, true, true, true, true };

enum eTable
{
	Top,
	LeftTop,
	RightTop,
	Middle,
	LeftDown,
	RightDown,
	Down,
};

vector<bool> table[7] = { top, leftTop, rightTop, middle, leftDown, rightDown, down };

int s = 0;
string n;

void TopMiddleDown(eTable t)
{
	string output;
	for (int i = 0; i < n.size(); i++)
	{
		int now = n[i] - '0';
		string temp;
		temp += ' ';
		for (int j = 0; j < s; j++)
		{
			if (table[t][now] == true)
			{
				temp += '-';
			}
			else
			{
				temp += ' ';
			}
		}
		temp += ' ';
		output += temp;
		output += ' ';
	}
	cout << output << '\n';
}

void LeftTopRightTopLeftDownRightDown(eTable t)
{
	string output;
	for (int j = 0; j < s; j++)
	{
		for (int i = 0; i < n.size(); i++)
		{
			int now = n[i] - '0';
			string temp;

			if (table[t][now] == true)
			{
				temp += '|';
			}
			else
			{
				temp += ' ';
			}

			if (table[t + 1][now] == true)
			{
				temp += '|';
			}
			else
			{
				temp += ' ';
			}

			temp += ' ';

			// 중간에 공백 삽입
			for (int k = 0; k < s; k++)
			{
				temp.insert(1, " ");
			}

			output += temp;
		}
		cout << output << '\n';
		output.clear();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> s >> n;

	// top
	TopMiddleDown(eTable::Top);

	// leftTop, rightTop
	LeftTopRightTopLeftDownRightDown(LeftTop);

	// middle
	TopMiddleDown(eTable::Middle);

	// leftDown, rightDown
	LeftTopRightTopLeftDownRightDown(LeftDown);

	// down
	TopMiddleDown(eTable::Down);

	return 0;
}