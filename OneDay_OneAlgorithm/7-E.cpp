#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[61][31][31];

ll func(int day, int w, int h, string s)
{
	//cout << "day: " << day << " w: " << w << " h: " << h << '\n';
	//cout << s << '\n';
	if (w < 0) return 0;
	if (h < 0) return 0;
	if (h < w) return 0;
	if (day >= n * 2)
	{
		if (w == 0 && h == 0) return 1;
		else return 0;
	}
	if (dp[day][w][h]) return dp[day][w][h];
	dp[day][w][h] += func(day + 1, w - 1, h, s + "w");
	dp[day][w][h] += func(day + 1, w, h - 1, s + "h");
	//cout << "day: " << day << " w: " << w << " h: " << h;
	//cout << " - dp: " << dp[day][w][h] << '\n';
	return dp[day][w][h];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		cout << func(1, n - 1, n, "w") << '\n';
	}
}