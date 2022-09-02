#include <bits/stdc++.h>
using namespace std;

int n;
int input[3];

int visited[61][61][61];
int att[6][3] = {	{9, 3, 1},
					{9, 1, 3},
					{3, 9, 1},
					{3, 1, 9},
					{1, 9, 3},
					{1, 3, 9}, };

struct A { int a, b, c; };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	queue<A> q;
	q.push({ input[0], input[1], input[2] });
	visited[input[0]][input[1]][input[2]] = 1;
	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (visited[0][0][0]) break;

		for (int i = 0; i < 6; i++)
		{
			int na = max(0, a - att[i][0]);
			int nb = max(0, b - att[i][1]);
			int nc = max(0, c - att[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}
	cout << visited[0][0][0] - 1;
}