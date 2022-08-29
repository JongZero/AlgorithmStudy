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
			// 다른 게 있다면 4개로 다시 분할
			if (a[i][j] != s)
			{
				size /= 2;
				string ret;
				ret += '(';
				ret += quad(sy, sx, size);
				ret += quad(sy, sx + size, size);
				ret += quad(sy + size, sx, size);
				ret += quad(sy + size, sx + size, size);
				ret += ')';
				return ret;
			}
		}
	}
	// 다른 게 없고 모두 같다면
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
	cout << quad(0, 0, n) << "\n";
}