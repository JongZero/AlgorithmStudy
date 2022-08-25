#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;
		map<string, int> mp;
		for (int j = 0; j < n; j++)
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
		// 모두 다 벗으면 안되므로 1개의 경우의 수는 제외
		ret--;
		cout << ret << '\n';
	}
}