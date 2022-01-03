#include <iostream>
using namespace std;

int main()
{
	int n = -1;
	int count = 0;

	while (true)
	{
		cin >> n;

		int originalNum = n;

		while (true)
		{
			// 6
			int n1 = n % 10;

			// 20
			int n10 = n - n1;

			// 2
			int n10_1 = n10 /= 10;

			// 60
			int new_n10 = n1 * 10;

			// 8
			int new_n1 = n1 + n10_1;

			if (new_n1 >= 10)
			{
				new_n1 -= 10;
			}

			// 68
			int newNum = new_n10 + new_n1;

			n = newNum;
			count++;

			if (originalNum == newNum)
				break;
		}

		cout << count << endl;
		break;
	}

	return 0;
}