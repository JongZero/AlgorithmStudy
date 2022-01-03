#include <iostream>
using namespace std;

int Fibo(int n, int n1, int n2)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{

	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	int sum = 1;
	int result = Fibo(n);

	cout << result;

	return 0;
}