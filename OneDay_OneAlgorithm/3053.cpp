#include <iostream>

// for PI
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int r;
	cin >> r;

	// ��Ŭ���� �����п��� �������� r�� ���� ����
	double circle = M_PI * r * r;
	printf("%lf", circle);
	printf("\n");

	// �ýñ����п��� ������ r�� ���� ����
	double taxi = (double)r * (double)r * 2;
	printf("%lf", taxi);

	return 0;
}