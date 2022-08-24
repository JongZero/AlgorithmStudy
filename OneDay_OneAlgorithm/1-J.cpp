#include <bits/stdc++.h>
using namespace std;

vector<string> now;
void combi(int n, int r, int start, 
	const vector<string>& input,
	map<string, int>& mp, int& result)
{
	if (n == r)
	{
		int temp = 1;
		for (auto it : mp)
		{
			temp *= it.second;
		}
		result += temp;
		return;
	}

	if (now.size() == r)
	{
		int temp = 1;
		for (int i = 0; i < r; i++)
		{
			temp *= mp[now[i]];
		}
		result += temp;
	}
	for (int i = start + 1; i < n; i++)
	{
		now.push_back(input[i]);
		combi(n, r, i, input, mp, result);
		now.pop_back();
	}
}

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

		vector<string> input;
		map<string, int> mp;
		for (int j = 0; j < n; j++)
		{
			string name, type;
			cin >> name >> type;

			if (mp[type] == 0)
			{
				input.push_back(type);
			}

			mp[type]++;
		}

		int result = n;
		if (mp.size() > 1)
		{
			for (int j = 2; j <= mp.size(); j++)
			{
				combi(mp.size(), j, -1, input, mp, result);
			}
		}
		cout << result << '\n';
	}
}