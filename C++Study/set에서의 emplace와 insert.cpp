#include <set>
#include <iostream>
#include <string>
using namespace std;

/// Effective Modern C++ 예제

class AA
{
public:
	AA( string name, int num ) : _name(name), _num(num) { }

public:
	string _name;
	int _num;
};

int main()
{
	set<AA> _set;
	//_set.insert(5);		// 컴파일 에러
	_set.emplace(5);	// 컴파일 에러 X, -> string에 ""이 들어감
}