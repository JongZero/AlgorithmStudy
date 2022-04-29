#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a = 0;
	int b = 0;

	std::cin >> a >> b;

	std::queue<long long> q;
	q.push(a);

	int resultCount = 0;
	bool isArrive = false;
	while (!q.empty())
	{
		int size = q.size();

		// 사이즈 만큼 for문, 깊이를 카운트하기 위함
		isArrive = false;
		for (int i = 0; i < size; i++)
		{
			long long front = q.front();
			q.pop();

			if (front == b)
			{
				isArrive = true;
				break;
			}

			// 맨 뒤에 1을 더함
			long long addNum = front * 10 + 1;
			if (addNum <= b)
				q.push(front * 10 + 1);
			
			// 곱하기 2
			addNum = front * 2;
			if (addNum <= b)
				q.push(front * 2);
		}

		resultCount++;

		if (isArrive)
		{
			break;
		}
	}

	if (isArrive)
	{
		std::cout << resultCount;
	}
	else
	{
		std::cout << -1;
	}

	return 0;
}