#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;	// 음수인 경우도 생각 ex) 1-3 = -2가 최대임.
vector<int> num;
vector<char> oper;

int calc(char o, int a, int b)
{
	if (o == '+') return a + b;
	if (o == '-') return a - b;
	if (o == '*') return a * b;
}

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
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	func(0, num[0]);
	cout << ret;
}