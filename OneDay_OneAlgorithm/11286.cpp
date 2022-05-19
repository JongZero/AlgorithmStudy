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

		// �ִ밪 ��� �� �迭���� ����
		if (input == 0)
		{
			// �迭�� ����ִ� ���� 0 ���
			if (q.size() <= 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// �ִ� �� ��� ��
				resultVec.emplace_back(q.top());

				// ����
				q.pop();
			}
		}
		// �迭�� x�� �ֱ�
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