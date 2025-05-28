#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";

	std::map<int, int> pos_L = { {1,3}, {4,2}, {7,1}, {0,0} };
	std::map<int, int> pos_R = { {3,3}, {6,2}, {9,1}, {0,0} };
	std::map<int, int> pos_C = { {2,3}, {5,2}, {8,1}, {0,0} };

	int prev_L_n = -1;
	int prev_R_n = -1;

	int prev_L = 0;
	int prev_R = 0;
	for (int n : numbers) {
		if (n == 1 || n == 4 || n == 7) {
			answer += "L";
			prev_L = pos_L[n];
			prev_L_n = n;
		}
		else if (n == 3 || n == 6 || n == 9) {
			answer += "R";
			prev_R = pos_R[n];
			prev_R_n = n;
		}
		else {
			int pos = pos_C[n];
			int distance_L = abs(prev_L - pos);
			int distance_R = abs(prev_R - pos);

			if (pos_C.find(prev_L_n) != pos_C.end()) {
				distance_L = abs(pos_C[prev_L_n] - pos) - 1;
			}
			if (pos_C.find(prev_R_n) != pos_C.end()) {
				distance_R = abs(pos_C[prev_R_n] - pos) - 1;
			}

			if (distance_L == distance_R) {
				if (hand == "left") {
					answer += "L";
					prev_L = pos;
					prev_L_n = n;
				}
				else {
					answer += "R";
					prev_R = pos;
					prev_R_n = n;
				}
			}
			else if (distance_L > distance_R) {
				answer += "R";
				prev_R = pos;
				prev_R_n = n;
			}
			else {
				answer += "L";
				prev_L = pos;
				prev_L_n = n;
			}
		}
	}

	return answer;
}