#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	while (true)
	{
		getline(cin, s);
		if (s == ".") break;

		bool isYes = true;
		stack<char> stk;
		for (char c : s)
		{
			if (c == '(' || c == ')' || c == '[' || c == ']')
			{
				if (c == '(' || c == '[')
				{
					stk.push(c);
				}
				else
				{
					if (stk.size())
					{
						if (stk.top() == '(' && c == ')')
						{
							stk.pop();
						}
						else if (stk.top() == '[' && c == ']')
						{
							stk.pop();
						}
						else
						{
							isYes = false;
							break;
						}
					}
					else
					{
						isYes = false;
						break;
					}
				}
			}
		}
		if (isYes && stk.size() == 0)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
}