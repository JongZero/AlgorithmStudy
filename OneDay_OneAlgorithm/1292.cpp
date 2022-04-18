#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A(0), B(0);
	std::cin >> A >> B;

	int sum = 0;
	int count = 0;
	for (int i = 1; i <= B; i++)
	{
		for (int j = 0; j < i; j++)
		{
			count++;

			if (count >= A && count <= B)
			{
				sum += i;
			}
		}
	}

	std::cout << sum;

	return 0;
}