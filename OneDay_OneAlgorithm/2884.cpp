#include <iostream>
using namespace std;

int main()
{
	int h = 0, m = 0;
	cin >> h >> m;

	int t = 45;

	// ���� 45���� ���� ���
	if (m < t)
	{
		h -= 1;
		m += 15;
	}
	else
	{
		m -= 45;
	}

	if (h < 0)
		h = 23;

	cout << h << endl;
	cout << m << endl;

	return 0;
}