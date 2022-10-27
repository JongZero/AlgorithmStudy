#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		string t;
		cin >> t;
		if (t == "0") break;

		stack<char> s;
		for (int i = 0; i < t.size(); i++)
		{
			if (s.size() > 0)
			{

			}
			
			s.push(t[i]);
		}
	}
}