#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

ll go(ll n, ll p)
{
	if (p == 1) return n % c;

	ll ret = go(n, p / 2);
	ret = (ret * ret) % c;

	if (p % 2 == 1)
	{
		ret = (ret * a) % c;
	}
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b >> c;
	cout << go(a, b);
}