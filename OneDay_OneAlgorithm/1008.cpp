#include <iostream>
using namespace std;

int main()
{
	int a, b = 0;

	cin >> a >> b;
	
	cout << fixed;		// �Ҽ��� �Ʒ��� ����
	cout.precision(9);	// ���� ���� ��ü 9�ڸ� ǥ��
	
	cout << (double)a / (double)b;
	return 0;
}