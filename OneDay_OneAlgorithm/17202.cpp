#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	string str;
	for (int i = 0; i < 8; i++)
	{
		str += a[i];
		str += b[i];
	}

	// 16글자이므로 15번
	for (int i = 0; i < 14; i++)
	{
		string temp;
		for (int j = 0; j < str.size() - 1; j++)
		{
			int first = str[j] - '0';
			int second = str[j + 1] - '0';
			temp += to_string((first + second) % 10);
		}
		str = temp;
	}

	cout << str[0] << str[1];

	return 0;
}