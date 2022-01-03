#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int t = 0;

	for (int i = 1; i <= n; i++)
	{
		t += i;
	}

	cout << t;
	return 0;
}