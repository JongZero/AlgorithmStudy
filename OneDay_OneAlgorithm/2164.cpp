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
		// �� ������ ������.
		q.pop();

		if (q.size() <= 1)
		{
			break;
		}

		// ������ �� ���� �� ���� �ִ� ī�带 �� �ؿ� �ִ´�.
		int top = q.front();
		q.push(top);
		q.pop();
	}

	std::cout << q.front() + 1;

	return 0;
}