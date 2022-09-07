#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9;
int a[17][17];

int test = 1 << 16;

vector<int> now;
void func(int depth, int r, int sum, int prev)
{
	//if (sum >= ret) return;
	if (depth == r)
	{
		for (int ii : now)
		{
			cout << ii << ' ';
		}
		cout << '\n';
		cout << "sum : " << sum << '\n';
		ret = min(ret, sum);
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(now[i], now[depth]);
		func(depth + 1, r, sum + a[prev][i], i);
		swap(now[i], now[depth]);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> a[i][j];
	//	}
	//}
	//cout << '\n';

	cout << test;

	//for (int i = 0; i < n; i++) now.push_back(i);
	//func(0, n, 0, 0);
	//cout << ret;
}