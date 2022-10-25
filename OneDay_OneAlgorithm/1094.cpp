#include <bits/stdc++.h>
using namespace std;

int x, ret, sum;

void dfs(int sum, int mul, int cnt)
{
	if (sum > 64) return;
	if (mul > 64) return;
	if (sum == x)
	{
		ret = cnt;
	}

	mul *= 2;
	dfs(sum + mul, mul, cnt + 1);
	dfs(sum, mul, cnt);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> x;

	if (x % 2 == 0)
		dfs(0, 1, 0);
	else
		dfs(1, 1, 1);

	cout << ret;
}