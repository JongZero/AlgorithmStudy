#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	cout << (n * m) - 1;
	
	return 0;
}