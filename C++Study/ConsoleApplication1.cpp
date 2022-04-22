// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// lvalue : 주소가 있는 것 변수
// rvalue : 주소가 없는 것 상수

// move 썼을 때는 lvalue를 rvalue로 변환

// 이동을 개행연산 move 생성자가 해주는 것
// move는 lvalue -> rvalue로 바꾸는 것





// Copy Ellision(복사 생략) - C++11
// 컴파일러가 복사 또는 이동 연산자를 회피 할 수 있으면 회피하는 것을 허용하는 방식
// Return Value Optimization / Named Return Value Optimization
//

struct Foo
{
    Foo() { std::cout << "생성됨"; }

};

Foo RVO_F()     // Return Value Optimization
{
    return Foo();
}

Foo NRVO_F()    // Named Return Value Optimization
{
    Foo foo;
    return foo;
}

int main()
{
    // 옵션을 켜줘야 작동함
    // (릴리즈에서 작동, 릴리즈로 빌드하는 이유)
    // 복사 생성 생략
    Foo rvo_foo = RVO_F();
}

////////////////////////////////////
// ////////////////////////////////
// Passing Temporary as Value

void f(Foo f)
{
    std::cout << "Fn\n";
}

int main()
{
    f(Foo());
}

//////////////////////////////////////
////////////////////////////////////
// 중괄호 초기화

int main()
{
    int value1 = 5; // C
    int value2(5);  // C++
    int value3{ 5 };// C++ 유니폼 초기화(균일한 초기화)
    int value4{};   // default 0

    // 중괄호 초기화는 축소변환(narrowing conversion)을 지원하지 않는다.
    // 즉 자동으로 변환되는 것을 막을 수 있다.

    // 컴파일 에러난다.
    int v1{ 5.1 };
    std::cout << v1 << '\n';

    double d{ 0.5f };
    int i{ d }; // error // 데이터가 잘리는 것을 지원하지 않는다.

    double x, y, z;
    int sum1{ x + y + z };  //error
    int sum2(x + y + z);    // ok
    int sum3 = x + y + z;   // ok
}

// 중괄호 초기화를 사용하면 좋은 점
// C++의 가장 성가신 구문 해석에서 자유롭다. //  함수연산자()
// 축소 변환(narrowing conversion)을 방지한다.

class A
{
public:
    A() {}
};

int main()
{
    A a();  // 함수 연산자다 객체 a를 만들고 기본 생성자 호출하는 것이 아님, 컴파일에러도 안남
    A a;    // 객체 a생성, 생성자 호출
}

class B
{
public:
    B(A a) {}
};

int main()
{
    B b(A());   // B를 리턴하는 b함수 호출
    B b{ A{} };   // A를 인자로 주고 B클래스 객체 b생성
}

// Initialize List
class A_Initial
{
public:
	A_Initial(std::initializer_list<int> I_list)
	{
		for (auto itr = I_list.begin(); itr != I_list.end(); ++itr)
		{
			std::cout << "I_List_생성자\n";
		}
	}
	A_Initial(int a) {}
};

int main()
{
	A_Initial a{ 1,2,3,4,5 };

	A_Initial a(3.5);      // 형변환
	A_Initial a{ 3.5 };    // 에러
}

//////////////////////////////////////
//////////////////////////////////////

int main()
{
    auto a = { 1 };     // 첫 번째 형태이므로 std::initializer_list<int>
    auto b{ 1 };        // 두 번째 형태이므로 그냥 int

    auto c = { 1,2 };   // initializer_list
    auto d{ 1,2 };      // 인자가 2개 이상이라 오류
    auto e = { 1,2,3.0 };   // std::initializer_list<T>의 T를 추론할 수 없어서 오류
    
    // 문자열
    auto list = { "a", "b", "c" };  // initializer_list<const char*>

    // using namespace std::literals; // 문자열 리ㅓ럴 연산자를 사용하기 위해 추가해줘야함
    // using namespace std도 가능 (std안에 포함되어 있어서)
    auto list = { "a"s, "b"s, "c"s };  // initializer_list<std::string>

}


//////////////////////////////////////////////////
// ////////////////////////////////////////////
// 템플릿은 리스트에 대해서 추론이 안된다.
template <typename T>
void foo(T param) {}

int main()
{
    // auto의 경우는 중괄호 초기치를 initializer_list로 추론
    auto x = { 11,23,9 };   // x의 타입은 std::initialier_list<int>

    // template의 T는 추론을 못함, 이것이 auto와 템플릿의 차이
    foo({ 11,23,9 });
}

// 이렇게하면 되긴 함
template <typename T>
void foo(std::initializer_list<int> T) {}


////////////////////////////////////////////
/////////////////////////////////////////////
// 오류 {1,2,3} 타입 추론 안됨
auto createInitList(void)
{
    return { 1,2,3 };
}

// 람다의 매개변수도 마찬가지로 initailzer_list의 타입 추론이 안됨


//////////////////////////////////////////
//////////////////////////////////////////

#include <vector>
int main()
{
    std::vector<int> v1(10, 20);        // 20 요소 10개 넣기
    std::vector<int> v2{ 10, 20 };      // 10, 20 (2개)
}

/////////////////////////////////////
////////////////////////////////////
