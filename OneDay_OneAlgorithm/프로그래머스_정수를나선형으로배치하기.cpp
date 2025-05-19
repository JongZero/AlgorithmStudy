#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

void Print(std::vector<std::vector<int>>& a)
{
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;

	answer.resize(n);
	for (vector<int>& a : answer) {
		a.resize(n);
	}

	enum TYPE { ROW, COLUMN };
	enum DIR { PLUS, MINUS };
	std::vector<std::tuple<TYPE, int, DIR>> index;

	for (int i = 0; i < n; ++i) {
		index.emplace_back(ROW, i, PLUS);
		index.emplace_back(COLUMN, n - (1 + i), PLUS);
		index.emplace_back(ROW, n - (1 + i), MINUS);
		index.emplace_back(COLUMN, i, MINUS);
	}

	int value = 1;
	for (const auto& [type, num, dir] : index) {
		if (type == ROW) {
			if (dir == PLUS) {
				for (int i = 0; i < n; ++i) {
					if (answer[num][i] != 0)
						continue;

					answer[num][i] = value;
					++value;
					//Print(answer);
				}
			}
			else {  // MINUS
				for (int i = n - 1; i >= 0; --i) {
					if (answer[num][i] != 0)
						continue;

					answer[num][i] = value;
					++value;
					//Print(answer);
				}
			}
		}
		else {  // COLUMN
			if (dir == PLUS) {
				for (int i = 0; i < n; ++i) {
					if (answer[i][num] != 0)
						continue;

					answer[i][num] = value;
					++value;
					//Print(answer);
				}
			}
			else {  // MINUS
				for (int i = n - 1; i >= 0; --i) {
					if (answer[i][num] != 0)
						continue;

					answer[i][num] = value;
					++value;
					//Print(answer);
				}
			}
		}
	}

	return answer;
}