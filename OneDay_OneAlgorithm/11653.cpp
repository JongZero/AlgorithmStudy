#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	while (true)
	{
		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << "\n";
				n = n / i;
				break;
			}
		}

		if (n <= 1)
		{
			break;
		}
	}

	return 0;
}