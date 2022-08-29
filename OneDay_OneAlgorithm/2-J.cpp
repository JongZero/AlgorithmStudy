#include <bits/stdc++.h>
using namespace std;

int h, w;
char a[101][101];
int ret[101][101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; j++)
		{
			a[i][j] = s[j];
		}
	}
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c = a[i][j];
			if (c == 'c')
			{
				int m = 0;
				for (int k = j; k < w; k++, m++)
				{
					ret[i][k] = m;
					if (m != 0 && ret[i][k] == 'c') break;
				}
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}