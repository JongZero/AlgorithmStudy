#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;

	std::queue<int> q;
	std::queue<int> resultQ;
	for (int i = 0; i < n; i++)
	{
		q.push(i);
	}

	while (q.size() >= k)
	{
		// 먼저, k - 1개를 빼서 맨 뒤에 넣는다.
		for (int i = 0; i < k - 1; i++)
		{
			int front = q.front();
			q.pop();
			q.push(front);
		}
		
		// 그 다음, k번째를 빼고 결과 큐에 저장한다.
		int front = q.front();
		q.pop();
		resultQ.push(front);
	}

	// 큐에 남은 요소들을 추가
	// k번째를 찾으면 뒤에 다시 안넣는다.
	int count = 0;
	while (!q.empty())
	{
		count++;

		if (count >= k)
		{
			resultQ.push(q.front());
			count = 0;
		}
		else
		{
			// 맨 뒤에 다시 넣는다.
			q.push(q.front());
		}

		q.pop();
	}

	// 순서대로 출력
	std::cout << '<';
	while (resultQ.size() > 1)
	{
		std::cout << resultQ.front() + 1 << ", ";
		resultQ.pop();
	}

	// 마지막은 괄호를 닫아준다.
	std::cout << resultQ.front() + 1 << '>';

	return 0;
}