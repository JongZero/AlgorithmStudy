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

		// ������ ��ŭ for��, ���̸� ī��Ʈ�ϱ� ����
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

			// �� �ڿ� 1�� ����
			long long addNum = front * 10 + 1;
			if (addNum <= b)
				q.push(front * 10 + 1);
			
			// ���ϱ� 2
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