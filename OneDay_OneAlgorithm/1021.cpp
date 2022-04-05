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

	// �ϴ� n���� �ִ´�.
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

	// m����ŭ �̾Ƴ�������
	// �ּ� Ƚ���� ���ؾ���
	int minCount = 0;
	for (int i = 0; i < m; i++)
	{
		int input = inputs[i];

		// �տ������� �˻�
		int frontCount = 0;			// 2,3�� ���� Ƚ��
		std::deque<int> checkFrontQ = q;
		while (true)
		{
			int front = checkFrontQ.front();

			// 1�� ���� �˻�
			if (front == input)
			{
				checkFrontQ.pop_front();
				break;
			}

			frontCount++;

			// 2�� ���� ����
			checkFrontQ.pop_front();
			checkFrontQ.push_back(front);
		}

		// �ڿ������� �˻�
		int backCount = 0;			// 2,3�� ���� Ƚ��
		std::deque<int> checkBackQ = q;
		while (true)
		{
			int front = checkBackQ.front();

			// 1�� ���� �˻�
			if (front == input)
			{
				checkBackQ.pop_front();
				break;
			}

			backCount++;

			// 3�� ���� ����
			int back = checkBackQ.back();
			checkBackQ.pop_back();
			checkBackQ.push_front(back);
		}

		if (frontCount > backCount)
		{
			// 3�� ���� Ƚ���� �� ���� ���
			minCount += backCount;
			q = checkBackQ;
		}
		else //(frontCount < backCount)
		{
			// 2�� ���� Ƚ���� �� ���� ���
			minCount += frontCount;
			q = checkFrontQ;
		}
	}

	std::cout << minCount;

	return 0;
}