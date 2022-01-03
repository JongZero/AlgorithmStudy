#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string s;
	cin >> s;

	s += "??!";

	cout << s;

	return 0;
}