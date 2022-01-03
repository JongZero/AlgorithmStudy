#include <iostream>
using namespace std;

int main()
{
	int a = 0;

	cin >> a;

	if (a < 60)
		cout << "F";
	else if (a >= 60)
	{
		if (a >= 90)
			cout << "A";
		else if (a >= 80)
			cout << "B";
		else if (a >= 70)
			cout << "C";
		else
			cout << "D";
	}

	return 0;
}