#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

ll func(ll n, ll p)
{
	if (p == 1) return n % c;
	ll temp = func(n, p / 2);
	temp = (temp * temp) % c;
	if (p % 2 == 1)
		temp = (temp * a) % c;
	return temp;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b >> c;
	cout << func(a, b) << '\n';
}