#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int INF = 987654321;
int af, bf, ar, br, ret = INF, ret2;// , dp[1001][1001], visited[1001][1001];
map<pa, int> m;
bool isEnd = false;
queue<pa> q;
/*
int func(int a, int b, int cnt)
{
	cout << a << ", " << b << " cnt: " << cnt << '\n';

	if (visited[a][b]) return INF;
	if (cnt >= ret) return INF;
	if (a == ar && b == br)
	{
		ret = min(ret, cnt);
		return ret;
	}
	
	if (dp[a][b] != INF) return dp[a][b];
		
	int& d = dp[a][b];
	d = 0;
	visited[a][b] = 1;

	// 물통 a에 물을 가득 채운다.
	d = min(d, func(af, b, cnt + 1));
	// 물통 b에 물을 가득 채운다.
	d = min(d, func(a, bf, cnt + 1));

	// 물통 a의 물을 모두 버린다.
	d = min(d, func(0, b, cnt + 1));
	// 물통 b의 물을 모두 버린다.
	d = min(d, func(a, 0, cnt + 1));

	// 물통 a의 물을 b에 붓는다.
	if (a <= bf - b)
	{
		d = min(d, func(0, b + a, cnt + 1));
	}
	else
	{
		d = min(d, func(a - (bf - b), bf, cnt + 1));
	}
	// 물통 b의 물을 a에 붓는다.
	if (b <= af - a)
	{
		d = min(d, func(a + b, 0, cnt + 1));
	}
	else
	{
		d = min(d, func(af, b - (af - a), cnt + 1));
	}

	visited[a][b] = 0;
	return d;
}
*/
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	//fill(&dp[0][0], &dp[0][0] + 1001 * 1001, INF);
	cin >> af >> bf >> ar >> br;
	//func(0, 0, 0);
	//if (ret == INF) cout << -1;
	//else cout << ret;

	q.push({ 0, 0 });
	while (true)
	{
		int size = q.size();
		if (size == 0) break;
		for (int i = 0; i < size; i++)
		{
			int a, b;
			tie(a, b) = q.front(); q.pop();
			if (a == ar && b == br)
			{
				isEnd = true;
				break;
			}
			if (m.find({ a, b }) != m.end())
			{
				continue;
			}
			m[{a, b}]++;

			// 물통 a에 물을 가득 채운다.
			q.push({af, b});
			// 물통 b에 물을 가득 채운다.
			q.push({ a, bf });

			// 물통 a의 물을 모두 버린다.
			q.push({ 0, b });
			// 물통 b의 물을 모두 버린다.
			q.push({ a, 0 });

			// 물통 a의 물을 b에 붓는다.
			if (a <= bf - b)
			{
				q.push({ 0, b + a });
			}
			else
			{
				q.push({ a - (bf - b), bf });
			}
			// 물통 b의 물을 a에 붓는다.
			if (b <= af - a)
			{
				q.push({ a + b, 0 });
			}
			else
			{
				q.push({ af, b - (af - a) });
			}
		}
		if (isEnd) break;
		ret2++;
	}
	if (isEnd) cout << ret2;
	else cout << -1;
}