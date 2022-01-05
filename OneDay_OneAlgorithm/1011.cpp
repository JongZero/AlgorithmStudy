#include <iostream>
using namespace std;

// 1 - 1	1
// 2 - 2	1 1
// 3 - 3	1 1 1
// 4 - 3	1 2 1
// 5 - 4	1 2 1 1
// 6 - 4	1 2 2 1
// 7 - 5	1 2 2 1 1
// 8 - 5	1 2 2 2 1
// 9 - 5	1 2 3 2 1
// 10 - 6	1 2 3 2 1 1
// 11 - 6	1 2 3 2 2 1
// 12 - 6	1 2 3 3 2 1
// 13 - 7	1 2 3 3 2 1 1
// 14 - 7	1 2 3 3 2 2 1
// 15 - 7	1 2 3 3 3 2 1
// 16 - 7	1 2 3 4 3 2 1
// 17 - 8	1 2 3 4 3 2 1 1
// 18 - 8	1 2 3 4 3 2 2 1
// 19 - 8	1 2 3 4 3 3 2 1
// 20 - 8	1 2 3 4 4 3 2 1
// 21 - 9	1 2 3 4 4 3 2 1 1
// 22 - 9	1 2 3 4 4 3 2 2 1
// 23 - 9	1 2 3 4 4 3 3 2 1
// 24 - 9	1 2 3 4 4 4 3 2 1
// 25 - 9	1 2 3 4 5 4 3 2 1
// 26 - 10	1 2 3 4 5 4 3 2 1 1
// 27 - 10	1 2 3 4 5 4 3 2 2 1
// 28 - 10	1 2 3 4 5 4 3 3 2 1
// 29 - 10	1 2 3 4 5 4 4 3 2 1
// 30 - 10	1 2 3 4 5 5 4 3 2 1

int main()
{
	long long t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long x, y;
		cin >> x >> y;

		long long distance = y - x;

		long long k = 1;				// 현재 k
		long long answer = 1;			// 답
		long long answerCount = 1;	// 몇 번 지나야 answer++ 인지

		bool isRangePlus = false;		// range를 증가시킬지 여부, 2번에 1번 증가시킴
		long long range = 0;

		long long totalLoop = 2;				// 몇 번 반복되는지
		long long totalLoopCount = totalLoop;	// 카운트
		while (true)
		{
			if (k + range >= distance)
				break;

			k += answerCount;
			answer++;

			totalLoopCount -= answerCount;
			
			if (totalLoopCount <= 0)
			{
				totalLoop += 2;
				totalLoopCount = totalLoop;

				answerCount = totalLoop / 2;
			}

			if (isRangePlus)
			{
				isRangePlus = false;
				range++;
			}
			else
			{
				isRangePlus = true;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}