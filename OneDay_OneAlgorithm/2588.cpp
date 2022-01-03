#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;

	// 들어올 a, b는 세자리 수
	cin >> a >> b;
	
	// b의 일의 자리
	int c1 = b % 10;
	
	// b의 십의 자리
	int c10 = b % 100 - c1;
	c10 = c10 / 10;

	// b의 백의 자리
	int c100 = b - (c10 * 10) - c1;
	c100 = c100 / 100;
	
	// 결과 1
	int r1 = c1 * a;
	
	// 결과 2
	int r2 = c10 * a;

	// 결과 3
	int r3 = c100 * a;

	// 결과 4
	int r4 = a * b;

	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;

	return 0;
}