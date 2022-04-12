#include <iostream>

int g_Index = 0;

int Fibo(int index, int n1, int n2)
{
	// 0이라면
	if (0 == g_Index)
	{
		return 0;
	}
	else if (index == g_Index)
	{
		return n2;
	}
	else
	{
		index++;
		return Fibo(index, n2, n1 + n2);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> g_Index;

	// 2부터 시작 
	int result = Fibo(1, 0, 1);

	std::cout << result;

	return 0;
}