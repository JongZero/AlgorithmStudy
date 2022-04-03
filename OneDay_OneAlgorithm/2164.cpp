#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::queue<int> q;

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		// 맨 윗장을 버린다.
		q.pop();

		if (q.size() <= 1)
		{
			break;
		}

		// 버리고 난 다음 맨 위에 있는 카드를 맨 밑에 넣는다.
		int top = q.front();
		q.push(top);
		q.pop();
	}

	std::cout << q.front() + 1;

	return 0;
}