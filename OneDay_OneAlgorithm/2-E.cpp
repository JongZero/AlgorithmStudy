#include <bits/stdc++.h>
using namespace std;

int n;
char a[68][68];

string quad(int k, int sy, int sx)
{
	if (k == 1) return string(1, a[sy][sx]);
	char b = a[sy][sx];
	string ret;
	for (int i = sy; i < sy + k; i++)
	{
		for (int j = sx; j < sx + k; j++)
		{
			if (b != a[i][j])
			{
				k /= 2;
				ret += '(';
				ret += quad(k, sy, sx);
				ret += quad(k, sy, sx + k);
				ret += quad(k, sy + k, sx);
				ret += quad(k, sy + k, sx + k);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, a[sy][sx]);
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
	cout << quad(n, 0, 0);
}