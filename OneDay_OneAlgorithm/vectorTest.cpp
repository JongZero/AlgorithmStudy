#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 1<<10 은 2의 10제곱인가?
	int a = 1 << 10;
	cout << a <<'\n';
	cout << pow(2, 10) << '\n';
	// -> 결론 : 맞다

	// vector capacity의 동작에 대해서
	vector<int> v;
	v.reserve(3);
	cout << v.capacity() << '\n';
	v.resize(4);
	cout << v.capacity() << '\n';

	// resize는 capacity를 증가시킬 뿐 아니라, 실제 원소의 개수도 채워 넣는다.

	return 0;
}