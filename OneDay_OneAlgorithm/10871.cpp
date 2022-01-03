#include <iostream>
using namespace std;

int main()
{
	int n = 0, x = 0;

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int j = 0;

		cin >> j;

		if (j < x)
			cout << j << " ";
	}

	return 0;
}