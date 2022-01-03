#include <iostream>
#include <string>
using namespace std;

/// 1065
// 문제
// 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
// 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.N이 주어졌을 때, 
// 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 1, 000보다 작거나 같은 자연수 N이 주어진다.
// 
// 출력
// 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

int main()
{
	int n = 0;

	cin >> n;

	int* numbers = new int[n];

	// 한수의 개수
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		numbers[i] = i + 1;

		string str = to_string(numbers[i]);

		// 두 자리수 이하
		if (str.size() <= 2)
			count++;
		// 세 자리수 이상
		else
		{
			// 각 자리 숫자의 차이
			int prevSub = 0;
			int sub = 0;

			// 등차수열인지 아닌지
			bool isEqual = false;

			// 각 자리의 숫자
			for (int j = 1; j < str.size(); j++)
			{
				int now = str[j] - '0';
				int prev = str[j - 1] - '0';
				
				sub = now - prev;

				if (j == 1)
				{
					prevSub = sub;
					continue;
				}
				// 이전 차이와 비교
				else
				{
					if (prevSub == sub)
					{
						isEqual = true;
						prevSub = sub;
					}
					// 하나라도 공차가 다르면 등차수열이 아니다.
					else
					{
						isEqual = false;
						break;
					}
				}
			}

			// 등차수열이라면 카운트 증가
			if (isEqual)
				count++;
		}
	}

	cout << count;

	delete[] numbers;
	numbers = nullptr;

	return 0;
}