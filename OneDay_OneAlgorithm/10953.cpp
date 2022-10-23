#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout << stoi(s.substr(0, 1)) + stoi(s.substr(2)) << '\n';
	}
}