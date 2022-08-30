#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	int now = 666;
	int cnt = 1;
	while (true)
	{
		if (n == cnt)
			break;

		now++;

		string s = to_string(now);
		if (s.find("666") != string::npos)
			cnt++;
	}
	cout << now;
}