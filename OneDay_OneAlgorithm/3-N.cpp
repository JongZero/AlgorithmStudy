#include <bits/stdc++.h>
using namespace std;

int k, root;
string s;
vector<int> a[11];
int now[11];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> k;
	int size = (int)pow(2, k) - 1;
	root = (size + 1) / 2;
	int temp = root / 2;
	for (int i = 2; i <= k - 1; i++)
	{
		now[i] = temp;
		temp /= 2;
	}
	for (int i = 1; i <= size; i++)
	{
		int t;
		cin >> t;

		if (i % 2 == 1)
		{
			a[k].push_back(t);
		}
		else if (i == root)
		{
			a[1].push_back(t);
		}
		else
		{
			for (int j = 2; j <= k - 1; j++)
			{
				if (now[j] == i)
				{
					a[j].push_back(t);
					now[j] = now[j] + (int)pow(2, (k - j + 1));
					break;
				}
			}
		}
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j : a[i])
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
}