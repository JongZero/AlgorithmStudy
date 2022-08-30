#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		map<string, int> mp;
		for (int i = 0; i < n; i++)
		{
			string name, type;
			cin >> name >> type;
			mp[type]++;
		}
		long long ret = 1;
		for (auto it : mp)
		{
			ret *= (long long)it.second + 1;
		}
		ret--;
		cout << ret << "\n";
	}
}