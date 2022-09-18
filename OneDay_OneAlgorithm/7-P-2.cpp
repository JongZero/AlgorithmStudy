#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;
int a, b, c, d, ret;
queue<pa> q;
map<pa, int> dp;
bool isEnd = false;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b >> c >> d;
	q.push({ 0, 0 });
	while (true)
	{
		int size = q.size();
		if (size == 0) break;
		for (int i = 0; i < size; i++)
		{
			int x, y;
			tie(x, y) = q.front(); q.pop();
			if (x == c && y == d)
			{
				isEnd = true;
				break;
			}
			if (dp.find({ x, y }) != dp.end()) continue;
			dp[{x, y}]++;
			q.push({ a, y });
			q.push({ x, b });

			q.push({ 0, y });
			q.push({ x, 0 });

			if (x <= b - y)
			{
				q.push({ 0, y + x });
			}
			else
			{
				q.push({ x - (b - y), b });
			}

			if (y <= a - x)
			{
				q.push({ x + y, 0 });
			}
			else
			{
				q.push({ a, y - (a - x) });
			}
		}
		if (isEnd) break;
		ret++;
	}
	if (isEnd) cout << ret;
	else cout << -1;
}