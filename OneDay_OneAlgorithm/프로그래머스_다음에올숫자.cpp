#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
	int answer = 0;

	int a = common[0];
	int b = common[1];
	int c = common[2];

	if (b - a == c - b) {
		answer = common[common.size() - 1] + (b - a);
	}
	else {
		answer = common[common.size() - 1] * (b / a);
	}

	return answer;
}