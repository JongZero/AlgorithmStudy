#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

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

		long long result = 1;
		for (auto it : mp)
		{
			result *= ((long long)it.second + 1);
		}
		// 모두 벗는 경우의 수를 제외
		result--;
		cout << result << '\n';
	}
}