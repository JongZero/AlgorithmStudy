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

	// 오버로딩은 리턴 타입은 고려되지 않는다.
	// double Sum(int a, int b), int Sum(int a, int b)는 오버로딩이 성립하지 않는다고 한다.
	// 진짜인지? 만약 Sum함수를 호출하면 둘 중에 어느 것이 호출되는지?

	// -> 애초에 반환 형식으로만 구분되는 함수를 오버로드할 수 없다고 컴파일 에러가 뜬다.

	return 0;
}