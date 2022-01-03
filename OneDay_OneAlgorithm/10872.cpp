#include <iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 1;

	return n * factorial(n - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	int result = factorial(n);
	cout << result;

	return 0;
}