#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> count(26);
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		char f = input.front();
		count[f - 'a']++;
	}

	bool isPick = false;
	for (int i = 0; i < 26; i++)
	{
		if (count[i] >= 5)
		{
			cout << char(i + 'a');
			isPick = true;
		}
	}

	if (isPick == false)
		cout << "PREDAJA";
}