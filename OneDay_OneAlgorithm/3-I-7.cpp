#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, ret = 1;
int visited[2][MAX + 1];
queue<int> q;
bool isMeet = false;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	if (n == k) { cout << 0; return 0; }
	q.push(n);
	visited[0][n] = 1;
	while (true)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int x = q.front(); q.pop();
			if (x == k)
			{
				isMeet = true; break;
			}
			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx > MAX) continue;
				if (visited[ret % 2][nx]) continue;
				visited[ret % 2][nx] = visited[(ret + 1) % 2][x] + 1;
				q.push(nx);
			}
		}
		if (isMeet) break;
		k += ret;
		if (k > MAX) break;
		if (visited[ret % 2][k]) { isMeet = true; break; }
		ret++;
	}
	if (isMeet) cout << ret;
	else cout << -1;
}