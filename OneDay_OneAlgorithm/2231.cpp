#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// 자연수 n의 가장 작은 생성자, 생성자가 없다면 0을 출력
	int result = 0;

	// 자연수의 최소 범위부터 최대범위까지 돌면서
	for (int i = 1; i <= 1000000; i++)
	{
		// 그 자연수와
		int sum = i;

		// 자연수의 각자리의 합을 모두 더해
		string numStr = to_string(i);
		for (int j = 0; j < numStr.size(); j++)
		{
			// char to int
			sum += numStr[j] - '0';
		}

		// n과 같으면 생성자이다.
		// 가장 작은 것만 찾으면 되므로 찾았다면 그 수가 가장 작은 수이다.
		if (sum == n)
		{
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}