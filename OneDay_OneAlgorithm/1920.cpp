#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> ma;

int n, m;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		ma[t] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if (ma.find(t) != ma.end())
			cout << "1\n";
		else
			cout << "0\n";
	}
}