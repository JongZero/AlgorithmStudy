#include <iostream>
#include <string>
using namespace std;

/// 11720
// ����
// N���� ���ڰ� ���� ���� �����ִ�.�� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ������ ���� N(1 �� N �� 100)�� �־�����.��° �ٿ� ���� N���� ������� �־�����.
// 
// ���
// �Է����� �־��� ���� N���� ���� ����Ѵ�.

int main()
{
	int n = 0;

	cin >> n;

	string inputNumber;

	cin >> inputNumber;

	int sum = 0;
	for (int i = 0; i < inputNumber.size(); i++)
	{
		// char to int
		int now = inputNumber[i] - '0';

		sum += now;
	}

	cout << sum;

	return 0;
}