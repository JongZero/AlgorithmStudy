#include <string>
using namespace std;

/// C++ std::string 클래스
string myString = "hello";
myString += "!";

string myOtherString = myString;
if (myString == myOtherString)
{
	myOtherString[0] = 'H';
}

cout << myString << endl;			// 출력 : hello, there
cout << myOtherString << endl;		// 출력 : Hello, there
// 이 예제에서 스트링을 할당하거나 크기를 조절하는 코드가 여러 군데 흩어져 있어도 메모리 누수가 발생하지 않는다.
// string 객체는 모두 스택 변수로 생성되기 때문이다.
// string 클래스를 사용하면 메모리를 할당하거나 크기를 조절할 일이 상당히 많긴 하지만 string 객체가 스코프를 벗어나자마자
// 여기에 할당된 메모리를 string 소멸자가 모두 정리한다.

// string 클래스에서 제공하는 c_str() 메서드를 사용하면 C 언어에 대한 호환성을 보장할 수 있다.
// 이 메서드는 C 스타일 스트링을 표현하는 const 문자 포인터를 리턴한다.
// 하지만 string에 대한 메모리를 다시 할당하거나 해당 string 객체를 제거하면 이 메서드가 리턴한 const 포인터를 더 이상 사용할 수 없게 된다.
// 따라서 현재 string에 담긴 내용을 정확히 사용하려면 이 메서드를 호출한 직후에 리턴된 포인터를 활용하도록 코드를 작성하는 것이 좋다.
// 또한 함수 안에 생성된 스택 기반 string 객체에 대해서는 c_str()을 호출한 결과를 절대로 리턴값으로 전달하면 안 된다.

// 또한 string에서 제공하는 data() 메서드는 c++ 14까지만 해도 c_str()처럼 const char* 타입으로 값을 리턴했다.
// 그러나 c++ 17 부터는 non-const 스트링에 대해 호출하면 char*를 리턴하도록 변경됐다.

/// std::string 리터럴
// 소스 코드에 나온 스트링 리터럴은 주로 const char*로 처리한다.
// 표준 사용자 정의 리터럴 's'를 사용하면 스트링 리터럴을 std::string으로 만들 수 있다.
auto string1 = "Hello World";		// string1의 타입은 const char*이다.
auto string2 = "Hello World"s;		// string2의 타입은 std::string이다.
// 표준 사용자 정의 리터럴 's'를 사용하려면 using namespace std::string_literals; 또는
// using namespace std; 를 추가해야 한다.

/// 하이 레벨 숫자 변환
// std 네임스페이스는 숫자와 string을 쉽게 변환할 수 있도록 다양한 헬퍼 함수를 제공한다.
// 숫자 타입을 string으로 변환하는 함수는 다음과 같다.
// 이 함수들은 메모리 할당 작업도 처리해준다
// 이 함수들은 string 객체를 새로 생성하여 리턴한다.
string to_string(int val);
string to_string(unsigned val);
string to_string(long val);
string to_string(unsigned long val);
string to_string(long long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

// 이와 반대로 변환하는 함수도 다음과 같이 std 네임스페이스에 정의되어 있다.
// 이 함수의 프로토타입에서 str은 변환하려는 원본 string 값을 의미하고, 
// idx는 아직 변환되지 않은 부분의 맨 앞에 있는 문자의 인덱스를 가리키는 포인터고,
// base는 변환할 수의 밑(base, 기수, 기저)이다.
// idx 포인터를 널 포인터로 지정하면 이 값을 무시한다.
// 여기 나온 변환 함수들은 제일 앞에 나온 공백 문자를 무시하고,
// 변환에 실패하면 invalid_argument 익셉션을 던지고,
// 변환된 값이 리턴 타입의 범위를 벗어나면 out_of_range 익셉션을 던진다.
int stoi(const string & str, size_t* idx = 0, int base = 10);
long stol(const string & str, size_t* idx = 0, int base = 10);
unsigned long stoul(const string & str, size_t* idx = 0, int base = 10);
long long stoll(const string & str, size_t* idx = 0, int base = 10);
unsigned long long stoull(const string & str, size_t* idx = 0, int base = 10);
float stof(const string & str, size_t* idx = 0);
double stod(const string & str, size_t* idx = 0);
long double stold(const string & str, size_t* idx = 0);

#include <iostream>

// 예를 들면 다음과 같다.
int main()
{
	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);	// index는 4가됨(아직 변환되지 않은 부분의 맨 앞에 있는 문자의 인덱스)

	cout << "Parsed value : " << value << endl;
	cout << "First non-parsed character : '" << toParse[index] << "'" << endl;
}
// 이 코드의 실행 결과는 다음과 같다.
// Parsed value : 123
// First non-parsed character : 'U'

#include <charconv>
/// 로우 레벨 숫자 변환
// c++ 17부터 로우 레벨 숫자 변환에 대한 함수도 다양하게 제공된다.
// 이 함수는 <charconv> 헤더에 정의되어 있다.
// 이 함수는 메모리 할당에 관련된 작업은 전혀 해주지 않기 때문에 호출한 측에서 버퍼를 할당하는 방식으로 사용해야 한다.
// 또한 고성능과 로케일 독립성에 튜닝됐다.
// 그래서 다른 하이 레벨 숫자 변환 함수에 비해 처리 속도가 엄청나게 빠르다.
// 숫자 데이터와 사람이 읽기 좋은 포맷(예:JSON, XML등) 사이의 변환 작업을 로케일에 독립적이면서 빠른 속도로 처리하고 싶다면
// 이렇나 로우 레벨 함수를 사용한다.
// 정수를 문자로 변환하려면 다음과 같은 함수를 사용한다.
to_chars_result to_chars(char* first, char* last, IntegerT value, int base = 10);
// 여기서 IntegerT 자리에 있는 부호 있는 정수나 부호 없는 정수 또는 char 타입이 나올 수 있다.
// 결과는 to_chars_result 타입으로 리턴되며, 다음과 같이 정의되어 있다.
struct to_chars_result
{
	char* ptr;
	errc ec;
};

// 정상적으로 변환됐다면 ptr 멤버는 끝에서 두 번째 문자를 가리키고, 그렇지 않으면 last 값과 같다.
// (이때 ec == errc::value_too_large다)
// 예를 들면 다음과 같다.
std::string out(10, ' ');
auto result = std::to_chars(out.data(), out.data() + out.size(), 12345);
if (result.ec == std::errc())
{
	// 제대로 변환된 경우
}

// 1장에서 소개한 c++ 17의 구조적 바인딩을 적용하면 다음과 같이 표현할 수 있다.
std::string out(10, ' ');
auto [ptr, ec] = std::to_chars(out.data(), out.data() + out.size(), 12345);
if (result.ec == std::errc())
{
	// 제대로 변환된 경우
}

// 또한 다음과 같이 부동소수점 타입에 대한 변환 함수도 제공한다.
to_chars_result to_chars(char* first, char* last, FloatT value);
to_chars_result to_chars(char* first, char* last, FloatT value, chars_format format);
to_chars_result to_chars(char* first, char* last, FloatT value, chars_format format, int precision);
// 여기서 FloatT 자리에 float, double, long double이 나올 수 있다.
// 구체적인 포맷은 다음과 같이 정의된 chars_format 플래그를 조합해서 지정할 수 있다.
enum class chars_format
{
	scientific,						// 스타일: (-)d.ddde±dd
	fixed,							// 스타일: (-)ddd.ddd
	hex,							// 스타일: (-)h.hhhp±d(주의: 0x는 적지 않는다)
	general = fixed | scientific	// 다음 문단 참조
};
// 기본 포맷인 chars_format::general을 적용하면 to_chars()는 부동소수점값을 십진수 표기법인 (-)ddd.ddd와
// 십진수 지수 표기법인 (-)d.ddde±dd 중에서 소수점 왼쪽에 나오는 숫자를 표기할 때 전체 길이가 가장 짧은 형태로 변환된다.
// (예: 100.001 보다는 1.0e+6 선택)
// 포맷에 정밀도를 지정하지 않으면 주어진 포맷에서 가장 짧게 표현할 수 있는 형태로 결정된다.
// 참고로 정밀도의 최댓값은 여섯 자리다.

// 반대 방향, 즉 스트링을 숫자로 변환하는 함수도 있다.
from_chars_result from_chars(const char* first, const char* last, IntegerT& value, 
							 int base = 10);
from_chars_result from_chars(const char* first, const char* last, IntegerT& value, 
							 chars_format format = chars_format::general);

// from_chars_result 타입은 다음과 같이 정의되어 있다.
struct from_chars_result
{
	const char* ptr;
	errc ec;
};
// 여기서 ptr 멤버는 변환에 실패할 경우 첫 번째 문자에 대한 포인터가 되고, 제대로 변환될 때는 last와 같다.
// 변환된 문자가 하나도 없다면 ptr은 first와 같으며, 에러 코드는 errc::invalid_argument가 된다.
// 파싱된 값이 너무 커서 지정된 타입으로 표현할 수 없다면 에러 코드의 값은 errc::result_out_of_range가 된다.
// 참고로 from_chars()는 앞에 나온 공백 문자를 무시하지 않는다.

/// std::string_view 클래스
// c++ 17 이전에는 읽기 전용 스트링을 받는 함수의 매개변수 타입을 쉽게 결정할 수 없었다.
// const char*로 지정하면 std::string을 사용하는 클라이언트에서 c_str()나 data()를 이용하여 string을 const char*로 변환해서 호출해야 한다.
// 더 심각한 문제는 이렇게 하면 std::string의 객체지향 속성과 여기서 제공하는 뛰어난 헬퍼 메서드를 제대로 활용할 수 없다.
// 그렇다면 매개변수를 const std::string&로 지정하면 될까? 그렇게 하면 항상 std::string만 사용해야 한다.
// 예를 들어 스트링 리터럴을 전달하면 컴파일러는 그 스트링 리터럴의 복사본이 담긴 string 객체를 생성해서 함수로 전달하기 때문에 오버헤드가 발생한다.
// 간혹 이러한 함수에 대해 오버로딩 버전을 여러 개 만들기도 하는데(예를 들어 어떤 버전은 const char*를 받고, 또 어떤 버전은 const string&을 받도록), 그리 세련된 방법은 아니다.

// c++ 17부터 추가된 std::string_view 클래스를 사용하면 이러한 고민을 해결할 수 있다.
// 이 클래스는 std::basic_string_view 클래스 템플릿의 인스턴스로서 <string_view> 헤더에 정의되어 있다.
// string_view는 실제로 const string& 대신 사용할 수 있으며 오버헤드도 없다. 다시 말해 스트링을 복사하지 않는다.
// string_view의 인터페이스는 c_str()이 없다는 점을 제외하면 std::string과 같다. data()는 똑같이 제공된다.
// string_view는 remove_prefix(size_t)와 remove_suffix(size_t)라는 메서드도 추가로 제공하는데,
// 지정한 오프셋만큼 스트링의 시작 포인터를 앞으로 당기거나 끝 포인터를 뒤로 미뤄서 스트링을 축소하는 기능을 제공한다.

// 참고로 string과 string_view를 서로 연결/결합할 수 없다.
// 예를 들어 다음과 같이 작성하면 컴파일 에러가 발생한다.
string str = "Hello";
string_view sv = " world";
auto result = str + sv;

// 제대로 컴파일하려면 마지막 줄을 다음과 같이 수정한다.
auto result = str + sv.data();

// 다음 코드를 보면 알겠지만 std::string을 사용할 줄 안다면 string_view의 사용법을 따로 배우지 않고도 곧바로 쓸 수 있다.
// 다음에 나온 extractExtension() 함수는 주어진 파일명에서 확장자만 뽑아서 리턴한다.
// 참고로 string_view는 대부분 값으로 전달한다. 스트링에 대한 포인터와 길이만 갖고 있어서 복사하는 데 오버헤드가 적기 때문이다.
string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}
// 함수를 이렇게 정의하면 모든 종류의 스트링에 적용할 수 있다.
// 다음과 같이 말이다.
string fileName = R"(c:\temp\my file.ext)";
cout << "C++ string : " << extractExtension(fileName) << endl;

const char* cString = R"(c:\temp\my file.ext)";
cout << "C string : " << extractExtension(fileName) << endl;

cout << "Literal : " << extractExtension(R"(c:\temp\my file.ext)") << endl;
// 여기서 extractExtension()을 호출하는 부분에서 복제 연산이 하나도 발생하지 않는다.
// extractExtension() 함수의 매개변수와 리턴 타입은 단지 포인터와 길이만 나타낸다.
// 그래서 굉장히 효율적이다.

// string_view 생성자 중에서 원시(raw) 버퍼와 길이를 매개변수로 받는 것도 있다.
// 이러한 생성자는 NUL로 끝나지 않는 스트링 버퍼로 string_view를 생성할 때 사용한다.
// 또한 NUL로 끝나는 스트링 버퍼를 사용할 때도 유용하다.
// 하지만 스트링의 길이를 이미 알고 있기 때문에 생성자에서 문자 수를 따로 셀 필요는 없다.
const char* raw = /* ... */;
size_t length = /* ... */;
cout << "Raw : " << extractExtension(string_view(raw, length)) << endl;

// string_view를 사용하는 것만으로 string이 생성되지는 않는다.
// string 생성자를 직접 호출하거나 string_view::data()로 생성해야 한다.
// 예를 들어 다음과 같이 const string&를 매개변수로 받는 함수가 있다고 하자.
void handleExtension(const string& extension) { /* ... */ }

// 이 함수를 다음과 같이 호출하면 제대로 동작하지 않는다.
handleExtension(extractExtension("my file.ext"));

// 제대로 호출하려면 다음 두 가지 방식 중 하나를 적용한다.
handleExtension(extractExtension("my file.ext").data());	// data() 메서드
handleExtension(string(extractExtension("my file.ext")));	// 명시적 ctor

// 결론 : 읽기 전용 스트링을 받는 함수나 메서드의 매개변수 타입은 const std::string&나 const char* 대신 std::string_view로 지정한다.

// std::string_view 리터럴
// 표준 사용자 정의 리터럴인 'sv'를 사용하면 스트링 리터럴을 std::string_view로 만들 수 있다.
// 예를 들면 다음과 같다.
auto sv = "My string_view"sv;

// 표준 사용자 정의 리터럴인 'sv'를 사용하려면 using namespace std::string_view_literals; 나
// using namespace std; 를 적어줘야 한다.