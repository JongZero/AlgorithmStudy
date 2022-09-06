#include <bits/stdc++.h>
using namespace std;

int n, ret = -1e9;
vector<int> num;
vector<char> oper;

int calc(char oper, int n1, int n2)
{
	if (oper == '+') return n1 + n2;
	if (oper == '-') return n1 - n2;
	if (oper == '*') return n1 * n2;
}

void func(int idx, int nowRet)
{
	if (idx >= num.size() - 1)
	{
		ret = max(ret, nowRet);
		return;
	}
	func(idx + 1, calc(oper[idx], nowRet, num[idx + 1]));
	if (idx + 2 <= num.size() - 1)
	{
		int temp = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
		func(idx + 2, calc(oper[idx], nowRet, temp));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	string s;
	cin >> s;
	for (char c : s)
	{
		if ('0' <= c && c <= '9') num.push_back(c - '0');
		else oper.push_back(c);
	}
	func(0, num[0]);
	cout << ret;
}