#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 1<<10 �� 2�� 10�����ΰ�?
	int a = 1 << 10;
	cout << a <<'\n';
	cout << pow(2, 10) << '\n';
	// -> ��� : �´�

	// vector capacity�� ���ۿ� ���ؼ�
	vector<int> v;
	v.reserve(3);
	cout << v.capacity() << '\n';
	v.resize(4);
	cout << v.capacity() << '\n';

	// resize�� capacity�� ������ų �� �ƴ϶�, ���� ������ ������ ä�� �ִ´�.

	return 0;
}