#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[200][200]{};

void solve(int x, int y, int d, int n, vector<vector<int>>& computers)
{
	if (visited[x][y] == true) {
		return;
	}
	visited[x][y] = true;

	if (d > answer) {
		answer = d;
	}
	d++;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	for (int i = 0; i < 4; ++i) {
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (_x < 0 || _x >= n || _y < 0 || _y >= n) {
			continue;
		}

		if (computers[_x][_y] == 1) {
			solve(_x, _y, d, n, computers);
		}
	}
}

int main() {

	int n = 3;
	vector<vector<int>> computers = { {1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			solve(i, j, 0, n, computers);
		}
	}

	return answer;
}