#include <iostream>

/// unique_ptr, shared_ptr 배열 생성
// unique_ptr는 C 스타일 배열을 저장하는 데도 활용할 수 있다.
// 다음 예는 열 개의 Employee 인스턴스로 구성된 배열을 생성하여 이를 unique_ptr에 저장하고,
// 배열에 담긴 원소를 접근하는 방법을 보여주고 있다.
auto employees = make_unique<Employee[]>(10);
cout << "Salary : " << employees[0].salary << endl;

// c++ 17부터 shared_ptr에 배열도 저장할 수 있다. 이전 버전에서는 이 기능을 지원하지 않는다.
// 하지만 c++ 17에서 배열을 저장하는 shared_ptr를 생성할 때는 make_shared<>()를 사용할 수 없고,
// 다음과 같이 작성해야 한다.
shared_ptr<Employee[]> employees(new Employee[10]);
cout << "Salary : " << employees[0].salary << endl;

/// 익셉션
// c++은 유연성이 굉장히 뛰어난 반면 안전성은 그리 좋지 않다.
// 메모리 공간을 무작위로 접근하거나 0으로 나누는 연산을 수행하더라도 컴파일러는 가만히 내버려둔다(컴퓨터는 무한을 다룰 수 없음에도 불구하고)
// 이처럼 c++에 안전성을 좀 더 높이기 위해 제공하는 기능 중 하나로 익셉션(exception, 예외)가 있다.

// 익셉션이란 예상하지 못한 상황을 표현하는 클래스/객체다.
// 익셉션과 관련하여 몇 가지 새로운 용어가 등장한다.
// 코드에서 특정한 조건을 만족해서 익셉션을 발생시키는 것을 익셉션을 던진다(throw)고 표현하고, throw 구문으로 작성한다.
// 또한 이렇게 발생된 익셉션에 대해 적절한 동작을 수행하는 것을 익셉션을 잡는다(catch)고 표현하고, catch 구문으로 작성한다.
// 다음에 나오는 divideNumbers()란 함수를 사용해 익셉션을 던지고 잡는 예를 살펴보자.
// 이 함수는 전달된 분모의 인수가 0이면 익셉션을 발생시킨다.
// 여기서는 std::invalid_argument란 익셉션을 사용했는데, 이렇게 하려면 <stdexcept> 헤더 파일을 불러와야 한다.
double divideNumbers(double numerator, double denominator)
{
	if (denominator == 0)
	{
		throw invalid_argument("Denominator cannot be 0.");
	}
	return numerator / denominator;
}

// throw 문장이 실행되면 함수에서 값을 리턴하지 않고 실행을 즉시 중단한다.
// 이처럼 익셉션이 발생하는 함수를 호출할 때는 다음 코드처럼 try/catch 블록으로 감싼다.
// 그러면 함수에서 익셉션이 발생할 때 적절히 대처할 수 있다.

int main()
{
	try
	{
		cout << divideNumbers(2.5, 0.5) << endl;
		cout << divideNumbers(2.3, 0) << endl;
		cout << divideNumbers(4.5, 2.5) << endl;
	}
	catch (const invalid_argument& exception)
	{
		cout << "Exception caught: " << exception.what() << endl;
	}
}

// divideNumbers()를 처음 호출할 때는 정상적으로 실행되어 결과가 화면에 출력된다.
// 두 번째로 호출할 때는 익셉션이 발생한다.
// 아무런 값도 리턴되지 않기 때문에 익셉션을 잡았다는 에러 메시지만 화면에 출력된다.
// 세 번째로 호출하는 문장은 실행되지 않는다.
// 두 번째 호출에서 익셉션이 발생해서 프로그램의 실행 흐름이 곧바로 catch 블록으로 건너뛰었기 때문이다.
// 앞에 나온 코드를 실행한 결과는 다음과 같다.
// 5
// An exception was caught: Denominator cannot be 0.

// c++에서 익셉션을 제대로 처리하기 힘들 수도 있다.
// 익셉션을 제대로 활용하려면 익셉션을 던질 시점에 스택 변수에서 어떤 일이 일어나는지 파악해야 한다.
// 그리고 발생한 익셉션 중에서 꼭 처리해야 할 것만 잡아서 적절히 대처해야 한다.
// 앞에서는 c++에서 기본으로 제공하는 std::invalid_argument 타입의 익셉션을 사용했는데,
// 기왕이면 발생할 수 있는 상황에 딱 맞게 익셉션 타입을 직접 정의해서 사용하는 것이 좋다.

// 마지막으로 c++ 컴파일러는 발생 가능한 모든 익셉션을 꼭 잡도록 강제하지 않는다.
// 익셉션을 처리하는 코드를 따로 작성하지 않으면 프로그램 자체에서 처리하는데, 그러면 프로그램이 그냥 종료된다.

/// auto
// auto로 표현식의 타입을 추론하면 함수에 지정된 레퍼런스나 const 한정자가 제거된다.
// 예를 들어 다음과 같은 함수를 살펴보자.
#include <string>

const std::string message = "Test";

const std::string& foo()
{
	return message;
}

int main()
{
	auto f1 = foo();
}
// auto를 지정하면 레퍼런스와 const 한정자가 사라지기 때문에 f1은 string 타입이 된다.
// 따라서 값이 **복제되어버린다.**
// const 레퍼런스 타입으로 지정하려면 다음과 같이 auto 키워드 앞뒤에 레퍼런스 타입과 const 키워드를 붙인다.
const auto& f2 = foo();

// 결론 : auto를 지정하면 레퍼런스와 const 지정자가 사라져서 값이 복제된다는 점에 주의한다.
//			복제 방식으로 전달되지 않게 하려면 auto&나 const auto&로 지정한다.

/// decltype
// decltype 키워드는 인수로 지정한 표현식의 타입을 알아낸다.
// 예를 들면 다음과 같다.
int x = 123;
decltype(x) y = 456;
// 이렇게 작성하면 컴파일러는 y의 타입이 x의 타입인 int라고 추론한다.

// decltype은 레퍼런스나 const 지정자를 삭제하지 않는다는 점에서 auto와 다르다.
// 여기서 다시 string을 가리키는 const 레퍼런스를 리턴하는 함수 foo()를 살펴보자.
// f2를 다음과 같이 decltype로 정의하면 const string& 타입이 되어 복제 방식으로 처리하지 않는다.
decltype(foo()) f2 = foo();

// 얼핏 보면 decltype을 사용한다고 해서 특별히 나아질 게 없다고 생각할 수 있지만 템플릿을 사용할 때 상당히 강력한 효과를 발휘한다.