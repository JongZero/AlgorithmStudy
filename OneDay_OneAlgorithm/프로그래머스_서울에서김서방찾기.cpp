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

	return "�輭���� " + to_string(i) + "�� �ִ�";
}