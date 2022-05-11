#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;
	cin >> n >> k;

	queue<int> _queue;
	for (int i = 1; i <= n; i++)
	{
		_queue.push(i);
	}

	vector<int> resultVec;
	int index = 0;
	while (!_queue.empty())
	{
		int front = _queue.front();
		index++;
		_queue.pop();
		
		if (index < k)
		{
			_queue.push(front);
		}
		else
		{
			index = 0;
			resultVec.emplace_back(front);
		}
	}

	cout << "<";
	for (int i = 0; i < resultVec.size(); i++)
	{
		cout << resultVec[i];

		if (i != resultVec.size() - 1)
			cout << ", ";
	}
	cout << ">";

	return 0;
}