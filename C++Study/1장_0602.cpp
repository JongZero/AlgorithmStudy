#include <iostream>

using namespace std;		/// 헤더 파일 안에서는 절대로 using 문을 작성하면 안된다.
							// 그러면 그 헤더 파일을 인클루드하는 모든 파일에서 using 문으로 지정한 방식으로 호출해야 한다.

int main()
{
	/// \r : 캐리지 리턴 (출력 커서를 처음으로 옮김)
	/// printf()나 scanf()는 타입 안정성(타입 세이프)을 보장하지 않기 때문에 C++ 스트림 라이브러리 사용을 권장
	
	/// 리터럴 : 코드에 표시한 숫자나 스트링과 같은 값
	// C++은 다양한 표준 리터럴을 제공
	// 숫자는 다음과 같은 리터럴로 표현할 수 있음

	cout << 123 << '\n';		// 10진수 리터럴 (123)
	cout << 0173 << '\n';		// 8진수 리터럴 (123)
	cout << 0x7B << '\n';		// 16진수 리터럴 (123)
	cout << 0b1111011 << '\n';	// 2진수 리터럴 (123)
	
	cout << 3.14f << '\n';
	cout << 3.14 << '\n';
	cout << 'a' << '\n';
	cout << "character array" << '\n';

	// 숫자 리터럴에서는 자릿수 구분자를 사용할 수 있다.
	// 자릿수 구분자는 작은따옴표로 표현한다.
	cout << 23'456'789 << '\n';
	cout << 0.123'456f << '\n';
}

/// C++17 중첩된 네임스페이스
namespace MyLibraries
{
	namespace Networking
	{
		namespace FTP
		{
			// ...
		}
	}
}

// C++17에서는
namespace MyLibraries::Networking::FTP
{
	//...
}
// 또는 네임스페이스 앨리어스를 사용하여 다르게 표현하거나 더 짧게 만들 수 있음
namespace MyFTP = MyLibraries::Networking::FTP;

