#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, k, ret, retCount;
int visited[100001];

int dx[] = { -1, 1, 2 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << '\n' << 1;
		return 0;
	}

	queue<int> q;
	q.push(n);
	visited[n] = 1;
	int nowVisited = 1;
	vector<int> visitedList;
	while (q.size())
	{
		int size = q.size();
		//cout << "size : " << size << '\n';
		for (int a = 0; a < size; a++)
		{
			int x = q.front();
			q.pop();

			//cout << "x : " << x << '\n';

			for (int i = 0; i < 3; i++)
			{
				int nx = x;
				if (i != 2)
					nx += dx[i];
				else
					nx *= dx[i];

				if (nx < 0 || nx > 100000) continue;
				if (visited[nx]) continue;
				//cout << "push : " << nx << '\n';
				visitedList.push_back(nx);
			}
		}

		nowVisited++;
		for (int nx : visitedList)
		{
			q.push(nx);
			visited[nx] = nowVisited;
			if (nx == k) retCount++;
		}
		visitedList.clear();
		if (retCount > 0) break;
	}
	cout << nowVisited - 1 << '\n' << retCount;
}