#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	map<char, int> mp;
	mp['a'] = 1;
	mp['e'] = 1;
	mp['i'] = 1;
	mp['o'] = 1;
	mp['u'] = 1;

	char prev = 0;

	while (true)
	{
		string s;
		cin >> s;
		if (s == "end") break;

		bool isOneAEIOU = false;
		bool isAcceptable = true;
		string check;
		for (char c : s)
		{
			// 모음(a,e,i,o,u) 하나를 반드시 포함하는가?
			if (mp.find(c) != mp.end())
			{
				isOneAEIOU = true;
				break;
			}
		}
		if (isOneAEIOU == false)
		{
			isAcceptable = false;
			//cout << "s : " << s << " 모음 하나도 포함 안함" << "\n";
		}
		for (char c : s)
		{
			// 모음이 3개 혹은 자음이 3개 연속으로 오는가?
			if (check.size() >= 3)
			{
				// 앞에 하나 지움
				check = check.substr(1);
			}
			check += c;
			if (check.size() == 3)
			{
				bool isSame = true;
				bool isAEIOU = true;
				if (mp.find(check.front()) == mp.end())
					isAEIOU = false;	// 자음 검사
				for (int i = 1; i < 3; i++)
				{
					if (isAEIOU)
					{
						if (mp.find(check[i]) == mp.end())
						{
							isSame = false;
							break;
						}
					}
					else
					{
						if (mp.find(check[i]) != mp.end())
						{
							isSame = false;
							break;
						}
					}
				}
				if (isSame)
				{
					isAcceptable = false;
					//cout << "s : " << s << "모음 3개 혹은 자음 3개 연속으로 옴" << "\n";
					break;
				}
			}

			// 같은 글자가 연속적으로 두번 오는가?
			if (prev != 0)
			{
				if (prev == c)
				{
					if (prev != 'e' && prev != 'o')
					{
						//cout << "s : " << s << "같은 글자가 연속적으로 두번 옴, prev : " << prev << "\n";
						isAcceptable = false;
						break;
					}
				}
			}

			prev = c;
		}

		string ret = "<";
		ret += s;
		ret += "> is ";
		if (isAcceptable)
		{
			ret += "acceptable.";
		}
		else
		{
			ret += "not acceptable.";
		}
		cout << ret << "\n";
	}
}