#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int price[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> price[i];
	}

	int ham = 2000;
	for (int i = 0; i < 3; i++)
	{
		if (ham > price[i])
		{
			ham = price[i];
		}
	}

	int drink = price[3];
	if (price[3] > price[4])
	{
		drink = price[4];
	}

	cout << ham + drink - 50;

	return 0;
}