#include <iostream>
#include <vector>
#include <string>

using namespace std;
long long dpArray[1000001] = { 0, };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// 1	1
	// 2	00 11
	// 3	001 100 111 2 + 1
	// 4	0000 0011 1001 1100 1111 1 + 3 + 1
	// 5	00001 00100 10000 00111 11100 10011 11001 11111 3 + 4 + 1
	// 6	000000 000011 001100 110000 100100 100001 001111 110011 111100 100111 111001 111111 1 + 4 + 5 + 1
	// 7	0000001 0000100 0010000 1000000 

	dpArray[1] = 1;
	dpArray[2] = 2;

	int k = 15746;

	for (int i = 3; i <= n; i++)
	{
		dpArray[i] = ((dpArray[i - 1] % k) + (dpArray[i - 2] % k)) % k;
	}

	cout << dpArray[n];

	return 0;
}