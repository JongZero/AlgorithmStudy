#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	cin >> s;

	int pos = s.find('*');
	string start = s.substr(0, pos);
	string end = s.substr(pos + 1, s.size() - pos - 1);

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		if (input.size() < start.size() + end.size())
		{
			cout << "NE\n";
			continue;
		}

		string inputStart = input.substr(0, start.size());
		string inputEnd = input.substr(input.size() - end.size(), end.size());

		if (start == inputStart && end == inputEnd)
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NE\n";
		}
	}
}