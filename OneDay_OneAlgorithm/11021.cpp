#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0;

		cin >> a >> b;

		cout << "Case #" << i + 1 << ": " << a + b << "\n";
	}

	return 0;
}