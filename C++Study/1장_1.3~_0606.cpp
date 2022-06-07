/// 유니폼 초기화
//c++ 11 이전에는 타입의 초기화 방식이 일정하지 않았다. 
// 예를 들어 다음과 같이 원을 정의할 때 한 번은 구조체로, 한 번은 클래스로 작성한 경우를 살펴보자.
struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius)
		: mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;
};

// c++ 11 이전에는 CircleStruct 타입 변수와 CircleClass 타입 변수를 초기화하는 방법이 서로 달랐다.
CircleStruct myCircle1 = { 10, 10, 2.5 };
CircleClass myCircle2(10, 10, 2.5);
// 구조체에 대해서는 {...} 문법을 적용한 반면, 클래스에 대해서는 함수 표기법인 (...)로 생성자를 호출했다.
// 그런데 C++ 11 부터 타입을 초기화할 때 {...} 문법을 사용하는 유니폼 초기화(균일 초기화, 중괄호 초기화)를 따르도록 통일됐다.
CircleStruct myCircle3 = { 10, 10, 2.5 };
CircleClass myCircle4 = { 10, 10, 2.5 };
// myCircle4를 정의하는 문장이 실행될 때 CircleClass의 생성자가 자동으로 호출된다.
// 또한 다음과 같이 등호(=)를 생략해도 된다.
CircleStruct myCircle5{ 10, 10, 2.5 };
CircleClass myCircle6{ 10, 10, 2.5 };

// 이러한 유니폼 이니셜라이저는 구조체나 클래스뿐만 아니라 c++에 있는 모든 대상을 초기화하는 데 적용된다.
// 예를 들어 다음 코드는 네 변수를 모두 3이란 값으로 초기화한다.
int a = 3;
int b(3);
int c = { 3 };	// 유니폼 초기화
int d{ 3 };		// 유니폼 초기화

// 유니폼 초기화는 변수를 영 초기화(제로 초기화)할 때도 적용할 수 있다.
// 다음과 같이 중괄호로 빈 집합 표시만 해주면 된다.
int e{};	// 유니폼 초기화, e는 0이 된다.

// 유니폼 초기화를 사용하면 축소 변환(narrowing)을 방지할 수 있다.
// c++에서는 암묵적으로 축소 변환될 때가 있는데, 예를 들면 다음과 같다.
void func(int i) { }

int main()
{
	int x = 3.14;
	func(3.14);
}
// x에 값을 대입할 때와 func()를 호출할 때 전달한 3.14는 3으로 값이 줄어든다.
// 컴파일러에 따라 이렇게 축소할 때마다 경고 메시지가 발생할 수도 있다. (예: MS 비주얼 스튜디오 2017 커뮤니티 에디션)
// 유니폼 초기화를 사용하면 x에 값을 대입하거나 func()를 호출하는 문장이 담긴 코드를 c++ 11 표준을 완전히 지원하는 컴파일러로 컴파일하면
// 반드시 에러 메시지가 생성된다.
void func(int i) { }

int main()
{
	int x = { 3.14 };	// 축소로 인한 에러
	func({ 3.14 });		// 축소로 인한 에러
}

// 유니폼 초기화는 동적으로 할당되는 배열을 초기화할 때도 적용할 수 있다.
// 예를 들면 다음과 같다.
int* pArray = new int[4]{ 0, 1, 2, 3 };

// 또한 클래스 멤버인 배열을 생성자 이니셜라이저로 초기화할 때도 사용할 수 있다.
class MyClass
{
public:
	MyClass() : mArray{ 0, 1, 2, 3 } {}
private:
	int mArray[4];
};

/// 직접 리스트 초기화와 복제 리스트 초기화
// 이니셜라이저는 다음 두 가지가 있으며, 이니셜라이저 리스트를 중괄호로 묶어서 표현한다.
// 복제 리스트 초기화(copy list initialization): T obj = {arg1, arg2, ...};
// 직접 리스트 초기화(direct list initialization): T obj {arg1, arg2, ...};

// c++ 17 부터는 auto 타입 추론 기능과 관련하여 복제 리스트 초기화와 직접 리스트 초기화가 크게 달라졌다.
// c++ 17 이전 (c++ 11/14)에는 복제 리스트 초기화와 직접 리스트 초기화 모두 initializer_list<>로 처리했다.
#include <initializer_list>
// 복제 리스트 초기화
auto a = { 11 };		// initializer_list<int>
auto b = { 11, 22 };	// initializer_list<int>

// 직접 리스트 초기화
auto c{ 11 };			// initializer_list<int>
auto d{ 11, 22 };		// initializer_list<int>

// c++ 17부터는 auto는 직접 리스트 초기화에 대해 값 하나만 추론한다.
// 따라서 이 코드를 실행하면 에러가 발생한다.
// 복제 리스트 초기화
auto a = { 11 };		// initializer_list<int>
auto b = { 11, 22 };	// initializer_list<int>

// 직접 리스트 초기화
auto c{ 11 };			// int
auto d{ 11, 22 };		// 원소가 너무 많다는 에러가 발생한다.

// 복제 리스트 초기화에서 중괄호 안에 나온 원소는 반드시 타입이 모두 같아야 한다.
// 예를 들어 다음과 같이 작성하면 컴파일 에러가 발생한다.
auto b = { 11, 22.33 };		// 컴파일에러