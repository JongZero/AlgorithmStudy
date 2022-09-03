#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
int n, k, ret = -1;
int visited[MAX];

queue<int> q;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	if (n == k) { cout << 0; return 0; }
	q.push(n);
	visited[n] = 1;
	int nowK = 1;
	while (q.size())
	{
		//cout << "\nk : " << k << '\n';
		bool isEnd = false;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int x = q.front();
			//cout << "x : " << x << ' ';
			q.pop();

			if (x == k)
			{
				ret = nowK;
				isEnd = true;
				break;
			}

			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx >= MAX) continue;
				if (visited[nx]) continue;
				visited[nx] = 1;
				q.push(nx);
			}
		}

		if (isEnd) break;
		memset(visited, 0, sizeof(visited));

		k += nowK;
		nowK++;

		if (k >= MAX || visited[k]) break;
	}
	if (ret != -1) ret--;
	cout << ret;
}