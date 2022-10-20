#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> s;
	while (s.size())
	{
		int si = s.size();
		if (si > 10)
			si = 10;

		cout << s.substr(0, si) << '\n';
		s.erase(0, si);
	}
}