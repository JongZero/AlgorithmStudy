#include <iostream>
#include <vector>
#include <deque>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	std::deque<int> q;

	// 일단 n까지 넣는다.
	for (int i = 0; i < n; i++)
	{
		q.push_back(i + 1);
	}

	std::vector<int> inputs(m);
	for (int i = 0; i < m; i++)
	{
		// input
		std::cin >> inputs[i];
	}

	// m개만큼 뽑아내려고함
	// 최소 횟수를 구해야함
	int minCount = 0;
	for (int i = 0; i < m; i++)
	{
		int input = inputs[i];

		// 앞에서부터 검사
		int frontCount = 0;			// 2,3번 연산 횟수
		std::deque<int> checkFrontQ = q;
		while (true)
		{
			int front = checkFrontQ.front();

			// 1번 연산 검사
			if (front == input)
			{
				checkFrontQ.pop_front();
				break;
			}

			frontCount++;

			// 2번 연산 수행
			checkFrontQ.pop_front();
			checkFrontQ.push_back(front);
		}

		// 뒤에서부터 검사
		int backCount = 0;			// 2,3번 연산 횟수
		std::deque<int> checkBackQ = q;
		while (true)
		{
			int front = checkBackQ.front();

			// 1번 연산 검사
			if (front == input)
			{
				checkBackQ.pop_front();
				break;
			}

			backCount++;

			// 3번 연산 수행
			int back = checkBackQ.back();
			checkBackQ.pop_back();
			checkBackQ.push_front(back);
		}

		if (frontCount > backCount)
		{
			// 3번 연산 횟수가 더 적을 경우
			minCount += backCount;
			q = checkBackQ;
		}
		else //(frontCount < backCount)
		{
			// 2번 연산 횟수가 더 적을 경우
			minCount += frontCount;
			q = checkFrontQ;
		}
	}

	std::cout << minCount;

	return 0;
}