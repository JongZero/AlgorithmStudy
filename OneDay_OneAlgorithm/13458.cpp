#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> inputNum(n);
	for (int i = 0; i < n; i++)
		cin >> inputNum[i];

	int b = 0;
	int c = 0;
	cin >> b >> c;

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		int num = inputNum[i];

		// 총 감독관의 감시 수 체크
		num -= b;
		result++;

		if (num <= 0)
			continue;

		// 부 감독관 몇 명 필요한지
		int remain = num % c;
		num /= c;
		result += num;

		if (remain != 0)
			result++;
	}
	
	cout << result;

	return 0;
}