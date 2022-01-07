#include <iostream>
using namespace std;

int g_FiboNums[21] = { 0, 1, };

int Fibo(int n)
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
		return Fibo(n - 2) + Fibo(n - 1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	int result = Fibo(n);

	cout << result;

	return 0;
}
