#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;
vector<char> oper;
string s;

int calc(char op, int n1, int n2)
{
	if (op == '+') return n1 + n2;
	if (op == '-') return n1 - n2;
	if (op == '*') return n1 * n2;
}

int ret = -1e9;
void func(int idx, int tempRet)
{
	if (idx >= num.size() - 1)
	{
		ret = max(ret, tempRet);
		return;
	}
	int te = calc(oper[idx], tempRet, num[idx + 1]);
	func(idx + 1, te);
	if (idx + 2 <= num.size() - 1)
	{
		int temp = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
		func(idx + 2, calc(oper[idx], tempRet, temp));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	cin >> s;
	for (char c : s)
	{
		if ('0' <= c && c <= '9') num.push_back(c - '0');
		else oper.push_back(c);
	}
	func(0, num[0]);
	cout << ret;
}