#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
double sum;
vector<int> a;
unordered_map<int, int> mp;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
		mp[t]++;
		sum += t;
	}

	sort(a.begin(), a.end());

	int nowMax = 0;
	vector<int> v;
	for (auto& it : mp)
	{
		if (it.second > nowMax)
		{
			nowMax = it.second;
			v.clear();
			v.push_back(it.first);
		}
		else if (it.second == nowMax)
		{
			v.push_back(it.first);
		}
	}
	sort(v.begin(), v.end());

	cout << floor(sum / (double)n + 0.5) << '\n';
	cout << a[a.size() / 2] << '\n';
	if (v.size() > 1) cout << v[1] << '\n';
	else cout << v[0] << '\n';
	cout << a.back() - a.front() << '\n';

	return 0;
}