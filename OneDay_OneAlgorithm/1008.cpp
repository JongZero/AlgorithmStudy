#include <iostream>
using namespace std;

int main()
{
	int a, b = 0;

	cin >> a >> b;
	
	cout << fixed;		// 소수점 아래로 고정
	cout.precision(9);	// 정수 포함 전체 9자리 표현
	
	cout << (double)a / (double)b;
	return 0;
}