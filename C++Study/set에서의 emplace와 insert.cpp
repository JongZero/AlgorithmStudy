#include <set>
#include <iostream>
#include <string>
using namespace std;

/// Effective Modern C++ ����

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
	//_set.insert(5);		// ������ ����
	_set.emplace(5);	// ������ ���� X, -> string�� ""�� ��
}