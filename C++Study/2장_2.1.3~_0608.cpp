#include <string>
using namespace std;

/// C++ std::string Ŭ����
string myString = "hello";
myString += "!";

string myOtherString = myString;
if (myString == myOtherString)
{
	myOtherString[0] = 'H';
}

cout << myString << endl;			// ��� : hello, there
cout << myOtherString << endl;		// ��� : Hello, there
// �� �������� ��Ʈ���� �Ҵ��ϰų� ũ�⸦ �����ϴ� �ڵ尡 ���� ���� ����� �־ �޸� ������ �߻����� �ʴ´�.
// string ��ü�� ��� ���� ������ �����Ǳ� �����̴�.
// string Ŭ������ ����ϸ� �޸𸮸� �Ҵ��ϰų� ũ�⸦ ������ ���� ����� ���� ������ string ��ü�� �������� ����ڸ���
// ���⿡ �Ҵ�� �޸𸮸� string �Ҹ��ڰ� ��� �����Ѵ�.

// string Ŭ�������� �����ϴ� c_str() �޼��带 ����ϸ� C �� ���� ȣȯ���� ������ �� �ִ�.
// �� �޼���� C ��Ÿ�� ��Ʈ���� ǥ���ϴ� const ���� �����͸� �����Ѵ�.
// ������ string�� ���� �޸𸮸� �ٽ� �Ҵ��ϰų� �ش� string ��ü�� �����ϸ� �� �޼��尡 ������ const �����͸� �� �̻� ����� �� ���� �ȴ�.
// ���� ���� string�� ��� ������ ��Ȯ�� ����Ϸ��� �� �޼��带 ȣ���� ���Ŀ� ���ϵ� �����͸� Ȱ���ϵ��� �ڵ带 �ۼ��ϴ� ���� ����.
// ���� �Լ� �ȿ� ������ ���� ��� string ��ü�� ���ؼ��� c_str()�� ȣ���� ����� ����� ���ϰ����� �����ϸ� �� �ȴ�.

// ���� string���� �����ϴ� data() �޼���� c++ 14������ �ص� c_str()ó�� const char* Ÿ������ ���� �����ߴ�.
// �׷��� c++ 17 ���ʹ� non-const ��Ʈ���� ���� ȣ���ϸ� char*�� �����ϵ��� ����ƴ�.

/// std::string ���ͷ�
// �ҽ� �ڵ忡 ���� ��Ʈ�� ���ͷ��� �ַ� const char*�� ó���Ѵ�.
// ǥ�� ����� ���� ���ͷ� 's'�� ����ϸ� ��Ʈ�� ���ͷ��� std::string���� ���� �� �ִ�.
auto string1 = "Hello World";		// string1�� Ÿ���� const char*�̴�.
auto string2 = "Hello World"s;		// string2�� Ÿ���� std::string�̴�.
// ǥ�� ����� ���� ���ͷ� 's'�� ����Ϸ��� using namespace std::string_literals; �Ǵ�
// using namespace std; �� �߰��ؾ� �Ѵ�.

/// ���� ���� ���� ��ȯ
// std ���ӽ����̽��� ���ڿ� string�� ���� ��ȯ�� �� �ֵ��� �پ��� ���� �Լ��� �����Ѵ�.
// ���� Ÿ���� string���� ��ȯ�ϴ� �Լ��� ������ ����.
// �� �Լ����� �޸� �Ҵ� �۾��� ó�����ش�
// �� �Լ����� string ��ü�� ���� �����Ͽ� �����Ѵ�.
string to_string(int val);
string to_string(unsigned val);
string to_string(long val);
string to_string(unsigned long val);
string to_string(long long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

// �̿� �ݴ�� ��ȯ�ϴ� �Լ��� ������ ���� std ���ӽ����̽��� ���ǵǾ� �ִ�.
// �� �Լ��� ������Ÿ�Կ��� str�� ��ȯ�Ϸ��� ���� string ���� �ǹ��ϰ�, 
// idx�� ���� ��ȯ���� ���� �κ��� �� �տ� �ִ� ������ �ε����� ����Ű�� �����Ͱ�,
// base�� ��ȯ�� ���� ��(base, ���, ����)�̴�.
// idx �����͸� �� �����ͷ� �����ϸ� �� ���� �����Ѵ�.
// ���� ���� ��ȯ �Լ����� ���� �տ� ���� ���� ���ڸ� �����ϰ�,
// ��ȯ�� �����ϸ� invalid_argument �ͼ����� ������,
// ��ȯ�� ���� ���� Ÿ���� ������ ����� out_of_range �ͼ����� ������.
int stoi(const string & str, size_t* idx = 0, int base = 10);
long stol(const string & str, size_t* idx = 0, int base = 10);
unsigned long stoul(const string & str, size_t* idx = 0, int base = 10);
long long stoll(const string & str, size_t* idx = 0, int base = 10);
unsigned long long stoull(const string & str, size_t* idx = 0, int base = 10);
float stof(const string & str, size_t* idx = 0);
double stod(const string & str, size_t* idx = 0);
long double stold(const string & str, size_t* idx = 0);

#include <iostream>

// ���� ��� ������ ����.
int main()
{
	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);	// index�� 4����(���� ��ȯ���� ���� �κ��� �� �տ� �ִ� ������ �ε���)

	cout << "Parsed value : " << value << endl;
	cout << "First non-parsed character : '" << toParse[index] << "'" << endl;
}
// �� �ڵ��� ���� ����� ������ ����.
// Parsed value : 123
// First non-parsed character : 'U'

#include <charconv>
/// �ο� ���� ���� ��ȯ
// c++ 17���� �ο� ���� ���� ��ȯ�� ���� �Լ��� �پ��ϰ� �����ȴ�.
// �� �Լ��� <charconv> ����� ���ǵǾ� �ִ�.
// �� �Լ��� �޸� �Ҵ翡 ���õ� �۾��� ���� ������ �ʱ� ������ ȣ���� ������ ���۸� �Ҵ��ϴ� ������� ����ؾ� �Ѵ�.
// ���� ���ɰ� ������ �������� Ʃ�׵ƴ�.
// �׷��� �ٸ� ���� ���� ���� ��ȯ �Լ��� ���� ó�� �ӵ��� ��û���� ������.
// ���� �����Ϳ� ����� �б� ���� ����(��:JSON, XML��) ������ ��ȯ �۾��� �����Ͽ� �������̸鼭 ���� �ӵ��� ó���ϰ� �ʹٸ�
// �̷��� �ο� ���� �Լ��� ����Ѵ�.
// ������ ���ڷ� ��ȯ�Ϸ��� ������ ���� �Լ��� ����Ѵ�.
to_chars_result to_chars(char* first, char* last, IntegerT value, int base = 10);
// ���⼭ IntegerT �ڸ��� �ִ� ��ȣ �ִ� ������ ��ȣ ���� ���� �Ǵ� char Ÿ���� ���� �� �ִ�.
// ����� to_chars_result Ÿ������ ���ϵǸ�, ������ ���� ���ǵǾ� �ִ�.
struct to_chars_result
{
	char* ptr;
	errc ec;
};

// ���������� ��ȯ�ƴٸ� ptr ����� ������ �� ��° ���ڸ� ����Ű��, �׷��� ������ last ���� ����.
// (�̶� ec == errc::value_too_large��)
// ���� ��� ������ ����.
std::string out(10, ' ');
auto result = std::to_chars(out.data(), out.data() + out.size(), 12345);
if (result.ec == std::errc())
{
	// ����� ��ȯ�� ���
}

// 1�忡�� �Ұ��� c++ 17�� ������ ���ε��� �����ϸ� ������ ���� ǥ���� �� �ִ�.
std::string out(10, ' ');
auto [ptr, ec] = std::to_chars(out.data(), out.data() + out.size(), 12345);
if (result.ec == std::errc())
{
	// ����� ��ȯ�� ���
}

// ���� ������ ���� �ε��Ҽ��� Ÿ�Կ� ���� ��ȯ �Լ��� �����Ѵ�.
to_chars_result to_chars(char* first, char* last, FloatT value);
to_chars_result to_chars(char* first, char* last, FloatT value, chars_format format);
to_chars_result to_chars(char* first, char* last, FloatT value, chars_format format, int precision);
// ���⼭ FloatT �ڸ��� float, double, long double�� ���� �� �ִ�.
// ��ü���� ������ ������ ���� ���ǵ� chars_format �÷��׸� �����ؼ� ������ �� �ִ�.
enum class chars_format
{
	scientific,						// ��Ÿ��: (-)d.ddde��dd
	fixed,							// ��Ÿ��: (-)ddd.ddd
	hex,							// ��Ÿ��: (-)h.hhhp��d(����: 0x�� ���� �ʴ´�)
	general = fixed | scientific	// ���� ���� ����
};
// �⺻ ������ chars_format::general�� �����ϸ� to_chars()�� �ε��Ҽ������� ������ ǥ����� (-)ddd.ddd��
// ������ ���� ǥ����� (-)d.ddde��dd �߿��� �Ҽ��� ���ʿ� ������ ���ڸ� ǥ���� �� ��ü ���̰� ���� ª�� ���·� ��ȯ�ȴ�.
// (��: 100.001 ���ٴ� 1.0e+6 ����)
// ���˿� ���е��� �������� ������ �־��� ���˿��� ���� ª�� ǥ���� �� �ִ� ���·� �����ȴ�.
// ����� ���е��� �ִ��� ���� �ڸ���.

// �ݴ� ����, �� ��Ʈ���� ���ڷ� ��ȯ�ϴ� �Լ��� �ִ�.
from_chars_result from_chars(const char* first, const char* last, IntegerT& value, 
							 int base = 10);
from_chars_result from_chars(const char* first, const char* last, IntegerT& value, 
							 chars_format format = chars_format::general);

// from_chars_result Ÿ���� ������ ���� ���ǵǾ� �ִ�.
struct from_chars_result
{
	const char* ptr;
	errc ec;
};
// ���⼭ ptr ����� ��ȯ�� ������ ��� ù ��° ���ڿ� ���� �����Ͱ� �ǰ�, ����� ��ȯ�� ���� last�� ����.
// ��ȯ�� ���ڰ� �ϳ��� ���ٸ� ptr�� first�� ������, ���� �ڵ�� errc::invalid_argument�� �ȴ�.
// �Ľ̵� ���� �ʹ� Ŀ�� ������ Ÿ������ ǥ���� �� ���ٸ� ���� �ڵ��� ���� errc::result_out_of_range�� �ȴ�.
// ����� from_chars()�� �տ� ���� ���� ���ڸ� �������� �ʴ´�.

/// std::string_view Ŭ����
// c++ 17 �������� �б� ���� ��Ʈ���� �޴� �Լ��� �Ű����� Ÿ���� ���� ������ �� ������.
// const char*�� �����ϸ� std::string�� ����ϴ� Ŭ���̾�Ʈ���� c_str()�� data()�� �̿��Ͽ� string�� const char*�� ��ȯ�ؼ� ȣ���ؾ� �Ѵ�.
// �� �ɰ��� ������ �̷��� �ϸ� std::string�� ��ü���� �Ӽ��� ���⼭ �����ϴ� �پ ���� �޼��带 ����� Ȱ���� �� ����.
// �׷��ٸ� �Ű������� const std::string&�� �����ϸ� �ɱ�? �׷��� �ϸ� �׻� std::string�� ����ؾ� �Ѵ�.
// ���� ��� ��Ʈ�� ���ͷ��� �����ϸ� �����Ϸ��� �� ��Ʈ�� ���ͷ��� ���纻�� ��� string ��ü�� �����ؼ� �Լ��� �����ϱ� ������ ������尡 �߻��Ѵ�.
// ��Ȥ �̷��� �Լ��� ���� �����ε� ������ ���� �� ����⵵ �ϴµ�(���� ��� � ������ const char*�� �ް�, �� � ������ const string&�� �޵���), �׸� ���õ� ����� �ƴϴ�.

// c++ 17���� �߰��� std::string_view Ŭ������ ����ϸ� �̷��� ����� �ذ��� �� �ִ�.
// �� Ŭ������ std::basic_string_view Ŭ���� ���ø��� �ν��Ͻ��μ� <string_view> ����� ���ǵǾ� �ִ�.
// string_view�� ������ const string& ��� ����� �� ������ ������嵵 ����. �ٽ� ���� ��Ʈ���� �������� �ʴ´�.
// string_view�� �������̽��� c_str()�� ���ٴ� ���� �����ϸ� std::string�� ����. data()�� �Ȱ��� �����ȴ�.
// string_view�� remove_prefix(size_t)�� remove_suffix(size_t)��� �޼��嵵 �߰��� �����ϴµ�,
// ������ �����¸�ŭ ��Ʈ���� ���� �����͸� ������ ���ų� �� �����͸� �ڷ� �̷Ｍ ��Ʈ���� ����ϴ� ����� �����Ѵ�.

// ����� string�� string_view�� ���� ����/������ �� ����.
// ���� ��� ������ ���� �ۼ��ϸ� ������ ������ �߻��Ѵ�.
string str = "Hello";
string_view sv = " world";
auto result = str + sv;

// ����� �������Ϸ��� ������ ���� ������ ���� �����Ѵ�.
auto result = str + sv.data();

// ���� �ڵ带 ���� �˰����� std::string�� ����� �� �ȴٸ� string_view�� ������ ���� ����� �ʰ� ��ٷ� �� �� �ִ�.
// ������ ���� extractExtension() �Լ��� �־��� ���ϸ��� Ȯ���ڸ� �̾Ƽ� �����Ѵ�.
// ����� string_view�� ��κ� ������ �����Ѵ�. ��Ʈ���� ���� �����Ϳ� ���̸� ���� �־ �����ϴ� �� ������尡 ���� �����̴�.
string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}
// �Լ��� �̷��� �����ϸ� ��� ������ ��Ʈ���� ������ �� �ִ�.
// ������ ���� ���̴�.
string fileName = R"(c:\temp\my file.ext)";
cout << "C++ string : " << extractExtension(fileName) << endl;

const char* cString = R"(c:\temp\my file.ext)";
cout << "C string : " << extractExtension(fileName) << endl;

cout << "Literal : " << extractExtension(R"(c:\temp\my file.ext)") << endl;
// ���⼭ extractExtension()�� ȣ���ϴ� �κп��� ���� ������ �ϳ��� �߻����� �ʴ´�.
// extractExtension() �Լ��� �Ű������� ���� Ÿ���� ���� �����Ϳ� ���̸� ��Ÿ����.
// �׷��� ������ ȿ�����̴�.

// string_view ������ �߿��� ����(raw) ���ۿ� ���̸� �Ű������� �޴� �͵� �ִ�.
// �̷��� �����ڴ� NUL�� ������ �ʴ� ��Ʈ�� ���۷� string_view�� ������ �� ����Ѵ�.
// ���� NUL�� ������ ��Ʈ�� ���۸� ����� ���� �����ϴ�.
// ������ ��Ʈ���� ���̸� �̹� �˰� �ֱ� ������ �����ڿ��� ���� ���� ���� �� �ʿ�� ����.
const char* raw = /* ... */;
size_t length = /* ... */;
cout << "Raw : " << extractExtension(string_view(raw, length)) << endl;

// string_view�� ����ϴ� �͸����� string�� ���������� �ʴ´�.
// string �����ڸ� ���� ȣ���ϰų� string_view::data()�� �����ؾ� �Ѵ�.
// ���� ��� ������ ���� const string&�� �Ű������� �޴� �Լ��� �ִٰ� ����.
void handleExtension(const string& extension) { /* ... */ }

// �� �Լ��� ������ ���� ȣ���ϸ� ����� �������� �ʴ´�.
handleExtension(extractExtension("my file.ext"));

// ����� ȣ���Ϸ��� ���� �� ���� ��� �� �ϳ��� �����Ѵ�.
handleExtension(extractExtension("my file.ext").data());	// data() �޼���
handleExtension(string(extractExtension("my file.ext")));	// ����� ctor

// ��� : �б� ���� ��Ʈ���� �޴� �Լ��� �޼����� �Ű����� Ÿ���� const std::string&�� const char* ��� std::string_view�� �����Ѵ�.

// std::string_view ���ͷ�
// ǥ�� ����� ���� ���ͷ��� 'sv'�� ����ϸ� ��Ʈ�� ���ͷ��� std::string_view�� ���� �� �ִ�.
// ���� ��� ������ ����.
auto sv = "My string_view"sv;

// ǥ�� ����� ���� ���ͷ��� 'sv'�� ����Ϸ��� using namespace std::string_view_literals; ��
// using namespace std; �� ������� �Ѵ�.