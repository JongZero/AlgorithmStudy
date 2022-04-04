#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		// 문서의 개수
		int n = 0;
		// 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지
		int m = 0;
		std::cin >> n >> m;

		// 문서 큐, 앞은 최초 순서 뒤는 중요도
		std::queue<std::pair<int, int>> q;

		// n개 문서의 중요도 차례대로 주어진다.
		for (int j = 0; j < n; j++)
		{
			// 중요도
			int inputPoint = 0;
			std::cin >> inputPoint;
			
			// 최초 순서와 중요도를 큐에 넣는다.
			q.push(std::pair<int, int>(j, inputPoint));
		}

		// 출력 순서
		int index = 0;
		while (true)
		{
			// 현재 사이즈만큼 순회하면서, 중요도가 자신보다 더 큰수가 하나라도 있는지 체크한다.
			bool isExist = false;
			int checkNum = q.front().second;
			int qSize = q.size();
			for (int j = 0; j < qSize; j++)
			{
				std::pair<int, int> front = q.front();

				if (checkNum < front.second)
				{
					isExist = true;
				}

				// 빼고 맨 뒤에 넣는다.
				// (다른 것들도 체크해야 되기 때문)
				q.pop();
				q.push(front);
			}

			// 중요도가 자신보다 더 큰수가 하나라도 있다면
			std::pair<int, int> front = q.front();
			if (isExist)
			{
				// 현재 문서를 가장 뒤에 재배치한다.
				q.push(front);
				q.pop();
			}
			// 없다면
			else
			{
				// 출력 순서 증가
				index++;

				// 인쇄한다.
				q.pop();

				// 내가 찾고자 하는 문서라면
				// 현재 출력 순서를 출력한다.
				if (m == front.first)
				{
					std::cout << index << '\n';
					break;
				}
			}
		}
	}

	return 0;
}