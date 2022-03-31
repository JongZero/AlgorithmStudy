#include <iostream>
#include <math.h>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		int mul = 1;
		char mulChar = '1';
		for (int j = 0; j < b; j++)
		{
			mul = mulChar - '0';
			mul = a * a;
			mulChar = mul + '0';
		}


		int comNum = num % 10;

		if (comNum == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			std::cout << comNum << '\n';
		}
	}

	return 0;
}