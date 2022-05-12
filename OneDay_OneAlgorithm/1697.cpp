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

	int time = 0;	// 걸린 시간
	while (!q.empty())
	{
		bool isArrived = false;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int front = q.front();
			isVisited[front] = true;
			q.pop();

			// 도착했는가?
			if (front == k)
			{
				isArrived = true;
				break;
			}

			// 3가지 간선
			// 걷기 X+1
			if (front + 1 <= Max && isVisited[front + 1] == false)
				q.push(front + 1);
			// 걷기 X-1
			if (front - 1 >= Min && isVisited[front - 1] == false)
				q.push(front - 1);
			// 순간이동 2*X
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