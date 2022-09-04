#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> num;
vector<char> oper;

bool check(char oper, int n1, int n2)
{
	if (oper == '<') return n1 < n2;
	else return n1 > n2;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> k;
	string s;
	cin.ignore(1);
	getline(cin, s);
	for (char c : s)
	{
		if (c != ' ') oper.push_back(c);
	}

	for (int i = 0; i <= 9; i++) num.push_back(i);
	vector<string> ret;
	do
	{
		string temp;
		bool isTrue = true;
		for (int i = 0; i < k; i++)
		{
			temp += to_string(num[i]);
			isTrue = check(oper[i], num[i], num[i + 1]);
			if (!isTrue) break;
		}
		if (isTrue)
		{
			temp += to_string(num[k]);
			ret.push_back(temp);
		}
	} while (next_permutation(num.begin(), num.end()));
	sort(ret.begin(), ret.end());
	cout << ret.back() << '\n' << ret.front();
}