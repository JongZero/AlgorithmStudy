#include <bits/stdc++.h>
using namespace std;

int x, n, total;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> x >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		total += (a * b);
	}
	if (total == x)
		cout << "Yes";
	else
		cout << "No";
}