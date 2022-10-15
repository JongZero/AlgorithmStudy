#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> m;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	vector<int> ori = v;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		m[v[i]] = i;
	}

	for (int i = 0; i < ori.size(); i++)
	{
		cout << m[ori[i]] << ' ';
	}
}