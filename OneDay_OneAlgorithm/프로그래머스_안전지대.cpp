#include <string>
#include <vector>

using namespace std;

bool check[100][100]{};
int answer = 0;

void _check(int x, int y, int n, bool bomb)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;

	check[x][y] = true;

	if (bomb == false)
		return;

	int near_x[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int near_y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 0; i < 8; ++i) {
		int _x = x + near_x[i];
		int _y = y + near_y[i];
		_check(_x, _y, n, false);
	}
}

int solution(vector<vector<int>> board) {

	int n = board.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 1) {
				_check(i, j, n, true);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (check[i][j] == false) {
				answer++;
			}
		}
	}

	return answer;
}