#include <bits/stdc++.h>
using namespace std;

int n, m;	// 1보다 크거나 같고 100000보다 작거나 같은 자연수
string inputStr[100004];
map<string, int> ma;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> inputStr[i];
		ma[inputStr[i]] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		int a = atoi(input.c_str());
		// 문자인 경우
		if (a == 0)
		{
			cout << ma[input.c_str()] << '\n';
		}
		else
		{
			cout << inputStr[a - 1] << '\n';
		}
	}
}