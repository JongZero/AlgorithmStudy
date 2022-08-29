#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ret;

bool cmp(const string& a, const string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();	// 작은 것이 앞에
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		string temp;
		for (char c : s)
		{
			if (c < 'a' || 'z' < c)
			{
				temp += c;
			}
			else
			{
				if (temp.size() > 0)
				{
					while (temp.size() > 1 && temp.front() == '0')
					{
						temp = temp.substr(1);
					}
					ret.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size() > 0)
		{
			while (temp.size() > 1 && temp.front() == '0')
			{
				temp = temp.substr(1);
			}
			ret.push_back(temp);
			temp = "";
		}
	}
	sort(ret.begin(), ret.end(), cmp);
	for (string s : ret)
	{
		cout << s << '\n';
	}
}