#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		mp[s[i]]++;
	}

	char h = 0;
	string result;
	string temp;
	for (auto& it : mp)
	{
		int count = it.second;
		for (int i = 0; i < count / 2; i++)
		{
			temp += it.first;
		}
		if (it.second % 2 == 1)
		{
			if (h == 0)
			{
				h = it.first;
			}
			else
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
			
	}
	result = temp;
	reverse(temp.begin(), temp.end());

	if (h != 0)
	{
		result += h;
	}
	result += temp;

	cout << result;
}