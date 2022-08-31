#include <bits/stdc++.h>
using namespace std;

int n, d, ret;
map<int, int> parent;
map<int, vector<int>> mp;

void clearChild(int c, int depth)
{
	if (mp.find(c) != mp.end())
	{
		int size = mp[c].size();
		for (int i = 0; i < size; i++)
		{
			int child = mp[c][i];
			clearChild(child, depth + 1);
		}
		mp.erase(c);
		if (depth == 0 && mp.find(parent[c]) != mp.end())
		{
			auto f = find(mp[parent[c]].begin(), mp[parent[c]].end(), c);
			if (f != mp[parent[c]].end())
				mp[parent[c]].erase(f);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		mp[i];
		if (input == -1) continue;
		mp[input].push_back(i);
		parent[i] = input;
	}
	cin >> d;
	clearChild(d, 0);
	for (auto it : mp)
	{
		if (it.second.size() == 0)
		{
			ret++;
		}
	}
	cout << ret << '\n';
}