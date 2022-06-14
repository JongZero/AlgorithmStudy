#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<std::tuple<int, int, int>, int> g_Map;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		std::tuple<int, int, int> p = make_tuple(a, b, c);

		if (g_Map.count(p) == 0)
		{
			g_Map[p] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		}

		return g_Map[p];
	}
	else
	{
		std::tuple<int, int, int> p = make_tuple(a, b, c);

		if (g_Map.count(p) == 0)
		{
			g_Map[p] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}

		return g_Map[p];
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a{ 0 }, b{ 0 }, c{ 0 };

	while (true)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		int result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}

	return 0;
}