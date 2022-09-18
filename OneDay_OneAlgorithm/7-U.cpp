#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c, a[31], visited[31];
ll ret;
void func(int nowC, int start)
{
	if (nowC > c) return;
	ret++;
	for (int i = start + 1; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		func(nowC + a[i], i);
		visited[i] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	func(0, -1);
	cout << ret;
}