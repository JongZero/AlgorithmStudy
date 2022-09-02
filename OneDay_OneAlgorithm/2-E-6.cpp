#include <bits/stdc++.h>
using namespace std;

int n;
char a[65][65];

string quad(int sy, int sx, int size)
{
	if (size == 1) return string(1, a[sy][sx]);
	char s = a[sy][sx];
	for (int i = sy; i < sy + size; i++)
	{
		for (int j = sx; j < sx + size; j++)
		{
			if (s != a[i][j])
			{
				size /= 2;
				string ret = "(";
				ret += quad(sy, sx, size);
				ret += quad(sy, sx + size, size);
				ret += quad(sy + size, sx, size);
				ret += quad(sy + size, sx + size, size);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, s);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}
	cout << quad(0, 0, n);
}