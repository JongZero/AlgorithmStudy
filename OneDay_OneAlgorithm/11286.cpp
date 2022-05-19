#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

struct temp
{
	bool operator()(const int& a, const int& b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<int> resultVec;
	priority_queue<int, vector<int>, temp> q;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> input;

		// 최대값 출력 후 배열에서 제거
		if (input == 0)
		{
			// 배열이 비어있는 경우는 0 출력
			if (q.size() <= 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// 최대 값 출력 후
				resultVec.emplace_back(q.top());

				// 제거
				q.pop();
			}
		}
		// 배열에 x값 넣기
		else
		{
			q.push(input);
		}
	}

	for (int i = 0; i < resultVec.size(); i++)
	{
		cout << resultVec[i] << '\n';
	}

	return 0;
}