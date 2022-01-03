#include <iostream>
#include <vector>
using namespace std;

int Type1(int n);
int Type2(int n);
int Type3(int n);
int Type4(int n);
int Type5(int n);
int Type6(int n);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// a, b, c
	// a, c, b
	// b, a, c
	// b, c, a
	// c, a, b
	// c, b, a

	std::vector<int> counts;
	
	counts.push_back(Type1(n));
	counts.push_back(Type2(n));
	counts.push_back(Type3(n));
	counts.push_back(Type4(n));
	counts.push_back(Type5(n));
	counts.push_back(Type6(n));

	int min = counts[0];
	for (int i = 0; i < counts.size(); i++)
	{
		if (min > counts[i])
			min = counts[i];
	}

	cout << min;

	return 0;
}

int Type1(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}

		if (n % 3 == 0)
		{
			n /= 3;
		}
		else if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}

int Type2(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}

		if (n % 3 == 0)
		{
			n /= 3;
		}
		else if (n % 2 == 0)
		{
			if (count == 0)
				n -= 1;
			else
				n /= 2;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}

int Type3(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}
		
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else if (n % 3 == 0)
		{
			n /= 3;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}

int Type4(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}

		if (n % 2 == 0)
		{
			n /= 2;
		}
		else if (n % 3 == 0)
		{
			if (count == 0)
				n -= 1;
			else
				n /= 3;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}

int Type5(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}

		if (count == 0)
		{
			n -= 1;
			count++;
			continue;
		}

		if (n % 2 == 0)
		{
			n /= 2;
		}
		else if (n % 3 == 0)
		{
			n /= 3;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}

int Type6(int n)
{
	int count = 0;

	while (true)
	{
		if (n == 1)
		{
			break;
		}

		if (count == 0)
		{
			n -= 1;
			count++;
			continue;
		}

		if (n % 3 == 0)
		{
			n /= 3;
		}
		else if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n -= 1;
		}

		count++;
	}

	return count;
}
