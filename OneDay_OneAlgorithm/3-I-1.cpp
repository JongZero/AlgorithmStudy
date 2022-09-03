#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
int n, k, ret = -1;
int visited[2][MAX];
queue<int> q;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	if (n == k) { cout << 0; return 0; }
	q.push(n);
	visited[0][n] = 1;
	int nowK = 1;
	while (q.size())
	{
		//cout << "\nk : " << k << '\n';

		int size = q.size();
		queue<int> qq = q;
		//while (qq.size())
		//{
		//	cout << qq.front() << ' ';
		//	qq.pop();
		//}
		//cout << '\n';
		for (int i = 0; i < size; i++)
		{
			int x = q.front(); q.pop();

			//cout << "x : " << x << '\n';
			if (x == k)
			{
				ret = nowK;
				break;
			}

			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx >= MAX) continue;
				if (visited[nowK % 2][nx]) continue;
				//if (nx == k)
				//{
				//	ret = nowK;
				//	break;
				//}
				visited[nowK % 2][nx] = visited[(nowK + 1) % 2][x] + 1;
				q.push(nx);
			}
			if (ret != -1) break;
		}
		if (ret != -1) break;

		k += nowK;
		if (k >= MAX) break;
		if (visited[nowK % 2][k])
		{
			ret = nowK;
			break;
		}
		nowK++;
	}
	cout << ret;
}