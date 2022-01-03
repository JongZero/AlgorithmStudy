#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		// 두 원의 중점이 같고 반지름도 같다면 무한대의 개수로 겹친다.
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << "\n";
			continue;
		}
		// 두 원의 중점이 같고 반지름이 다르다면 만나지 않는다.
		else if (x1 == x2 && y1 == y2 && r1 != r2)
		{
			cout << 0 << "\n";
			continue;
		}

		// 두 원의 중점 사이의 거리를 구한다.
		int distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
		int rPlus = pow(r1 + r2, 2);
		int rMinus = pow(r2 - r1, 2);

		// r1 + r2와 거리를 비교하여 같으면 두 원은 1곳이 겹치고
		// r1 + r2가 더 크면 두 원은 2곳이 겹치고
		// 거리가 더 크면 두 원은 겹치지 않는다. 따라서 정답은 0, 1, 2중에 하나가 나올 것이다.
		if (rPlus > distance)
		{
			// 내접하는 경우
			if (rMinus == distance)
			{
				cout << 1;
			}
			// 한 원이 한 원 안에 속하는 경우
			else if (rMinus > distance)
			{
				cout << 0;
			}
			else
			{
				cout << 2;
			}
		}
		// 외접하는 경우
		else if (rPlus == distance)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}

		cout << "\n";
	}

	return 0;
}