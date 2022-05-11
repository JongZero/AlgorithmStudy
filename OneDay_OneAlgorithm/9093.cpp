#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++)
	{
		string input;
		getline(cin, input);

		for (int j = 0; j < input.size(); j++)
		{
			char temp = input[j];
			if (temp != ' ')
			{
				stack<char> tempStack;
				for (int k = j; k < input.size(); k++, j++)
				{
					if (input[k] != ' ')
						tempStack.push(input[k]);
					else
						break;
				}

				string resultStr;
				while (!tempStack.empty())
				{
					resultStr += tempStack.top();
					tempStack.pop();
				}

				cout << resultStr << ' ';
			}
		}

		cout << '\n';
	}

	return 0;
}