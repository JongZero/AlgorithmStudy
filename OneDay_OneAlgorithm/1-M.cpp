#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	cin >> n;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		// 일단 홀수면 안됨
		if (s.size() % 2 == 1)
			continue;

		char nowOpen = s[0];
		int count = 0;
		for (int j = 1; j < s.size(); j++)
		{
			if (nowOpen == 0)
			{
				nowOpen = s[j];
				continue;
			}
			
			if (nowOpen == s[j])
			{
				nowOpen = 0;
				if (count % 2 == 1)
					break;
				count = 0;
			}
			else
			{
				count++;
			}
		}
		if (count % 2 == 1)
		{
			// 데칼코마니면 가능
			string temp = s.substr(0, s.size() / 2);
			string check = s.substr(s.size() / 2);
			reverse(temp.begin(), temp.end());
			if (temp == check)
				ret++;
			else
				continue;
		}
		else
		{
			ret++;
		}
	}

	cout << ret;
}