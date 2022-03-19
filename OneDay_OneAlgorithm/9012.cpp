#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int stack[51] = { 0, };

		std::string input;
		std::cin >> input;

		int nowIndex = 0;
		int stackSize = 0;
		bool isClose = false;
		for (int k = 0; k < input.size(); k++)
		{
			if (input[i] == '(')
			{
				stack[nowIndex] = 1;
				nowIndex++;
				stackSize++;
				isClose = false;

				if (isClose == true)
				{
					break;
				}
			}
			else if (stackSize > 0)
			{
				isClose = true;
				stack[nowIndex - 1] = 0;
				nowIndex--;
				stackSize--;
			}
		}

		if (stackSize == 0)
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}



	return 0;
}