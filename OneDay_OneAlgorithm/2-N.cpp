#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		bool isVPS = false;
		string s;
		cin >> s;
		stack<char> stk;
		for (char c : s)
		{
			if (stk.size() && stk.top() == '(' && stk.top() != c) stk.pop();
			else stk.push(c);
		}
		if (stk.size() == 0) isVPS = true;
		if (isVPS) cout << "YES" << '\n';
		else cout << "NO" << "\n";
	}
}