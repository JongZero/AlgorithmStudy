#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int n = 10;
int a[11][11];
int c[6], ret = 987654321;

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
				return false;
		}
	}
	return true;
}

bool isAttach(int y, int x, int t)
{
	if (y + t > n || x + t > n) return false;
	for (int i = y; i < y + t; i++)
	{
		for (int j = x; j < x + t; j++)
		{
			if (a[i][j] == 0)
				return false;
		}
	}
	//cout << y << ", " << x << "에 " << t << "사이즈 색종이 붙일 수 있다\n";
	return true;
}

void attach(int y, int x, int t)
{
	for (int i = y; i < y + t; i++)
	{
		for (int j = x; j < x + t; j++)
		{
			a[i][j] = 0;
		}
	}
}

void detach(int y, int x, int t)
{
	for (int i = y; i < y + t; i++)
	{
		for (int j = x; j < x + t; j++)
		{
			a[i][j] = 1;
		}
	}
}

void func(int y, int x)
{
	int temp = 0;
	for (int i = 1; i <= 5; i++)
	{
		temp += c[i];
	}
	if (temp >= ret) return;

	if (check())
	{
		ret = min(ret, temp);
		return;
	}

	if (x == n)
	{
		func(y + 1, 0);
		return;
	}

	if (a[y][x] == 0)
	{
		func(y, x + 1);
		return;
	}

	// 1 ~ 5번 색종이를 붙여본다.
	for (int k = 5; k >= 1; k--)
	{
		if (isAttach(y, x, k))
		{
			if (c[k] >= 5)
				continue;

			// 붙일 수 있다면 붙이고 넘긴다.
			attach(y, x, k);
			c[k]++;
			func(y, x + k);
			detach(y, x, k);
			c[k]--;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	func(0, 0);
	if (ret == 987654321) cout << -1;
	else cout << ret;
}