#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Sum(int a, int b)
{
	return a + b;
}

double Sum(int a, int b)
{
	return a + b;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// �����ε��� ���� Ÿ���� ������� �ʴ´�.
	// double Sum(int a, int b), int Sum(int a, int b)�� �����ε��� �������� �ʴ´ٰ� �Ѵ�.
	// ��¥����? ���� Sum�Լ��� ȣ���ϸ� �� �߿� ��� ���� ȣ��Ǵ���?

	// -> ���ʿ� ��ȯ �������θ� ���еǴ� �Լ��� �����ε��� �� ���ٰ� ������ ������ ���.

	return 0;
}