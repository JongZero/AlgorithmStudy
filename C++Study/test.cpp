#include <vector>
#include <iostream>
using namespace std;

/*
class A {
public:
	A( int i ) { std::cout << "A (i)\n"; }
	A() { std::cout << "A ()\n"; }
	A( const A& a ) noexcept { std::cout << "A (A &)\n"; }
	A( A&& a ) { std::cout << "A (A &&)\n"; }

};

int main() {
	std::vector<A> v;
	v.reserve( 2 );
	std::cout << "push_back" << std::endl;
	v.push_back( 1 );
	std::cout << "emplace_back" << std::endl;
	v.emplace_back( 1 );
}
*/

// emplace가 더 비효율적인 경우
class A {
public:
	A( int i ) {
		std::cout << "A's c'tor" << std::endl;
	}
	A( const A& a ) {
		std::cout << "A's copy c'tor" << std::endl;
	}
	A( A&& a ) {
		std::cout << "A's move c'tor" << std::endl;
	}

};

int main() {
	std::cout << "first call" << std::endl;
	std::vector<A> v;
	v.emplace_back( 1 );
	std::cout << "second call" << std::endl;
	v.emplace_back( A( 1 ) );
}