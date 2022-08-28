#include <bits/stdc++.h>
using namespace std;

int n, c;

struct Num
{
	int n = 0;
	int order = 0;
	int count = 0;
	static int order_s;

	Num(int _n) : n(_n) { order = order_s; order_s++; }

	bool operator < (const Num& a) const
	{
		if (count == a.count)
			return order < a.order;	// 오름차순, 작은 것이 앞에

		return count > a.count;	// 내림차순
	}
};
int Num::order_s = 0;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> c;
	vector<Num> v;
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		if (mp[input] == 0)
		{
			Num num(input);
			v.push_back(num);
		}

		mp[input]++;
	}
	for (Num& num : v)
	{
		num.count = mp[num.n];
	}
	sort(v.begin(), v.end());
	for (Num num : v)
	{
		for (int i = 0; i < num.count; i++)
		{
			cout << num.n << " ";
		}
	}
}