#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
	int answer = 0;

	int64_t num64 = num;

	while (num64 != 1) {

		answer++;
		if (answer == 500) {
			return -1;
		}

		if (num64 % 2 == 0) {
			num64 /= 2;
		}
		else {
			num64 *= 3;
			num64++;
		}
	}

	return answer;
}