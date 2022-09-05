#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
int n, k, timee = 1;
int visited[2][MAX];
queue<int> q;
bool isMeet = false;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	if (n == k)
	{
		cout << 0;
		return 0;
	}
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
				isMeet = true; 
				break;
			}
			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx >= MAX) continue;
				if (visited[timee % 2][nx]) continue;
				visited[timee % 2][nx] = visited[(timee + 1) % 2][x] + 1;
				q.push(nx);
			}
		}
		if (isMeet) break;
		k += timee;
		if (k >= MAX) break;
		if (visited[timee % 2][k])
		{
			isMeet = true;
			break;
		}
		timee++;
	}
	if (isMeet) cout << timee;
	else cout << -1;
}