#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret;
int now = 1, nex;
vector<int> a[11];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	cin >> j;
	m--;
	vector<int> apple;
	for (int i = 0; i < j; i++)
	{
		int input;
		cin >> input;
		apple.push_back(input);
	}

	for (int i = 0; i < j; i++)
	{
		nex = apple[i];

		if (nex >= now && nex <= now + m)
		{
			// °¡¸¸È÷
		}
		else if (now < nex)
		{
			ret += ((nex - m) - now);
			now = nex - m;
		}
		else if (now > nex)
		{
			ret += (now - nex);
			now = nex;
		}
	}
	cout << ret << '\n';
}