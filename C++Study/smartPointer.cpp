#include <iostream>

int main()
{
	int* p1 = 0;
	int* p2 = NULL;
	int* p3 = nullptr;

	// 포인터 변수를 초기화하기 위해 기존의 방식대로 0, NULL을 사용해도 되지만
	// nullptr을 사용하는 것이 안전하고 코드의 가독성을 높일 수 있다.

	// nullptr의 데이터 타입
	// std::nullptr_t 타입
}

///////////////////////////
//using
#include <unordered_map>
#include <string>
#include <memory>

int main()
{
	typedef std::unique_ptr < std::unordered_map < std::string, std::string>> UPtrMapSS;

	// 위와 동일한 코드임, 더 가독성있다.
	using UPtrMapSS = std::unique_ptr < std::unordered_map < std::string, std::string>>;

	// 1. 이해하기 쉽다.
	typedef void (*FP)(int, const std::string&);	// typedef
	using FP = void (*)(int, const std::string&);	// 별칭 선언(alias)

	// 2. typedef는 템플릿화를 할 수 없지만 별칭 선언은 템플릿화할 수 있다.
	// typedef

}

class Widget {};

template <typename T>
struct My
{
	typedef std::list<T, My<T>> type;
};

template <typename T>
using Myall = std::list<T, My<T>>;

int main()
{
	My<Widget>::type lw;

	Myall<Widget> lw;
}

//////////////////////////////////////////////
////////////////////////////////////////////////
// 포인터의 문제점
// 포인터가 가리키는 주소의 값이 배열인지 하나의 객체인지 판별이 불가능 -> 포인터 선언의 타입
// 파괴하기 위해 어떤 방법을 써야할 지 알아낼 방법이 없다. delete를 써야할지, delete[]를 써야할지
// 포인터가 가리키는 대상을 내가 소유하고 있는지 아닌지 알 수 있는 방법이 없다. -> 배타적 소유권
// 댕글링 포인터(dangling pointer), 자원이 이미 해제된 자원인지 아닌지 판별할 수 없다.
// 자원 해제는 정확히 한 번만 해야한다. -> 중복 해제 방지 방법

// C++11 부터는 다음과 같은 새로운 스마트 포인터를 제공한다.
// unique_ptr : 배타적 소유권
// shared_ptr : 공유 자원 관리
// weak_ptr : shared_ptr 보완
using namespace std;

class Foo
{
public:
	Foo() { std::cout << "생성\n"; }
	~Foo() { std::cout << "소멸\n"; }
};

int main()
{
	Foo* ptr = new Foo();
	delete ptr;

	unique_ptr<Foo> sptr(new Foo());				// 객체 2개 생성
	unique_ptr<Foo> ssptr = make_unique<Foo>();		// C++14

	// 해제하지 않아도 자동으로 소멸된다.

	// 블럭 단위로 작동한다.
	{
		unique_ptr<Foo> ptr2 = make_unique<Foo>();
		// 블록을 벗어나는 순간 ptr2 삭제, 메모리해제, 소멸자 호출...
	}

	{
		new
		throw	// throw만나면 블럭 밖으로 가버림, delete 호출 X
		delete
	}

}

/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// RAII 패턴
// Resource Acquisition Is Initialization
// 자원의 획득은 초기화다
// 스택에 할당된 메모리는 자동으로 해제되는 것을 이용한 디자인 패턴
