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
		long long ret = 1;	// 경우의 수는 수가 매우 커질 수 있으므로 long long
		for (auto it : mp)
		{
			ret *= (long long)it.second + 1;	// 벗는 경우의 수 고려해서 +1
		}
		ret--;	// 아무것도 안입는 경우의 수 제외
		cout << ret << '\n';
	}
}