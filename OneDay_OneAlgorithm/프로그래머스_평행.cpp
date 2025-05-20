#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;

	unordered_set<string> check;

	for (int i = 0; i < 4; ++i) {
		int x = dots[i][0];
		int y = dots[i][1];

		for (int j = i + 1; j < 4; ++j) {
			int _x = dots[j][0];
			int _y = dots[j][1];

			string d_x = to_string(x - _x);
			string d_y = to_string(y - _y);
			string d = d_x + "_" + d_y;

			if (check.find(d) != check.end()) {
				return 1;
			}
			else {
				for (const string& c_d : check) {
					int c_d_x = stoi(c_d.substr(0, c_d.find("_")));
					int c_d_y = stoi(c_d.substr(c_d.find("_") + 1, c_d.length()));

					cout << "c_d_x, c_d_y: " << c_d_x << " " << c_d_y << " " << "\n";
					cout << "d_x, d_y: " << d_x << " " << d_y << " " << "\n";

					if (c_d_y * stoi(d_x) == c_d_x * stoi(d_y)) {
						return 1;
					}
				}

				check.insert(d);
			}
		}
	}

	return answer;
}