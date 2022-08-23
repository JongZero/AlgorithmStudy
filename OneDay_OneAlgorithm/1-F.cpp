#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int c = (int)s[i] + 13;
			if (c - 26 >= 'a')
				cout << char(c - 26);
			else
				cout << char(c);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int c = (int)s[i] + 13;
			if (c - 26 >= 'A')
				cout << char(c - 26);
			else
				cout << char(c);
		}
		else
			cout << s[i];
	}
}