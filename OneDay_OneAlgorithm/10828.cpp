#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int stack[10000] = { 0, };

	int n = 0;
	cin >> n;

	cin.ignore();

	int index = 0;	// push할 때 숫자가 들어가야 할 배열의 위치
	int top = -1;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		// push
		if (input[0] == 'p' && input[1] == 'u')
		{
			int numberStartIndex = input.find(' ');
			string addNumStr = input.substr(numberStartIndex + 1, input.size() - 1);

			int addNum = stoi(addNumStr);

			stack[index] = addNum;
			index++;

			top = addNum;

			size++;
		}
		// pop
		else if (input[0] == 'p' && input[1] == 'o')
		{
			if (index <= 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				index--;

				cout << stack[index] << '\n';

				stack[index] = 0;

				size--;

				if (index > 0)
				{
					top = stack[index - 1];
				}
				else
				{
					top = -1;
				}
			}
		}
		// size
		else if (input[0] == 's' && input[1] == 'i')
		{
			cout << size << '\n';
		}
		// empty
		else if (input[0] == 'e' && input[1] == 'm')
		{
			if (size > 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
		else
		{
			cout << top << '\n';
		}
	}

	return 0;
}