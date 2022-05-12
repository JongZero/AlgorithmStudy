#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int Min = 0;
const int Max = 100000;
vector<bool> isVisited(Max + 1);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;
	cin >> n >> k;

	queue<int> q;
	q.push(n);

	int time = 0;	// �ɸ� �ð�
	while (!q.empty())
	{
		bool isArrived = false;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int front = q.front();
			isVisited[front] = true;
			q.pop();

			// �����ߴ°�?
			if (front == k)
			{
				isArrived = true;
				break;
			}

			// 3���� ����
			// �ȱ� X+1
			if (front + 1 <= Max && isVisited[front + 1] == false)
				q.push(front + 1);
			// �ȱ� X-1
			if (front - 1 >= Min && isVisited[front - 1] == false)
				q.push(front - 1);
			// �����̵� 2*X
			if (front * 2 <= Max && isVisited[front * 2] == false)
				q.push(front * 2);
		}

		if (isArrived)
			break;

		time++;
	}

	cout << time;

	return 0;
}