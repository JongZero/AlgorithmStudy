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
			// ����(a,e,i,o,u) �ϳ��� �ݵ�� �����ϴ°�?
			if (mp.find(c) != mp.end())
			{
				isOneAEIOU = true;
				break;
			}
		}
		if (isOneAEIOU == false)
		{
			isAcceptable = false;
			//cout << "s : " << s << " ���� �ϳ��� ���� ����" << "\n";
		}
		for (char c : s)
		{
			// ������ 3�� Ȥ�� ������ 3�� �������� ���°�?
			if (check.size() >= 3)
			{
				// �տ� �ϳ� ����
				check = check.substr(1);
			}
			check += c;
			if (check.size() == 3)
			{
				bool isSame = true;
				bool isAEIOU = true;
				if (mp.find(check.front()) == mp.end())
					isAEIOU = false;	// ���� �˻�
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
					//cout << "s : " << s << "���� 3�� Ȥ�� ���� 3�� �������� ��" << "\n";
					break;
				}
			}

			// ���� ���ڰ� ���������� �ι� ���°�?
			if (prev != 0)
			{
				if (prev == c)
				{
					if (prev != 'e' && prev != 'o')
					{
						//cout << "s : " << s << "���� ���ڰ� ���������� �ι� ��, prev : " << prev << "\n";
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