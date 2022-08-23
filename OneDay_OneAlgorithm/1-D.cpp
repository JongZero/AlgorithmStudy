#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	cin >> s;

	string rev = s;
	reverse(rev.begin(), rev.end());

	if (s == rev)
		cout << 1;
	else
		cout << 0;
}