#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int y = 0;
	std::cin >> y;

	int convert = 2541 - 1998;
	std::cout << y - convert;

	return 0;
}