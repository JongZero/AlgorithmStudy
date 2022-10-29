#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		string t;
		cin >> t;
		if (t == "0") break;

		string s = t.substr(0, t.size() / 2);
		string e;
		if (t.size() % 2 == 0)
			e = t.substr(t.size() / 2);
		else
			e = t.substr(t.size() / 2 + 1);

		reverse(e.begin(), e.end());
		if (s == e)
			cout << "yes";
		else
			cout << "no";
		cout << '\n';
	}
}