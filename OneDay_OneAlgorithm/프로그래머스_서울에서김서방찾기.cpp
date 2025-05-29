#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	int i = 0;

	for (const string& s : seoul) {
		if (s == "Kim") {
			break;
		}
		++i;
	}

	return "김서방은 " + to_string(i) + "에 있다";
}