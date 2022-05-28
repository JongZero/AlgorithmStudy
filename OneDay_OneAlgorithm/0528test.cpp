#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base
{
public:
	void Func() { cout << "Base Func()" << '\n'; };
};

class Derived : public Base
{
public:
	void Func() { cout << "Dervied Func()" << '\n'; }
	void DerivedFunc() { cout << "sdfsdf\n"; }
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 의문 : 오버라이딩은 부모 클래스의 멤버 함수를 재정의 하는 것인데,
	//		 가상 함수가 아닌 멤버 함수를 재정의 하는 것도 오버라이딩인가?
	//		 -> 책에 따라 개념적으로 조금씩 다르다. 명품 C++은 가상 함수를 재정의하는 것이 오버라이딩이라고 말하고 있다.

	Base* d = new Derived;
	d->Func();

	delete d;

	// 의문 2 : dynamic_cast시에 상속 관계에 있지만 가상 함수가 하나도 없으면 컴파일 에러가 발생하는가?
	// -> 발생한다. 다형성을 가진 객체에서만 동작한다.
	dynamic_cast<Derived*>(d)->DerivedFunc();

	return 0;
}