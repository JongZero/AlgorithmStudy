#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string input;
	cin >> input;

	const int alphabetCount = 'z' - 'a' + 1;
	int alphabets[alphabetCount] = { 0, };

	for (int i = 0; i < input.size(); i++)
	{
		alphabets[input[i] - 'a']++;
	}

	for (int i = 0; i < alphabetCount; i++)
	{
		cout << alphabets[i] << ' ';
	}
}