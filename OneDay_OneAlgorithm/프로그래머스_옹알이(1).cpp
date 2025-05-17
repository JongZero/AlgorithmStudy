#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	for (const string& s : babbling) {
		string parse = s;
		while (parse.length() > 0) {
			char c = parse[0];

			// aya
			if (c == 'a') {
				if (parse.length() >= 3) {
					if (parse[1] == 'y' && parse[2] == 'a') {
						parse = parse.substr(3, parse.length());
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			// ye
			else if (c == 'y') {
				if (parse.length() >= 2) {
					if (parse[1] == 'e') {
						parse = parse.substr(2, parse.length());
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			// woo
			else if (c == 'w') {
				if (parse.length() >= 3) {
					if (parse[1] == 'o' && parse[2] == 'o') {
						parse = parse.substr(3, parse.length());
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			// ma
			else if (c == 'm') {
				if (parse.length() >= 2) {
					if (parse[1] == 'a') {
						parse = parse.substr(2, parse.length());
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}

		if (parse.length() == 0) {
			answer++;
		}
	}

	return answer;
}