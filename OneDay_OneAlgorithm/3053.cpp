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

	// 유클리드 기하학에서 반지름이 r인 원의 넓이
	double circle = M_PI * r * r;
	printf("%lf", circle);
	printf("\n");

	// 택시기하학에서 반지름 r인 원의 넓이
	double taxi = (double)r * (double)r * 2;
	printf("%lf", taxi);

	return 0;
}