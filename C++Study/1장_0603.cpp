#include <iostream>
#include <array>

/// 타입
// enum과 enum class
// enum은 원래 타입을 엄격하게 따지지 않는다.
// 타입을 엄격히 따지는 것을 '스트롱 타입'또는 '타입에 안전하다(타입 세이프하다)'고 표현한다.
// enum 타입은 항상 정수로 해석하기 때문에 선언한 형태에 관계없이 모든 enum 타입을 서로 비교할 수 있다.
// 타입을 엄격하게 적용하고 싶다면 enum class를 사용한다.
enum class PieceType
{
	King = 1,
	Queen,		// 2
	Rook = 10,
	Pawn		// 11
};

// enum class로 정의한 열거 타입 값들의 이름은 스코프(유효 범위)가 자동으로 확장되지 않는다.
// 다시 말해 enum class 스코프 안에서만 유효하다. 따라서 열거 타입 값을 사용할 때마다 다음과 같이 스코프 지정 연산자를 붙여야 한다.
PieceType piece = PieceType::King;

// 또한 enum class로 정의한 열거 타입 값은 자동으로 정수 타입으로 변환되지 않는다.
// 그래서 다음과 같이 표현할 수 없다.
void f()
{
	//if (PieceType::Queen == 2) { }

	// 명시적으로 형변환하면 가능
	if (static_cast<int>(PieceType::Queen) == 2) { }
}

// 기본적으로 열거 타입의 값은 정수 타입으로 저장된다.
// 하지만 다음과 같이 내부 표현 타입을 바꿀 수 있다.
enum class PieceTypeUL : unsigned long 
{
	King = 1,
	Queen,		// 2
	Rook = 10,
	Pawn		// 11
};

// 결론 : 열거 타입을 사용할 때는 타입에 안전하지 않은, 즉 타입 언세이프한 enum보다는 스트롱 타입 버전인 enum class로 작성하는 것이 좋다.

/// 조건문
/// c++ 17 if문의 이니셜라이저
// c++ 17부터 if 문 안에 이니셜라이저(초기자)를 넣는 기능이 추가됐다.
// 문법은 다음과 같다.
// if (<이니셜라이저> ; <조건문>) { <본문> }

// <이니셜라이저>에서 정의한 변수는 <조건문>과 <본문> 안에서만 사용할 수 있고 if 문 밖에서는 사용할 수 없다.
// ex)

void init()
{
	//if (Employee employee = GetEmployee() ; employee.salary > 1000) { }
}
// <이니셜라이저>로 직원 정보를 가져와서 조건문에서 그 직원의 급여가 1000 이상인지 확인하고,
// 이를 만족하면 본문에 나온 코드를 실행한다.

enum class Color
{
	DarkBlue,
	Black,
	Red,
	Green,
};

void doSomethingForDarkBlue() {}

/// Switch
void swi(Color backGroundColor)
{
	switch (backGroundColor)
	{
	case Color::DarkBlue:
		doSomethingForDarkBlue();
		[[fallthrough]];
	case Color::Black:
		// ...
		break;
	}

	switch (backGroundColor)
	{
	case Color::DarkBlue:
		doSomethingForDarkBlue();
		[[fallthrough]];
	case Color::Black:
		// ...
		break;
	case Color::Red:
		[[fallthrough]];
	case Color::Green:
		// ...
		break;
	}
}


/// 논리 연산자
// C++은 논리 표현식을 단락 논리(축약 논리) 방식으로 평가한다.
// 다시 말해 표현식을 평가하는 도중에 최종 결과가 확정되면 나머지 부분은 평가하지 않는다.
// 예를 들어 다음 코드처럼 여러 개의 부울 표현식에 대한 논리 OR 연산을 평가할 때 결과가 true인 표현식을 발견하는
// 즉시 나머지 부분은 검사하지 않고 끝낸다.

bool result = bool1 || bool2 || (i > 7) || (27 / 13 % i + 1) < 2;
// 여기서 bool1이 true라는 결과가 나오면 표현식 전체가 true일 수밖에 없으므로 나머지 부분은 평가하지 않는다.

// 결론 : 단락 기능은 프로그램 성능을 높이는 데 도움 된다.
// 단락 되는 논리식을 작성할 때는 가볍게 검사할 수 있는 부분은 앞에 두고, 시간이 좀 걸리는 부분은 뒤에 둔다.

/// 함수
// 함수 리턴 타입 추론
// C++ 14부터는 함수의 리턴 타입을 컴파일러가 알아서 지정할 수 있다.
// 이 기능을 적용하려면 다음과 같이 리턴 타입 자리에 auto 키워드를 적는다.
auto addNumbers(int num1, int num2)
{
	return num1 + num2;
}
// 그러면 컴파일러는 return 문에 나온 표현식의 타입에 따라 리턴 타입을 추론한다.
// 함수 안에는 return문이 여러 개가 있을 수 있는데, 이때 각 타입은 모두 같아야 한다.
// 리턴값으로 재귀 호출문을 지정할 수도 있는데, 이때 재귀 호출이 아닌 return 문도 반드시 함께 지정한다.

// 현재 함수 이름
// 함수마다 내부적으로 __func__라는 로컬 변수가 정의되어 있다.
// 이 변수는 현재 함수의 이름을 값으로 갖고 있으며, 주로 로그를 남기는 데 활용한다.
int addNumbers(int num1, int num2)
{
	std::cout << "Entering function " << __func__ << std::endl;
	return num1 + num2;
}

/// C 스타일 배열
// 스택 기반의 C 스타일 배열의 크기는 C++ 17부터 제공하는 std::size() 함수로 알아낼 수 있다
// (이 함수를 사용하려면 <array> 헤더를 인클루드해야 한다)
// 예를 들면 다음과 같다.
int myArray[3] = { 0, };
unsigned int arraySize = std::size(myArray);

// 현재 사용하는 컴파일러가 C++ 17을 지원하지 않는다면 예전 방식처럼 sizeof 연산자로 크기를 구하면 된다.
// sizeof 연산자는 인수로 지정한 대상의 크기를 바이트 단위로 리턴한다.
// 스택 기반 배열에 담긴 원소 수를 알아내려면 이 연산자가 리턴한 값을 첫 번째 원소의 크기로 나눠야 한다.
// 예를 들면 다음과 같다.
unsigned int arraySize = sizeof(myArray) / sizeof(myArray[0]);

/// std::array
// C++에서는 std::array라는 고정 크기 컨테이너를 제공한다.
// 이 타입은 <array> 헤더 파일에 정의되어 있다.
// 사실 C 스타일 배열 위에 한 꺼풀 덮어쓴 것에 불과하다.

// std::array는 C 스타일 배열에 비해 여러가지 장점이 있다.
// 1. 항상 크기를 정확히 알 수 있음
// 2. 자동으로 포인터를 캐스팅(동적 형변환)하지 않아서 특정한 종류의 버그를 방지할 수 있음
// 3. 반복자(이터레이터)로 배열에 원소에 대한 반복문을 쉽게 작성 가능

std::array<int, 3> arr = { 9, 8, 7 };
unsigned int arrSize = arr.size();

/// 구조적 바인딩
// C++ 17부터 구조적 바인딩이란 개념이 도입됐다.
// 구조적 바인딩을 이용하면 여러 개의 변수를 선언할 때 배열, 구조체, 페어 또는 튜플의 값으로 초기화할 수 있다.
// 예를 들어 다음과 같이 배열이 정의되어 있다고 하자.
std::array<int, 3> values = { 11,22,33 };

int main()
{
	
}