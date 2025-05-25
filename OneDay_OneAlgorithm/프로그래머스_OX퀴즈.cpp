#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
	vector<string> vAnswer;

	for (const string& s : quiz) {
		string sQuiz = s.substr(0, s.find("=") - 1);
		int answer = stoi(s.substr(s.find("=") + 1, s.length()));

		bool O = false;
		if (sQuiz.find(" - ") != string::npos) {
			int num1 = stoi(sQuiz.substr(0, sQuiz.find(" - ")));
			int num2 = stoi(sQuiz.substr(sQuiz.find(" - ") + 2, sQuiz.length()));
			if (num1 - num2 == answer) {
				O = true;
			}
		}
		else {
			int num1 = stoi(sQuiz.substr(0, sQuiz.find(" + ")));
			int num2 = stoi(sQuiz.substr(sQuiz.find(" + ") + 2, sQuiz.length()));
			if (num1 + num2 == answer) {
				O = true;
			}
		}

		if (O == true) {
			vAnswer.push_back("O");
		}
		else {
			vAnswer.push_back("X");
		}
	}

	return vAnswer;
}