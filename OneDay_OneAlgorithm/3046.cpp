#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int r1, s;
	cin >> r1 >> s;

	int r2 = 2 * s - r1;
	cout << r2;

	return 0;
}