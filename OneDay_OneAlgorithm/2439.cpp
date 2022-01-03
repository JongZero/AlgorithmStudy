#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < n - i; k++)
		{
			cout << " ";
		}

		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}