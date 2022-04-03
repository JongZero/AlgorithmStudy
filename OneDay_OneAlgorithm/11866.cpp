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
		// ����, k - 1���� ���� �� �ڿ� �ִ´�.
		for (int i = 0; i < k - 1; i++)
		{
			int front = q.front();
			q.pop();
			q.push(front);
		}
		
		// �� ����, k��°�� ���� ��� ť�� �����Ѵ�.
		int front = q.front();
		q.pop();
		resultQ.push(front);
	}

	// ť�� ���� ��ҵ��� �߰�
	// k��°�� ã���� �ڿ� �ٽ� �ȳִ´�.
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
			// �� �ڿ� �ٽ� �ִ´�.
			q.push(q.front());
		}

		q.pop();
	}

	// ������� ���
	std::cout << '<';
	while (resultQ.size() > 1)
	{
		std::cout << resultQ.front() + 1 << ", ";
		resultQ.pop();
	}

	// �������� ��ȣ�� �ݾ��ش�.
	std::cout << resultQ.front() + 1 << '>';

	return 0;
}