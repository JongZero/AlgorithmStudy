#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		// 첫 번째 숫자가 두 번째 숫자의 약수
		if (b % a == 0)
		{
			cout << "factor" << "\n";
		}
		else if (a % b == 0)
		{
			cout << "multiple" << "\n";
		}
		else
		{
			cout << "neither" << "\n";
		}
	}
	
	return 0;
}